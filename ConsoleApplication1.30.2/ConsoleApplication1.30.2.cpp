// ConsoleApplication1.30.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задача 2. Иерархия геометрических фигур.

#include <iostream>
#include <clocale>
#include <ctime>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

class LineSegment {

	double segment = 5;
public:
	void setSideLength(double length) {
		segment = length;
	}

	double getSideLength() {
		return segment;
	}
};

class GeometricFigures :public LineSegment {
private:
	double factor = atan(1), ratio = 1;
	double  secondParametr = 0, square = 0, parametr = 0;
	string figureName = "", colors = "";
public:
	void setFactor(double fact) {
		factor = fact;
	}

	double getFactor() {
		return factor;
	}

	void setColor(string col) {
		colors = col;
	}

	string getColor() {
		return colors;
	}

	void setRatio(double rat) {
		ratio = rat;
	}

	double getRatio() {
		return ratio;
	}

	void setParametr(double par) {
		parametr = par;
	}

	double getParametr() {
		return  parametr;
	}

	void setSecondParametr(double secPar) {
		secondParametr = secPar;
	}

	double getSecondParametr() {
		return secondParametr;
	}

	void setSquare(double sq) {
		square = sq;
	}

	double getSquare() {
		return square;
	}

	GeometricFigures(double inFactor, double inRatio, double insecondParametr, double inSquare, string inColors, string infigureName) : figureName(infigureName), factor(inFactor), ratio(inRatio), square(inSquare), secondParametr(insecondParametr), colors(inColors) {
		setParametr(getSideLength());
		if (infigureName == "circle") {
			inFactor = atan(1); inRatio = 1; inColors = "blue";
			setFactor(inFactor);
			setRatio(inRatio);
			insecondParametr = getParametr() * getRatio();
			setSecondParametr(insecondParametr);
		}
		else if (infigureName == "square") {
			inFactor = 1; inRatio = 1; inColors = "green";
			insecondParametr = getParametr();
			setFactor(inFactor);
			setRatio(inRatio);
			insecondParametr = getParametr() * getRatio();
			setSecondParametr(insecondParametr);
		}
		else if (infigureName == "triangle") {
			inFactor = sqrt(3) / 4; inRatio = sqrt(3) / 2, inColors = "yellow";
			setFactor(inFactor);
			setRatio(inRatio);
			insecondParametr = getParametr() * getRatio();
			setSecondParametr(insecondParametr);
		}
		else if (infigureName == "rectangle") {
			cout << "\nВведите длину второй стороны прямоугольника.";
			cin >> insecondParametr;
			assert(insecondParametr > 0);
			setSecondParametr(insecondParametr);
			inFactor = insecondParametr / getParametr(); inRatio = inFactor, inColors = "red";
			setFactor(inFactor);
			setRatio(inRatio);
		}
		inSquare = getFactor() * getParametr() * getParametr();
		setSquare(inSquare);
		setColor(inColors);
	};
};

int main()
{
	setlocale(LC_ALL, "Russian");
	string geomFigure = "", color = "";
	double figureSide = 0, secondSide = 0, figureSquare = 0, squareFactor = 0, figureFactor = 0;
	cout << "\nУкажите название фигуры: круг -  circle, квадрат - square, прямоугольник - rectangle, треугольник - triangle. ";
	cin >> geomFigure;
	GeometricFigures* figure = new GeometricFigures(squareFactor, figureFactor, secondSide, figureSquare, color, geomFigure);
	cout << "\n Площадь фигуры равна " << figure->getSquare();
	cout << "\n Цвет                 " << figure->getColor();
	cout << "\n Стороны описывающего прямоугольника: " << figure->getParametr() << " " << figure->getSecondParametr();
	cout << "\n Центр описывающего прямоугольника: " << (figure->getParametr()) / 2 << " " << (figure->getSecondParametr()) / 2;
	delete figure;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
