/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 5, y, r, g, b);
	gfx.PutPixel(x + 6, y, r, g, b);
	gfx.PutPixel(x + 7, y, r, g, b);
	gfx.PutPixel(x + 8, y, r, g, b);
	gfx.PutPixel(x + 9, y, r, g, b);
	gfx.PutPixel(x + 10, y, r, g, b);
	gfx.PutPixel(x - 10, y, r, g, b);
	gfx.PutPixel(x - 9, y, r, g, b);
	gfx.PutPixel(x - 8, y, r, g, b);
	gfx.PutPixel(x - 7, y, r, g, b);
	gfx.PutPixel(x - 6, y, r, g, b);
	gfx.PutPixel(x - 5, y, r, g, b);
	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x, y + 6, r, g, b);
	gfx.PutPixel(x, y + 7, r, g, b);
	gfx.PutPixel(x, y + 8, r, g, b);
	gfx.PutPixel(x, y + 9, r, g, b);
	gfx.PutPixel(x, y + 10, r, g, b);
	gfx.PutPixel(x, y - 10, r, g, b);
	gfx.PutPixel(x, y - 9, r, g, b);
	gfx.PutPixel(x, y - 8, r, g, b);
	gfx.PutPixel(x, y - 7, r, g, b);
	gfx.PutPixel(x, y - 6, r, g, b);
	gfx.PutPixel(x, y - 5, r, g, b);
}

void Game::KeepInsideScreen(int &posX, int &posY, int &velX, int &velY, int sizeX, int sizeY)
{
	if ((posX + sizeX) >= gfx.ScreenWidth)
	{
		posX = gfx.ScreenWidth - sizeX - 1;
		velX = 0;
	}

	if ((posX - sizeX) <= 0)
	{
		posX = sizeX + 1;
		velX = 0;
	}

	if ((posY + sizeY) >= gfx.ScreenHeight)
	{
		posY = gfx.ScreenHeight - sizeY - 1;
		velY = 0;
	}

	if ((posY - sizeY) <= 0)
	{
		posY = sizeY + 1;
		velY = 0;
	}
}

bool Game::IsShapeColliding()
{
	return false;
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!inhibitUp)
		{
			velY -= velInc;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!inhibitDown)
		{
			velY += velInc;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (!inhibitLeft)
		{
			velX -= velInc;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!inhibitRight)
		{
			velX += velInc;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		green = 0;
	}
	else
	{
		green = 255;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		velX = 0;
		velY = 0;
	}

	pos1X += velX;
	pos1Y += velY;

	KeepInsideScreen(pos1X, pos1Y, velX, velY, 10, 10);

	// Check Collision
	if ((pos1X - 10 <= (pos2X + 10) && pos1X + 10 >= (pos2X - 10)) && (pos1Y - 10 <= (pos2Y + 10) && pos1Y + 10 >= (pos2Y - 10)))
	{
		green = 0;
	}
}

void Game::ComposeFrame()
{
	// Movable Shape
	DrawBox(pos1X, pos1Y, red, green, blue);

	//Fixed Shape
	DrawBox(pos2X, pos2Y, red, green, 0);
}


