#include<iostream>

int euclidAlgo(const int& lhs, const int& rhs);

int main(){
	int lhs, rhs;
	std::cout << "Enter two numbers to run Euclid's algorithim" << std::endl;
	std::cout << "Number A: ";
	std::cin >> lhs;
	std::cout << "Number B: ";
	std::cin >> rhs;
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
