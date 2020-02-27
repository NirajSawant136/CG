#include<iostream>
#include<graphics.h>
using namespace std;

class Rect{

	private:int x, y, l, b;

	public:	
			void getCor(int x1 , int y1 , int l , int b){

				// cout<<"Enter starting cordinate -> ";
				// cin>>x>>y;
				// cout<<"\nEnter length and breath -> ";
				// cin>>l>>b;
				this->x = x1;
				this->y = y1;
				this->l = l;
				this->b = b;

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

				draw();

				delay(5000);
				closegraph();
			}

			int midpoint(int a, int b){

				return (a+b)/2;
			}

			void draw(){

				Line(x, y, x+l, y);
				Line(x, y, x, y+b);
				Line(x+l, y, x+l, y+b);
				Line(x, y+b, x+l, y+b);

				Line(midpoint(x, x+l), midpoint(y,y), midpoint(x+l, x+l), midpoint(y,y+b));
				Line(midpoint(x+l, x+l), midpoint(y,y+b), midpoint(x, x+l), midpoint(y+b,y+b));
				Line(midpoint(x,x), midpoint(y,y+b), midpoint(x, x+l), midpoint(y+b,y+b));
				Line(midpoint(x,x+l), midpoint(y,y), midpoint(x, x), midpoint(y,y+b));

				Line(midpoint(x+l/2, x+l), midpoint(y,y+b/2), midpoint(x+l, x+l/2), midpoint(y+b/2,y+b));
				Line(midpoint(x+l, x+l/2), midpoint(y+b/2,y+b), midpoint(x, x+l/2), midpoint(y+b/2,y+b));
				Line(midpoint(x, x+l/2), midpoint(y+b/2,y), midpoint(x, x+l/2), midpoint(y+b/2,y+b));
				Line(midpoint(x, x+l/2), midpoint(y+b/2,y), midpoint(x+l/2, x+l), midpoint(y,y+b/2));
			}
};
int main(int argc, char const *argv[])
{
	Rect r;
	r.getCor(100, 100, 200, 150);
	return 0;
}