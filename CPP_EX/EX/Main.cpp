#include <iostream>
#include <windows.h>
//#include <vector>
//#include <list>

#include "for_each.h"
using namespace std;
// НАЧАЛО 15:40
// 16:07 закончил писать main and for_each
// 16:40 готов vector но не для строк (для них не гарантирую адекватную работу)
// 19:30 осталось доделать итератор а именно != и ++
// 20:12 Ну в принципе все, только вот за последний заглянуть в списке, не очень получилось
// + Ну плюс сколько-то часов следущего дня, но теперь все работает :)
template<class T>
class vector
{
public:
	T* arr;
	int size;

	typedef typename T* iterator;

	vector()
	{
		size = 1;
		arr = new T[size];
	}
	void resize()
	{
		T* temp = new T[size];
		for(int i=0; i<size; i++)
		{
			temp[i]=arr[i];
		}
		delete[] arr;
		size = size+1;
		arr = new T[size];
		for(int i=0; i<size-1; i++)
		{
		arr[i] = temp[i];
		}
		delete[] temp;
	}

	void push_back(T a)
	{
		arr[size-1]=a;
		resize();
	}

	iterator begin()
	{
		return arr;
	}

	iterator end()
	{
		return arr+size;
	}

	~vector()
    {
        delete[] arr;
    }
};

template<class T>
class list
{
public:
	int count;
    struct listElem
    {
	public:
		T data;
		listElem* next;
       
		listElem()// конструктор
		{
			this->next=NULL;
		}
		
		friend bool operator != (listElem& a, listElem& b)
		{
			return a.next != b.next;
		}

    };
	class iter
	{
	public:
		listElem* a;
		
		
		T &operator *()
		{
			return (*a).data;
		}

		iter &operator = (listElem* b)
		{
			a = b;
			return *this;
		}

		friend bool operator != (iter &a, iter &aa)
		{
			return						*(a.a) != *(aa.a);
			//return (*(this->a)).next != (*(a.a)).next;
		}

		iter & operator ++()
		{
			(*(this->a)) = (*((*(this->a)).next));
			return *this; 
		}
	};
    listElem* head;
	listElem* last;
public:
	
	typedef typename iter iterator;
	//typedef listElem* list_type;
	//list_type node;
	//typedef _List_iterator<_Mybase> iterator;
	//typedef _Container::iterator iterator
    list()
	{ 
		head = last = NULL; 
		count = 0;
	}
    void push_back(T value)
    {
        listElem* add = new listElem;
		add->next = NULL;
        add->data = value;
        if(head == NULL) //Если в списке нет элементов
        {
            head = last = add;													// First step
        }
        else
        {
			listElem *current;
			if(count==1)														// Second step
			{
			for(current=head;current->next!=0;current=current->next);
			current->next=add;
			current=current->next;
			listElem* add_new_last = new listElem;
			current->next = add_new_last;
			last = current->next;
			}
			else																// Other steps :)
			{
				for(current=head;(current->next)->next!=0;current=current->next);
				current->next=add;
				current=current->next;
				listElem* add_new_last = new listElem;
				current->next = add_new_last;
				last = current->next;
			}

			//////// I need push, and push next 0 - TRUE? Yes it is
			//////// Then I push in 0, and do new 0
			////////      Explanation of Work
			//		--------------------------------------     <-- It is RAM :)
			//		| X |									first step
			//		--------------------------------------
			//		| X | | X | | 0 |						Second step
			//		--------------------------------------
			//		| X | | X | | X | | 0 |					\
			//		--------------------------------------   |
			//		| X | | X | | X | | X |	| 0 |			  }	Other steps ^-^
			//		--------------------------------------	 |
			//		| X | | X | | X | | X |	| X | | 0 |		/
			//		
			//		.	.	.	.	.	.	.	.	.	.	
			//
        }

        count++;
	
    }

	iterator begin()
	{
		iterator a;
		a = head;
		return a; //должен быть первый параметр контейнер
    }
	iterator end()
    {
		iterator a;
		a = last;
        return a; //должен быть первый параметр контейнер
    }
	
};

int main()
{
	SetConsoleOutputCP(1251);
	int a[3]={5,13,-5};
	
	vector<int> vi;
	vi.push_back(5);
	vi.push_back(13);
	vi.push_back(-5);

	list<double> li;
	li.push_back(5.05);
	li.push_back(13.05);
	li.push_back(-5.05);
	li.push_back(555);//////////////// Надо делать на один лишний

	int arr_sum=0;
	int vi_sum=0;
	double li_sum=0;

	vector<int>::iterator iter_vi;
	list<double>::iterator iter_li;
	iter_vi = vi.begin();
	iter_li = li.begin();

	double f = *iter_li;
	cout<<"Это первый Элемент Списка "<<f<<endl;
//	f = *(++iter_li);
//	cout<<"Это второй Элемент Списка "<<f<<endl;
//	f = *(++iter_li);
//	cout<<"Это третий Элемент Списка "<<f<<endl;
	f = *(li.end());
	cout<<"Это <За последний> Элемент Списка (Но, он не очень работает) "<<f<<endl;

	for_each(a,((a)+3),arr_sum);
	for_each(iter_vi,vi.end(),vi_sum);
	for_each(iter_li,li.end(),li_sum);

	/////// COUT_ALL \\\\\\\++
	cout<<arr_sum<<endl;
	cout<<vi_sum<<endl;
	cout<<li_sum<<endl;
	system("pause");
}