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


/* one of the most beautiful q I have solved on spoj.
Basically concept is to divide the entire given string in length of 2. Like "ABACDA" = AB|CA|DA
now 2nd row must contain the remaing colors so solution can be like ----              -CD|DB|BC
But in "CDDBBC", there are continuous B, so we flip the last cell  ---------------    -CD|DB|CB     <----- solution
*/

ll arr[4];

int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	cin>>n;

	string s;
	cin>>s;

	string ans = "";

	for(ll i=0; i<2*n; i+=2)
	{
		ll color1 = -1, color2 = -1;
		loop(j,0,3)
			arr[j] = 1;

		//this line is marking 0 in the array whose color is present in the current block of the give string
		arr[s[i] - 'A'] = 0;
		arr[s[i+1] - 'A'] = 0;
		//now array contains the color which are not present and that's index is marked by 1.
		
		loop(j,0,3)
		{
			if(arr[j] == 1)
			{
				if(color1 == -1)	
					color1 = j;
				else 	
					color2 = j;
			}
		}
		//after this step color1 and color2 contains the colors that are not present, basically we extracted it from arr[].

		ans += (color1 + 'A');
		ans += (color2 + 'A');
		//now we added the colors to the output string.

		if(i-1 >= 0 && ans[i] == ans[i-1])
			swap(ans[i], ans[i+1]);
		//this last step is imposrtant. If the last character of the previous block is same as the first character of the
		//current block then we need to swap the characters of the current block. Like if prev block is "AB" and current 
		//is "BD", then we swap "BD" to "DB". This is done because "ABBD" is not valid while "ABDB" is valid. 
	}
	cout<<ans<<endl;
	return 0;
}