#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define ll long long 

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

void solve(int n)
{
	vec<vec<int>> A(n, vec<int>(n, 1)), B(n, vec<int>(n, 1));
	vec<vec<ll>> C(n, vec<ll>(n, 0));

	double tstart = gettimeofday_sec();
	rep(i, n) rep(j, n) rep(k, n) C[i][j] += A[i][k] * B[k][j];
	double tend = gettimeofday_sec();

	cout << (double)(tend - tstart) << endl;
	return;
}

int main(void)
{
	int p;
	cin >> p;
	rep(i, p) solve(i + 1);
	return 0;
}
	
