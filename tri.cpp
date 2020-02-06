#include<iostream>
#include<graphics.h>
using namespace std;

class triangle{

	public:	
			int sign(int i){

				if( i < 0)
					return(-1);
				return(1);
			}

			void line(int x1 , int y1 , int x2 , int y2){

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
					delay(10);
				}

				
			}

			void circle(int xc, int yc, int r){

				int x = 0;
				int y = r;
				int d = 3 - 2*r;
				
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
						y -= 1;
						d += 4*(x-y) + 10;
					}
				}while( x <= y );
			}
			void draw(int x1, int y1, int x2, int y2, int x3, int y3){

				int gd = DETECT , gm;

				initgraph(&gd , &gm , NULL);

				line(x1,  y1,  x2,  y2);
				line(x2,  y2,  x3,  y3);
				line(x1,  y1,  x3,  y3);
				circle(300, 300, 142);

				getch();
				closegraph();
			}
};
int main(int argc, char const *argv[])
{
	triangle t;
	t.draw(200, 200, 200, 400, 400, 400);
	return 0;
}