#include<iostream>
#include<graphics.h>
using namespace std;

class Rect{

	private:int x, y, l, b;

	public:	
			void getCor(){

				cout<<"Enter starting cordinate -> ";
				cin>>x>>y;
				cout<<"\nEnter length and breath -> ";
				cin>>l>>b;

				drawShape();
			}

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


				float x = x1 + 0.5*sign(dx);
				float y = y1 + 0.5*sign(dy);

				

				for( int i = 0; i < len ; i++){

					putpixel((int)x , (int)y , WHITE);
					x += g*dx;
					y += dy;
				}

				
			}

			void drawShape(){

				int gd = DETECT , gm;

				initgraph(&gd , &gm , NULL);

				draw(x, y, l, b);

				delay(5000);
				closegraph();
			}

			void draw(int x1, int y1, int l1, int b1){

				Line(x, y, x+l, y);
				Line(x, y, x, y+b);
				Line(x+l, y, x+l, y+b);
				Line(x, y+b, x+l, y+b);

				Line(x+l/2, y, x+l, y+b/2);
				Line(x+l, y+b/2, x+l/2, y+b);
				Line(x+l/2, y+b, x, y+b/2);
				Line(x, y+b/2, x+l/2, y);
			}
};
int main(int argc, char const *argv[])
{
	Rect r;
	r.getCor();
	return 0;
}