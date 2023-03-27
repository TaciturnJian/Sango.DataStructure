#include <iostream>
#include <time.h>
#include "Sango.KMP.hpp"

#define Loop(x) for (int i = 0; i < x; i++)

int main() {
	Sango::KMPSolution kmp("ababc");
	Sango::BruteForce bf("ababc");

	unsigned long long p, q;
	int times = 1000000;
	std::string text = "abcabcabcabcabcabcababccasaa";

	p = clock();
	Loop(times)
		kmp.SearchFirst(text);
	q = clock();

	std::cout << q - p << std::endl;

	p = clock();
	Loop(times)
		bf.SearchFirst(text);
	q = clock();
	std::cout << q - p << std::endl;
}