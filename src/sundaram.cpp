#include <iostream>
#include <vector>

int parseToInt(const char* args[]);
void sieveOfSundaram(const int&n, std::vector<int>& vec);

int main(const int argc, const char* argv[]){
	int limit = parseToInt(argv);
	std::vector<int> primes;
	sieveOfSundaram(limit, primes);
	/* Iterate through the vector,
	if the current index is not the
	last in the vector, output the
	value, append a comma and
	a space, and print the next.
	If the current index is the last
	then just print its value and
	and end the current line */
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


void sieveOfSundaram(const int& n, std::vector<int>& vec){
	/* The algorithim will return all primes smaller than
	(2*x+2), so to get the inital number, it must be (n-2)/2 */
	int newN = (n-2)/2;
	/* Here we create a vector of bools, and set them all to false,
	this will help later to determine if a number is of the form i+j+2*i*j */
	std::vector<bool> isPrime(newN+1, false);
	/* Recursively mark off numbers who are of the form i+j+2*i*j */
	for(int i=1; i<=newN; i++){
		for(int j=i; (i+j+2*i*j) <= newN; j++){
			isPrime[i+j+2*i*j] = true;
		}
	}
	/* Two is known to be prime for cetrain,
	so it is added to the list */
	vec.push_back(2);
	/* Primes take the form 2*i+1 instead of i+j+2*i*j, so anywhere that
	isnt marked is prime, and it is added into the list of pirmes */
	for(int i=1; i<=newN; i++){
		if(isPrime[i] == false){
			vec.push_back(2*i+1);
		}
	}
}
