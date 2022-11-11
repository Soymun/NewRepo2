#include <iostream>
#include <fstream>
#include <string>
class Сircle {

	public:int x;

	public:int y;

	public:int R;
};
using namespace std;
void insertionSort(Сircle* list[], int listLength)
{
	for (int i = 1; i < listLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && list[j]->R > list[j + 1]->R)
		{
			std::swap(list[j], list[j + 1]);
			j--;
		}
	}
}

void insertionSortDesc(Сircle* list[], int listLength)
{
	for (int i = 1; i < listLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && list[j]->R < list[j + 1]->R)
		{
			std::swap(list[j], list[j + 1]);
			j--;
		}
	}
}
void saveInArray(Сircle circle[], Сircle* linkCircle[]) {
	std::cout << "Введите массив (Для того чтобы выйти из ввода массива,введите радиус -1): \n";
	int x;
	int y;
	int r;
	int i = 0;
	std::cin >> x;
	std::cin >> y;
	std::cin >> r;
	while (r != -1)
	{
		Сircle cr = Сircle();
		cr.x = x;
		cr.y = y;
		cr.R = r;
		circle[i] = cr;
		linkCircle[i] = &circle[i];
		i++;
		std::cin >> x;
		std::cin >> y;
		std::cin >> r;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int flag;
	int length;
	std::cout << "Введите длину массива: ";
	std::cin >> length;
	Сircle* circle = new Сircle[length];
	Сircle* *linkCircle = new Сircle*[length];
	saveInArray(circle, linkCircle);
	ifstream file;
	string line;
	int g = 0;
	Сircle cr = Сircle();
	while (true)
	{
		std::cout << "Меню:\n1)Сортировка по возрастанию\n2)Сортировка по убыванию\n3)Новый массив из файла\n4)Новый массив из консоли\n5)Выйти из программы\n";
		std::cin >> flag;
		switch (flag)
		{
		case 1:
			std::cout << "Сортировка массива по возрастанию: \n";
			insertionSort(linkCircle, length);
			for (int j = 0; j < length; j++) {
				std::cout << "Окружность: " <<" x: " << linkCircle[j]->x << " y: " << linkCircle[j]->y << " R: " << linkCircle[j]->R <<"\n";
			}
			std::cout << "\n";
			break;
		case 2:
			std::cout << "Сортировка массива по убыванию: \n";
			insertionSortDesc(linkCircle, length);
			for (int j = 0; j < length; j++) {
				std::cout << "Окружность: " << " x: " << linkCircle[j]->x << " y: " << linkCircle[j]->y << " R: " << linkCircle[j]->R <<"\n";
			}
			std::cout << "\n";
			break;
		case 3:
			file.open("txt.txt", ifstream::app);
			while (getline(file, line)) {
				Сircle cr = Сircle();
				cr.x = line[0] - '0';
				cr.y = line[2] - '0';
				cr.R = line[4] - '0';

				circle[g] = cr;
				linkCircle[g] = &circle[g];
				g++;
			}
			break;
		case 4:
			saveInArray(circle, linkCircle);
			break;
		}
		if (flag == 5) {
			delete[] circle;
			delete[] linkCircle;
			break;
		}
	}

}