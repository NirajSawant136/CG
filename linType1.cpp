#include<iostream>
#include<graphics.h>
using namespace std;

int sign(int i){

	if( i < 0)
		return(-1);
	return(1);
}

void dotLine(int x1 , int y1 , int x2 , int y2){

	

	//cin>>x1>>y1>>x2>>y2;

	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);

	float len = (dx > dy)?dx:dy;

	dx /= len; 
	dy /= len;


	float x = x1 + 0.5*sign(dx);
	float y = y1 + 0.5*sign(dy);

	

	int counter = 0;
	for( int i = 0; i < len ; i++){

		if(counter%6 == 0)
			putpixel((int)x , (int)y , WHITE);
		
		x += dx;
		y += dy;
		counter++;
	}

	getch();
	closegraph();
}
void dashLine(int x1 , int y1 , int x2 , int y2){

	//cin>>x1>>y1>>x2>>y2;

	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);

	float len = (dx > dy)?dx:dy;

	dx /= len; 
	dy /= len;

	float x = x1 + 0.5*sign(dx);
	float y = y1 + 0.5*sign(dy);

	

	int counter = 0;
	for( int i = 0; i < len ; i++){

		if(0 <= counter%20 && counter%20 <= 10)
			putpixel((int)x , (int)y , WHITE);

		counter++;
		x += dx;
		y += dy;
	}
	
	
}
void dotdashLine(int x1 , int y1 , int x2 , int y2){

	//cin>>x1>>y1>>x2>>y2;

	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);

	float len = (dx > dy)?dx:dy;

	dx /= len; 
	dy /= len;

	float x = x1 + 0.5*sign(dx);
	float y = y1 + 0.5*sign(dy);

	

	int counter = 0;
	for( int i = 0; i < len ; i++){

		if((0 <= counter%20 && counter%20 <= 10)||counter%5 == 0)
			putpixel((int)x , (int)y , WHITE);

		counter++;
		x += dx;
		y += dy;
	}
	
	
}
int main()
{
	int gd = DETECT , gm;
	initgraph(&gd , &gm , NULL);

	//dotLine(0 ,0 , 200 , 200);
	//dashLine(0 , 0 , 300 , 300);
	dotdashLine(0 , 0 , 300 , 300);

	getch();
	closegraph();
	
	return 0;
}