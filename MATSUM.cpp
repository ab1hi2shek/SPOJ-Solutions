/*
	CODE BY - ABHISHEK KUMAR
			  NIT DURGAPUR
*/

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long
#define ull unsigned long long
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
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
#define M0D 1000000007
#define MAXM 1055

ll arr[MAXM][MAXM];
ll fenwick[MAXM][MAXM];

void update(ll x, ll y, ll val, ll n)
{
	while( x <= n)
	{
		ll temp = y;
		while(temp <= n)
		{
			fenwick[x][temp] += val;
			temp += (temp & -temp);
		}
		x += (x & -x);
	}
}

ll sum(ll x, ll y)
{
	ll sum = 0;
	while(x > 0)
	{
		ll temp = y;
		while(temp > 0)
		{
			sum += fenwick[x][temp];
			temp -= (temp & -temp);
		}
		x -= (x & -x);
	}
	return sum;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		memset(arr, 0, sizeof(arr));
		memset(fenwick, 0, sizeof(fenwick));
		ll n;
		cin>>n;

		while(1)
		{
			string s;
			cin>> s;

			if(s[0] == 'E')
				break;
			else if(s[0] == 'S' && s[1] == 'E')
			{
				ll x,y,num;
				cin>>x>>y>>num;
				x++;
				y++;
				update(x, y, -arr[x][y] + num, n);
				arr[x][y] = num;
			}
			else
			{
				ll x1,y1,x2,y2;
				cin>>x1>>y1>>x2>>y2;
				ll ans = 0;
				ans += sum(x2+1, y2+1);
				ans += sum(x1, y1);
				ans -= sum(x1, y2+1);
				ans -= sum(x2+1, y1);
				cout<<ans<<endl;
			}
		}
		nline;		
	}
	return 0;
}