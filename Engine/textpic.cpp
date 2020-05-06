#include "textpic.h"

textpic::textpic(const char gOverFile[], Graphics& gfx): gOverFile(gOverFile), gfx(gfx){

	
	gImage.push_back(std::vector<char>());
	fn = fopen(gOverFile, "r");
	char c;

	int k = 0;
	while ((c = std::getc(fn)) != EOF) {
		gImage[k].push_back(c);
		if (c == '\n') {
			gImage.push_back(std::vector<char>());
			k++;
		}
	}
}

void textpic::Draw( int x,  int y,int dim)
{

	Color c = { 255,255,255 };
	for (size_t i = 0; i < gImage.size(); i++)
	{
		for (size_t j = 0; j < gImage[i].size(); j++)
		{
			if (gImage[i][j] == '1')	gfx.DrawRect(x+j*dim,y+i*dim, x + j *dim+dim, y + i *dim+dim, c );
		}
	}
}

