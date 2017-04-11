#include<bits/stdc++.h>
#define pb push_back
#define cl clear()
#define sz size()
#define rep(i,n) for(int i = 0; i<n ; i++)
#define INF 200000000

using namespace std;
typedef long long ll;
typedef pair<int,ll> Node;
typedef vector<Node> vn;
typedef vector<int> vi;
typedef vector<vn> li;
typedef vector<ll> vll;
typedef vector<bool> vb;

vll dist;
li adj(1001);
vb marked;

class cmp{
public:
  bool operator()(Node n1,Node n2){
    if(n1.second>n2.second)
      return true;
    else
      return false;
  }
};

class cmp2{
public:
  bool operator()(Node n1,Node n2){
    if(n1.second<n2.second)
      return true;
    else
      return false;
  }
};

void dijkstra(int s){
    priority_queue< Node , vector<Node> , cmp > pq;
    pq.push(Node(s, 0));
    dist[s] = 0;
    int actual, j, adjacent;
    long long weight;

    while( !pq.empty() ){

      actual = pq.top().first;
      pq.pop();

      if( marked[actual] == 0 ){
        marked[actual] = 1;
        for( j = 0; j < adj[actual].size(); j++ ){
          adjacent = adj[actual][j].first;
          weight = adj[actual][j].second;
          if( marked[adjacent] == 0 ){
            if( dist[adjacent] > dist[actual] + weight ){
              dist[adjacent] = dist[actual] + weight;
              pq.push(Node( adjacent, dist[adjacent] ));
            }
          }
        }
      }
    }

}

void clearList(int n){
    rep(i,n) adj[i].clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vi banks, stations,sol;
    int n,m,b,p,s,t,w,cb,cp,num;
    while(cin >> n >> m >> b >> p){
        priority_queue<Node,deque<Node>,cmp2 > pq;
        while(m--){
            cin >> s >> t >> w;
            adj[s].pb(Node(t,w));
            adj[t].pb(Node(s,w));
        }
        dist.assign(n+1,INF);

        banks.cl;
        while(b--){
            cin >> cb;
            banks.pb(cb);
        }

        stations.cl;
        while(p--){
            cin >> cp;
            stations.pb(cp);
        }

        rep(i,stations.sz){
            marked = vb(n+1,0);
            dijkstra(stations[i]);
        }

        rep(i,banks.sz)
            pq.push(Node(banks[i],dist[banks[i]]));

        num = 0; sol.cl;
        do{
            num++;
            sol.pb(pq.top().first); w = pq.top().second; pq.pop();

        }while(pq.top().second == w && !pq.empty());

        sort(sol.begin(),sol.end());

        cout << sol.sz << " ";

        if(w!=INF) cout << w; else cout << "*";

        cout << "\n";

        rep(i,sol.sz){
            cout << sol[i];
            i == sol.sz-1? cout << "\n" : cout << " ";
        }

        clearList(n);
    }
    return 0;
}
