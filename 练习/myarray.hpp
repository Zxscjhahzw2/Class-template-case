#pragma once
#include<iostream>
#include<string>
using namespace std;


template<class T>
class Myarray {

public:
	Myarray(int cap) {//有参构造
		this->m_cap = cap;
		this->m_size = 0;
		this->paddress = new T[this->m_cap];
	}

	Myarray(const Myarray& arr) {//拷贝构造，深拷贝
		this->m_cap = arr.m_cap;
		this->m_size = arr.m_size;
		this->paddress = new T[arr.m_cap];//深拷贝
		for (int i = 0; i < this->m_size; i++) {
			this->paddress[i] = arr.paddress[i];
		}
	}

	~Myarray() {//析构函数
		if (this->paddress != NULL) {
			delete[] this->paddress;
			this->paddress = NULL;

		}
	}
	//operator=防止浅拷贝问题
	Myarray& operator=(const Myarray& arr) {
		//先判断原来堆区是否有数据，如果有先释放
		if (this->paddress != NULL) {
			delete[]this->paddress;
			this->paddress = NULL;
			this->m_cap = 0;
			this->m_size = 0;
		}
		this->m_cap = arr.m_cap;
		this->m_size = arr.m_size;
		this->paddress = new T[arr.cap];
		for (int i = 0; i < arr.m_cap;i++)
		{
			this->paddress[i] = arr.paddress[i];
		}
		return *this;
	}
	//尾插法
	void push_back(const T&val) {
		//判断容量是否等于大小
		if (this->m_cap == this->m_size) {
			return;
		}
		this->paddress[this->m_size] = val;//数组末尾插入数据
		this->m_size++;//更新数组大小
	}

	void pop_back() {
		//让用户访问不到最后一个元素，即为尾删
		if (this->m_size == 0) {
			return;
		}
	/*	this->paddress[this->m_size - 1] = 0;*/
		this->m_size--;
	}
	//通过下标方式访问数组中的元素
	T& operator[](int index) {
		return this->paddress[index];
	}
	//返回数组的容量
	int getcap() {
		return this->m_cap;
	}

	//返回数组的大小
	int getsize() {
		return this->m_size;
	}
private:
	T* paddress;//指针指向堆区开辟的真实数组
	int m_cap;//指针容量
	int m_size;//指针大小

}; 