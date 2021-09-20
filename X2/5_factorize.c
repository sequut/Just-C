#define SIZE 31623
typedef struct Factors {
	int k;
	int primes[32];
	int powers[32];
} Factors;

int prime[SIZE] = { 0 };
int sost = 1;
void Factorize(int X, Factors* res) {


	if (sost) {
		prime[0] = 1;
		prime[1] = 1;
		for (int i = 0; i < SIZE; i++){
			if (prime[i] == 0){
				for (int j = 2 * i; j < SIZE; j += i){
					prime[j] = 1;
				}
			}
		}
		sost = 0;
	}	
	if (X == 1) {
		res->k = 0;
		return;
	}

	res->k = 0;
	for (int i = 2; i < SIZE; i++) {
		if ((X % i == 0) && (prime[i] == 0)) {
			res->primes[res->k] = i;

			while (X % i == 0) {
				res->powers[res->k] += 1;
				X /= i;
			}
			res->k += 1;
		}
	}
	if (X != 1) {
		res->powers[res->k] = 1;
		res->primes[res->k] = X;
		res->k += 1;
	}
}