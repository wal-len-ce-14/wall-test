#include<iostream>
using namespace std;

class Person{
	int No;
	public:
		Person(int a): No(a){cout << "create No." << No << "  person\n";}
};

class Teacher: virtual public Person{
	public:
		Teacher(int a): Person(a){
			cout << "Teacher called\n" << endl;
		}
};

class Student: virtual public Person{
	public:
		Student(int a): Person(a){
			cout << "Student called\n" << endl;
		}
};

class TA: public Teacher, public Student{
	public:
		TA(int a): Student(a), Teacher(a){
			cout << "TA called" << endl;
		}
};

int main(){
	TA p1(1);
	return 0;
}
