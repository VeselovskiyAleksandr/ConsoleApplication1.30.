 // ConsoleApplication1.30.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 27. Задача 1. Реализация деревни эльфов.

#include <iostream>
#include <locale.h>
#include <ctime>
#include <string>
using namespace std;

class TreeMiddleBranche {
	int elfName = 0;
public:
	void setElfName(int eN) {
		elfName = eN;
	}

	int getElfName() {
		return elfName;
	}

	TreeMiddleBranche(int intreesNumber, int innumberBigBranches, int innumberMiddleBranches, int inelfName) :elfName(inelfName) {};
};

class TreeBigBranche {
	int numberMiddleBranches = 0, elfName = 0;
public:
	void setElfName(int eN) {
		elfName = eN;
	}

	int getElfName() {
		return elfName;
	}

	void loadMidBr(int branches) {
		numberMiddleBranches = branches;
	}

	int getMidBr() {
		return numberMiddleBranches;
	}

	TreeMiddleBranche** middleBranche = nullptr;
	TreeMiddleBranche* getmiddleBranche(int indexM) {
		return middleBranche[indexM];
	}

	TreeBigBranche(int intreesNumber, int innumberBigBranches, int innumberMiddleBranches, int inelfName) : numberMiddleBranches(innumberMiddleBranches), elfName(inelfName) {
		middleBranche = new TreeMiddleBranche * [innumberMiddleBranches];
		for (int i = 0; i < innumberMiddleBranches; i++) {
			middleBranche[i] = new TreeMiddleBranche(intreesNumber, innumberBigBranches, innumberMiddleBranches, inelfName);
			cout << "\n средняя ветвь " << i + 1 << " имя эльфа:";
			cin >> inelfName;
			middleBranche[i]->setElfName(inelfName);
		}
	}
};

class Tree {

	int numberBigBranches = 0, numberMiddleBranches = 0, elfName = 0;
public:
	void loadBigBr(int Branches) {
		numberBigBranches = Branches;
	};
	int getBigBr() {
		return numberBigBranches;
	}

	TreeBigBranche** bigBranche = nullptr;
	TreeBigBranche* getbigBranche(int indexB) {
		return bigBranche[indexB];
	}

	Tree(int intreesNumber, int innumberBigBranches, int innumberMiddleBranches, int inelfName) : numberBigBranches(innumberBigBranches), elfName(inelfName) {
		bigBranche = new TreeBigBranche * [innumberBigBranches];
		for (int j = 0; j < innumberBigBranches; j++) {
			innumberMiddleBranches = rand() % 2 + 2;
			cout << "\n большая ветвь " << j + 1;
			bigBranche[j] = new TreeBigBranche(intreesNumber, innumberBigBranches, innumberMiddleBranches, inelfName);
			bigBranche[j]->loadMidBr(innumberMiddleBranches);
			cout << "\n большая ветвь " << j + 1 << " имя эльфа: ";
			cin >> inelfName;
			bigBranche[j]->setElfName(inelfName);
		}
	}
};

class ElfVillage {
	int treesNumber = 0, numberBigBranches = 0;
public:
	Tree** tree = nullptr;
	Tree* getTree(int index) {
		return tree[index];
	}

	ElfVillage(int intreesNumber, int innumberBigBranches, int innumberMiddleBranches, int inelfName) : treesNumber(intreesNumber) {
		tree = new Tree * [intreesNumber];
		for (int i = 0; i < treesNumber; ++i) {
			srand(time(nullptr));
			innumberBigBranches = rand() % 3 + 3;
			cout << "\n дерево " << i + 1;
			tree[i] = new Tree(intreesNumber, innumberBigBranches, innumberMiddleBranches, inelfName);
			tree[i]->loadBigBr(innumberBigBranches);
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(nullptr));
	int numBBr = 0, numMBr = 0, name = 0, numTr = 5, nameElf = 0;
	cout << "\nИмена эльфов - любые целые числа кроме нуля. Если жилище эльфа на ветке отсутствует введите 0.\n";
	srand(time(nullptr));
	ElfVillage* elfVillage = new ElfVillage(numTr, numBBr, numMBr, name);
	cout << "\nВведите имя искомого эльфа. ";
	while (nameElf == 0) {
		cin >> nameElf;
		if (nameElf == 0) {
			cout << "\n Таких имён у эльфов нет. Введите правильно имя. ";
		}
	}
	int index = -1, countName = 0;
	for (int i = 0; i < numTr; ++i) {
		for (int j = 0; j < elfVillage->getTree(i)->getBigBr(); ++j) {
			if (nameElf == elfVillage->getTree(i)->getbigBranche(j)->getElfName()) {
				cout << "\n Искомый эльф проживает по адресу: дерево " << i + 1 << " большая ветвь " << j + 1;
				index = i;
				break;
			}
			for (int k = 0; k < elfVillage->getTree(i)->getbigBranche(j)->getMidBr(); ++k) {
				if (nameElf == elfVillage->getTree(i)->getbigBranche(j)->getmiddleBranche(k)->getElfName()) {
					cout << "\n Искомый эльф проживает по адресу: дерево " << i + 1 << " большая ветвь " << j + 1 << " средняя ветвь " << k + 1;
					index = i;
					break;
				}
			}
		}
	}
	if (index >= 0) {
		for (int j = 0; j < elfVillage->getTree(index)->getBigBr(); ++j) {
			if (elfVillage->getTree(index)->getbigBranche(j)->getElfName() != 0) {
				countName++;
			}
			for (int k = 0; k < elfVillage->getTree(index)->getbigBranche(j)->getMidBr(); ++k) {
				if (elfVillage->getTree(index)->getbigBranche(j)->getmiddleBranche(k)->getElfName() != 0) {
					countName++;
				}
			}
		}
		cout << "\nРядом с ним проживает " << countName - 1 << " соседей.";
	}
	else if (index < 0) {
		cout << "\nЭльфа с таким именем в деревне нет.";
	}
	for (int i = 0; i < numTr; ++i) {
		for (int j = 0; j < elfVillage->getTree(i)->getBigBr(); ++j) {			
			for (int k = 0; k < elfVillage->getTree(i)->getbigBranche(j)->getMidBr(); ++k) {
			delete elfVillage->getTree(i)->getbigBranche(j)->middleBranche[k];			
				}
			delete elfVillage->getTree(i)->getbigBranche(j);
			}
		delete elfVillage->getTree(i);
		}
	delete elfVillage;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие .
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
