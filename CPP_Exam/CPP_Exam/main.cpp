#include <iostream>

using namespace std;

int e10(){
	return 1,2,3;
}

void e16(){
	int X = 1 << 2 + 3;
	cout<<X<<endl;
}

void e23(){
	int X = 1 << 2 < 3;
	cout<<X<<endl;
}

void e42(){
	int X = 1 | 2 || 3;
	cout<<X<<endl;
}

void e44(){
	int X = 2 | 1 ^ 3;
	cout<<X<<endl;
}

//http://stackoverflow.com/questions/9189522/something-we-found-when-using-comma-in-condition-ternary-operator
int e49(){
	return 1?1,2,3:4,5,6;
}

int e51(int n){
	if(n<0) e51(-n); else if(n!=0) e51(n-1); return n;
}

int e60(int n){
	if(n<0) return e60(-n); else if(n==0) return n; return 1+e60(n-1);
}

void e65(){
	try{
		throw 13;
		//int X = ++2;
		//cout<<X<<endl;
	}
	catch (int e)
    { 
        cout<<"An exception occurred. Exception Number: " << e << '\n'; 
    }
	
}

void e68(){
	//int N=3;// Not working
	const int N=3;
	int X[N];
}

void e74(){
	int *var = new int(2);
	*var*=2;
	printf("%d\n", *var);
}

void eMy1(){
	int X = ~1; // 1 -> 01 -> ~ -> 10 -> 2
	cout<<X<<endl;
}

int eMy49(){
	return 1?(1,2,3):(4,5,6);
}

int eMy49M(){
	return true?1,true:2,false;
}

// Pointers
int sum1(int a, int b){
	return a+b;
}
//http://ru.stackoverflow.com/questions/284850/%D0%9F%D0%BE%D1%87%D0%B5%D0%BC%D1%83-%D0%BD%D0%B5%D0%BB%D1%8C%D0%B7%D1%8F-%D1%81%D0%BA%D0%BB%D0%B0%D0%B4%D1%8B%D0%B2%D0%B0%D1%82%D1%8C-%D1%83%D0%BA%D0%B0%D0%B7%D0%B0%D1%82%D0%B5%D0%BB%D0%B8
int* sum2(int *a, int *b){
	printf("%d\n", a);
	printf("%d\n", b);
	cout<<a<<endl;
	cout<<b<<endl;
	*a+=4;
	printf("%d\n", a);
	printf("%d\n", b);
	cout<<a<<endl;
	cout<<b<<endl;
	int c;
	c = a - b;
	cout<<"c*intSize = "<<c<<" + "<<sizeof(int)<<" = "<<c*sizeof(int)<<endl;
	cout<<"a - b = "<<((int)a - (int)b)<<endl;
	return &c;
}

void arrayInit(int *arr, int &b){
	cout<<"arrayInit: "<<arr<<endl;
	cout<<"arrayInit: "<<b<<endl;
	*arr *= 5;
	b *= 5;
}
void pointerGames(){
	cout<<"\n__PointerGames__"<<endl;

	cout<<sum1(5, 5)<<endl;
	int X = 5;
	int Y = 10;
	cout<<sum2(&X, &Y)<<endl;

	int Z = 13;
	cout<<Z<<endl;
	cout<<&Z<<endl;
	cout<<*&Z<<endl;
	cout<<Z<<endl;

	int *arr = new int(3);
	int b = 3;
	cout<<arr<<endl;
	cout<<*arr<<endl;
	cout<<&b<<endl;
	cout<<b<<endl;
	arrayInit(arr, b);
	cout<<arr<<endl;
	cout<<*arr<<endl;
	cout<<&b<<endl;
	cout<<b<<endl;
	arrayInit(&b, *arr);
	cout<<arr<<endl;
	cout<<*arr<<endl;
	cout<<&b<<endl;
	cout<<b<<endl;
}

int main(){
	

	cout<<"Hello World"<<endl;
	
	cout<<e10()<<endl;
	e42();
	e44();
	eMy1();
	
	cout<<e49()<<endl;
	cout<<eMy49()<<endl;
	cout<<eMy49M()<<endl;

	cout<<e51(5)<<endl;

	cout<<e60(-5)<<endl;

	e65();
	e74();

	pointerGames();


	system("pause");
	return 0;
}