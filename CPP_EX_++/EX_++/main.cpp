#include <iostream>
using namespace std;

int main ()
{
 int n, k, st,sv ;
 int i = 0, j = 0;
 double **mas;

 setlocale (LC_CTYPE, "rus");

 cout << "Введите количесво строк массива(к-во у-й): ";
 cin >> st; //Число строк
 n=st+1;

 cout <<"Введите количесво столбцов массива(к-во х): ";
 cin >>sv; //Число столбцов
 k=sv+n;

 mas = new double*[n]; //Выделение памяти под n-строк

 for(i = 0; i < n; i++)
   {
	 mas[i] = new double[k]; //Выделение памяти для каждой строки по k-столбцов 
   }

 for(i = 0; i < n; i++)
	{
		if (i<n-1)	  
		  cout <<"Введите коэффициенты(значения базисных переменных,свободные члены) "<<i+1<<" -го ур-ия"<<endl;
	    else 
	      cout <<"Введите целевую функцию с ОТРИЦАТЕЛЬНЫМ ЗНАКОМ: "<<endl;  
        for(j = 0; j < k; j++)
          {
		    cout<< "mas["<< i<< "][" <<j <<"]="; //Ввод массива 
            cin>> mas[i][j];
          } 
     }

 //вывод массива
cout<<endl;
cout<<endl<<"***********************************"<<endl;
cout<<" Таблица: "<<endl;
int min;
  for(i = 0; i < n; i++)
    {	  
	  for(j = 0; j < k; j++)
        {          
          cout<< " "<<mas[i][j]<<" ";
	    }
	  cout<<" "<<endl;
    }
   cout<<endl<<"***********************************"<<endl;  
   
   int w=0;
   w=sv+1;
   
   //определяем оптимальность решения
int kpol=0;
 for (j = 0; j < k; j++)
	{
		if (mas[n-1][j]>0)
			kpol++;	
		 }
// cout<<"kpol="<<kpol<<"\n";если в последней строчке 4 положительных числа,то мы нашли решение
	cout<<"целевая функция равняется"<<mas[n-1][k-1]<<"\n";
 
		while (kpol<w)   
		{
			kpol=0;

  // поиск минимального
min = 0;
  for (j = 1; j < sv; j++)
    if (mas[n-1][j] < mas[n-1][min]) min = j; 
  cout << " этот столбец ведущий "<<mas[n-1][min] << endl;
double t;

t=mas[n-1][min];

// поиск столбца
cout<<endl<<"***********************************"<<endl;
int myn=0;
double r=0,z=0; 
z=(mas[myn][k-1])/(mas[myn][min]);
  for (i= 1; i < st; i++)
	  {
		  r=  (mas[i][k-1])/(mas[i][min]);
      if (z>r) myn=i;
	 }
  cout << "эта строка ведущая "<<mas[myn][k-1]<< endl;
  cout<<"строка"<<myn;
  cout<<endl<<"***********************************"<<"\n";
  cout <<"коэффицент"<<mas[myn][min]<<endl;

//деление на выбранный элемент
double l=0;
l=mas[myn][min];//для деления на коэффициент
for (j = 0; j < k; j++)
	{	  
		mas[myn][j]=mas[myn][j]/l; 
    }
cout<<endl;

 //вывод массива
cout<<endl<<"***********************************"<<endl;
 cout<<endl;  
  for(i = 0; i < n; i++)
    {	  
	  for(j = 0; j < k; j++)
        {  
          cout<< " "<<mas[i][j]<<" ";
	    }
	    cout<<" "<<endl;
     }


//из элеметов соответствующих строк вычитаем элементы найденной нам строки
double p=0;
 for(i = 0; i < n; i++)	
	{
		p=mas[i][min];
			if (i!=myn)       
			{
				for(j = 0; j < k; j++)
					{
						mas[i][j]=mas[i][j]-mas[myn][j]*p;
					}
			}
     }


 //вывод массива
cout<<endl<<"***********************************"<<endl;
 cout<<endl;  
  for(i = 0; i < n; i++)
    {	  
	  for(j = 0; j < k; j++)
        {  
          cout<< " "<<mas[i][j]<<" ";
	    }
	    cout<<" "<<endl;
     }

cout<<endl<<"***********************************"<<endl; 
//cout<<"целевая функция равняется"<<mas[n-1][k-1]<<"\n";
  for (j = 0; j < k; j++)
	{
		if (mas[n-1][j]>0)
			kpol++;	
 }	
  // cout<<"kpol="<<kpol<<"\n";если в последней строчке  положительных числа столько, сколько было x(+1 своб.член),то мы нашли решение
  		}
		cout<<"решение оптимально,целевая функция равняется"<<mas[n-1][k-1]<<"\n";		
 system ("pause");
 return 0;
}