#include<iostream>


using namespace std;


void row_with_out_zero(int** array, int row, int col) //Поиск и вывод строк без нулей 
{
	bool flag = false;                      //флаг для случая когда нет нулей в массиве 
	bool *row_with_out_zero=new bool[row];        
	for (int i = 0; i < row; ++i)
	{
		row_with_out_zero[i] = true;        // булевый массив обозначающий строки без нулей. Индекс-строка.
	}


	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (array[i][j] == 0)
			{
				row_with_out_zero[i] = false;         //Если встречается нуль - булевый массив=true в индексе равный строке которой есть нуль
				flag = true;                   //встретился ноль
			}
		}
	}

	if (flag == false)
	{
		cout << "во всех строках есть хотя бы один ноль"<<endl;           //во всех строках есть хотя бы один ноль
	}
	else
	{
		cout << "строки без нулей: ";
		for (int i = 0; i < row; ++i)
		{
			if (row_with_out_zero[i] == true)
			{
				cout << i << ' ';                          //вывод номеров строк в которых нет нулей 
			}
		}
		cout << endl;
	}

}

void max_value(int** array, int row, int col)     //функция выводит координаты максимальных чисел в матрице 
{
	int max_value=array[0][0],max_count=0;               //переменная для максимума ,счетчик максимума 

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (max_value < array[i][j]) max_value = array[i][j];   //поиск максимума
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (max_value == array[i][j]) max_count++;            //считаем сколько раз максимум встретился в массиве

		}
	}
	if (max_count == row*col)
	{
		cout << "Массив состоит из одиннаковых элементов" << endl;
	}
	else if (max_count == 1)
	{
		cout << "В массиве максимальное число встречается один раз" << endl;
	}
	else
	{
		cout << "координаты максимального(ых) элемаента(ов):" << endl;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (array[i][j] == max_value)
				{
					cout << "+ ";                                //вывод координат максимума
				}
				else
				{
					cout << "- ";
				}
			}
			cout << endl;
		}
	}
}

int main()
{
	int row,col;

	cin >> row>>col;

	cout << "Enter size of array: ";
	while (true)
	{
		cin >> row >>col;
		if (row <= 1 || col <= 1)
			cout << "Incorrect size of array" << endl;        //проверка размера массива   (row > 1 , col > 1)
		else
			break;

	}


	int** array = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		array[i] = new int[col];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> array[i][j];
		}
	}


	row_with_out_zero(array, row, col);
	max_value(array, row, col);

	
	return 0;
}