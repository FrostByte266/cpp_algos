#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

void bubbleSort(std::vector<int>& vec);
void populateVector(std::vector<int>& vec, const int& limit);
void outputVector(std::vector<int>& vec);
int parseToInt(const char* args[]);

int main(const int argc, const char* argv[]){
	//Seed randon number
	srand(time(nullptr));
	//Get the number of vector elements from args array
	int size = parseToInt(argv);
	//Create a vector and fill it with random numbers
	std::vector<int> numbers;
	//Fill vector with random numbers and print it
	std::cout << "Unsorted vector: ";
	populateVector(numbers, size);
	outputVector(numbers);
	//Apply bubble sort and print it
	bubbleSort(numbers);
	std::cout << "Sorted Vector: ";
	outputVector(numbers);
	return 0;
}

void bubbleSort(std::vector<int>& vec){
	/* Bubble sort algorithm will iterate
	through the vector, if the current index is
	more than the next index, swap them */
	for(int i=0; i<vec.size()-1; i++){
		for(int k=0; k<vec.size()-i-1; k++){
			if(vec[k] > vec[k+1]){
				std::swap(vec[k], vec[k+1]);
			}
		}
	}
}

void populateVector(std::vector<int>& vec, const int& limit){
	/* Iterate through the vector, populating
	it with randomly generated numbers
	0 - 1,000 */
	for(int i=0; i<limit; i++){
		vec.push_back(rand()%1000);
	}
}

void outputVector(std::vector<int>& vec){
	/* Iterate through the vector, if the index
	isnt't the last one in the vector, output it, and
	a comma, if it is the last one, then just ouput the
	value and a newline */ 
	for(int i=0; i<vec.size(); ++i){
		if(i != vec.size()-1){
			std::cout << vec[i] << ", ";
		}else{
			std::cout << vec[i] << std::endl;
		}
	}
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
