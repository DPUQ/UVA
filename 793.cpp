#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i<n; i++)

using namespace std;
typedef vector<int> vi;

class DisjointSet
{

private :
    vi parent,ran;


public :
    DisjointSet(int n){
        ran.assign(n,0);
        parent.resize(n);
        rep(i,n) parent[i] = i;
    }

    int findSet(int i) { return (parent[i] == i) ? i : (parent[i] = findSet(parent[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j){

        if(!isSameSet(i,j)){
            int x = findSet(i), y = findSet(j);

            if(ran[x]>ran[y]) parent[y] = x;

            else{
                parent[x] = y;
                if(ran[x] == ran[y]) ran[y]++;
            }

        }

    }

};

int main()
{
    int n,a,b,cases,suc,unsuc;
    string line;
    char c;

    scanf("%d",&cases);
    while(cases--)
    {

        scanf("\n%d\n",&n);

        DisjointSet ds(n+1);
        suc = 0,unsuc = 0;

        while(true)
        {
            if(!getline(cin,line) || line.empty()) break;
            sscanf(line.c_str(),"%c %d %d",&c,&a,&b);
            if(c == 'c') ds.unionSet(a,b);
            if(c == 'q') ds.isSameSet(a,b)?suc++ : unsuc++;

        }

        printf("%d,%d\n",suc,unsuc);
        if(cases>0) printf("\n");
    }

    return 0;
}

