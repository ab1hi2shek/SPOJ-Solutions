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
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll a,b;
		cin>>a>>b;

		ll arr[a];
		loop(i,0,a-1)	
			cin>>arr[i];

		ll i=0,j=0;
		ll sum = arr[0];
		ll maxSum = arr[0];
		ll maxIndex = 1, start = 0, end = 0;
		while( j < a)
		{
			//cout<<i<<" "<<j<<endl;
			if(j+1<a && sum+arr[j+1]<=b)
			{
				j++;
				sum += arr[j];
			}
			else
			{
				if(i==j)
				{
					sum -= arr[i];
					while(j+1 < a && arr[j+1] > b)
					{
						i++;
						j++;
					}
					i++;
					j++;
					//cout<<" ting tong "<<i<<" "<<j<<endl;
					if(j>=a)
						break;
					sum += arr[i];
				}
				else
				{
					sum -= arr[i];
					i++;
				}
			}

			if(j-i+1 > maxIndex || (j-i+1 == maxIndex && sum < maxSum))
			{
				maxIndex = j-i+1;
				maxSum = sum;
				start = i;
				end = j;
			}
		}
		//cout<<start<<" "<<end<<endl;
		// sum = 0;
		// for(ll k=start;k<=end;k++)
		// 	sum += arr[k];
		if(maxSum > b)
		{
			maxSum = 0;
			maxIndex = 0;
		}
		cout<<maxSum<<" "<<maxIndex<<endl;

	}
}