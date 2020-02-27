#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

class Trans2D{

	private: int x[3], y[3];
	
	public: 
			Trans2D(){
				y[2] = x[0]= y[0]= 150;
				x[2]= x[1]= y[1]= 250;

			}

			int sign(int k){

				if(k < 0)
					return -1;
				return 1;
			}

			void Line(int x1, int y1, int x2, int y2){

				float dx = abs(x2 - x1);
				float dy = abs(y2 - y1);

				int g = (x2 >= x1)?1:-1;

				float len = (dx > dy)?dx:dy;

				dx /= len;
				dy /= len;

				float x = x1 + 0.5*sign(dx);
				float y = y1 + 0.5*sign(dy);


				for(int i = 0; i < len; i++){

					putpixel((int)x, (int)y, WHITE);
					x += g*dx;
					y += dy;
				}
			}

			void drawShape(){

				int gd = DETECT, gm;

				initgraph(&gd, &gm, NULL);

				drawTriangle();

				delay(500);

				//translate();

				//delay(700);

				//scale();

				//delay(700);

				rotate();

				delay(10000);
				closegraph();
			}

			void drawTriangle(){

				cleardevice();

				Line(x[0], y[0], x[1], y[1]);
				Line(x[2], y[2], x[1], y[1]);
				Line(x[2], y[2], x[0], y[0]);
			} 

			void translate(){

				int tx = 150;
				int ty = 130;

				for(int i=0;i<3;i++){

					this->x[i] += tx;
					this->y[i] += ty;
				}
				drawTriangle();
			}

			void scale(){

				double sx = 1.5;
				double sy = 1.5;

				for(int i=0;i<3;i++){

					this->x[i] *= sx;
					this->y[i] *= sy;
				}
				drawTriangle();
			}

			void rotate(){

				double theta = -10;

				for(int i=0;i<3;i++){

					this->x[i] = this->x[i]*cos(theta) - this->y[i]*sin(theta);
					this->y[i] = this->y[i]*cos(theta) + this->x[i]*sin(theta);
				}
				drawTriangle();
			}
};
int main(int argc, char const *argv[])
{
	Trans2D t2;
	t2.drawShape();
	return 0;
}