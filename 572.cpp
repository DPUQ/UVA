#include <bits/stdc++.h>
#define MAX 101

using namespace std;

typedef pair<int,int> ii;

char mat[MAX][MAX];
int n,m;

bool validar(ii p){

return p.first >=0 && p.first<n && p.second >=0 && p.second <m && mat[p.first][p.second]!='X' && mat[p.first][p.second]=='@';

}

ii le(ii p){
ii ret;
ret.first = p.first;
ret.second = p.second - 1;
return ret;
}

ii ri(ii p){
ii ret;
ret.first = p.first;
ret.second = p.second + 1;
return ret;
}

ii up(ii p){
ii ret;
ret.first = p.first-1;
ret.second = p.second ;
return ret;
}

ii dow(ii p){
ii ret;
ret.first = p.first+1;
ret.second = p.second;
return ret;
}

ii d1(ii p){
ii ret;
ret.first = p.first-1;
ret.second = p.second - 1;
return ret;
}

ii d2(ii p){
ii ret;
ret.first = p.first -1;
ret.second = p.second + 1;
return ret;
}

ii d3(ii p){
ii ret;
ret.first = p.first+1;
ret.second = p.second - 1;
return ret;
}

ii d4(ii p){
ii ret;
ret.first = p.first+1;
ret.second = p.second + 1;
return ret;
}

void floodfill(ii p){

    queue<ii> cola;
    cola.push(p);
    ii encolar,aux;
    while(!cola.empty()){
        aux = cola.front();
        mat[aux.first][aux.second] = 'X';
        cola.pop();
        encolar = le(aux);
        if(validar(encolar)){
            cola.push(encolar);
        }
        encolar = ri(aux);
        if(validar(encolar)){
            cola.push(encolar);
        }
        encolar = up(aux);
        if(validar(encolar)){
            cola.push(encolar);
        }
        encolar = dow(aux);
        if(validar(encolar)){
            cola.push(encolar);
        }
        encolar = d4(aux);
        if(validar(encolar)){
            cola.push(encolar);
        }
        encolar = d1(aux);
        if(validar(encolar)){
            cola.push(encolar);
        }
        encolar = d2(aux);
        if(validar(encolar)){
            cola.push(encolar);
        }
        encolar = d3(aux);
        if(validar(encolar)){
            cola.push(encolar);
        }
    }

}

int main(){

int k;
char c;

while (true){

    scanf("%d %d",&n,&m);
    if(n == 0)
        break;

    k=0;
    scanf("%c",&c);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%c",&mat[i][j]);
        }
        scanf("%c",&c);
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j]=='@'){
                k++;
                floodfill(ii(i,j));
            }
        }
    }

    printf("%d\n",k);
}

return 0;
}
