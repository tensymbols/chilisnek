#pragma once

#include "Board.h"

class Snake {
private:
	class Segment {
	public:
		void InitHead(const Location&);
		void InitBody(const Color&);
		void Follow(const Segment&);
		
		void moveDir(const Location&);
		void Draw(Board&) ;

		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;

	};
	int currSize = 1;
	static constexpr Color BodyColor = Colors::Cyan;
	static constexpr Color HeadColor = Colors::Yellow;
	static constexpr int maxSeg = 100;
	Segment segments[maxSeg];

	
public:
	Snake(const Location&);

	Location GetNextHeadLocation(const Location&delta) const;
	const int GetCurrSize();
	bool IsInTileExceptEnd(const Location &loc) const;
	bool IsInTile(const Location &loc) const;
	void Draw(Board&) ;
	void moveDir( Location&);
	void Grow();

};