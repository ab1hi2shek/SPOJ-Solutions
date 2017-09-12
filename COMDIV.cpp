#include <bits/stdc++.h>
using namespace std;

#define ll int

ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}
 
int main()
{
	ll t;
	scanf("%d", &t);

	while(t--)
	{
		ll A,B;
		scanf("%d%d", &A, &B);

		ll val = gcd(A,B);
		ll count = 0;


		for(ll i= 1; i*i<=val; i++)
		{
			if(val%i==0){
				count += 2;
				if(i == val/i)
					count--;
			}
		}
		printf("%d\n", count);
	}
}