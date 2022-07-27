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
double segment = 5;
public:	
double getParametr() {
		return segment;
	}
};

class GeometricFigures :public LineSegment {
	double coordX = getParametr() / 2;
	double sideSquare = getParametr()* getParametr();
public:
	double getSideSquare() {
		return sideSquare;
	}

	double getCoordX() {
		return coordX;
	}	
};

class Circle : public GeometricFigures {
	double  factor = atan(1), ratio = 1;
	double secondParametr = getParametr() * ratio, square = factor * getSideSquare();
	string colorFigure= ColorsToString(Colors::blue);
public: 
	double getSquare() {
		return square;
	}

	double getSecondParametr() {
		return secondParametr;
	}

	double getCoordY() {
		return secondParametr/2;
	}

	string getColor() {
		return colorFigure;
	}
};

class  RegularTetragon : public GeometricFigures {
	double factor = 1, ratio = 1;
	double  secondParametr = getParametr() * ratio, square = factor * getSideSquare();
	string colorFigure = ColorsToString(Colors::green);
public:
	double getSecondParametr() {
		return secondParametr;
	}

	double getSquare() {
		return square;
	}

	double getCoordY() {
		return secondParametr / 2;
	}

	string getColor() {
		return colorFigure;
	}
};

class Triangle : public GeometricFigures {
public:
	double factor = sqrt(3) / 4, ratio = sqrt(3) / 2;
	double secondParametr = getParametr() * ratio, square = factor * getSideSquare();
	string colorFigure = ColorsToString(Colors::yellow);
public:
	double getSecondParametr() {
		return secondParametr;
	}

	double getSquare() {
		return square;
	}

	double getCoordY() {
		return secondParametr / 2;
	}

	string getColor() {
		return colorFigure;
	}
};

class Rectangle :public  GeometricFigures {
	string colorFigure = ColorsToString(Colors::red);
	double secondParametr = 0, coordY = 0;
public:
	void setHandInput(double secPar) {
		secondParametr = secPar;
	}

	double getSecondParametr() {
		return secondParametr;
	}

	double getSquare() {
		return getParametr() * getSecondParametr();
	}

	double getCoordY() {
		return getSecondParametr()/2;
	}

	string getColor() {
		return colorFigure;
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
		cout << "\n Площадь фигуры равна " << circle->getSquare();
		cout << "\n Цвет                 " << circle->getColor();
		cout << "\n Стороны описывающего прямоугольника: " << circle->getParametr() << " " << circle->getSecondParametr();
		cout << "\n Центр описывающего прямоугольника: " << circle->getCoordX() << " " << circle->getCoordY();
		delete circle;
	}
	else if (geomFigure == "square") {
		RegularTetragon* regularTetragon = new  RegularTetragon();
		cout << "\n Площадь фигуры равна " << regularTetragon->getSquare();
		cout << "\n Цвет                 " << regularTetragon->getColor();
		cout << "\n Стороны описывающего прямоугольника: " << regularTetragon->getParametr() << " " << regularTetragon->getSecondParametr();
		cout << "\n Центр описывающего прямоугольника: " << regularTetragon->getCoordX() << " " << regularTetragon->getCoordY();
		delete regularTetragon;
	}
	else if (geomFigure == "triangle") {
		Triangle* triangle = new  Triangle();
		cout << "\n Площадь фигуры равна " << triangle->getSquare();
		cout << "\n Цвет                 " << triangle->getColor();
		cout << "\n Стороны описывающего прямоугольника: " << triangle->getParametr() << " " << triangle->getSecondParametr();
		cout << "\n Центр описывающего прямоугольника: " << triangle->getCoordX()<< " " << triangle->getCoordY();
		delete  triangle;
		
	}
	else if (geomFigure == "rectangle") {
		Rectangle* rectangle = new Rectangle();
		double secPar = 0;
		cout << "\nВведите длину второй стороны прямоугольника.";
		cin >> secPar;
		assert(secPar > 0);
		rectangle->setHandInput(secPar);
		cout << "\n Площадь фигуры равна " << rectangle->getSquare();
		cout << "\n Цвет                 " << rectangle->getColor();
		cout << "\n Стороны описывающего прямоугольника: " << rectangle->getParametr() << " " << rectangle->getSecondParametr();
		cout << "\n Центр описывающего прямоугольника: " << rectangle->getCoordX() << " " << rectangle->getCoordY();
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
