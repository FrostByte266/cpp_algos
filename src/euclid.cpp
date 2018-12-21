#include<iostream>

int euclidAlgo(const int& lhs, const int& rhs);
int parseToInt(const char* args[], const int& argNum);

int main(const int argc, const char* argv[]){
	int lhs, rhs;
	lhs = parseToInt(argv, 1);
	rhs = parseToInt(argv, 2);
	std::cout << euclidAlgo(lhs, rhs) <<std::endl;
	return 0;
}

int euclidAlgo(const int& lhs, const int& rhs){
	if (lhs == 0){
		std::cout << "---------" << std::endl << "The answer is: ";
		return rhs;
	}else{
		std::cout << "---------" << std::endl << "Number A: " << lhs << std::endl << "Number B: " << rhs << std::endl;
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
