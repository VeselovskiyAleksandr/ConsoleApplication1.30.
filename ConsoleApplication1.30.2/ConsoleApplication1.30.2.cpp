// ConsoleApplication1.30.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задача 2. Иерархия геометрических фигур.

#include <iostream>
#include <clocale>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

enum class Colors {
	blue, red, green,  yellow
};

constexpr const char* ColorsToString(Colors c) noexcept {
	 switch (c) {
	 case Colors::blue:return "blue";
	 case Colors::red: return"red";
	 case Colors::green:return"green";
	 case Colors::yellow:return"yellow";
	}
}

class LineSegment {
public:
	double segment = 5;
};

class Circle :public LineSegment {
public:
	double  factor = atan(1), ratio = 1;
	double parametr = segment, secondParametr = parametr * ratio;
	double square = factor * parametr * parametr;
	Colors color = Colors::blue;

	Circle() {};
};

class  RegularTetragon :public LineSegment {
public:
	double factor = 1, ratio = 1;
	double parametr = segment, secondParametr = parametr * ratio;
	double square = factor * parametr * parametr;
	Colors color = Colors::green;

	RegularTetragon() {};
};

class Triangle :public LineSegment {
public:
	double factor = sqrt(3) / 4, ratio = sqrt(3) / 2;
	double parametr = segment, secondParametr = parametr * ratio;
	double square = factor * parametr * parametr;
	Colors color = Colors::yellow;

	Triangle() {};
};

class Rectangle :public LineSegment {
	double  factor = 0, ratio = 0, square = 0, secondParametr =0;
public:
	double parametr = segment;
	Colors color = Colors::red;

	void setFactor(double fact) {
		factor = fact;
	}

	void setRatio(double rat) {
		ratio = rat;
	}

	void setSq(double sq) {
		square = sq;
	}

	void setSecondParametr(double secPar) {
		secondParametr = secPar;
	}

	double getFactor() {
		return factor;
	}

	double getRatio() {
		return ratio;
	}

	double getSq() {
		return square;
	}

	double getSecondParametr() {
		return secondParametr;
	}

	Rectangle(double insecondParametr, double inratio, double insquare, double infactor):secondParametr(insecondParametr), ratio(inratio), square(insquare), factor(infactor){	
	 infactor = insecondParametr / parametr; inratio = infactor;
	 insquare = infactor * parametr * parametr;
	 setFactor(infactor);
	 setRatio(inratio);
	 setSq(insquare);
	 setSecondParametr(insecondParametr);
	}
	

};

int main()
{
	setlocale(LC_ALL, "Russian");
	string geomFigure = "";
	cout << "\nУкажите название фигуры: круг -  circle, квадрат - square, прямоугольник - rectangle, треугольник - triangle. ";
	cin >> geomFigure;
	if (geomFigure == "circle") {
		Circle* circle = new Circle();
		cout << "\n Площадь фигуры равна " << circle->square;
		cout << "\n Цвет                 " << ColorsToString(Colors::blue);
		cout << "\n Стороны описывающего прямоугольника: " << circle->parametr << " " << circle->secondParametr;
		cout << "\n Центр описывающего прямоугольника: " << (circle->parametr) / 2 << " " << (circle->secondParametr) / 2;
		delete circle;
	}
	else if (geomFigure == "square") {
		RegularTetragon* regularTetragon = new  RegularTetragon();
		cout << "\n Площадь фигуры равна " << regularTetragon->square;
		cout << "\n Цвет                 " << ColorsToString(Colors::green);
		cout << "\n Стороны описывающего прямоугольника: " << regularTetragon->parametr << " " << regularTetragon->secondParametr;
		cout << "\n Центр описывающего прямоугольника: " << (regularTetragon->parametr) / 2 << " " << (regularTetragon->secondParametr) / 2;
		delete regularTetragon;
	}
	else if (geomFigure == "triangle") {
		Triangle* triangle = new  Triangle();
		cout << "\n Площадь фигуры равна " << triangle->square;
		cout << "\n Цвет                 " << ColorsToString(Colors::yellow);
		cout << "\n Стороны описывающего прямоугольника: " << triangle->parametr << " " << triangle->secondParametr;
		cout << "\n Центр описывающего прямоугольника: " << (triangle->parametr) / 2 << " " << (triangle->secondParametr) / 2;
		delete  triangle;
	}
	else if (geomFigure == "rectangle") {
		double secPar = 0, ratioPar = 0, sq=0, squareFactor=0;
		cout << "\nВведите длину второй стороны прямоугольника.";
		cin >> secPar;
		assert(secPar > 0);
		Rectangle* rectangle = new Rectangle(secPar, ratioPar, sq, squareFactor);
		cout << "\n Площадь фигуры равна " << rectangle->getSq();
		cout << "\n Цвет                 " << ColorsToString(Colors::red);
		cout << "\n Стороны описывающего прямоугольника: " << rectangle->parametr << " " << rectangle->getSecondParametr();
		cout << "\n Центр описывающего прямоугольника: " << (rectangle->parametr) / 2 << " " << (rectangle->getSecondParametr()) / 2;
		delete  rectangle;
	}
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
