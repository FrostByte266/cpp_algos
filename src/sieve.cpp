#include <iostream>
#include <vector>

void sieveAlgo(const int& n, std::vector<int>& vec);
int parseToInt(const char* args[]);

int main(const int argc, const char * argv[]){
	int maxVal = parseToInt(argv);
	std::vector<int> primes;
	sieveAlgo(maxVal, primes);
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

int parseToInt(const char* args[]){
	/* This function will attempt to convert
	the first command line argument to an integer,
	if it fails, the program will exit, if not,
	it will return the first argument as an integer */
	try{
		int choice = std::stoi(args[1]);
		return choice;
	}catch(const std::exception& e){
		std::cout << "Argument could not be parsed, make sure you entered and integer!" << std::endl;
		exit(1);
	}
}

void sieveAlgo(const int& n, std::vector<int>& vec){
	/* Create an vector of bools representing the index's
	prime status (is prime of is not prime)
	and then use memset to set every value to true */
	std::vector<bool> isPrime(n+1, true);
	for(int p=2; p*p<=n; p++){
		//If the current index is true, then it has to be a prime
		if(isPrime[p] == true){
			for(int i=p*2; i<=n; i+=p){
				/* Eliminate all numbers
				that are multiples of p
				and are greater than or
				equal to the square of p,
				numbers which are less than
				p squared have already been 
				processed */
				isPrime[i]=false;
			}
		}
	}
	/* Loop through the array, if the index
	is true, it is a prime, and we will
	add it to the vector passed into
	the function */
	for (int p=2; p<=n; p++){
		if(isPrime[p]){
			vec.push_back(p);
		}
	}
}
