#include<iostream>
using namespace std;
#include<string>
#include"myarray.hpp"

class Person {
public:
	Person() {}
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};
void printIntArray(Myarray <int>&array){
	for (int i = 0; i < array.getsize(); i++) {
		cout << array[i]<<endl;
	}
}
//template<class Person>
void printPersonArray(Myarray <Person>& array) {
	for (int i = 0; i < array.getsize(); i++) {
		cout << "����" << array[i].name << "����" << array[i].age << endl;
	}
}

void test1() {
	Myarray <int>array(5);
	for (int i = 0; i < 5; i++) {
		array.push_back(i);
	}
	printIntArray(array);
	cout << "array������:" << array.getcap() << endl;
	cout << "array�Ĵ�С:" << array.getsize() << endl;

	Myarray<int>arr2(array);
	//printIntArray(arr2);
	arr2.pop_back();
	printIntArray(arr2);
	cout << "arr2������:" << arr2.getcap() << endl;
	cout << "arr2�Ĵ�С:" << arr2.getsize() << endl;
}
//�����Զ�����������


void test2() {
	Myarray <Person>array(7);
	
	Person p1("yiyi", 1);
	Person p2("erer", 2);
	Person p3("sansan", 3);
	Person p4("sisi", 4);
	Person p5("wuwu", 5);
	//����
	array.push_back(p1);
	array.push_back(p2);
	array.push_back(p3);
	array.push_back(p4);
	array.push_back(p5);
	printPersonArray(array);
	cout << "array������:" << array.getcap() << endl;
	cout << "array�Ĵ�С:" << array.getsize() << endl;

	Myarray<Person>arr2(array);
	
	arr2.pop_back();
	printPersonArray(arr2);
	cout << "arr2������:" << arr2.getcap() << endl;
	cout << "arr2�Ĵ�С:" << arr2.getsize() << endl;
}
int main() {

	//test1();
	test2();
	system("pause");
	return 0;
}