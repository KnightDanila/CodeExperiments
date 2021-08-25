/*
#include <iostream>

int main()
{
	std::cout<<""<<std::endl;	// НО ЕСЛИ не подключать <iostream> мы не можем получить доступ к std:: - то есть std находится внутри файла <iostream>
	return 0;
}

*/
/*
#include <iostream>

using namespace std;
namespace secret_data
{
	int a;
}

class classTemp
{
private: int data;
public : int betta;

}


int main()
{
	int a;
	secret_data::a;

	return 0;
}
*/
#include <iostream>
#include <math.h>

double Determinant(double **a,int n)
{
   int i,j,j1,j2;
   double det = 0;
   double **m = NULL;

   if (n < 1) { /* Error */

   } else if (n == 1) { /* Shouldn't get used */
      det = a[0][0];
   } else if (n == 2) {
      det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
   } else {
      det = 0;
      for (j1=0;j1<n;j1++) {
         m = (double**)malloc((n-1)*sizeof(double *));
         for (i=0;i<n-1;i++)
            m[i] = (double*)malloc((n-1)*sizeof(double));
         for (i=1;i<n;i++) {
            j2 = 0;
            for (j=0;j<n;j++) {
               if (j != j1){
                  //continue;
					m[i-1][j2] = a[i][j];
					j2++;
			   }
            }
         }
         det += pow(-1.0,1.0+j1+1.0) * a[0][j1] * Determinant(m,n-1);
         for (i=0;i<n-1;i++)
            free(m[i]);
         free(m);
      }
   }
   return(det);
}

int main()
{
	double **a = new double*[3];
	a[0] = new double[3];
	a[1] = new double[3];
	a[2] = new double[3];
	a[0][0] = 3;
	a[0][1] = 2;
	a[0][2] = -1;

	a[1][0] = 2;
	a[1][1] = -2;
	a[1][2] = 4;

	a[2][0] = -1;
	a[2][1] = 0.5;
	a[2][2] = -1;
	std::cout<<Determinant(a,3);

	return 0;
}
