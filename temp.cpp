#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define myLoop(x) for(int i=0;i<x;i++)
#define rangeLoop(x,y) for(int i=x;i<y;i++)
#define myNestedLoop(x) for(int j=0;j<x;j++)
#define MOD 1000000009
#define speedUp ios::sync_with_stdio(false)
#define MAXLOG 14
#define MAX 1001


int root = 0;
vector<int> myGraph[MAX];
int N,M;
int parent[MAX];
int depth[MAX];
int sparse[MAXLOG][1001];

// int LCA(int u, int v) {
//  if(depth[u] < depth[v]) swap(u,v);
//  int diff = depth[u] - depth[v];
//  for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
//  if(u == v) return u;
//  for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
//      u = pa[i][u];
//      v = pa[i][v];
//  }
//  return pa[0][u];
// }

int lca(int u, int v){
    if(depth[u] < depth[v])
        swap(u,v);

    int diff = depth[u] - depth[v];
    myLoop(MAXLOG){
        cout<<"U is : "<<u<<endl;
        if( (diff>>i)&1)
            u = sparse[i][u];
    }

    if(u==v)
        return u;

    for(int i=MAXLOG-1;i>=0;i--){
        
        if(sparse[i][u] != sparse[i][v]){
            u = sparse[i][u];
            v = sparse[i][v];
        }
        cout<<"U is : "<<u<<" and V is "<<v<<endl;  
    }

    return sparse[0][u];
}

void getParent(int current, int par, int dep){
    parent[current] = par;
    sparse[0][current] = par;
    depth[current] = dep;

    myLoop(myGraph[current].size()){
        if(myGraph[current][i] != par){
            getParent(myGraph[current][i], current, dep+1);
        }
    }
}

int main(int argc, char const *argv[]){
    int left, right;

    if (argc == 1){
        cout<<"Exiting. Provide File name"<<endl;
        exit(0);
    }

    int h;
    string line;
    ifstream myFile(argv[1]);
    if (myFile.is_open())
    {
        myFile >> N;
        myFile >> M;
        for(int i=0;i<M;i++){
            myFile >> left;
            myFile >> right;
            myGraph[left-1].push_back(right-1);
            
        }
    }

    myLoop(MAXLOG){
        myNestedLoop(N){
            sparse[i][j] = -1;
        }
    }

    // Creating the Sparse Table
    // Getting Parents
    getParent(root, -1, 1);

    // Sparse Table Formation for LCA
    for(int i=1;i<MAXLOG;i++){
        for(int j=0;j<N;j++){
            if(sparse[i-1][j] != -1)
                sparse[i][j] = sparse[i-1][sparse[i-1][j]];
        }
    }

    myLoop(MAXLOG){
        myNestedLoop(N){
            cout<<sparse[i][j]<<" ";
        }
        cout<<endl;
    }

    int Q;
    cin>>Q;
    while(Q--){
        cin>>left>>right;
        cout<<"The LCA of "<<left<<" and "<<right<<" is: "<<lca(left-1, right-1)+1<<endl;
    }

}