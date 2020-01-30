#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

int sign(int i){

	if( i < 0)
		return(-1);
	return(1);
}

void Line(int x1 , int y1 , int x2 , int y2){

	

	//cin>>x1>>y1>>x2>>y2;

	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);

	float len = (dx > dy)?dx:dy;

	dx /= len; 
	dy /= len;

	cout<<dx<<dy;

	float x = x1 + 0.5*sign(dx);
	float y = y1 + 0.5*sign(dy);

	

	for( int i = 0; i < len ; i++){

		putpixel((int)x , (int)y , WHITE);
		x += dx;
		y += dy;
	}

}

void thickLine(int x1 , int y1 , int x2 , int y2 , int w){

	int gd = DETECT , gm;

	float Wy = ((w - 1)*sqrt( pow((x1-x2),2) + pow((y1-y2),2)))/(2*abs(x2-x1));
	float Wx = ((w - 1)*sqrt( pow((x1-x2),2) + pow((y1-y2),2)))/(2*abs(y2-y1));

	float m = (y2-y1)/(x2-x1);
	cout<<Wy<<" "<<Wx;
	initgraph(&gd , &gm , NULL);

	if(m <= 1){

		for(int i = 0 ; i < Wy; i++){

			Line(x1 , y1+i , x2 , y2+i);
			Line(x1 , y1-i , x2 , y2-i);
		}
		// Line(x1 , y1 , x2 , y2);

	}
	else if(m > 1){

		for(int i = 0 ; i < Wx; i++){

			Line(x1+i , y1 , x2+i , y2);
			Line(x1-i , y1 , x2-i , y2);
		}
		// Line(x1 , y1 , x2 , y2);

	}

	getch();
	closegraph();
}

int main(int argc, char const *argv[])
{
	/* code */
	thickLine(100 , 100 , 200 , 250 , 20);
	return 0;
}