#include<iostream>
#include<cstdlib>
using namespace std;

int heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho <= n) {
          for(int i=0;i<7;i++)
              cout <<a[i]<<" ";
          system("pause");
          system("cls");
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

int main()
{
	int a[]={1,3,6,4,2,9,8};
	cout<<"Vetor 1: ";
	for(int i=0;i<7;i++)
		cout <<a[i]<<" ";
	cout<<endl;
	heapsort(a,7);
	cout<<"Vetor 2: ";
	for(int i=0;i<7;i++)
		cout <<a[i]<<" ";
}
