#include<stdlib.h> 
#include<iostream> 
#include<time.h>

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

void merge(int arr[], int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    //Create temporary array
    int L[n1], R[n2]; 
  
    //Copy array to temps
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]; 
	}
    for (j = 0; j < n2; j++){ 
        R[j] = arr[m + 1+ j]; 
	}
    //Start merging the two
    i = 0;
    j = 0; 
    k = l;
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]){ 
            arr[k] = L[i]; 
            i++; 
        }else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r){ 
    if (l < r){ 
		//Find the middle
        int m = l+(r-l)/2; 
  
        //Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
		//Merge sorted array
        merge(arr, l, m, r); 
    } 
} 
  
void printArray(int A[], int size){ 
    int i; 
    for (i=0; i < size; i++)
		if(i != size - 1){
			std::cout << A[i] << ", ";
		}else{
			std::cout << A[i] << std::endl;
		}
} 
  
int main(const int argc, const char* argv[]){
	//Get the size of the array from argv
	int size = parseToInt(argv);
	//Fill array with random numbers
    srand(time(NULL));	
    int arr[size];
	for(int s = 0; s < size; s++){
		arr[s] = rand()%1000;
	}
	//Find the number of elements in the array
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
	
	//Output original, sort, and then output sorted
    std::cout << "Unsorted: ";
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    std::cout << "Sorted: ";
    printArray(arr, arr_size); 
    return 0; 
} 
