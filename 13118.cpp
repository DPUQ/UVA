#include <bits/stdc++.h>
#define INF INT_MAX
#define rep(i,n) for(int i = 0; i<n ; i++)
#define gi first.first.first
#define gj first.first.second
#define mi first.second.first
#define mj first.second.second
#define mG first.first
#define mM first.second
#define time second

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> mov;
typedef pair <mov,int> state;

string mat[41];
bool vis[41][41][41][41];
int n,m,ie,je,ig,jg,im,jm,res;
int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};

bool canMove(ii p)
{
    return p.first >=0 && p.first <n && p.second >=0 && p.second <m && mat[p.first][p.second]!='#';
}

bool isVal(state enq)
{
  if(!vis[enq.gi][enq.gj][enq.mi][enq.mj]){
        vis[enq.gi][enq.gj][enq.mi][enq.mj] = true;
        return true;
  }
  return false;
}

bool isEnd(state aux)
{
    return aux.gi == ie && aux.gj == je && aux.mi == ie && aux.mj == je;
}

void bfs()
{
    int nig,njg,nim,njm;
    queue<state> q;
    q.push(state(mov(ii(ig,jg),ii(im,jm)),0));
    state aux;
    ii movG,movM;
    while(!q.empty())
    {
        aux = q.front();
        q.pop();
        vis[aux.gi][aux.gj][aux.mi][aux.mj] = true;
        if(isEnd(aux)) aux.time < res? res = aux.time : res = res;
        rep(k,4)
        {
            nig = aux.gi + di[k];
            njg = aux.gj + dj[k];
            nim = aux.mi + di[k];
            njm = aux.mj - dj[k];
            movG = ii(nig,njg);
            movM = ii(nim,njm);
            if(canMove(movG)||canMove(movM))
            {
                state enq;
                canMove(movG)?enq.mG = movG : enq.mG = aux.mG;
                canMove(movM)?enq.mM = movM : enq.mM = aux.mM;
                enq.time = aux.time+1;
                if(isVal(enq)) q.push(enq);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n >> m)
    {
        cin >> ie >> je >> ig >> jg >> im >> jm;
        ie--;
        je--;
        ig--;
        jg--;
        im--;
        jm--;
        rep(i,n)
        {
            cin >> mat[i];
        }
        memset(vis, 0, sizeof(vis));
        res = INF;
        bfs();
        if(res!=INF)
            cout << res <<"\n";
        else
            cout << "NO LOVE\n";
    }
    return 0;
}
