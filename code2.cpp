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
	ll n;
	cin>>n;

	ll arr[n];
	loop(i,0,n-1)
		cin>>arr[i];

	ll hash[n+1] = {0};
	loop(i,0,n-1)
		hash[arr[i]]++;

	vector<ll> v;
	loop(i,1,n)
	{
		if(hash[i] == 0)
			v.push_back(i);
	}
	sort(all(v));

	ll indx = 0;
	ll foca[n+1] = {0};
	vector<ll> ans;
	ll xoxp = 0;
	loop(i,0,n-1)
	{
		if(hash[arr[i]] == 1)
			ans.push_back(arr[i]);
		else
		{
			if(indx < v.size() && v[indx] < arr[i])
			{
				xoxp++;
				ans.push_back(v[indx++]);//<<" ";
				hash[arr[i]]--;
			}
			else
			{
				if(foca[arr[i]] == 0)
				{
					foca[arr[i]] = 1;
					ans.push_back(arr[i]);//<<" ";
				}
				else
				{
					xoxp++;
					ans.push_back(v[indx++]);//<<" ";
				}
			}
		}
	}

	cout<<xoxp<<endl;
	loop(i,0,ans.size()-1)
		cout<<ans[i]<<" ";
	nline;
	return 0;
}