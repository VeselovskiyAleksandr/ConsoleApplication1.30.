// ConsoleApplication1.30.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задача 2. Иерархия геометрических фигур.

#include <iostream>
#include <clocale>
#include <string>
#include <cmath>
#include <cassert>
#include <map>
using namespace std;

enum class Colors {
	blue, red, green,  yellow
};

constexpr const char* ColorsToString(Colors c) noexcept {
	 switch (c) {
	 case Colors::blue:return "blue";     //  Функцию constexpr const char* ColorsToString(Colors c) noexcept
	 case Colors::red: return"red";        //Оставил для примера.
	 case Colors::green:return"green";
	 case Colors::yellow:return"yellow";
	}
}

void StringToColors(string color, Colors figColor) {
	if (color == "blue") {
		figColor= Colors::blue;
	}
	else if (color == "red") {
		figColor = Colors::red;
	}
	else if (color == "green") {
		figColor = Colors::green;
	}
	else if (color == "yellow") {
		figColor = Colors::yellow;
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
	Colors figureColor=Colors::blue;
	protected :
	double sideSquare = getParametr()* getParametr();
public:
	void setColor(string figColor) {
		StringToColors(figColor, figureColor);
	}

	Colors getColor() {
		return figureColor;
	}

	double getCoordX() {
		return coordX;
	}	
};

class Circle : public GeometricFigures {
	double  factor = atan(1), ratio = 1;
	double secondParametr = getParametr() * ratio, square = factor * sideSquare;
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
};

class  RegularTetragon : public GeometricFigures {
	double factor = 1, ratio = 1;
	double  secondParametr = getParametr() * ratio, square = factor * sideSquare;
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
};

class Triangle : public GeometricFigures {
public:
	double factor = sqrt(3) / 4, ratio = sqrt(3) / 2;
	double secondParametr = getParametr() * ratio, square = factor * sideSquare;
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
};

class Rectangle :public  GeometricFigures {
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
};

int main()
{
	setlocale(LC_ALL, "Russian");
	string geomFigure = "", figureColor="";
	cout << "\nУкажите название фигуры: круг -  circle, квадрат - square, прямоугольник - rectangle, треугольник - triangle. ";
	cin >> geomFigure;
	cout << "\nУкажите цвет фигуры: синий - blue, жёлтый - yellow, зелёный - green, красный - red";
		cin >> figureColor;
	if (geomFigure == "circle") {
		Circle* circle = new Circle();
		circle->setColor(figureColor);
		cout << "\n Площадь фигуры равна " << circle->getSquare();
		cout << "\n Стороны описывающего прямоугольника: " << circle->getParametr() << " " << circle->getSecondParametr();
		cout << "\n Центр описывающего прямоугольника: " << circle->getCoordX() << " " << circle->getCoordY();
		delete circle;
	}
	else if (geomFigure == "square") {
		RegularTetragon* regularTetragon = new  RegularTetragon();
		regularTetragon->setColor(figureColor);
		cout << "\n Площадь фигуры равна " << regularTetragon->getSquare();
		cout << "\n Стороны описывающего прямоугольника: " << regularTetragon->getParametr() << " " << regularTetragon->getSecondParametr();
		cout << "\n Центр описывающего прямоугольника: " << regularTetragon->getCoordX() << " " << regularTetragon->getCoordY();
		delete regularTetragon;
	}
	else if (geomFigure == "triangle") {
		Triangle* triangle = new  Triangle();
		triangle->setColor(figureColor);
		cout << "\n Площадь фигуры равна " << triangle->getSquare();
		cout << "\n Стороны описывающего прямоугольника: " << triangle->getParametr() << " " << triangle->getSecondParametr();
		cout << "\n Центр описывающего прямоугольника: " << triangle->getCoordX()<< " " << triangle->getCoordY();
		delete  triangle;
		
	}
	else if (geomFigure == "rectangle") {
		Rectangle* rectangle = new Rectangle();
		rectangle->setColor(figureColor);
		double secPar = 0;
		cout << "\nВведите длину второй стороны прямоугольника.";
		cin >> secPar;
		assert(secPar > 0);
		rectangle->setHandInput(secPar);
		cout << "\n Площадь фигуры равна " << rectangle->getSquare();
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
