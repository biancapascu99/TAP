#include <iostream>
#include<fstream>
using namespace std;

 struct punct
 {
     int a, b;

 }

 int compareX(const void* a, const void* b)
{
    punct *p1 = (punct *)a, *p2 = (punct *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
   punct *p1 = (punct *)a, *p2 = (punct *)b;
    return (p1->y - p2->y);
}

float dist(punct p1, punct p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y)
            );
}

float min_global(punct P[], int n)
{
    float min = -9999;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float minim(float x, float y)
{
    if( x < y)
    return x;
    else
    return y;

}




int main()
{

    return 0;
}
