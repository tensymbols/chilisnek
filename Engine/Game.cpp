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
#include "SpriteCodex.h"
#include <iostream>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snek({ 5,5 }),
	goal(rng, brd, snek),
	gOver("gameover.txt", gfx),
	win("win.txt", gfx)
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
	if (isStarted) {
		if (!gameOver) {


			if (wnd.kbd.KeyIsPressed('W')) {
				deltaloc = { 0,-1 };
			}
			else
				if (wnd.kbd.KeyIsPressed('S')) {
					deltaloc = { 0,1 };
				}
				else
					if (wnd.kbd.KeyIsPressed('A')) {
						deltaloc = { -1,0 };
					}
					else
						if (wnd.kbd.KeyIsPressed('D')) {
							deltaloc = { 1,0 };
						}
			rateCnt++;
			if (rateCnt >= snekRate) {
				rateCnt = 0;
				const Location next = snek.GetNextHeadLocation(deltaloc);
				if (!brd.IsInsideBoard(next) || snek.IsInTileExceptEnd(next)   )
				{
					gameOver = 1;
				}
				else if (snek.GetCurrSize() > 99) {
					gameOver = 2;
				}
				else {
					const bool eating = next == goal.GetLocation();
					if (eating) {
						snek.Grow();
					}

					snek.moveDir(deltaloc);
					if (eating) {
						goal.Respawn(rng, brd, snek);
					}
				}
			}

		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_RETURN)) isStarted = true;
}

void Game::ComposeFrame()
{
	snek.Draw(brd);
	goal.Draw(brd);
	std::cout << "congrats you won!!";
	if (gameOver == 1) gOver.Draw(250,200, 10);
	else if (gameOver == 2) win.Draw(200, 250, 10);
	

	
	//if (gameOver) SpriteCodex::DrawGameOver(300,200,gfx);

}
