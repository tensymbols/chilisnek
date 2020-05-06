#pragma once
#include "Graphics.h"
#include "Location.h"

class Board {
public:
	Board(Graphics &gfx);
	void DrawCell(const Location &, const Color &);
	int GetGridHeight() const;
	int GetGridWidth() const ;
	bool IsInsideBoard(const Location&);
private:
	static constexpr int dim = 20;
	static constexpr int width = 40;
	static constexpr int height = 30;
	const int shift = 1;
	Graphics &gfx;
};