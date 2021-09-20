int MOD;
int pnorm(int x) {
	long long aa = x;
	aa %= MOD;
	aa += MOD;
	aa %= MOD;
	return aa;
}
static long long fast_step_mod(long long num, long long step, long long mod) {
	long long result = 1;
	while (step) {
		if (step % 2 == 0) {
			step /= 2;
			num *= num;
			num %= mod;
		}
		else {
			result *= num;
			result %= mod;
			step -= 1;
		}
	}
	return result;
}
static long long Find_obr(long long a, long long m) {
	if (a == 0)
		return -1;

	return fast_step_mod(a, m - 2, m);
}
int pdiv(int x, int y) {
	return pmul(x, Find_obr(y, MOD));
}
int pmul(int x, int y) {
	long long aa = x;
	long long bb = y;

	aa %= MOD;
	bb %= MOD;
	
	long long c;
	c = aa * bb;
	c %= MOD;
	return c;
}
int psub(int x, int y) {
	return ((x - y) % MOD + MOD) % MOD;
}
int padd(int x, int y) {
	return (x + y) % MOD;
}