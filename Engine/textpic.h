#pragma once
#include "Graphics.h"
#include <vector>


class textpic {
public:
	textpic(const char[], Graphics&);
	void Draw(const int,const int, const int);
private:
	const char *gOverFile = new  char[128];
	FILE *fn;
	std::vector<std::vector<char>> gImage;
	
	Graphics& gfx;
};