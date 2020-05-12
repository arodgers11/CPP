// palindromeR.hpp -- recursive palindrome tester
// c. 2017 Andy Rodgers

#ifndef PALINDROMER_HPP
#define PALINDROMER_HPP

#include <iostream>

using namespace std;

class PalindromeR {
	public:
	//default constructor
	PalindromeR();
	int test_string(const string& s);
	//destructor
	~PalindromeR();
};

#endif