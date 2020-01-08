//
//  main.cpp
//  Problema 2(v3)
//
//  Created by John Giumanca on 11/01/2018.
//  Copyright © 2018 John Giumanca. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <list>
using namespace std;
ifstream f ("data.in");
ofstream g("data.out");



int main(){
    int n,v1,v2,parent[100],depth[100],max_depth=0,card = 0;;
    bool non_adjacent[100];
    list<int> tree_level[100];
    
    f>>n;
    f>>v1>>v2;
    parent[v2]=v1;
    depth[v2]=2;
    non_adjacent[v2] = true;
    parent[v1]=0;
    depth[v1]=1;
    non_adjacent[v1] = false;
    
    while(f>>v1 && f>>v2){
        parent[v2]=v1;
        non_adjacent[v2]=true;
        non_adjacent[v1]=false;
        depth[v2]=depth[v1]+1;
        if(depth[v2] > max_depth)
            max_depth = depth[v2];
    }
    
    for (int i=1; i<=n; i++) {
        tree_level[depth[i]].push_back(i);
    }
    
    for (int i = max_depth; i>=1; i--) {
        for(list<int>::iterator j = tree_level[i].begin(); j!=tree_level[i].end();j++){
            if(non_adjacent[*j]){
                card++;
                g<<*j<<' ';
                if(parent[*j]!=0)
                    non_adjacent[parent[*j]]=false;
                if(parent[parent[*j]]!=0)
                    non_adjacent[parent[parent[*j]]] = true;
            }
        }
    }
    g<<endl<<card;
    
    
}

