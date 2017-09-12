#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
 
int main()
{
//	std::ios::sync_with_stdio(false);
	
	while(1)
	{
		ll n;
		scanf("%d", &n);

		if(n==0)
			break;

		ll count = 0;
		ll k = 1;
		while(n-k>0)
		{
			n = n - k;
			k = k*2;
			count++;
		}

		printf("%d\n", count);
	}
	return 0;
}