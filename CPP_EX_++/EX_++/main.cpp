#include <iostream>
using namespace std;

int main ()
{
 int n, k, st,sv ;
 int i = 0, j = 0;
 double **mas;

 setlocale (LC_CTYPE, "rus");

 cout << "������� ��������� ����� �������(�-�� �-�): ";
 cin >> st; //����� �����
 n=st+1;

 cout <<"������� ��������� �������� �������(�-�� �): ";
 cin >>sv; //����� ��������
 k=sv+n;

 mas = new double*[n]; //��������� ������ ��� n-�����

 for(i = 0; i < n; i++)
   {
	 mas[i] = new double[k]; //��������� ������ ��� ������ ������ �� k-�������� 
   }

 for(i = 0; i < n; i++)
	{
		if (i<n-1)	  
		  cout <<"������� ������������(�������� �������� ����������,��������� �����) "<<i+1<<" -�� ��-��"<<endl;
	    else 
	      cout <<"������� ������� ������� � ������������� ������: "<<endl;  
        for(j = 0; j < k; j++)
          {
		    cout<< "mas["<< i<< "][" <<j <<"]="; //���� ������� 
            cin>> mas[i][j];
          } 
     }

 //����� �������
cout<<endl;
cout<<endl<<"***********************************"<<endl;
cout<<" �������: "<<endl;
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
   
   //���������� ������������� �������
int kpol=0;
 for (j = 0; j < k; j++)
	{
		if (mas[n-1][j]>0)
			kpol++;	
		 }
// cout<<"kpol="<<kpol<<"\n";���� � ��������� ������� 4 ������������� �����,�� �� ����� �������
	cout<<"������� ������� ���������"<<mas[n-1][k-1]<<"\n";
 
		while (kpol<w)   
		{
			kpol=0;

  // ����� ������������
min = 0;
  for (j = 1; j < sv; j++)
    if (mas[n-1][j] < mas[n-1][min]) min = j; 
  cout << " ���� ������� ������� "<<mas[n-1][min] << endl;
double t;

t=mas[n-1][min];

// ����� �������
cout<<endl<<"***********************************"<<endl;
int myn=0;
double r=0,z=0; 
z=(mas[myn][k-1])/(mas[myn][min]);
  for (i= 1; i < st; i++)
	  {
		  r=  (mas[i][k-1])/(mas[i][min]);
      if (z>r) myn=i;
	 }
  cout << "��� ������ ������� "<<mas[myn][k-1]<< endl;
  cout<<"������"<<myn;
  cout<<endl<<"***********************************"<<"\n";
  cout <<"����������"<<mas[myn][min]<<endl;

//������� �� ��������� �������
double l=0;
l=mas[myn][min];//��� ������� �� �����������
for (j = 0; j < k; j++)
	{	  
		mas[myn][j]=mas[myn][j]/l; 
    }
cout<<endl;

 //����� �������
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


//�� �������� ��������������� ����� �������� �������� ��������� ��� ������
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


 //����� �������
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
//cout<<"������� ������� ���������"<<mas[n-1][k-1]<<"\n";
  for (j = 0; j < k; j++)
	{
		if (mas[n-1][j]>0)
			kpol++;	
 }	
  // cout<<"kpol="<<kpol<<"\n";���� � ��������� �������  ������������� ����� �������, ������� ���� x(+1 ����.����),�� �� ����� �������
  		}
		cout<<"������� ����������,������� ������� ���������"<<mas[n-1][k-1]<<"\n";		
 system ("pause");
 return 0;
}