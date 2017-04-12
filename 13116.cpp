#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i<n ; i++)
#define INF 1000001
#define gi first.first
#define gj first.second
#define floor second.first
#define time second.second

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> pos;

int n,m,h,res;
char mat[101][101][101];
bool vis[101][101][101];
pos st,en;
int di[] = {0,0,-1,1,0,0};
int dj[] = {-1,1,0,0,0,0};
int dk[] = {0,0,0,0,-1,1};

bool validar(pos enq, bool k){
    if(enq.gi>=0 && enq.gi<n && enq.gj>=0 && enq.gj<m && enq.floor>=0 && enq.floor<h){

        if(k && !vis[enq.floor][enq.gi][enq.gj] && mat[enq.floor][enq.gi][enq.gj]=='-')
            return vis[enq.floor][enq.gi][enq.gj] = true;

        else if(!vis[enq.floor][enq.gi][enq.gj] && mat[enq.floor][enq.gi][enq.gj]!='#')
            return vis[enq.floor][enq.gi][enq.gj] = true;
    }

    return false;
}

bool isEnd(pos aux){
    return aux.floor == en.floor && aux.gi == en.gi && aux.gj == en.gj;
}

void bfs(){
    queue<pos> q;
    vis[st.floor][st.gi][st.gj]=true;
    q.push(st);
    pos aux,enq;
    int ni,nj,nk,ci,cj,ck,ct;
    while(!q.empty()){
        aux = q.front(); q.pop();
        if(isEnd(aux)) {res=min(res,aux.time); /*cout << "reach end with time " << aux.time <<"\n";*/}
        ci = aux.gi; cj = aux.gj; ck = aux.floor; ct = aux.time;
        rep(i,6){
            if(i>=4 && mat[ck][ci][cj]!='-')break;
            ni = ci + di[i];
            nj = cj + dj[i];
            nk = ck + dk[i];
            enq = pos(ii(ni,nj),ii(nk,ct+1));
            if(validar(enq,i>3)) {q.push(enq); /*cout << "enqueued " << ni <<" " << nj <<" "<<nk<< "with time " << ct+1<<"\n"; */}
        }
    }

}


int main()
{
    while(1)
    {
        cin >> n >> m >> h;

        if(n == m && m == h && h == 0) break;

        rep(k,h)
            rep(i,n)
                rep(j,m){
                    cin >> mat[k][i][j];
                    if(mat[k][i][j]=='S') st = pos(ii(i,j),ii(k,0));
                    if(mat[k][i][j] == 'E') en = pos(ii(i,j),ii(k,INF));
                }

        memset(vis,0,sizeof vis);
        res = INF;
        bfs();
        if(res!=INF) cout << res << "\n";
        else cout << "-1\n";
    }

    return 0;
}
