#include "Board.h"


Board::Board(Graphics &gfx) :
	gfx(gfx) {
}

void Board::DrawCell(const Location &loc, const Color &c)
{

	int startX = dim * (loc.x)+shift;
	int endX = dim * (loc.x+1)-shift;
	int startY = dim * (loc.y)+shift;
	int endY = dim * (loc.y+1)-shift;

	gfx.DrawRect(startX,startY,endX,endY, c);
	
}

int Board::GetGridHeight() const  {
	return height;
}
int Board::GetGridWidth() const  {
	return width;
}

bool Board::IsInsideBoard(const Location &loc)
{

	return (loc.x>=0 && loc.x <width &&
			loc.y>=0 && loc.y < height);
}
