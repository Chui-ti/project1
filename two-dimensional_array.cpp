#include<iostream>


using namespace std;


void row_with_out_zero(int** array, int row, int col) //Поиск и вывод строк без нулей 
{
	int count_rows_with_zero = 0;         //считчик количества строк с нулями 
	bool flag;                                  //флаг для случая когда нет нулей в массиве 
	bool *row_with_out_zero=new bool[row];        
	for (int i = 0; i < row; ++i)
	{
		row_with_out_zero[i] = true;        // булевый массив обозначающий строки без нулей. Индекс-строка.
	}


	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			flag = true;
			if (array[i][j] == 0)
			{
				row_with_out_zero[i] = false;         //Если встречается нуль - булевый массив=true в индексе равный строке которой есть нуль
				flag = false;                   //встретился ноль в массиве 
			}
			if (flag == false)                                 //если встретился ноль
				count_rows_with_zero++;                          //то счетчик количества строк с нулями +1
		}
	}

	if (count_rows_with_zero == row)            //Если количество строк с нулями == количеству строк в массиве ,то выводим сообщение об этом 
	{
		cout << "All rows has zero"<<endl;           //во всех строках есть хотя бы один ноль
	}
	else
	{
		cout << "Rows without zeros: ";              //иначе выводим координаты строк в которых нет нулей
		for (int i = 0; i < row; ++i)
		{
			if (row_with_out_zero[i] == true)
			{
				cout << i+1 << ' ';                          //вывод номеров строк в которых нет нулей 
			}
		}
		cout << endl << endl;
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
	if (max_count == row*col)                  //случай, когда в массиве все элементы равны
	{
		cout << "Array has euqle values" << endl;
	}
	else if (max_count == 1)              //случай, когда всего один максимум, тогда всего один максимум, по условию не выводим координату
	{
		cout << "Array has only one max" << endl;
	}
	else                                                //иначе больше 1 максимума, тогда выводим координаты 
	{
		cout << "Coordinates of max values: " << endl;
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


	cout << "Enter size of array: ";
	while (true)
	{
		cin >> row >>col;             //пользователь вводит размер массива 
		if (row <= 1 || col <= 1)
			cout << "Incorrect size of array" << endl;        //проверка размера массива   (row > 1 , col > 1)
		else
			break;

	}


	int** array = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		array[i] = new int[col];                   //инициализация двухмерного массива 
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> array[i][j];            //пользователь вводит двухмерный массив
		}
	}


	row_with_out_zero(array, row, col);       //первая подзадача


	max_value(array, row, col);         //вторая подзадача

	
	return 0;
}
