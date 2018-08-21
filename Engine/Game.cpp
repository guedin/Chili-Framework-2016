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

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		velX = 0;
		velY = 0;
	}

	changeShape = wnd.kbd.KeyIsPressed(VK_SHIFT);

	// Keep inside the window box
	if (posX + 10 >= gfx.ScreenWidth)
	{
		posX = gfx.ScreenWidth - 11;
		velX = 0;
	}

	if (posX - 10 <= 0)
	{
		posX = 11;
		velX = 0;
	}

	if (posY + 10 >= gfx.ScreenHeight)
	{
		posY = gfx.ScreenHeight - 11;
		velY = 0;
	}

	if (posY - 10 <= 0)
	{
		posY = 11;
		velY = 0;
	}

	// Check Collision
	if ((posX - 10 < (shape2X + 10) && posX + 10 >(shape2X - 10)) && (posY - 10 < (shape2Y + 10) && posY + 10 > (shape2Y - 10)))
	{
		green = 0;
	}

	posX += velX;
	posY += velY;	
}

void Game::ComposeFrame()
{
	// Movable Shape
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

	//Fixed Shape
	gfx.PutPixel(shape2X + 5, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X + 6, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X + 7, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X + 8, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X + 9, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X + 10, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X - 10, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X - 9, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X - 8, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X - 7, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X - 6, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X - 5, shape2Y, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y + 5, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y + 6, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y + 7, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y + 8, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y + 9, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y + 10, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y - 10, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y - 9, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y - 8, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y - 7, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y - 6, red, green, 0);
	gfx.PutPixel(shape2X, shape2Y - 5, red, green, 0);

}
