#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long
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
#define MAXM 1005

vector<string> arr;
bool visited[MAXM][MAXM];
ll temp;
ll xindex,yindex;
ll X[4] = {-1,0,1,0};
ll Y[4] = {0,1,0,-1}; 

void dfs(ll i, ll j, ll r, ll c, ll count)
{
	visited[i][j] = true;
	count++;
	if(count>temp)
	{
		temp = count;
		xindex = i;
		yindex = j;
	}
	//if(count>temp2 && !visited[i]) 

	for(ll k=0;k<4;k++)
	{
		ll p = i + X[k];
		ll q = j + Y[k];

		if(p >=0 && q >=0 && p<r && q<c && visited[p][q] == false && arr[p][q] == '.')
			dfs(p,q,r,c,count);
	}
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		memset(visited, false, sizeof(visited));
		temp = 0;
		arr.clear();
		ll c,r;
		cin>>c>>r;

		loop(i,0,r-1)
		{
			string s;
			cin>>s;
			arr.push_back(s);
		}

		ll ans = 0;
		loop(i,0,r-1)
		{
			loop(j,0,c-1)
			{
				if(arr[i][j] == '.' && !visited[i][j])
				{
					dfs(i,j,r,c,0);
					temp = 0;
					memset(visited, false, sizeof(visited));
					dfs(xindex,yindex,r,c,0);
					ans = max(ans, temp);
				}
			}
		}
		if(ans!=0)
			ans--;
		cout<<"Maximum rope length is "<<ans<<"."<<endl;
	}
}