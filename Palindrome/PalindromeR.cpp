#include "PalindromeR.hpp"
#include <string>
using namespace std;

PalindromeR::PalindromeR(){}
PalindromeR::~PalindromeR(){}
int PalindromeR::test_string(const string& s){
	size_t L=s.length();
		int i=0;
		int j=0;
		if(L==1 || L==0)return -1;
		while(!isalnum(s[0+i]))i++;
		while(!isalnum(s[L-1-j]))j++;
		if(toupper(s[0+i])==toupper(s[L-1-j])){
			string S=s.substr(i+1,L-2-j-i);
			return test_string(S);
		}
		else return 1;
};