/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -
	Logic -
	Category - 
	Platform
*/	  

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long int
 
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
#define MAXN 100005
#define abc 1000
#define INF 1000000007

int arr[MAXN];
int decomp[abc];
int block_size;

void preprocess(int n)
{
	int block_index = -1;
	block_size = sqrt(n);

	memset(decomp, INF, sizeof(decomp));
	loop(i,0,n-1)
	{
		if(i % block_size == 0)
			block_index++;
		//cout<<block_index<<" "<<decomp[block_index]<< endl;
 		decomp[block_index] = min(decomp[block_index], arr[i]);
	}
}

int query(int l, int r)
{
	int ans = INT_MAX;
	//cout<<" initial l = "<<l<<endl;
	while(l <= r && l%block_size != 0)
		ans = min(ans, arr[l++]);
	//cout<<" stage 1 - -  l = "<<l<<endl;
	while(l + block_size <= r)
	{
		ans = min(ans, decomp[l/block_size]);
		l += block_size;
	}
	//cout<<" stage 2 ---  l = "<<l<<endl;
	while(l<=r)
		ans = min(ans, arr[l++]);
	//cout<<" stage 3 ---- l = "<<l<<endl;
	return ans;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	cin>>n;

	loop(i,0,n-1)
		cin>>arr[i];
	preprocess(n);

	int q;
	cin>>q;

	while(q--)
	{
		ll a,b;
		cin>>a>>b;

		cout<<query(a,b)<<endl;
	}
	return 0;
}