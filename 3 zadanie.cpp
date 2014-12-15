	
#include <iostream>
using namespace std;

  int main (void){
   const int n=5;
   int a[n];
   int i,k,m;
      for (i=0; i<n; i++)
      cin >> a[i];
      if (std::cin.fail())
	{
		std::cout << "Неккоректный ввод!" << std::endl;
		return 0;
	}
      k=a[0];
      a[0]=(a[0]+a[1])/2;
             for (i=1; i<n-1; i++)
        {
         m=k;
         k=a[i];
         a[i]=(m+2*a[i]+a[i+1])/4;
         }
         a[n-1]=(k+a[n-1])/2;
        for (i=0; i<n; i++)
       cout << a[i] << ' ';
       cout << endl;
return 0;
}
