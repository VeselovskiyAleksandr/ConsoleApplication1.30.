// ConsoleApplication1.30.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
#include <ctime>
#include <string>
using namespace std;

enum class Colors {
	blue, red, green, yellow
};

class Circle {
	double factor = atan(1), ratio=1;
	Colors color = Colors::blue;
public:
	double getFactor(){
		return factor;
	}
	string getColorCircle() {
		return "blue";
	}
	double getRatio() {
		return ratio;
	}

	Circle() {};
};

class  RegularTetragon{
	double factor = 1, ratio=1;
	Colors color = Colors::green;
public:
	double getFactor() {
		return factor;
	}
	string getColorRegularTetragon() {
		return "green";
	}
	double getRatio() {
		return ratio;
	}

	RegularTetragon() {};
};

class Triangle {
	double factor = sqrt(3) / 4, ratio= sqrt(3)/2;
	Colors color = Colors::green;
public:
	double getFactor() {
		return factor;
    }
	string getColorTriangle() {
		return "yellow";
	}
	double getRatio() {
		return ratio;
	}

	Triangle() {};
};

class Rectangle {
	double parametr = 1, secondParametr = 1, factor = 1, ratio=1;
	Colors color = Colors::green;
public:
	void setParametr(double par, double secondPar) {
		parametr = par;
		secondParametr = secondPar;
        factor = secondParametr / parametr;
		ratio = factor;
	}

	double getFactor() {
		return factor;
	}
	string getColorRectangle() {
		return "red";
	}
	double getRatio() {
		return ratio;
	}

	Rectangle() {}
};

 
class GeometricFigures {
	 string figureName = "";
	 double parametr = 0, secondParametr = 0, square = 0;
public:
	void setFigureName(string figName) {
		figureName = figName;
	}

	void setSecondParametr(double par, double ratio) {
		secondParametr =ratio* par;
	}

	void setParametr (double par) {
		parametr = par;
	}

	double getParametr() {
		return parametr;
	}
	double getSecondParametr() {
		return secondParametr;
	}

	double getSquare(double factor, double secondParametr=0) {
		square = factor * parametr * parametr;
		return square;
	}

	Rectangle* rectangle=new Rectangle();
	Triangle* triangle = new Triangle();
	RegularTetragon* regularTetragon = new RegularTetragon();
	Circle* circle = new Circle();
	 GeometricFigures(string infigureName, double inparametr, double insecondParametr=0) :figureName(infigureName), parametr(inparametr), secondParametr(insecondParametr){
		 if (infigureName == "rectangle") {
         setParametr(inparametr);		
			 cout << "\nВведите длину второй стороны прямоугольника.";
			 cin >> insecondParametr;
			 rectangle->setParametr(inparametr, insecondParametr);
			 cout << "\n Площадь фигуры равна " << getSquare((rectangle->getFactor()), insecondParametr);
			 cout << "\n Цвет:                 " << rectangle->getColorRectangle();
			 setSecondParametr(inparametr,rectangle->getRatio());
		 }
		 else if (infigureName == "square") {
			 setParametr(inparametr);
			 cout << "\n Площадь фигуры равна " << getSquare((regularTetragon->getFactor()), insecondParametr);
			 cout << "\n Цвет                 " << regularTetragon->getColorRegularTetragon();
			 setSecondParametr(inparametr, regularTetragon->getRatio());
		 }
		 else if (infigureName == "circle") {
			 setParametr(inparametr);
			 cout << "\n Площадь фигуры равна " << getSquare((circle->getFactor()), insecondParametr);
			 cout << "\n Цвет                 " << circle->getColorCircle();
			 setSecondParametr(inparametr,  circle->getRatio());
		 }
		 else if (infigureName == "triangle") {
			 setParametr(inparametr);
			 cout << "\n Площадь фигуры равна " << getSquare((triangle->getFactor()), insecondParametr);
			 cout << "\n Цвет                 " << triangle->getColorTriangle();
			 setSecondParametr(inparametr, triangle->getRatio());
		 }
		 cout << "\n Стороны описывающего прямоугольника: " << inparametr << " " << getSecondParametr();
		 cout << "\n Центр описывающего прямоугольника: " << inparametr/2 << " " << getSecondParametr()/2;
		 delete rectangle;
		 delete regularTetragon;
		 delete circle;
	     delete triangle;
	 }	
};

int main() {
	setlocale(LC_ALL, "Russian");	
	string geomFigure = "";
	double figureSide = 0;
	cout << "\nУкажите название фигуры: круг -  circle, квадрат - square, прямоугольник - rectangle, треугольник - triangle. ";
	cin >> geomFigure;
	cout << "\nУкажите длину стороны (для круга - диаметр). ";
	cin >> figureSide;
	GeometricFigures* geometricFigures=new GeometricFigures(geomFigure, figureSide);
	delete geometricFigures;
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
