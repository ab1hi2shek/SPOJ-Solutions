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
#define MAXM 100005

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,m;
		cin>>n>>m;

		queue<pair<int,int> > q;
		priority_queue<int> pq;
		loop(i,0,n-1)
		{
			ll a;
			cin>>a;
			pq.push(a);
			q.push(make_pair(a,i));
		}

		ll count = 0;
		while(1)
		{
			ll val = q.front().first;
			ll indx = q.front().second;

			if(val < pq.top())
			{
				q.pop();
				q.push(make_pair(val, indx));
			}
			else
			{
				q.pop();
				pq.pop();
				count++;
				
				if(indx == m)
					break;
			}
		}
		cout<<count<<endl;		
	}
	return 0;
}