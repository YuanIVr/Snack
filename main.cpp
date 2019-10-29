#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "game.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
typedef struct
{
	int width;
	int height;
	char* pxs;
}Map;
void printMap(Map* map_);
void createMap(Map* map_, int w, int h, char a);
void putPx(Map* map_, int x, int y, char a);
void clrMap(Map* map_, char a);
int getLen(Map* map_);
void drawSnack(Snack* sn, Map* map)
{
	int i;
	Point* p = (*sn).pt;
	for (i = 0; i < (*sn).length; i++)
	{
		putPx(map, (*p).x, (*p).y, (*sn).body);
		p++;
	}
}
int mapLen;
Snack snack;
int date = 0;
void gameStart()
{
	createSnack(&snack, 7, 14, 4, '#');
}
void gameRun(Map* map_){
	clrMap(map_, '_');
	Map map = *map_;


	//
	//Update game data:
	goP(&snack, up);



	//
	//Draw game data:
	drawSnack(&snack, map_);



	//
	//Refresh screen:
	system("cls");
	printMap(map_);





	/*--------------------------
	---------------*/
	printf("%d", date);
	date++;
	sleep(0.01);
	gameRun(map_);
}
int main() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Map map;
	createMap(&map, 25, 20, '-');
	mapLen = getLen(&map);
	gameStart();
	gameRun(&map);
	return 0;
}
void printMap(Map* map_)
{
	Map map = *map_;
	int i, j;
	char* p = map.pxs;
	cout << p;
}
void createMap(Map* map_, int w, int h, char a)
{
	int i, j, size = (w * 2 + 1) * h + 1;
	char* p;
	(*map_).width = w;
	(*map_).height = h;
	(*map_).pxs = (char*)malloc(sizeof(char) * size);
	p = ((*map_).pxs);
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w * 2 + 1; j += 2)
		{
			if (j != w * 2)
			{
				*p = a;
				p++;
				*p = ' ';
				p++;
			}
			else 
			{
				*p = '\n';
				p++;
			}
		}
	}
	*p = '\0';

}
void putPx(Map* map_, int x, int y, char a)
{
	if (x >= 0 && x < (*map_).width && y >= 0 && y < (*map_).height)
	{
		char* p = (*map_).pxs;
		p += x * 2 + y * ((*map_).width * 2 + 1) - 2;
		*p = a;
	}
}
int getLen(Map* map_)
{
	return ((*map_).width * 2 + 1) * (*map_).height + 1;
}
void clrMap(Map* map_, char a)
{
	int i, j;
	char* p = (*map_).pxs;
	for (j = 0; j < (*map_).height; j++)
	{
		for (i = 0; i < (*map_).width; i++)
		{
			*p = a;
			p+=2;
		}
		p++;
	}
	
}