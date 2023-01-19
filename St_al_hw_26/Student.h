#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Student
{
	string name, surname;
	int age;
	vector <int> ball;
	double avg_ball;
public:
	Student() {}
	Student(string _name, string _surname, int _age);
	void Set_avg();
	void Set_avg2();
	friend ostream& operator << (ostream& os, Student& st);

	double Get_avg() { return avg_ball; }
	string Get_name() { return name; }
	string Get_surname() { return surname; }
	int Get_age() { return age; }
};

Student rand_name1();
Student rand_name2();
void Creat_st(vector <Student>& stu);
void h();
void show_menu();
void min_max(vector<Student>& st);
void sort_st(vector<Student>& st);
bool pred1(Student s1, Student s2);
bool pred2(Student s1, Student s2);

void vv();
