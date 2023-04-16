#include <iostream>
//#include<stdio.h>
#include <ctype.h>
#include <conio.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#define SIZE_OF_WINDOW 720 //Размер окна

using namespace std;

int main(void)
{
	initwindow(SIZE_OF_WINDOW, SIZE_OF_WINDOW);

	
	while (1)
	{
		float SHIFT = 5;// Коэффициент сдвиг
		float Scaling = 1.015;	// Коэффициент маштабирования
		float Turn = 0.025;	// Угол в радианах на который вращаем
		float xc, yc;	// средний х, y

		//float Xc, Yc;	// средний y


		float x1 = 260, x2 = 460, x3 = 260;
		float y1 = 240, y2 = 240, y3 = 570;

		/*float FIG[3][3] = { {x1, y1, 1}, {x2, y2, 1}, {x3, y3, 1} };

		float FIG[3][3] = { {1, 0, 0}, {0, 1, 0}, {x1, y1, 1} };

		float FIG[1][3] = { {x1, y1, 1} };
		float SDVIG[3][3] = { {1, 0, 0}, {0, 1, 0}, {SHIFT, SHIFT, 1} };*/

		int i, j;
		char BUTTON;

		setcolor(RGB(100, 100, 255));
		line(x1, y1, x2, y2);
		setcolor(RGB(0, 255, 0));
		line(x3, y3, x2, y2);
		setcolor(RGB(255, 200, 0));
		line(x1, y1, x3, y3);
		while (BUTTON = _getch())
		{

			switch (BUTTON)
			{
			//case -32:	// сдвиг
			{
					//BUTTON = _getch();
					//case 72 80 75 77

					//switch (BUTTON) {
			case 'w':	// вверх
				y1 -= 5;
				y2 -= 5;
				y3 -= 5;
				break;

			case 's':	// вниз
				y1 += 5;
				y2 += 5;
				y3 += 5;
				break;

			case 'a':	// влево
				x1 -= 5;
				x2 -= 5;
				x3 -= 5;
				break;

			case 'd':	// вправо
				x1 += 5;
				x2 += 5;
				x3 += 5;
				break;
				//}
				//break;
				}

			// поворот
			{
			case 'q':
				xc = (x1 + x2 + x3) / 3;
				yc = (y1 + y2 + y3) / 3;
				x1 -= xc;
				y1 -= yc;
				x2 -= xc;
				y2 -= yc;
				x3 -= xc;
				y3 -= yc;

				x1 = ((x1 * cos(-Turn)) - (y1 * sin(-Turn))) * 1.0003125;
				y1 = ((x1 * sin(-Turn)) + (y1 * cos(-Turn))) * 1.0003125;
				x2 = ((x2 * cos(-Turn)) - (y2 * sin(-Turn))) * 1.0003125;
				y2 = ((x2 * sin(-Turn)) + (y2 * cos(-Turn))) * 1.0003125;
				x3 = ((x3 * cos(-Turn)) - (y3 * sin(-Turn))) * 1.0003125;
				y3 = ((x3 * sin(-Turn)) + (y3 * cos(-Turn))) * 1.0003125;

				x1 += xc;
				y1 += yc;
				x2 += xc;
				y2 += yc;
				x3 += xc;
				y3 += yc;

				break;

			case 'e':
				xc = (x1 + x2 + x3) / 3;
				yc = (y1 + y2 + y3) / 3;
				x1 -= xc;
				y1 -= yc;
				x2 -= xc;
				y2 -= yc;
				x3 -= xc;
				y3 -= yc;

				x1 = ((x1 * cos(Turn)) - (y1 * sin(Turn))) * 1.0003125;
				y1 = ((x1 * sin(Turn)) + (y1 * cos(Turn))) * 1.0003125;
				x2 = ((x2 * cos(Turn)) - (y2 * sin(Turn))) * 1.0003125;
				y2 = ((x2 * sin(Turn)) + (y2 * cos(Turn))) * 1.0003125;
				x3 = ((x3 * cos(Turn)) - (y3 * sin(Turn))) * 1.0003125;
				y3 = ((x3 * sin(Turn)) + (y3 * cos(Turn))) * 1.0003125;

				x1 += xc;
				y1 += yc;
				x2 += xc;
				y2 += yc;
				x3 += xc;
				y3 += yc;

				break;
			}

			// масштабирование
			{
			case '+':	// увеличение

				xc = (x1 + x2 + x3) / 3;
				yc = (y1 + y2 + y3) / 3;
				x1 -= xc;
				y1 -= yc;
				x2 -= xc;
				y2 -= yc;
				x3 -= xc;
				y3 -= yc;

				//putpixel(xc, yc, RGB(0, 255, 0));

				x1 *= Scaling;
				y1 *= Scaling;
				x2 *= Scaling;
				y2 *= Scaling;
				x3 *= Scaling;
				y3 *= Scaling;

				x1 += xc;
				y1 += yc;
				x2 += xc;
				y2 += yc;
				x3 += xc;
				y3 += yc;

				break;

			case '-':	// масштабирование

				xc = (x1 + x2 + x3) / 3;
				yc = (y1 + y2 + y3) / 3;
				x1 -= xc;
				y1 -= yc;
				x2 -= xc;
				y2 -= yc;
				x3 -= xc;
				y3 -= yc;

				x1 /= Scaling;
				y1 /= Scaling;
				x2 /= Scaling;
				y2 /= Scaling;
				x3 /= Scaling;
				y3 /= Scaling;

				x1 += xc;
				y1 += yc;
				x2 += xc;
				y2 += yc;
				x3 += xc;
				y3 += yc;

				break;
			}
			}

			
			
			cleardevice();

			setcolor(RGB(100, 100, 255));
			line(round(x1), round(y1), round(x2), round(y2));
			setcolor(RGB(0, 255, 0));
			line(round(x3), round(y3), round(x2), round(y2));
			setcolor(RGB(255, 200, 0));
			line(round(x1), round(y1), round(x3), round(y3));
		}
	}
	return 0;
}
