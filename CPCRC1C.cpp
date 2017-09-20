/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 19/09/2017
	Logic - DIgit DP
	Category - Medium
	Platform - SPOJ
*/	  

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

vector<ll> dA;
vector<ll> dB;
ll dp[10][100][2];

void getDigits(ll flag, ll n)
{
	while(n!=0)
	{
		if(flag==0)
			dA.push_back(n%10);
		else
			dB.push_back(n%10);
		n /= 10;
	}
}

ll digitDP(ll index, ll sum, ll tight, ll flag)
{
	if(index == -1)
		return sum;
	if(dp[index][sum][tight] != -1)
		return dp[index][sum][tight];

	ll p = !flag ? dA[index] : dB[index];
 	ll k = tight ? p : 9;

 	ll ret = 0;
	loop(i,0,k)
	{
		ll newTight = (p == i) ? tight : 0;
		ret += digitDP(index-1, sum+i, newTight, flag);
	}

	if(!tight)
		dp[index][sum][tight] = ret;
	return ret;
}

ll digitSum(ll a, ll b)
{
	memset(dp,-1,sizeof(dp));
	dA.clear();
	dB.clear();
	getDigits(0,a);
	getDigits(1,b);

	ll x = digitDP(dA.size()-1, 0, 1, 0);
	ll y = digitDP(dB.size()-1, 0, 1, 1);

	return y-x;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll a,b;

	while(1)
	{
		cin>>a>>b;

		if(a == -1 && b==-1)
			break;

		cout<<digitSum(a-1, b)<<endl;
	}
}