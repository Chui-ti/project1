#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool run(string name) //функция проверки неуспешных сценариев
{
	ifstream file;
	char ch;
	int n = 0, f = 0;

	file.open(name + ".txt"); //открытие файла пользователя

	if (!file.is_open()) // проверка, открывается ли файл
	{
		cout << "Oops... Problems with file";
		f = 1;
	}
	else if (file.peek() == EOF) // проверка на наличие текста внутри файла
	{
		cout << "File is empty";
		f = 1;
	}
	else
	{
		while (true)
		{
			file >> ch;
			if (!file) //если текст в файле закончился, цикл прекращается
				break;
			else if (ch == '.' || ch == '!' || ch == '?') // если встретился символ-завершение, значит в файле закончилось предложение
			{
				++n; //считаем количество предложений
			}
		}
		if (n < 3) // если в файле предложений меньше трех, программа не будет выполняться
		{
			cout << "We didn't find three sentences in the file";
			f = 1;
		}
	}

	file.close(); //закрываем файл

	if (f == 1) //если один из неуспешных сценариев произошел, вернем "ложь" для завершения работы программы
		return false;
	else
		return true; //вернем "правду", если все условия для работы программы соблюдены
}
void output(string name) //функция вывода предложений в обратном порядке
{
	ifstream file;
	char ch;
	int k = 0, n_1 = 0, n_2 = 0, n_3 = 0;                 //Разбиваем текст из файла на 3 массива ,следовательно 3 длины массива 
	int flag = 1;                                      //(n_1,n_2,n_3 - длина первого массива, второго, третьего)

	file.open(name + ".txt"); //открываем файл

	while (true)
	{
		ch = file.get(); //получаем по одному элементу из файла
		if (!file)
			break; //если текст закончился, выходим из цикла
		if (k == 0)
			n_1++; //Пока первое предложение считаем длину для первого массива 
		else if (k == 1)
			n_2++; //считаем длину для второго массива 
		else
			n_3++; //считаем длину для второго массива

		if (ch == '.' || ch == '!' || ch == '?') //если встречается знак-завершение, значит одно предложение закончилось
		{
			++k; //считаем количество предложений
			if (k == 3) //если встретили 3 предложения, остальные не учитываем, выходим из цикла
				break;
		}

	}
	file.seekg(0); //выставляем "курсор" на первый элемент в файле

	char* array_1 = new char[n_1]; //создаем массив для хранения первого предложений по символам
	char* array_2 = new char[n_2]; //создаем массив для хранения второго предложений по символам
	char* array_3 = new char[n_3]; //создаем массив для хранения третьего предложений по символам

	int i = 0;
	char symbol;
	k = 0;              //флажок для указания в какой массив записывать символы

	while (true)
	{
		symbol = file.get(); // получаем предложение по символам 
		if (!file) //завершаем цикл, если дошли до конца файла
			break;
		if (k == 0)                  //если первое предложение ,то
			array_1[i] = symbol; //получаем по одному элементу из файла и записываем в первый массив (первое предложение)
		else if (k == 1)             //если второе предложение ,то
			array_2[i] = symbol; //получаем по одному элементу из файла и записываем во второй массив (второе предложение)
		else                        //если третье предложение ,то
			array_3[i] = symbol; //получаем по одному элементу из файла и записываем в третий массив (третье предложение)

		++i;
		if (i == n_1 && k == 0) //если счетчик равен длине первого предложения и флажок на первом предложении, то переходим на второе
		{
			k++;         //второе предложение
			i = 0;   //обнуляем счетчик
		}
		else if (i == n_2 && k == 1)//если счетчик равен длине второго предложения и флажок на втором предложении, то переходим на третий
		{
			k++;        //третье предложение
			i = 0;   //обнуляем счетчик
		}
	}

	for (int i = 0; i < n_3; ++i) // цикл вывода третьего предложений
	{

		cout << array_3[i];

	}

	for (int i = 0; i < n_2; ++i) // цикл вывода второго предложений
	{

		cout << array_2[i];

	}

	for (int i = 0; i < n_1; ++i) // цикл вывода первого предложений
	{

		cout << array_1[i];

	}

	file.close(); // закрытие файла


}
int main() //главная функция, в которой вызываем остальные
{
	ifstream file;

	string name;

	cout << "Enter file name: ";
	cin >> name; //запрашиваем у пользователя имя файла

	if (run(name))//вызываем функцию проверки неуспешных сценариев
	{
		output(name);//вызываем функцию для работы с предложениями

	}


	return 0;
}
