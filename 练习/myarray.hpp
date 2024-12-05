#pragma once
#include<iostream>
#include<string>
using namespace std;


template<class T>
class Myarray {

public:
	Myarray(int cap) {//�вι���
		this->m_cap = cap;
		this->m_size = 0;
		this->paddress = new T[this->m_cap];
	}

	Myarray(const Myarray& arr) {//�������죬���
		this->m_cap = arr.m_cap;
		this->m_size = arr.m_size;
		this->paddress = new T[arr.m_cap];//���
		for (int i = 0; i < this->m_size; i++) {
			this->paddress[i] = arr.paddress[i];
		}
	}

	~Myarray() {//��������
		if (this->paddress != NULL) {
			delete[] this->paddress;
			this->paddress = NULL;

		}
	}
	//operator=��ֹǳ��������
	Myarray& operator=(const Myarray& arr) {
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
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
	//β�巨
	void push_back(const T&val) {
		//�ж������Ƿ���ڴ�С
		if (this->m_cap == this->m_size) {
			return;
		}
		this->paddress[this->m_size] = val;//����ĩβ��������
		this->m_size++;//���������С
	}

	void pop_back() {
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ
		if (this->m_size == 0) {
			return;
		}
	/*	this->paddress[this->m_size - 1] = 0;*/
		this->m_size--;
	}
	//ͨ���±귽ʽ���������е�Ԫ��
	T& operator[](int index) {
		return this->paddress[index];
	}
	//�������������
	int getcap() {
		return this->m_cap;
	}

	//��������Ĵ�С
	int getsize() {
		return this->m_size;
	}
private:
	T* paddress;//ָ��ָ��������ٵ���ʵ����
	int m_cap;//ָ������
	int m_size;//ָ���С

}; 