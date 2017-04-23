#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i<n; i++)

using namespace std;
typedef vector<int> vi;

class DisjointSet
{

private :
    vi parent,ran,sizeSet;
    int sets;


public :
    DisjointSet(int n){
        sets = n;
        ran.assign(n,0);
        sizeSet.assign(n,1);
        parent.resize(n);
        rep(i,n) parent[i] = i;
    }

    int findSet(int i) { return (parent[i] == i) ? i : (parent[i] = findSet(parent[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j){

        if(!isSameSet(i,j)){
            int x = findSet(i), y = findSet(j);

            if(ran[x]>ran[y]) { parent[y] = x , sizeSet[x]+=sizeSet[y]; }

            else{
                parent[x] = y , sizeSet[y]+=sizeSet[x];
                if(ran[x] == ran[y]) ran[y]++;
            }

            sets--;
        }

    }

    int numSets(){ return sets; }
    int sizeOfSet(int i){ return sizeSet[findSet(i)]; }

};

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b,k;
    while(true)
    {
        cin >> n >> m;
        if(n == m && m == 0) break;

        DisjointSet ds(n);

        while(m--)
        {
            cin >> k >> a;
            a = ds.findSet(a);
            while(k>1){
                cin >> b;
                ds.unionSet(a,b);
                k--;
            }
        }

        cout << ds.sizeOfSet(0) << "\n";
    }
    return 0;
}

