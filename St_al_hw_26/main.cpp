#include "Student.h"

void main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector <Student> st;
	int n;
	bool key = 1;
	char ch;
	Creat_st(st);	
	do
	{
		show_menu();
		cout << "Enter: "; cin >> ch; cout << endl;
		system("cls");
		if (ch < '0' || ch>'5')
			cout << "Введены некорректыне данные, возобновите ввод" << endl;
		else
		{
			switch (ch)
			{
				case '1':
				{
					h();
					n = 0;
					for (auto it : st)
					{
						++n;
						cout << setw(3) << n << ')' << it << endl;
					}
				}break;
				case '2':
				{
					min_max(st);
				}break;
				case '3':
				{
					sort_st(st);
				}break;
				case '4':
				{				
					vv();
					for_each(st.begin(), st.end(), [](Student& s1)
					{ s1.Set_avg2() ; });

				}break;
				case '5':
				{
					cout << "Удаляет из вектора студентов со средним баллом ниже 5" << endl;
					auto it2 = remove_if(st.begin(), st.end(), [](Student s1)
						{return s1.Get_avg() < 5; });
					st.erase(it2, st.end());
					n = 0;
					for (auto it : st)
					{
						++n;
						cout << setw(3) << n << ')' << it << endl;
					}
				}break;
				case '0':
				{

				}break;
			default:
				break;
			}
		}
	} while (key);
}