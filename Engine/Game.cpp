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
	gfx.PutPixel(405, 300, 255, 255, 255);
	gfx.PutPixel(406, 300, 255, 255, 255);
	gfx.PutPixel(407, 300, 255, 255, 255);
	gfx.PutPixel(408, 300, 255, 255, 255);
	gfx.PutPixel(409, 300, 255, 255, 255);
	gfx.PutPixel(410, 300, 255, 255, 255);
	gfx.PutPixel(390, 300, 255, 255, 255);
	gfx.PutPixel(391, 300, 255, 255, 255);
	gfx.PutPixel(392, 300, 255, 255, 255);
	gfx.PutPixel(393, 300, 255, 255, 255);
	gfx.PutPixel(394, 300, 255, 255, 255);
	gfx.PutPixel(395, 300, 255, 255, 255);
	gfx.PutPixel(400, 305, 255, 255, 255);
	gfx.PutPixel(400, 306, 255, 255, 255);
	gfx.PutPixel(400, 307, 255, 255, 255);
	gfx.PutPixel(400, 308, 255, 255, 255);
	gfx.PutPixel(400, 309, 255, 255, 255);
	gfx.PutPixel(400, 310, 255, 255, 255);
	gfx.PutPixel(400, 290, 255, 255, 255);
	gfx.PutPixel(400, 291, 255, 255, 255);
	gfx.PutPixel(400, 292, 255, 255, 255);
	gfx.PutPixel(400, 293, 255, 255, 255);
	gfx.PutPixel(400, 294, 255, 255, 255);
	gfx.PutPixel(400, 295, 255, 255, 255);
}
