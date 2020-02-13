#include<iostream>
#include<graphics.h>
using namespace std;

class Inscribe{

	public:	
			int sign(int i){

				if( i < 0)
					return(-1);
				return(1);
			}

			void Line(int x1 , int y1 , int x2 , int y2){
				
				float dx = abs(x2 - x1);
				float dy = abs(y2 - y1);

				int g = (x2 > x1)?1:-1;

				float len = (dx > dy)?dx:dy;

				dx /= len; 
				dy /= len;

				//cout<<dx<<dy;

				float x = x1 + 0.5*sign(dx);
				float y = y1 + 0.5*sign(dy);

				for( int i = 0; i < len ; i++){

					putpixel((int)x , (int)y , WHITE);
					x += g*dx;
					y += dy;
				}

				
			}

			void circle(int xc, int yc, int r){

				int x = 0;
				int y = r;
				int d = 3 - 2*r;
				
				do{
					//delay(60);
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
						y -= 1;
						d += 4*(x-y) + 10;
					}
				}while( x <= y );
			}
			void draw(int xc, int yc, int r){

				int gd = DETECT , gm;

				initgraph(&gd , &gm , NULL);

				//outer circle
				circle(300, 300, r);

				//triangle 
				int s = 0.866*r;

				Line(300-s, 300+r/2, 300+s, 300+r/2);				
				Line(300, 300-r, 300-s, 300+r/2);
				Line(300, 300-r, 300+s, 300+r/2);

				//inner circle
				circle(300, 300, r/2);

				delay(4000);
				getch();
				closegraph();
			}
};
int main(int argc, char const *argv[])
{
	Inscribe i;
	i.draw(300, 300, 100);
	return 0;
}