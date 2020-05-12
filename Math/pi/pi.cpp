#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int factorial(int n) {
	if(n==0) return 1;
	else return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

long double sum(int k) {
	long double n=factorial(6*k)*(545140134*k+13591409);
	long long int d=factorial(3*k)*((factorial(k))^3)*(pow(-262537412640768000,k));
	cout << fixed << n << endl << d << endl << n/d;
	return n/d;
}

int main() {
	long double a=426880*sqrt(10005);
	int k=0;
	int i=0;
	long double s=0;
	cin >> k;
	long double pi=3;
	/*while(i<k) {
		sum(i);
		i++;
	}
	pi=a/s;*/
	sum(0);
	//cout << fixed << setprecision(100);
	//cout << a << endl << s << endl << pi;
}