#include <iostream>

using namespace std;
class A
{
	int a1;
public:
	int a2;
protected:
	int a3;
private:
	int a4;
};

class B : private A
{
	int b1; 
public:
	int b2;
protected:
	int b3;
private:
	int b4;
};

class counter
{
static int count;
public:
void setcount(int i) {count = i;};
void showcount () {cout << count << " "; }
};
int counter::count=0; // определение count

class operatorT
{
public:
	int i;
	operatorT operator ! ()
	{
		i=i*(-1);
		return *this;
	}
	
operatorT operator + (operatorT& a)
{
	this->i=this->i+a.i;
	return *this;
}
};
/*
operatorT operator !(operatorT& a)
{
	a.i=(a.i)*(-1);
	return a;
}
*/
/*
operatorT operator + (operatorT& a,operatorT& b)
{
	operatorT temp;
	temp.i=a.i+b.i;
	return temp;
}*/
void for_each(operatorT& a, void(*action)(int&))
{
	action(a.i);
}
void abs_(int& a)
{
	a=a*(-1);
}
int main()
{
operatorT b;
operatorT a;
a.i=10;
b.i=30;
a=a+b;

!a;
cout<<a.i<<endl;
for_each(a,abs_);
cout<<a.i<<endl;
system("pause");
return 0;
}
/*
int main() {
counter a, b;
a.showcount (); // выводит 0
b.showcount (); // выводит 0
a.setcount (10); // установка статического count в 10
a.showcount (); // выводит 10
b.showcount (); // также выводит 10
system("pause");
return 0;
}*/
/*
int main()
{
	B b;
	b.a=100;



	return 0;
}*/


