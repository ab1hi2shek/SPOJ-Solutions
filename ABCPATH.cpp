#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
#define sz(a) (a).size()
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
 
//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define nline cout<<endl
#define MAXM 51

vector<string> arr;
bool visited[MAXM][MAXM];
int ans = 0;
int X[8] = {-1,-1,-1,0,0,1,1,1};
int Y[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int i, int j, int m, int n, int count)
{
	visited[i][j] = true;
	count++;
	ans = max(ans,count);

	for(int k=0;k<8;k++)
	{
		int p = i + X[k];
		int q = j + Y[k];

		if(p>=0 && q>=0 && p<m && q<n && visited[p][q] == false && arr[p][q] == arr[i][j]+1)
			dfs(p,q,m,n,count);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int p = 1;
	while(1)
	{
		int m,n;
		cin>>m>>n;

		memset(visited, false, sizeof(visited));
		arr.clear();
		ans = 0;

		if(m==0 && n==0)
			break;

		loop(i,0,m-1)
		{
			string s;
			cin>>s;
			arr.push_back(s);
		}

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j] == 'A' && visited[i][j] == false)
					dfs(i,j,m,n,0);
			}
		}
		cout<<"Case "<<p++<<": "<<ans<<endl;
	}
}
