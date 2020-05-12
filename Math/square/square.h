#include <random>  
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;  
  
int main()  
{  
    //random_device rd;
    //mt19937 gen(rd());
	int n;
	cin >> n;
	int MAX=pow(10,n);
	random_device rd;
	default_random_engine generator(rd());
	double x=0;
	double y=0;
	long double i=0;
	long double k=0;
	uniform_real_distribution<double> distribution(.5,9.5);
	while(i < MAX){
	x=distribution(generator);
	y=distribution(generator);
	if ( 4<x and x<6 and 4<y and y<6)
		k++;
	i++;
	//cout << i << endl;
	}
	cout << abs((k/i - 0.049382716)*100);
	
	cin.get();
	system("./s.out");
}  