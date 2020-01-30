#include<iostream>
#include<graphics.h>
using namespace std;

class circle{
	
	private:int x, y, xc, yc, r, d;

	public:	
			void draw(){

				cout<<"Enter radius -> ";
				cin>> r;
				cout<<"Enter center -> ";
				cin>>xc>>yc;
				make();
			}
			void make(){

				int gd = DETECT , gm;
				initgraph(&gd, &gm, NULL);
				x = 0;
				y = r;

				d = 3 - 2*r;
				do{

					putpixel(x+xc , y+yc , WHITE);
					putpixel(x+xc , -y+yc , WHITE);
					putpixel(-x+xc , y+yc , WHITE);
					putpixel(-x+xc , -y+yc , WHITE);
					putpixel(y+xc , x+yc , WHITE);
					putpixel(y+xc , -x+yc , WHITE);
					putpixel(-y+xc , x+yc , WHITE);
					putpixel(-y+xc , -x+yc , WHITE);

					x += 1;
					if( d < 0 )
						d += 4*x + 6;
					else
						d += 4*x + 10;
				}while( x <= y );
				delay(4000);
			}
		
};
int main(int argc, char const *argv[]){

	circle c1;
	c1.draw();
	closegraph();
	return 0;
}