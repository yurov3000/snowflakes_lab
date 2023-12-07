#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <time.h>

void Draw(int x, int y, int color1, int color2){ // рисуем фигуру
	setcolor(color1);
	setfillstyle(1, color2);
	circle(x, y, 20);
	circle(x, y, 10);
	circle(x, y, 5);
	circle(x-30, y, 10);
	circle(x+30, y, 10);
	circle(x, y+30, 10);
	circle(x, y-30, 10);
	circle(x-20, y+20, 10);
	circle(x-20, y-20, 10);
	circle(x+20, y-20, 10);
	circle(x+20, y+20, 10);
	floodfill(x+25, y, color1);
	floodfill(x-25, y, color1);
	floodfill(x+25, y+15, color1);
	floodfill(x+25, y-15, color1);
	floodfill(x-25, y+15, color1);
	floodfill(x-25, y-15, color1);
	floodfill(x, y+15, color1);
	floodfill(x, y-25, color1);
	floodfill(x, y+15, color1);
	floodfill(x, y+25, color1);
	floodfill(x, y, color1); // закрашиваем фигуру
	
}

int main(int argc, char** argv){
	initwindow(500, 500); // инициализируем окно
	setfillstyle(1,0); // стиль заливки
	bar(0, 0, 449, 449); // заливаем фон
	
	srand(time(NULL)); // настраиваем рандом
	int color0 = 0;
	int x[20];
	int y[20];
	int color[14];
	int i;

	for (i = 0; i != 20; i++){ // координаты
		x[i] = rand() % 400; // заполняем рандомом массив x
	}
	for (i = 0; i != 20; i++){ // координаты
		y[i] = rand() % 400; // заполняем рандомом массив y
	}
	for (i = 1; i != 14; i++){ // цвета
		color[i] = rand() % 14;// заполняем массив с цветами
	}
	
	int count = 0; // количество снежинок на экране
	while(1){
		for (i = 0; i != 20; i++){ // выбираем рандомные координаты из массива
			if (count <= 15){
				Draw(x[i], y[i], 15, count); // рисуем фигуру (цвет = номеру count)
				setcolor(GREEN);
				outtextxy(310, 100, "HAPPY NEW YEAR :)");
				Sleep(200); // задержка между отрсивкой снежинок
				count++;
			}
			else{
				setfillstyle(1,0);
				bar(0, 0, 500, 500); // заливаем фон
				setcolor(GREEN);
				outtextxy(310, 100, "HAPPY NEW YEAR :)");
				count -= 14; // сбрасываем счетчик
			}
		}
		delay(50); // задержка цикла
	}
	getch();
	closegraph();
	return 0;		
}