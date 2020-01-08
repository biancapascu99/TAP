#include <iostream>
using namespace std;

int _mergeSort(int arr[],int temp[],int left,int right);
int merge(int arr[],int temp[],int left,int mid,int right);

//functie ce sorteaza vectorul de intrare si returneaza
//nr de inversiuni din el
int mergeSort(int arr[],int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

//functie recursiva care sorteaza vectorul de intrare si returneaza
//nr de inversiuni din el
int _mergeSort(int arr[],int temp[],int left,int right)
{
    int mid,nr_inv = 0;
    if(right > left)
    {
        //impartim tabloul in doua
        mid=(right + left)/2;
        // numarul inversiunilor va fi suma inversiunilor din partea stanga,
        // din partea dreapta si din contopirea lor
        nr_inv = _mergeSort(arr, temp, left, mid);
        nr_inv += _mergeSort(arr, temp, mid + 1, right);
        //nr de inversiuni din contopire
        nr_inv += merge(arr, temp, left, mid + 1, right);

    }
    return nr_inv;
}

//functie care contopeste cele doua jumatati sortate si
//returneaza nr de inversiuni

int merge(int arr[],int temp[],int left,int mid,int right)
{

    int i, j, k;
    int nr_inv = 0;

    i=left; //i indicele pt prima jumatate
    j=mid; //j indicele pt a doua jumatate
    k=left; //k indicele pentru imbinare
    //cautam inversiunile semnificative din contopire

    while((i <= mid-1) && (j <= right))
    {
        if(arr[i] > 2*arr[j])
        {
            //peste cate elemente se trece cu nr
            nr_inv += (mid - i);
            j++;
        }
        else
        {
            i++;
        }

    }


    i = left;
    j = mid;
    k = left;

    // a doua parcurgere pentru unificarea tabloului

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    // copiem elementele din stanga
    // daca exista
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    // copiem elementele din dreapta
    // daca exista
    while (j <= right)
        temp[k++] = arr[j++];
    //copiem elementele combinate in tabloul original
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return nr_inv;

}

int main ()
{
    //int arr [] = {4, 8, 11, 3, 5};
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = 5;

    cout << mergeSort (arr, n);

    return 0;
}
