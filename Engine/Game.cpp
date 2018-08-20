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
}

void Game::ComposeFrame()
{
	const int x = 200;
	const int y = 500;

	gfx.PutPixel(x+5, y, 255, 255, 255);
	gfx.PutPixel(x+6, y, 255, 255, 255);
	gfx.PutPixel(x+7, y, 255, 255, 255);
	gfx.PutPixel(x+8, y, 255, 255, 255);
	gfx.PutPixel(x+9, y, 255, 255, 255);
	gfx.PutPixel(x+10, y, 255, 255, 255);
	gfx.PutPixel(x-10, y, 255, 255, 255);
	gfx.PutPixel(x-9, y, 255, 255, 255);
	gfx.PutPixel(x-8, y, 255, 255, 255);
	gfx.PutPixel(x-7, y, 255, 255, 255);
	gfx.PutPixel(x-6, y, 255, 255, 255);
	gfx.PutPixel(x-5, y, 255, 255, 255);
	gfx.PutPixel(x, y+5, 255, 255, 255);
	gfx.PutPixel(x, y+6, 255, 255, 255);
	gfx.PutPixel(x, y+7, 255, 255, 255);
	gfx.PutPixel(x, y+8, 255, 255, 255);
	gfx.PutPixel(x, y+9, 255, 255, 255);
	gfx.PutPixel(x, y+10, 255, 255, 255);
	gfx.PutPixel(x, y-10, 255, 255, 255);
	gfx.PutPixel(x, y-9, 255, 255, 255);
	gfx.PutPixel(x, y-8, 255, 255, 255);
	gfx.PutPixel(x, y-7, 255, 255, 255);
	gfx.PutPixel(x, y-6, 255, 255, 255);
	gfx.PutPixel(x, y-5, 255, 255, 255);
}
