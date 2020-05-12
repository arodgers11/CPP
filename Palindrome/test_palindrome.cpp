// test_palindrome.cpp
// c. 2015 A. Deeter, revisions c. 2017 T. O'Neil

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>

#include "PalindromeI.hpp"
#include "PalindromeR.hpp"
#define rand_range (5 + rand() % 11)

inline char randChar() { return 'a' + (rand() % ('z' - 'a')); }

std::string randPalindrome(const int len, const int& correct) {
  std::string front = "", back = "";
  for (int i = 0; i < len >> 1; ++i) {
    const char s = randChar();
    front += s;
    back += i == correct ? ((s + 1 - 'a') % 26) + 'a' : s;
  }
  std::reverse(back.begin(), back.end());
  return front + back;
}

int main()
{
  srand(time(0));
  
  // Iterative tests
  PalindromeI* p = new PalindromeI();

  // test 1: empty strings and single letters are palindromes
  assert(p->test_string("") == -1);
  assert(p->test_string("a") == -1);
  std::cout << "Iter test 1 passed." << std::endl;

  // test 2: correct palindromes, all lowercase, no non-letters
  assert(p->test_string("aa") == -1);
  assert(p->test_string("bob") == -1);
  assert(p->test_string("abba") == -1);
  assert(p->test_string("stats") == -1);
  std::cout << "Iter test 2 passed." << std::endl;

  // test 3: correct palindromes, not all lowercase, with non-letters
  assert(p->test_string("aA") == -1);
  assert(p->test_string("Aa") == -1);
  assert(p->test_string("Bob") == -1);
  assert(p->test_string("Madam") == -1);
  assert(p->test_string("A man, a plan, a canal, Panama!") == -1);
  assert(p->test_string("Bob: Did Anna peep? Anna: Did Bob?") == -1);
  std::cout << "Iter test 3 passed." << std::endl;

  // test 4: returning the correct position of the failed palindromes
  assert(p->test_string("ab") == 0);
  assert(p->test_string("abca") == 1);
  assert(p->test_string("A man, a plan, a canal, Panema!") == 2);
  assert(p->test_string("rm -rf /") == 0);
  assert(p->test_string("a,,b,,c,,d,,b,,a") == 2);
  std::cout << "Iter test 4 passed." << std::endl;

  // test 5: random palindromes so you cannot hard code them
  
  for (int i = 0, len = rand_range, current = (rand() % (len / 2)) - 1; i < rand_range; ++i, len = rand_range, current = (rand() % (len / 2)) - 1)
    assert(p->test_string(randPalindrome(len, current)) == current);
  std::cout << "Iter test 5 passed." << std::endl;

  std::cout << "\nAll Iterative Tests Complete!\n" << std::endl;

  // cleanup
  delete p;
  
  // Recursive tests
  PalindromeR* p1 = new PalindromeR();

  // test 1: empty strings and single letters are palindromes
  assert(p1->test_string("") == -1);
  assert(p1->test_string("a") == -1);
  std::cout << "Recur test 1 passed." << std::endl;

  // test 2: correct palindromes, all lowercase, no non-letters
  assert(p1->test_string("aa") == -1);
  assert(p1->test_string("bob") == -1);
  assert(p1->test_string("abba") == -1);
  assert(p1->test_string("stats") == -1);
  std::cout << "Recur test 2 passed." << std::endl;

  // test 3: correct palindromes, not all lowercase, with non-letters
  assert(p1->test_string("aA") == -1);
  assert(p1->test_string("Aa") == -1);
  assert(p1->test_string("Bob") == -1);
  assert(p1->test_string("Madam") == -1);
  assert(p1->test_string("A man, a plan, a canal, Panama!") == -1);
  assert(p1->test_string("Bob: Did Anna peep? Anna: Did Bob?") == -1);
  std::cout << "Recur test 3 passed." << std::endl;

  // test 4: returning the correct position of the failed palindromes
  assert(p1->test_string("ab") == 1);
  assert(p1->test_string("abca") == 1);
  assert(p1->test_string("A man, a plan, a canal, Panema!") == 1);
  assert(p1->test_string("rm -rf /") == 1);
  assert(p1->test_string("a,,b,,c,,d,,b,,a") == 1);
  std::cout << "Recur test 4 passed." << std::endl;

  // test 5: random palindromes so you cannot hard code them
  
  for (int i = 0, len = rand_range, current = (rand() % (len / 2)) - 1; i < rand_range; ++i, len = rand_range, current = (rand() % (len / 2)) - 1) {
    if (current >= 0)
		assert(p1->test_string(randPalindrome(len, current)) == 1);
	else assert(p1->test_string(randPalindrome(len, current)) == -1);
  }
  std::cout << "Recur test 5 passed." << std::endl;

  std::cout << "\nAll Recursive Tests Complete!" << std::endl;

  // cleanup
  delete p1;
}