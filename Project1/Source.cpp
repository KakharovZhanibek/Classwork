#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

struct fio
{
	char *name;
	char *surname;
	char *patronymic;
};

struct student
{
	fio *FIO;
	int *assesstments;
	int attribute;
	int sum = 0;

};

void generate(fio *fio);

void main()
{
	setlocale(0, "");
	srand(time(0));
	rand();
	int stud_colvo;
	cout << "Введите количество студентов : ";
	student *students = new student[stud_colvo];
	if (students == NULL)
	{
		cout << "Память не выделена!" << endl;
	}
	else
	{
		for (int i = 0;i < stud_colvo;i++)
		{
			generate(students->FIO);

			students->assesstments = new int[10];
			
			for (int j = 0;j < 10;j++)
				students->assesstments[j] = 1 + rand() % 9;

			students++;
		}
		students = students - stud_colvo;
	}

	system("pause");
}

void check_marks(student*stud)
{
	if (stud->sum > 8)
	{
		stud->attribute = 5;

	}
	if (stud->sum > 6 && stud->sum < 9)
	{
		stud->attribute = 4;
	}
	else if (stud->sum > 4 && stud->sum < 8)

	{

	}
}
void calc_marks(student *stud)
{
	for (int i = 0;i < 10;i++)
		stud->sum += stud->assesstments[i];
	stud->sum += stud->sum / 10;
}
void generate(fio *fio)
{
	fio->name = new char[3];
	fio->patronymic = new char[3];
	fio->surname = new char[3];

	for (int i = 0;i < 3;i++)
	{
		fio->name[i] = 97 + rand() % 95;
		fio->patronymic[i] = 97 + rand() % 95;
		fio->surname[i] = 97 + rand() % 95;
	}
}