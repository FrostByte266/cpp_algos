#include<iostream>

int euclidAlgo(const int& lhs, const int& rhs);
int parseToInt(const char* args[], const int& argNum);

int main(const int argc, const char* argv[]){
	//Read inputs from command line
	int lhs, rhs;
	lhs = parseToInt(argv, 1);
	rhs = parseToInt(argv, 2);
	//Run the algorithm and print results
	std::cout << "The GCD of " << lhs << " and " << rhs << " is: " << euclidAlgo(lhs, rhs) << std::endl;
	return 0;
}

int euclidAlgo(const int& lhs, const int& rhs){
	if (lhs == 0){ //If there is no remainder, it has been reduced all the way
		return rhs;
	}else{ //If there is, run it again
		return euclidAlgo(rhs % lhs, lhs);
	}
}


int parseToInt(const char* args[], const int& argNum){
	/* This function will attempt to convert
	the first command line argument to an integer,
	if it fails, the program will exit, if not,
	it will return the first argument as an integer */
	try{
		int choice = std::stoi(args[argNum]);
		return choice;
	}catch(const std::exception& e){
		std::cout << "Argument could not be parsed, make sure you entered and integer!" << std::endl;
		exit(1);
	}
}
