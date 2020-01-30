#include<iostream>
#include<graphics.h>
using namespace std;

int sign(int i){

	if( i < 0)
		return(-1);
	return(1);
}

void Line(int x1 , int y1 , int x2 , int y2){

	int gd = DETECT , gm;

	//cin>>x1>>y1>>x2>>y2;

	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);

	float len = (dx > dy)?dx:dy;

	dx /= len; 
	dy /= len;

	cout<<dx<<dy;

	float x = x1 + 0.5*sign(dx);
	float y = y1 + 0.5*sign(dy);

	initgraph(&gd , &gm , NULL);

	for( int i = 0; i < len ; i++){

		putpixel((int)x , (int)y , WHITE);
		x += dx;
		y += dy;
	}

	getch();
	closegraph();
}

void Line(float x1 , float y1 , float x2 , float y2){

	int gd = DETECT , gm;

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

	float x = x1;
	float y = y1;

	int len = (dx>dy)?dx:dy;

	float p = 2*dy - dx;

	initgraph(&gd , &gm , NULL);

	if(dy > dx)
	{
		while(len--)
		{
			if(p <= 0)
			{

				x += 1;
				y += 1;

			}
			else{

				y += 1;
			}

			putpixel((int)x , (int)y , WHITE);
			p += 2*dy - 2*dx ;
		}
	}
	else
	{
		while(len--)
		{
			if(p >= 0)
			{

				x += 1;
				y += 1;

			}
			else{

				x += 1;
			}

			putpixel((int)x , (int)y , WHITE);
			p += 2*dy;
		}
	}

	getch();
	closegraph();

}


int main()
{
	/* code */
	Line(0 , 0 , 100 , 100);
	
	return 0;
}