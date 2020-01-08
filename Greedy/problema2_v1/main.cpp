#include<cstdio>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iostream>
using namespace std;

struct evenimente {
  int index;
  int durata;
  int t_limita;
};

vector <evenimente> v;

bool comparare(evenimente a, evenimente b) {
  if(a.t_limita <= b.t_limita)
    return true;

  return false;
}

int main() {

  ifstream f("date.in");

  int n;

  evenimente x;

  f>>n;
  for(int i = 0; i < n; i++) {
    f>>x.durata>>x.t_limita;
    x.index = i + 1;
    v.push_back(x);
  }

  sort(v.begin(), v.end(), comparare);

  int timp, intarziere_maxima;
  timp = intarziere_maxima = 0;

  for(int i = 0; i < n; i ++) {
    timp += v[i].durata;
   cout<<"activitatea "<< v[i].index<<" intervalul "<<(timp - v[i].durata)<<"  "<< timp<<" intarziere "<< timp - v[i].t_limita<<endl;
    if(timp - v[i].t_limita > intarziere_maxima)
      intarziere_maxima= timp - v[i].t_limita;
  }

  cout<<"Intarziere planificare  "<<intarziere_maxima;

  return 0;
}
