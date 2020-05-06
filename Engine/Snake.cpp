#include "Snake.h"

Snake::Snake(const Location &loc)
{
	segments[0].InitHead(loc);
}

Location Snake::GetNextHeadLocation(const Location & delta) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta);
	return l;
}

const int Snake::GetCurrSize()
{
	return currSize;
}

bool Snake::IsInTileExceptEnd(const Location &loc) const
{
	for (int i = 0; i < currSize-1; i++)
	{
		if(segments[i].GetLocation()==loc) return true;
	}

	return false;
}
bool Snake::IsInTile(const Location &loc) const
{
	for (int i = 0; i < currSize; i++)
	{
		if (segments[i].GetLocation() == loc) return true;
	}

	return false;
}

void Snake::moveDir( Location& delta) {
	for (int i = currSize -1; i > 0; i--)
	{
		segments[i].Follow(segments[i-1]);
	}
	segments[0].moveDir(delta);
}


void Snake::Grow() {
	if (currSize + 1 <= maxSeg) {
		segments[currSize].InitBody({ 255,0,unsigned char(230 - (currSize % 8) * 13),0});
		currSize++;
	}
}
void Snake::Draw(Board& brd) {
	for (int i = 0; i < currSize; i++)
	{
		segments[i].Draw(brd);
	}
}


void Snake::Segment::InitHead(const Location& loc_) {
	loc=loc_;
	c = Snake::HeadColor;
}

void Snake::Segment::InitBody(const Color &cl) {
	c = cl;
}
void Snake::Segment::Follow(const Segment& next) {
	loc = next.loc;
}
void Snake::Segment::Draw(Board& brd)  {
	brd.DrawCell(loc, c);
}
const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
void Snake::Segment::moveDir(const Location& delta) {
	loc.Add(delta);
}