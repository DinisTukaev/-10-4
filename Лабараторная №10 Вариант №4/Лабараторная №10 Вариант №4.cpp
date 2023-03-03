/* Лабараторная №10 Вариант №4
Создать класс Matrix (матрица целых чисел), используя класс Vector
(вектор целых чисел) с переопределенными для него операциями.
Определить для этого класса следующие операции:
+а) «>>»  ввод матрицы с консоли;
+б) «<<»  вывод матрицы на экран или в файл;
в) «+»  сложение матриц;
г) «»  вычитание матриц;
д) «*»  умножение матриц;
e) «[][]»  доступ к элементу.*/

#include <iostream>

using namespace std;

int rows1, rows2, rows3; // строки
int columns1, columns2, columns3; // колонки
int** array1 = new int* [rows1]; // двумерный динамический массив №1
int** array2 = new int* [rows2]; // двумерный динамический массив №2
int** array3 = new int* [rows3]; // двумерный динамический массив №3

int x; // индекс по столбцу матрицы
int y; // индекс по строке матрицы

class Vector
{
public:
	void CreateMatrix()
	{
		/*1 матрица*/
		cout << "Введите количетсво строк 1-ой матрицы: "; cin >> rows1;
		cout << "Введите количетсво столбцов 1-ой матрицы: "; cin >> columns1;
		cout << endl;

		for (int i = 0; i < rows1; i++)
		{
			array1[i] = new int[columns1];
		}

		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << "Введите [" << i + 1 << ";" << j + 1 << "] элемент 1-го массива: "; cin >> array1[i][j];
			}
		}

		/*2 матрица*/
		cout << "\nВведите количество строк 2-ой матрицы: "; cin >> rows2;
		cout << "Введите количество столбцов 2-ой матрицы: "; cin >> columns2;
		cout << endl;

		for (int i = 0; i < rows2; i++)
		{
			array2[i] = new int[columns2];
		}

		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < columns2; j++)
			{
				cout << "Введите [" << i + 1 << ";" << j + 1 << "] элемент 1-го массива: "; cin >> array2[i][j];
			}
		}
		cout << endl;
	}

	void OutputMatrixs()
	{
		cout << "Матрица №1\n";
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << array1[i][j] << " ";
			}
			cout << endl;
		}

		cout << "\nМатрица №2\n";
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < columns2; j++)
			{
				cout << array2[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void AccessElement() // доступ к элементу
	{
		cout << "Введите индекс числа в строке: "; cin >> y;
		cout << "Введите индекс числа в столбце: "; cin >> x;
		
		//cout << array1[2][2];

		//for (int i = 0; i < rows1; i++)
		//{
		//	array1[i] = new int[columns1];
		//	cout << array1[y][x];
		//}

		//for (int i = 0; i < rows1; i++)
		//{
		//	for (int j = 0; j < columns1; j++)
		//	{
		//		cout << array1[2][2];
		//	}
		//}
	}

	//void DeleteArray()
	//{
	//	for (int i = 0; i < rows1; i++)
	//		delete[] array1[i];
	//	delete[] array1;
	//}

};

class Matrix
{
public:
	void MatrixAddition() // сложение матриц
	{
		if (rows1 != rows2 && columns1 != columns2)
			cout << "Складывать можно только матрицы одинакового размера\n\n";
		else
		{
			rows3 = rows1;
			columns3 = columns1;

			for (int i = 0; i < rows3; i++)
			{
				array3[i] = new int[columns3];
			}

			for (int i = 0; i < rows3; i++)
			{
				for (int j = 0; j < columns3; j++)
				{
					array3[i][j] = array1[i][j] + array2[i][j];
				}
			}

			cout << "Матрица в результате сложения 2-х матриц\n";
			//cout << rows1 << endl << rows2 << endl << columns1 << endl << columns2;
			for (int i = 0; i < rows3; i++)
			{
				for (int j = 0; j < columns3; j++)
				{
					cout << array3[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
	}

	void MatrixSubtraction() // вычитание матриц
	{
		if (rows1 != rows2 && columns1 != columns2)
			cout << "Вычитать можно только матрицы одинакового размера\n\n";
		else
		{
			rows3 = rows1;
			columns3 = columns1;

			for (int i = 0; i < rows3; i++)
			{
				array3[i] = new int[columns3];
			}

			for (int i = 0; i < rows3; i++)
			{
				for (int j = 0; j < columns3; j++)
				{
					array3[i][j] = array1[i][j] - array2[i][j];
				}
			}

			cout << "Матрица в результате вычитания 2-х матриц\n";
			for (int i = 0; i < rows3; i++)
			{
				for (int j = 0; j < columns3; j++)
				{
					cout << array3[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
	}

	void MatrixMultiplication()  // умножение матриц
	{
		if (columns1 != rows2)
		{
			cout << "Число столбцов в первой матрице должно быть равно числу строк во второй матрице\n\n";
		}
		else
		{
			rows3 = rows1;
			columns3 = columns2;

			for (int i = 0; i < rows3; i++)
			{
				array3[i] = new int[columns3];
			}

			for (int i = 0; i < columns3; i++)
			{
				for (int j = 0; j < columns3; j++)
				{
					array3[i][j] = 0;
					for (int k = 0; k < columns3; k++)
					{
						array3[i][j] += array1[i][k] * array2[k][j];
					}
				}
			}

			cout << "Матрица в результате умножения 2-х матриц\n";
			for (int i = 0; i < columns3; i++)
			{
				for (int j = 0; j < columns3; j++)
					cout << array3[i][j] << " ";
				cout << endl;
			}
			cout << endl << endl;
		}
	}
};

int main()
{
	Vector vector;
	Matrix matrix;

	for (;;)
	{
		setlocale(LC_ALL, "RU");
		system("cls");
		cout << "*** МЕНЮ ***\n";
		cout << "\n1. Создать матрицы.\n";
		cout << "2. Вывести матрицы.\n";
		cout << "3. Сложить матрицы.\n";
		cout << "4. Вычесть матрицы.\n";
		cout << "5. Умножить матрицы.\n";
		cout << "6. Доступ к элементу.\n";
		cout << "7. Выход.\n";

		int number;
		cin >> number;
		switch (number)
		{
		case 1:
			system("cls");
			vector.CreateMatrix();
			system("pause");
			break;

		case 2:
			system("cls");
			vector.OutputMatrixs();
			system("pause");
			break;

		case 3:
			system("cls");
			matrix.MatrixAddition();
			system("pause");
			break;

		case 4:
			system("cls");
			matrix.MatrixSubtraction();
			system("pause");
			break;

		case 5:
			system("cls");
			matrix.MatrixMultiplication();
			system("pause");
			break;

		case 6:
			system("cls");
			vector.AccessElement();
			system("pause");
			break;

		case 7:
			system("cls");
			//vector.DeleteArray();
			return 0;
			break;
		}
	}
}
