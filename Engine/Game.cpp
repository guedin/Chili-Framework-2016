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

	posX += velX;
	posY += velY;

	changeShape = wnd.kbd.KeyIsPressed(VK_SHIFT);
}

void Game::ComposeFrame()
{
	if (changeShape)
	{
		gfx.PutPixel(posX + 5, posY, red, green, blue);
		gfx.PutPixel(posX + 4, posY, red, green, blue);
		gfx.PutPixel(posX + 3, posY, red, green, blue);
		gfx.PutPixel(posX + 2, posY, red, green, blue);
		gfx.PutPixel(posX + 1, posY, red, green, blue);
		gfx.PutPixel(posX, posY, red, green, blue);
	}
	else
	{
		gfx.PutPixel(posX + 5, posY, red, green, blue);
		gfx.PutPixel(posX + 6, posY, red, green, blue);
		gfx.PutPixel(posX + 7, posY, red, green, blue);
		gfx.PutPixel(posX + 8, posY, red, green, blue);
		gfx.PutPixel(posX + 9, posY, red, green, blue);
		gfx.PutPixel(posX + 10, posY, red, green, blue);
		gfx.PutPixel(posX - 10, posY, red, green, blue);
		gfx.PutPixel(posX - 9, posY, red, green, blue);
		gfx.PutPixel(posX - 8, posY, red, green, blue);
		gfx.PutPixel(posX - 7, posY, red, green, blue);
		gfx.PutPixel(posX - 6, posY, red, green, blue);
		gfx.PutPixel(posX - 5, posY, red, green, blue);
		gfx.PutPixel(posX, posY + 5, red, green, blue);
		gfx.PutPixel(posX, posY + 6, red, green, blue);
		gfx.PutPixel(posX, posY + 7, red, green, blue);
		gfx.PutPixel(posX, posY + 8, red, green, blue);
		gfx.PutPixel(posX, posY + 9, red, green, blue);
		gfx.PutPixel(posX, posY + 10, red, green, blue);
		gfx.PutPixel(posX, posY - 10, red, green, blue);
		gfx.PutPixel(posX, posY - 9, red, green, blue);
		gfx.PutPixel(posX, posY - 8, red, green, blue);
		gfx.PutPixel(posX, posY - 7, red, green, blue);
		gfx.PutPixel(posX, posY - 6, red, green, blue);
		gfx.PutPixel(posX, posY - 5, red, green, blue);
	}
}
