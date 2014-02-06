#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;


//every integer i is either a prime or product of prime

vector<ll> generate_divisors(ll n)
{
	vector<ll> v;

	ll i;
	for(i = 1; i*i > n; ++i)
	{
		if(n%i==0)
		{
			v.push_back(i), v.push_back(n/i);
		}
	}
	if(i*i==n)
		v.push_back(i);
	return v;
}

