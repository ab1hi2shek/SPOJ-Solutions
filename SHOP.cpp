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
#define MAXM 30

vector<string> arr;
ll dp[MAXM][MAXM];

ll rec(ll sx, ll sy, ll dx, ll dy, ll h, ll w, ll sum)
{
	cout<<sx<<" "<<sy<<" "<<dx<<" "<<dy<<endl;
	if(sx == dx && sy==dy)
		return (arr[dx][dy] - '0');
	if(sx<0 || sx >=h || sy <0 || sy >= w || arr[sx][sy] =='X')
		return INT_MAX;
	if(dp[sx][sy] != -1)
		return dp[sx][sy];

	ll p = (arr[sx][sy] - '0');
	// ll a = INT_MAX, b = INT_MAX, c = INT_MAX, d = INT_MAX;
	// if(arr[sx+1][sy] != 'X')
		ll a = p + rec(sx+1, sy, dx, dy, h, w, sum);
	//if(arr[sx-1][sy] != 'X')
		ll b = p + rec(sx-1, sy, dx, dy, h, w, sum);
	//if(arr[sx][sy+1] != 'X')
		ll c = p + rec(sx, sy+1, dx, dy, h, w, sum);
	//if(arr[sx][sy-1] != 'X')
		ll d = p + rec(sx, sy-1, dx, dy, h, w, sum);

	return dp[sx][sy] = min(a, min(b, min(c,d)));
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll w,h;

	while(1)
	{
		cin>>w>>h;

		if(w==0 && h==0)	
			break;

		memset(dp, -1, sizeof(dp));

		loop(i,0,h-1)
		{
			string s;
			cin>>s;
			arr.push_back(s);
		}

		ll sx,sy,dx,dy;
		loop(i,0,h-1)
		{
			loop(j,0,w-1)
			{
				if(arr[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
				else if(arr[i][j] == 'D')
				{
					dx = i;
					dy = j;
				}

			}
		}

		cout<<rec(sx, sy, dx, dy, h, w, 0);



	}
	return 0;
}