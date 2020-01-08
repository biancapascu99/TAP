#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct Point
{
	int x, y;
};
//comparare dupa X
int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}
//comparare dupa Y
int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}
//distnta dintre 2 pct
float dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
				(p1.y - p2.y)*(p1.y - p2.y)
			);
}

//distanta minima dintr-un vector
float min_vector(Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

//min dintre 2 valori
float min(float x, float y)
{
	return (x < y)? x : y;
}

//functie pt determinarea distantei minime dintr-o sectiune de dimeniune dx2d
float min_sectiune(Point sectiune[], int size, float d)
{
	float min = d;
    //calculam distanta intre toate punctele cu diferenta dintre coord y mai mici decat d
    //este O(n) pt ca se va executa de cel mult 6 ori
	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (sectiune[j].y - sectiune[i].y) < min; ++j)
			if (dist(sectiune[i],sectiune[j]) < min)
				min = dist(sectiune[i], sectiune[j]);

	return min;
}

//functie recursiva ce returneaza distanta minima
//Px vectorul sortat dupa x
//Py vectorul sortat dupa y

float divide(Point Px[], Point Py[], int n)
{
    //daca am 2 sau 3 elemente returnez distanta minima dintre ele
	if (n <= 3)
		return min_vector(Px, n);

    //gasim pct din mijloc(dreapta L)
	int mid = n/2;
	Point midPoint = Px[mid];
    //impartim pct in jurul dreptei L
    //vector pt stanga lui L
	Point Pyl[mid+1];
	//vector pt dreapta lui L
	Point Pyr[n-mid-1];
	int li = 0, ri = 0; //indici de parcurgere

    //populam cu valori Pls si Pld
    //imaprtim pct  sortate dupa y, prin compararea lor cu x-ul pct din mijlocul
    //sortarii dupa coordonata x(dreapta L)
    //O(nlogn) pentru ca inainte de toate fac sortarea asta

	for (int i = 0; i < n; i++)
	{
	if (Py[i].x <= midPoint.x)
		Pyl[li++] = Py[i];
	else
		Pyr[ri++] = Py[i];
	}

    //calculam dl(dist min din stanga) si dr(dist minima din dreapta)
	float dl = divide(Px, Pyl, mid);
	float dr = divide(Px + mid, Pyr, n-mid);
    //gasim mijlocul
	float d = min(dl, dr);

    //verificam daca exista o distanta mai mica la distanta d de dreapta L
	Point sectiune[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(Py[i].x - midPoint.x) < d)
			sectiune [j] = Py[i], j++;

    //returnam distanta minima din vector
	return min(d, min_sectiune(sectiune, j, d) );
}

float closest(Point P[], int n)
{
	Point Px[n];
	Point Py[n];
	for (int i = 0; i < n; i++)
	{
		Px[i] = P[i];
		Py[i] = P[i];
	}

	qsort(Px, n, sizeof(Point), compareX);
	qsort(Py, n, sizeof(Point), compareY);

	return divide(Px, Py, n);
}

// Driver program to test above functions
int main()
{
	Point P[] = {{0, 1}, {10, 2}, {40, 50}, {5, 1}, {6, 10}, {3, 4}};
	int n = sizeof(P) / sizeof(P[0]);
	cout << "Distanta minima este " << closest(P, n)<<endl;
	Point Px[n];
	for (int i = 0; i < n; i++)
	{
		Px[i] = P[i];
	}

	qsort(Px, n, sizeof(Point), compareX);
	for(int i=0;i<n;i++)
	cout<<Px[i].x<<" "<<Px[i].y<<endl;
	return 0;
}
