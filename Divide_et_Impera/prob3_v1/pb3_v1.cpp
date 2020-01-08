#include <iostream>
#include<fstream>

using namespace std;

int maxim(int a, int b)
{

    if(a > b)

        return a;

    else

        return b;
}

double det_mediana(int a[100],int n,int b[100],int m)
{

    int min_index=0, max_index=n, i, j;

    while(min_index < max_index)
    {
         i = (max_index - min_index)/2; //nr de elemente introduse in prima jumatate a lui a
         j = (n + m + 1)/2 - i; //nr de elemente introduse in prima jumatate a lui b

        if( i < n && j > 0 && b[j - 1] > a[i])

            min_index = i + 1;

        else

        if ( i > 0 && j < m && b[j] < a[i - 1])

            max_index = i - 1;



        else
        {

            if( i == 0 )
            return b[j - 1];

            else

            if( j == 0 )
            return a[i - 1];

            else

            return maxim( a[i - 1], b[j - 1] );

        }
    }
        return 0;

}

    ifstream f("date.in");


int main()
{
        int a[100],b[100],n,m;
        f >> n;
        for( int i = 0; i < n; i++ )
        f >> a[i];
        f >> m;
        for( int i = 0; i < m; i++ )
        f >> b[i];

        if(n < m)

        {
            cout<<"Mediana este "<<det_mediana(a,n,b,m);
        }
        else
        {
            cout<<"Mediana este "<<det_mediana(b,m,a,n);
        }

}


