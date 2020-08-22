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
	//지금 함수들을 보면 이름,반환형, 인자가 다 똑같고
	//구현되는 기능(cout으로 A를 출력하나 B를 출력하나)이 다르다
	//즉 멤버함수에 오버라이딩이 되어 있다.
}; 

int main()
{
	A a;
	B b;
	C c;
	D d;
	//앞에는 포인터로 부모가 자식을 가리키지만 여긴 레퍼런스로 가리키기
	//부모의 레퍼런스로 자식을 가리키면 자식이 부모처럼 행동한다(virtual 없다면)
	//부모 클래스의 함수가 virtual이 되어 있으면 자식은 자신의 오버라이딩된 함수를 사용한다.
	A& ref = b;
	ref.print();
	/*상속구조에서 가장 상위의 부모 클래스가 virtual이 되면 
	밑에 상속받은 자식 클래스들의 오버라이딩된 함수들은 다 virtual을 먹은 상태다
	보기 편하게 하려고 오버라이딩 함수에 virtual을 다 써준다.*/
	B& ref2 = c;
	ref2.print();
	return 0;
}