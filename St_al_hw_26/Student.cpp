#include "Student.h"
int kk;
int nn;
char chch;

Student::Student(string _name, string _surname, int _age)
{
	name = _name; surname = _surname; age = _age;
	for (int i = 0; i < 10; i++)
		ball.push_back(rand() % 11 + 1);
	Set_avg();
}

void Student::Set_avg()
{
	int sum = 0;
	for (int i = 0; i < ball.size(); i++)
		sum += ball[i];
	avg_ball = (double)sum / ball.size();
}

void Student::Set_avg2()
{
	if(chch=='-')avg_ball -= nn;
	else if(chch=='+')avg_ball += nn;
}

ostream& operator<<(ostream& os, Student& st)
{
	os << setw(12) << st.name << setw(12) << st.surname
		<< setw(5) << st.age << setw(6) << st.avg_ball;
	return os;
}

Student rand_name1()
{
	string* name = new string[10]
	{ "����������","���������","���","������","����","����","�������","�����","����","����" };
	string* surname = new string[10]
	{ "�������","������","�������","�����","��������","�������","���������","�����","������","�������" };
	Student st(name[rand() % 10], surname[rand() % 10], rand() % 16 + 16);
	return st;
}

Student rand_name2()
{
	string* name = new string[10]
	{ "��������","�����","�������","�����", "����������","�����","����","���","�������","�����" };
	string* surname = new string[10]
	{ "���������","��������","��������","���������", "���������","������","��������","�������","�������","����������" };
	Student st(name[rand() % 10], surname[rand() % 10], rand() % 16 + 16);
	return st;
}

void Creat_st(vector <Student>& stu)
{
	Student tmp;
	int size = 20;
	for (int i = 0; i < size; i++)
	{
		if (i < 10)
		{
			tmp = rand_name1();
			stu.push_back(tmp);
			tmp = {};
		}
		else 
		{ 
			tmp = rand_name2(); 
			stu.push_back(tmp);
			tmp = {};
		}
	}
}

void h()
{
	cout << setw(18) << "name |" << setw(12) << "surname |" << 
		setw(5) << "age |" << setw(6) << "avg |" << endl;
	cout << "-----------------------------------------" << endl;
}

void show_menu()
{
	cout << "� ������ ������� ������������ ��������� �� ��������� ��������:" << endl;
	cout << "(�������� �������� �� ������������������)" << endl;
	cout << "1 - ������� �� �����;" << endl;
	cout << "2 - ����� ������������ � ������������� ��������;" << endl;
	cout << "3 - ���������� ������ �� �������� ��� �� �����������;" << endl;
	cout << "4 - ���������� ��� ��������� �������� � ���������� �� �������� ���������;" << endl;
	cout << "5 - �������� ��������� �� ���������� ������ �������� ��������;" << endl;
	cout << "0 - �����" << endl;
}

void min_max(vector<Student>& st)
{
	cout << endl;
	cout << "������� � ����������� ������� ������:"<<endl;

	auto it = min_element(st.begin(), st.end(), [](Student s1, Student s2)
		{
			return s1.Get_avg() < s2.Get_avg();
		});
	h();
	cout << "    " << *it << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "������� � ������������ ������� ������: "<<endl;
	it = max_element(st.begin(), st.end(), [](Student s1, Student s2)
		{
			return s1.Get_avg() < s2.Get_avg();
		});
	h();
	cout << "    " << *it << endl << endl << endl;
}

void sort_st(vector<Student>& st)
{	
	bool key = 1;
	int i = 1;
	do
	{
		cout << "1 - ���������� �� �����������" << endl;
		cout << "2 - ���������� �� ��������" << endl;
		char ch;
		cout << "Enter: "; cin >> ch; cout << endl;
		if (ch < '1' || ch>'2')
		{
			cout << "������ �����" << endl << endl;
		}
		else
		{
			cout << "1 - ���������� �� �����" << endl;
			cout << "2 - ���������� �� �������" << endl;
			cout << "3 - ���������� �� �������� �����" << endl;
			cout << "4 - ���������� �� ��������" << endl;
			char n;
			cout << "Enter: "; cin >> n; cout << endl;
			system("cls");
			if (n < '0' || n>'4')
			{
				cout << "������ �����" << endl << endl;
			}
			else
			{
				switch (n)
				{
				case '1':
				{
					kk = 1;
					sort(st.begin(), st.end(), (ch=='1'? pred1:pred2));
					i = 1;
					for (auto it : st)
					{
						cout << setw(4) << i << ")" << it << endl;
						i++;
					}
					key = 0;
				}break;
				case '2':
				{
					kk = 2;
					sort(st.begin(), st.end(), (ch == '1' ? pred1 : pred2));
					i = 1;
					for (auto it : st)
					{
						cout << setw(4) << i << ")" << it << endl;
						i++;
					}
					key = 0;
				}break;
				case '3':
				{
					kk = 3;
					sort(st.begin(), st.end(), (ch == '1' ? pred1 : pred2));
					i = 1;
					for (auto it : st)
					{
						cout << setw(4) << i << ")" << it << endl;
						i++;
					}
					key = 0;
				}break;
				case '4':
				{
					kk = 4;
					sort(st.begin(), st.end(), (ch == '1' ? pred1 : pred2));
					i = 1;
					for (auto it : st)
					{
						cout << setw(4) << i << ")" << it << endl;
						i++;
					}
					key = 0;
				}break;
				case '0':
				{
					key = 0;
				}break;
				default:
					break;
				}
			}
		}
	} while (key);
}

bool pred1(Student s1, Student s2)
{
	if (kk == 1)return s1.Get_name() < s2.Get_name();
	if (kk == 2)return s1.Get_surname() < s2.Get_surname();
	if (kk == 3)return s1.Get_avg() < s2.Get_avg();
	if (kk == 4)return s1.Get_age() < s2.Get_age();
}

bool pred2(Student s1, Student s2)
{
	if (kk == 1)return s1.Get_name() > s2.Get_name();
	if (kk == 2)return s1.Get_surname() > s2.Get_surname();
	if (kk == 3)return s1.Get_avg() > s2.Get_avg();
	if (kk == 4)return s1.Get_age() > s2.Get_age();
}

void vv()
{
	bool b = 1;
	do
	{
		cout << "������� �������� �� ������� ������ �������� ������� ���� ���������" << endl;
		cout << "Enter: "; cin >> nn; cout << endl;
		cout << "��������� '+', ��������� '-'" << endl;
		cout << "Enter: "; cin >> chch; cout << endl;
		system("cls");
		if (chch != '-' && chch != '+')
		{
			cout << "������ �����" << endl;
		}
		else
		{
			b = 0;
		}
	} while (b);
}

