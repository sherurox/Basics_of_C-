
//Below are the libraries included in my program
#include <iostream>   
#include <vector>     
#include <cstdlib>    
#include <ctime>      
#include <algorithm>  
using namespace std;  

// This is the function to perform Hoare Partitioning
int hoarePartition(vector<int>& arr, int start, int end) {
    int pivot = arr[start];  
    int i = start - 1;       
    int j = end + 1;      
    while (true) {             
        do {
            i++;          
        } while (arr[i] < pivot);
        do {
            j--;          
        } while (arr[j] > pivot);
        if (i >= j)        
            return j;
        swap(arr[i], arr[j]);  // Swaping the elements at indices i and j if i < j
    }
}

/* 
This is the function to choose a random pivot index between start and end , and then swap it with the first element, 
and apply quicksort recursively
*/
void quicksort(vector<int>& arr, int start, int end) {
    if (start < end) {  

        int randomPivot = start + rand() % (end - start + 1);  
        swap(arr[start], arr[randomPivot]);  
        int p = hoarePartition(arr, start, end);
        quicksort(arr, start, p);
        quicksort(arr, p + 1, end);
    }
}

// This is the main function to handle input 
int main(int argc, char* argv[]) {
    cout<<"Hello Programmer, welcome to Quicksort"<<endl;
    vector<int> arr;     
    int size;                         // i initialised "size" to store the sizeber of elements in the input file
    cin >> size;  
    for (int i = 0; i < size; ++i) {  // Loop initiated through each element and then added it to the array
        int value;  
        cin >> value;  
        arr.push_back(value);  
    }

    srand(time(0));                     // Initializing the random sizeber generator with the current time as seed
    quicksort(arr, 0, arr.size() - 1);  // Calling quicksort on the entire array

    if (argc == 1) {                    // If no arguments are provided (only program name), so print the sorted array
        
        cout << "Total sizebers in the file are : " << arr.size() << endl;  // Output the total count of elements
        for (int x : arr) {  
            cout << x << endl;  
        }
    } else if (argc == 3) {             // "If" semantic for two arguments providedd (start and end)
       
        int a = atoi(argv[1]); 
        int b = atoi(argv[2]); 

        // Adjusting made for 1-based indexing as mentioned by proffessor
        int start = a - 1;  
        int end = b ;       

        // This is to check if the range is valueid 
        if (start >= 0 && end <= arr.size() && start < end) {
            cout << "Starting sizeber is: " << a << ", Ending sizeber is: " << b << ", Total sizebers in the provided range is: " << (end - start) << endl;  
            for (int i = start; i < end; ++i) {  
                cout << arr[i] << endl;  
            }
        } else {          // If the inputed range is invalueid, it will print the error message
            cerr << "Error: You have inputed an invalueid range" << endl;  
            return 1;    // Exit with an error code
        }
    } else {             // If the sizeber of arguments is not 1 or 3, print the error message
        cerr << "Error: You have inputed invalueid arguments" << endl;  
        return 1;  
    }

    return 0;           // Returned 0 to indicate successful execution :D
}


