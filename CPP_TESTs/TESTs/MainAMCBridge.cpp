#include <iostream>
#include <stdio.h> 
#include <string.h> 
#include <vector>

#include "Log.h"
#define LOG Log::getInstance()

using namespace std;



/*
int main() {
	
	system("pause");
	return 0;
}
*/

/*
	1. What is the difference between a reference and a pointer?
	https://www.geeksforgeeks.org/whats-difference-between-char-s-and-char-s-in-c/
	https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in
*/
/**
void change(int *a){
	cout << "sizeof(a) in void change(int *a)" << sizeof(a) << endl;
	*a = 5;
}
void change(int &a){
	cout << "sizeof(a) in void change(int &a)" << sizeof(a) << endl;
	a = 5;
}

int main() {
	
	int *x = new int();
	int y;

	change(x);
	change(y);
	
	cout<<*x<<endl;
	cout<<y<<endl;

	LOG->println("x", x);
	LOG->println("&x", &x);


	int *x1 = new int[5];
	int y1[5];

	cout << sizeof(x1) << endl;
	cout << sizeof(y1) << endl;
	change(y1);

	system("pause");
	return 0;
}
/**/
/**/

void printArr(char *arr)
{
	int i;
	unsigned int strSize = strlen(arr);
	printf("string size = %d\n", strSize);
	printf("string sizeof = %d\n", sizeof(arr));
	for (i = 0; i < strSize; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
}

// Driver program 
int main()
{
	char arr[] = { 'g', 'e', 'e', 'k', 's', 'q', 'u', 'i', 'z', '\0' };
	printf("string sizeof in main = %d\n", sizeof(arr));
	printArr(arr);
	char arr2[] = "geeks for geeks";
	printf("string sizeof in main  = %d\n", sizeof(arr2));
	printArr(arr2);
	char *arr3 = "geeks for geeks";
	printf("string sizeof in main = %d\n", sizeof(arr3));
	printArr(arr3); // Works because strlen counts to '\0' null
	
	
	

	system("pause");
	return 0;
}
/**/
/*
	2. Explain the difference between int x; int x(); and int x{};
*/
/**
int main() {
	
	int x=0;
	int y(0);
	int z{};

	cout << x << endl;
	cout << y << endl;
	cout << z << endl;

	system("pause");
	return 0;
}
/**/

/*
3. assert(sizeof(int) != sizeof(long)); Is this statement always true?
https://ru.wikipedia.org/wiki/%D0%A1%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D0%B0_%D1%82%D0%B8%D0%BF%D0%BE%D0%B2_%D0%A1%D0%B8
int = 2 or 4 bytes (OS x8, x16, x32 )
long = 4;
*/
/**
#include <assert.h>
int main() {

	
	LOG->println("sizeof(int)", sizeof(int));
	LOG->println("sizeof(long)", sizeof(long));

	assert(sizeof(int) != sizeof(long));

	system("pause");
	return 0;
}
/**/

/*
4. What will the following line of code print out and why? unsigned int x = -1; std::cout << x;

Max Value

*/
/**
#include <limits.h>

int main() {

	unsigned int x = -1; 
	LOG->println("x", x);
	LOG->println("sizeof(x)", sizeof(x));
	LOG->println("uint max", UINT_MAX);



	system("pause");
	return 0;
}
/**/

/*

5. Can you explain the difference between new and new[]? Is it possible to delete memory using delete[] allocated within the new operator?

	https://stackoverflow.com/questions/2425728/delete-vs-delete-operators-in-c

	The delete operator deallocates memory and calls the destructor for a single object created with new.
	The delete [] operator deallocates memory and calls destructors for an array of objects created with new [].
	Using delete on a pointer returned by new [] or delete [] on a pointer returned by new results in undefined behavior.

*/
/**
int main() {

	int *x = new int();
	int *y = new int[10];


	LOG->println("x", x);
	LOG->println("sizeof(x)", sizeof(x));
	LOG->println("y", y);
	LOG->println("sizeof(y)", sizeof(y));

	delete x;
	delete[] y;

	system("pause");
	return 0;
}
/**/

/*
6. What is the difference between new/malloc or delete/free?
https://stackoverflow.com/questions/240212/what-is-the-difference-between-new-delete-and-malloc-free
*/



/**
7. What is the difference between stack and heap allocation?
https://www.youtube.com/watch?v=_8-ht2AKyH4
*/
/**
int main() {

	int a = 5; // Stack
	int b[] = { 1, 2, 3 }; // Stack
	int c[100]; // Stack

	int* x; // Stack|Heap, x address on Stack BUT also Heap mean initialized data are stored on Heap
	x = new int();  // Heap | but x stored on Stack, and new() on Heap
	int* y = new int[10]; // Heap | but y stored on Stack, and new[10] on Heap


	LOG->println("x", x);
	LOG->println("sizeof(x)", sizeof(x));
	LOG->println("y", y);
	LOG->println("sizeof(y)", sizeof(y));

	delete x;
	delete[] y;

	system("pause");
	return 0;
}
/**/
/*
	8. What is the evaluation order of the function parameters in C++?

	https://www.youtube.com/watch?v=Byqcrhc5tLE
*/
/**
int first() {
	cout << "first \n";
	return 1;
}

int second() {
	cout << "second \n";
	return 2;
}

int third() {
	cout << "third \n";
	return 3;
}

int fourth() {
	int a = 1;
	return 3/(a-1);
}

void printFun(int a) {
	cout << "printFun \n";
	cout << a << endl;
}
int sumFun(int a, int b) {
	cout << "sumFun \n";
	cout << a + b << endl;
	return a + b;
}

int main() {
	cout << "sumFun(first(), second());" << endl;
	sumFun(first(), second());
	cout << endl;

	cout << "printFun(first() + second());" << endl;
	printFun(first() + second());
	cout << endl;

	cout << "printFun(sumFun(first(), second()));" << endl;
	printFun(sumFun(first(), second()));
	cout << endl;

	cout << "if((first() || second() || first()) && third())" << endl;
	if((first() || second() || first()) && third())
	{ }
	cout << endl;

	cout << "if ((first() && second() && first()) || third())" << endl;
	if ((first() && second() && first()) || third())
	{ }
	cout << endl;

	return 0;
}
/**/

/**
9. What is the construction order of global variables?
https://stackoverflow.com/questions/19618801/when-are-global-variables-created
C++ does not define an order for when global variables are constructed during program startup.
*/
/**
#include <map>
map<int, string> something; // global variable
unsigned create(unsigned a) {
	something.insert(make_pair(a, "somestring"));
	return a;
}
const unsigned a = create(1);

int main() {
	cout << "OK" << a;
	return 0;
}
/**/
/**
10. What is the forward declaration of classes? What is it used for?
https://www.geeksforgeeks.org/what-are-forward-declarations-in-c/
*/
/**
#include <iostream>
using namespace std;

// Forward declaration
class A;
class B;

class B {
	int x;

public:
	void getdata(int n)
	{
		x = n;
	}
	friend int sum(A, B);
};

class A {
	int y;

public:
	void getdata(int m)
	{
		y = m;
	}
	friend int sum(A, B);
};
int sum(A m, B n)
{
	int result;
	result = m.y + n.x;
	return result;
}

int main()
{
	B b;
	A a;
	a.getdata(5);
	b.getdata(4);
	cout << "The sum is : " << sum(a, b);
	return 0;
}
/**/
////////////////////////////////////////////////////////////////////////////////////////////////////
/**
11. What is the meaning of a const keyword and how can it be used? 
12. What is the meaning of a static keyword and how can it be used? 
13. What are the advantages of using friend classes?
14. What is an abstract class? What is the pure virtual function?
**/
/**
15. How do you create a virtual constructor and virtual destructor for a class? Why would you do it? 
**/
/**/
/**
void prntln() {
	cout << "********************************\n";
}

class base {
public:
	base() {
		cout << "Constructing base \n";
	}
	~base() {
		cout << "Destructing base \n";
	}
};

class derived : public base {
public:
	derived() {
		cout << "Constructing derived \n";
	}
	~derived() {
		cout << "Destructing derived \n";
	}
};

class baseVirtual {
public:
	baseVirtual() { 
		cout << "Constructing baseVirtual \n";
	}
	virtual ~baseVirtual() { 
		cout << "Destructing baseVirtual \n"; 
	}
};

class derivedVirtual : public baseVirtual {
public:
	derivedVirtual() {
		cout << "Constructing derivedVirtual \n";
	}
	~derivedVirtual() {
		cout << "Destructing derivedVirtual \n";
	}
};

int main(void)
{

	derived* d = new derived();
	base* b = d;
	delete b;
	//delete d;

	prntln();
	derivedVirtual* dv = new derivedVirtual();
	baseVirtual* bv = dv;
	delete bv;

	getchar();
	return 0;
}
/**/

////////////////////////////////////////////////////////////////////////////////////////////////////
/**
16. What is a vtable and how does it work?
17. Initialization order of Bases and Members.
**/
/*
18. Is it possible to call a virtual function inside of a constructor/destructor?
*/
// CPP program to illustrate
// calling virtual methods in
// constructor/destructor
/**
class dog
{
public:
	dog()
	{
		cout<< "dog() Constructor called" <<endl;
		bark() ;
	}

	~dog()
	{
		cout << "dog() Destructor called" << endl;
		bark();
	}

	virtual void bark()
	{
		cout<< "dog() Virtual method called" <<endl;
	}

	void seeCat()
	{
		bark();
	}
};

class yellowDog : public dog
{
public:
		yellowDog()
		{
			cout<< "yellowDog() Derived class Constructor called" <<endl;
		}
		void bark()
		{
			cout<< "yellowDog() Derived class Virtual method called" <<endl;
		}
};

int main()
{
	yellowDog d;
	d.seeCat();
}

/**/
////////////////////////////////////////////////////////////////////////////////////////////////////
/**
19. What is a template and how is it used? 
20. What is specialization? How can it help to improve efficiency? 
21. struct Vector{ int* data; int size; }; Write copy constructor, operator= and destructor for the struct Vector.
22. What is an iterator? What iterator types do you know?
**/
/*
23. What is RAII?
https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization
Получение ресурса есть инициализация (англ. Resource Acquisition Is Initialization (RAII)) — 
программная идиома объектно-ориентированного программирования, смысл которой заключается в том, 
что с помощью тех или иных программных механизмов получение некоторого ресурса неразрывно совмещается с инициализацией, 
а освобождение — с уничтожением объекта.
*/
/**
#include <cstdio>
#include <stdexcept>

class file {
public:
	file(const char* filename) : m_file_handle(std::fopen(filename, "w+"))
	{
		std::cout << "Constructor \n";
		if (!m_file_handle)
			throw std::runtime_error("file open failure");
	}
	~file()
	{
		std::cout << "Destructor \n";
		if (std::fclose(m_file_handle) != 0)
		{
			// fclose() может вернуть ошибку при записи на диск последних изменений
		}
	}

	void write(const char* str)
	{
		if (std::fputs(str, m_file_handle) == EOF)
			throw std::runtime_error("file write failure");
	}

private:
	std::FILE* m_file_handle;

	// Копирование и присваивание не реализовано.  Предотвратим их использование,
	// объявив соответствующие методы закрытыми.
	file(const file&);
	file& operator=(const file&);
};

// пример использования этого класса
void example_usage() {
	// открываем файл (захватываем ресурс)
	file logfile("logfile.txt");

	logfile.write("hello logfile!");

	// продолжаем использовать logfile...
	// Можно возбуждать исключения или выходить из функции не беспокоясь о закрытии файла; 
	// он будет закрыт автоматически когда переменная logfile выйдет из области видимости.
}

int main() {
	example_usage();

	return 0;
}

/**/
/*
24. When should you use std::unique_ptr vs. std::shared_ptr? 
25. How should runtime errors be handled in C++? What general approaches do you know?
26. What will happen if the exception will be thrown within a constructor?
27. C++ supports multiple inheritance. What is the "diamond problem" that can occur with multiple inheritance? Give an example.
*/


// I get It
/*
class A
{
public:
	~A() {}
	copy(A* a) {

	}
};

class B
{
public:
	virtual ~B() {}

	virtual void F() { std::cout << "B::F()" << std::endl; }
};

class C : public B
{
public:
	C()
	{
		a = new A();
	}
	C(C c)
	{
		this.a = c.a;



		this.a1 = c.a1;
		for (int i = 0; i < c.vectorA.length(); i++)
			this.vectorA.push_back(c.vectorA[i]);
		for (int i = 0; i < c.vectorA1.length(); i++)
			//
			this.vectorA1.push_back(c.vectorA1[i]);

	}

	~C() {
		delete a;
		for (int i = 0; i < vectorA1.length(); i++)
			delete[] vectorA1[i];
	}
	void F() { std::cout << "C::F()" << std::endl; }

protected:
	A* a = nullptr;
	A a1;
	std::vector<A> vectorA;
	std::vector<A*> vectorA1;
};

int main(){
C* c1 = new C();
B* c = new C(*c1);
delete c;
delete c1;

}
//https://www.cyberforum.ru/cpp-beginners/thread1840307.html
//https://codeshare.io/5DyOol
/*
class A
{
public:
	int a = 5;
	A() {
		this->a = 13;
	}
	A(int _a) {
		this->a = _a;
	}
	~A() {}
};

class B
{
public:
	virtual ~B() {}

	virtual void F() { std::cout << "B::F()" << std::endl; }
};

class C : public B
{
public:
	C()
	{
		a = new A(10);
	}
	C(const C &c){ // Вот, вот где я тупанул... Я то думал, что они намекают на конструктор копирования... 
		this->a = new A(*c.a);
		this->a1 = c.a1;
		for (int i = 0; i < c.vectorA.size(); i++)
			this->vectorA.push_back(c.vectorA[i]);
		for (int i = 0; i < c.vectorA1.size(); i++)
			this->vectorA1.push_back(new A(*c.vectorA1[i]));
	}

	~C() {
		delete a;
		for (int i = 0; i < vectorA1.size(); i++)
			delete[] vectorA1[i];
	}
	void F() { std::cout << "C::F()" << std::endl; }

protected:
	A* a = nullptr;
	A a1;
	std::vector<A> vectorA;
	std::vector<A*> vectorA1;
};

int main() {
	C* c1 = new C();
	B* c = new C(*c1);

	delete c1;
	delete c;
	
}
/**/



/*
	99. delete this 
	Is it allowed to delete this?

	https://stackoverflow.com/questions/3150942/is-delete-this-allowed-in-c
	https://isocpp.org/wiki/faq/freestore-mgmt#delete-this
*/
/**/
/**
#include <ctime>

class Soul
{
public:

	int id = rand();

	Soul() {
		cout << "Soul in - Soul()\n";
	}
	~Soul() {
		cout << "Soul out - ~Soul()\n";
	}

	void getId() {
		cout << "ID " << id << "\n";
	}

	void goUpToTheSpiritInTheSky()
	{
		cout << "Soul goUpToTheSpiritInTheSky()\n";
		delete this;
	}
};

void prntln() {
	cout << "********************************\n";
}

int main()
{
	srand(time(0));
	// Following is Valid
	Soul* s = new Soul();
	s->getId();
	s->goUpToTheSpiritInTheSky();
	s->getId();
	s = NULL; // make ptr NULL to make sure that things are not accessed using ptr.
	prntln();

	Soul* sa = new Soul();
	sa->getId();
	delete sa;
	sa->getId();
	prntln();

	sa = new Soul();
	sa->getId();
	sa->goUpToTheSpiritInTheSky();
	sa->getId();
	sa = NULL;
	prntln();

	sa = new Soul();
	sa->getId();
	sa->goUpToTheSpiritInTheSky();
	sa->getId();
	//delete sa; // Error
	sa = NULL;
	prntln();

	sa = new Soul();
	sa->getId();
	sa->~Soul();
	sa->getId(); // undefined behavior
	//delete sa; // Error
	sa = NULL;
	prntln();

	// And following is Invalid: Undefined Behavior
	Soul sb;
	sb.getId();
	//sb.goUpToTheSpiritInTheSky();

	getchar();
	return 0;
}
/**/