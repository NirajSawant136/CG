#include<iostream>
#include<graphics.h>
using namespace std;

class Square{
	
	private:int x, y, xc, yc, r, d;

	public:	
			void draw(){

				cout<<"\nEnter radius -> ";
				cin>> r;
				cout<<"\nEnter center -> ";
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
					delay(60);
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
					else{
						//y += 1;
						d += 4*(x-y) + 10;
					}
				}while( x <= y );
			}
		
};
int main(){

	Square s1;
	s1.draw();
	getch();
	closegraph();
	return 0;
}