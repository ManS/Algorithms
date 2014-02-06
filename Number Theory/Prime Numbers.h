#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;

bool isPrime1(ll n)
{
	if(n==2) return true;
	if(n < 2) return false;

	for(int i = 2; i < n; i++)
		if(n%i==0)
			return false;
	return true;
}

bool isPrime2(ll n)
{
	if(n==2) return true;
	if(n<2) return false;

	for(ll i=3; i < n ; i+=2)
		if(n%i == 0 || n%2==0)
			return false;
	return true;
}

bool isPrime3(ll n)
{
	if(n==2) return true;
	if(n < 2 || n%2==0) return false;

	for(ll i = 3; i <= sqrt(n) ; i+=2)
		if(n%i==0)
			return false;

	return true;
}

bool isPrime4(ll n)
{
	if(n==2) return true;
	if(n < 2 || n%2==0) return false;

	for(ll i=3; i*i <= n; i+=2)
		if(n%i == 0)
			return false;

	return true;
}

int countPrimesInRange(int n)
{
	int cnt =0;
	for(int i=0; i <= n; i++)
		if(isPrime4(i))
			cnt++;
	return cnt;
}

int countPrimesInRange_sieve(int n)
{
	vector<bool> isPrime(n+1,true);

	for(ll i =2; i*i <= n; ++i)
	{
		if(isPrime4(i))
		{
			for(ll j = i*2; j<=n; j+=i)
				isPrime[j]=false;
		}
	}
	
	int cnt =0;
	for(int i =1; i <= n ; i++)
	{
		if(isPrime[i])
			cnt++;
	}
	return cnt;
}