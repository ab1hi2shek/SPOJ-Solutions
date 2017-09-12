/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -	12/09/2017
	Logic -	AdHoc ... Kamenetsky's formula ... http://www.geeksforgeeks.org/count-digits-factorial-set-2/
	Category - Easy 
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
 
int main()
{
	int t;
    scanf("%d",&t);
    long long int a;
    while(t--)
    {
        scanf("%lld",&a);
        if(a==0||a==1||a==2) printf("1\n");
        else printf("%lld\n",(long long int)floor((log(2*acos(-1)*a)/2+a*(log(a)-1))/log(10))+1);
    }
    return 0;
}