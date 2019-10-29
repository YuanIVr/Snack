#include <iostream>
#include <cstdlib>
using namespace std;
int left = 0, right = 1, up = 2, down = 3;
typedef struct
{
	int x;
	int y;	
}Point;
typedef struct
{
	Point* pt;
	int length;
	char body;
}Snack;
typedef struct
{
	int x;
	int y;
	char body;
}Food;
void createSnack(Snack* sn, int x, int y, int len, char a)
{
	int i;
	(*sn).pt = (Point*)malloc(sizeof(Point) * len);
	Point* p = (*sn).pt;
	(*sn).length = len;
	for (i = 0; i< len; i++)
	{
		(*p).x = x + i;
		(*p).y = y;
		p++;
	}
	(*sn).body = a;
}
void toP(Snack* sn, int x, int y)
{
	Point* p = (*sn).pt;
	Point* p_ = (*sn).pt + 1;
	if ((*sn).length != 1 && x != (*p_).x && y != (*p_).y)
	{
		int i, ox, oy;
		ox = (*p).x;
		oy = (*p).y;
		(*p).x = x;
		(*p).y = y;
		for (i = 0; i < (*sn).length - 1; i++)
		{
			p++;
			(*p).x = ox;
			(*p).y = oy;
			if (i != (*sn).length - 1){
				ox = (*(p + 1)).x;
				oy = (*(p + 1)).y;
			}
		}
	}
}
void goP(Snack* sn, int type)
{
	int x = (*(*sn).pt).x;
	int y = (*(*sn).pt).y;
	switch (type)
	{
		case 0:
			toP(sn, x - 1, y);
			break;
		case 1:
			toP(sn, x + 1, y);
			break;
		case 2:
			toP(sn, x, y - 1);
			break;
		case 3:
			toP(sn, x, y + 1);
			break;
	}
}
