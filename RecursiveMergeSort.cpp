// C++ program to find out execution time of
// of functions
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;

// For demonstration purpose, we will fill up
// a vector with random integers and then sort
// them using sort function. We fill record
// and print the time required by sort function

vector <int> merge(vector <int> arr,vector <int> leftArr,vector <int> rightArr){
    int n1=leftArr.size();
    int n2=rightArr.size();
    int size = arr.size();
    int i=0, j=0, k=0;
    
    while(i<n1 && j<n2){
        if (leftArr[i]<rightArr[j]){
            arr[k]=leftArr[i];
            i++;
        }else{
            arr[k]=rightArr[j];
            j++;
        }
        k++;
    }
    
    while(i<n1 && k<size){
        arr[k]=leftArr[i];
        i++;
        k++;
    }
    
    while (j<n2 && k<size){
        arr[k]=rightArr[j];
        j++;
        k++;
    }
    
    return arr;
}


vector <int> mergeSort (vector <int> arr){
    int mid = arr.size()/2;
    vector <int> leftArr(arr.begin(), arr.begin()+mid);
    vector <int> rightArr (arr.begin()+mid, arr.end());
    int size = arr.size();
    if (size<=1){
        return arr;
    }
    rightArr = mergeSort(rightArr);
    leftArr = mergeSort(leftArr);
    
    return merge(arr,leftArr,rightArr);
}


int main()
{

    vector<int> values(10000);

    // Generate Random values
    auto f = []() -> int { return rand() % 10000; };

    // Fill up the vector
    vector <int> arr = {40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    for(int i: mergeSort(arr)){
        cout<< i <<" ";
    }
    cout << endl;

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to 
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}