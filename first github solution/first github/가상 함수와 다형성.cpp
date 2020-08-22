#include<iostream>
using namespace std;

class A
{
public:
	virtual void print() { cout << "A" << endl; }
};

class B : public  A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public  B
{
public:
	void print() { cout << "C" << endl; }
};

class D : public  C
{
public:
	void print() { cout << "D" << endl; }
	//���� �Լ����� ���� �̸�,��ȯ��, ���ڰ� �� �Ȱ���
	//�����Ǵ� ���(cout���� A�� ����ϳ� B�� ����ϳ�)�� �ٸ���
	//�� ����Լ��� �������̵��� �Ǿ� �ִ�.
}; 

int main()
{
	A a;
	B b;
	C c;
	D d;
	//�տ��� �����ͷ� �θ� �ڽ��� ����Ű���� ���� ���۷����� ����Ű��
	//�θ��� ���۷����� �ڽ��� ����Ű�� �ڽ��� �θ�ó�� �ൿ�Ѵ�(virtual ���ٸ�)
	//�θ� Ŭ������ �Լ��� virtual�� �Ǿ� ������ �ڽ��� �ڽ��� �������̵��� �Լ��� ����Ѵ�.
	A& ref = b;
	ref.print();
	/*��ӱ������� ���� ������ �θ� Ŭ������ virtual�� �Ǹ� 
	�ؿ� ��ӹ��� �ڽ� Ŭ�������� �������̵��� �Լ����� �� virtual�� ���� ���´�
	���� ���ϰ� �Ϸ��� �������̵� �Լ��� virtual�� �� ���ش�.*/
	B& ref2 = c;
	ref2.print();
	return 0;
}