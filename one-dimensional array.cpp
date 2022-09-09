#include <iostream>

using namespace std;


int Partition(float* values, int l, int r)            
{
	int x = values[r];
	int less = l;

	for (int i = l; i < r; ++i)
	{
		if (values[i] <= x)
		{
			swap(values[i], values[less]);
			++less;
		}
	}
	swap(values[less], values[r]);
	return less;
}

void QuickSortImpl(float* values, int l, int r)
{
	if (l < r) 
	{
		int q = Partition(values, l, r);
		QuickSortImpl(values, l, q - 1);
		QuickSortImpl(values, q + 1, r);
	}
}

void negative_digit(float* array,int n)    //функция выводит координаты отрицательных чисел, их количество, сумму отрицательных чисел
{
	bool* coord = new bool[n];        //кордианты отрицательных чисел, где индекс массива равный true обозначает индекс отрицательного числа  в массиве чисел 
	int count = 0;                   // количество отрицательных чисел
	float sum = 0;                   //сумма отрицательных чисел 

	for (int i = 0; i < n; ++i)
	{
		coord[i] = false;           // изначально заполняем булевый массив false`ми
		if (array[i] < 0)
		{
			count++;                //если встретилось отрицательное, то счетчик + 1
			coord[i] = true;        // также запоминаем координату (i)
		}

	}

	if (count == 0)
		cout << "There is no negative digits."<<endl;         //случай если нет отрицательных чисел -> нет суммы и координат
	else if (count == 1)
	{
		cout << "Thre is only one negative digit. Sum doesn`t exist"<<endl;
		cout << "Count negative digits : " << count << endl;                     //если одно отрицательное число, то выводим координату и количество
		cout << "Coordinate negative digit : ";
		for (int i = 0; i < n; ++i)
		{
			if (coord[i] == true)         //тот самый индекс, где отрцательное число 
			{
				cout << i;
				break;              //break так как всего 1 число, больше мы не найдем 
			}
		}
		cout << endl;
	}
	else                          // или когда отрицательных чисел больше чем 1
	{
		for (int i = 0; i < n; ++i)
		{	
			if (array[i]<0)
				sum += array[i];               //считаем сумму 
		}
		
		cout << "Sum negative digits :" << sum << endl;
		cout << "Count negative digits :" << count << endl;            //выводим количество, сумму и координаты
		cout << "Coordinates negative digits :";
		for (int i = 0; i < n; ++i)
		{
			if (coord[i] == true)
			{
				cout << i <<' ';               //выводим координаты отрицательных чисел 
			}
		}
		cout << endl;
	}
}

void composition(float* array, int n)             //функция выводит произведение между минимальным и максимальным числом
{
	int max = array[0];     // максимальное и минимальное число в массиве чисел
	int min = array[0];
	bool* coord_max = new bool[n];    // координаты максимальных и миннимальных чисел через булевые массивы,
	bool* coord_min = new bool[n];    // где индекс булевого массива соотвествует индексу числового массива
	int count_min = 0, count_max = 0;                        //количество максимальных и миннимальных элементов 

	for (int i = 0; i < n; ++i)
	{
		coord_max[i] = false;        //заполняем массивы false`ми 
		coord_min[i] = false;              

		if (max < array[i]) max = array[i];            //ищем максимальное число
		if (min > array[i]) min = array[i];               //и минимальное число 
	}

	if (min == max)
	{
		cout << "All values are equal" << endl;        //случай когда миннимальное число и максимальное число равны -> массив состоит из одинаковых чисел 
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (min == array[i])
		{
			coord_min[i] = true;            //ищем координаты минимальных чисел 
			count_min++;          //количество минимальных чисел 
		}
		if (max == array[i])
		{
			coord_max[i] = true;           //ищем координаты максимальных чисел 
			count_max++;         //количество максимальных чисел 
		}
	}


	if (count_min > 1)           //если количество минимальных больше чем 1, то нужно дать пользователю выбор какое из миннимальных
	{
		while (true)
		{
			cout << "indexs min: ";
			for (int i = 0; i < n; ++i)
			{
				if (coord_min[i] == true)
				{
					cout << i << ' ';      //выводим координаты миннимальных 
				}
			}
			cout << endl << "chose index of min digit: ";
			cin >> min;                                     //пользователь вводит координату числа


			if (coord_min[min] == true)              //проверяем, правильно ли пользователь ввел число 
				break;
			
			cout << "Mistake!" << endl;           //иначе сообщаем ,что пользователь ошибся 
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (coord_min[i] == true)
			{
				min = i;                   // если только 1 минимальное число, то программа выбирает это число 
				break;
			}
		}
	}

	if (count_max > 1)                    //по аналогии работает цикл с максимальным числом 
	{
		while (true)
		{
			cout << "indexs max: ";
			for (int i = 0; i < n; ++i)
			{
				if (coord_max[i] == true)
				{
					cout << i << ' ';
				}
			}
			cout << endl << "chose index of max digit: ";
			cin >> max;


			if (coord_max[max] == true)
				break;

			cout << "Mistake!" << endl;
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (coord_max[i] == true)
			{
				max = i;
				break;
			}
		}
	}

	float comp = 1;

	
	if (abs(min - max) == 1)
	{
		cout <<"Composition doens`t exist. Min and max stand side by side"<< endl;          //если максимальное и минимальное число стоят рядом, 
	}                                                                                     //то их произведение невозможно
	else
	{
		for (int i = min + 1; i < max; ++i)
		{

			comp *= array[i];                           //иначе считаем произведение между максимальным и минимальным числом
		}

		cout << "Composition is: " << comp << endl;  //вывод полученного произведения 
	}


}

int main() 
{

 	int n;       //количество элементов в массиве 
 
	cin >> n;


	float* array = new float[n];       //массив вещественных чисел 

	for (int i = 0; i < n; ++i) 
	{
		cin >> array[i];      //пользователь заполняет массив 
	}

	negative_digit(array, n);                     // первая подзадача          (количество отрицательных чисел и их координаты,сумму)

	composition(array, n);                        //вторая подзадача           (произведение между максимальным и минимальным числом)

	QuickSortImpl(array, 0, n-1);                 //сортировка массива 

	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << ' ';     //вывод массива в консоль
	}

	cout << endl;

	return 0;
}
