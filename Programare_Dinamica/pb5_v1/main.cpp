#include <algorithm>
#include <cstdio>
#include<iostream>
using namespace std;

const int NMAX = 1000;
struct eveniment {

  int inceput, sfarsit, profit;
};

eveniment v[NMAX];
int precedent[NMAX], dp[NMAX];
int n;

bool cmp(eveniment a, eveniment b) {
  return a.sfarsit < b.sfarsit;
}

int main() {

  freopen("date.in", "r", stdin);


  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d %d %d", &v[i].inceput, &v[i].sfarsit, &v[i].profit);

  sort(v + 1, v + n + 1, cmp);

  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
      if (v[j].sfarsit < v[i].inceput)
      {
        precedent[i] = j;
      // cout<<i<<" "<<precedent[i]<<" \n";
      }

  for (int i = 1; i <= n; i++) {
      //determin profitul maxim pe spactacole
    dp[i] = max (dp[i-1], dp[precedent[i]] + v[i].profit);
   cout<<dp[precedent[i]]<<" \n";
  }

  printf("%d\n", dp[n]);
  int pozitie = n;
  while (pozitie != 0) {
    if (dp[pozitie] == dp[pozitie-1])
    //se poate sa am acelasi profit pe mai multe pozitii. Le afisam doar pe cele diferite
      pozitie--;
    else {
      printf("%d %d\n", v[pozitie].inceput, v[pozitie].sfarsit);
      pozitie = precedent[pozitie];
    }
  }

  return 0;
}
