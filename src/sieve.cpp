#include <iostream>
#include <vector>
#include<bits/stdc++.h>

void sieveAlgo(const int& n, std::vector<int>& vec);

int main(){
	std::cout << "Input the number to calculate up to" << std::endl << "> ";
	int choice;
	std::cin >> choice;
	std::vector<int> primes;
	sieveAlgo(choice, primes);
	/* Iteracte through the vector
	if the current index is not the
	last in the vecotr, output the
	value, and append a comma and
	a space, and print the next
	if the current index is the last
	then just print its value and
	and end the cuurent line */
	for(int i=0; i<primes.size(); ++i){
		if(i != primes.size()-1){
			std::cout << primes[i] << ", ";
		}else{
			std::cout << primes[i] << std::endl;
		}
	}
	return 0;
}

void sieveAlgo(const int& n, std::vector<int>& vec){
	//Create an array of to represent if the index is prime
	//and then use memset to set every value to false
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for(int p=2; p*p<=n; p++){
		//If the current index is true, then it has to be a prime
		if(prime[p]){
			for(int i=p*2; i<=n; i+=p){
				/* Eliminate all numbers
				that are multiples of p
				and are greater than or
				equal to the square
				numbers which are less than
				p squared have already been */
				prime[i]=false;
			}
		}
	}
	/* Loop through the array, if the index
	is true, it is a prime, and we will
	add it to the vector passed into
	the function */
	for (int p=2; p<=n; p++){
		if(prime[p]){
			vec.push_back(p);
		}
	}
}
