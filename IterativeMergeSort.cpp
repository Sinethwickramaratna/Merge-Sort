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

vector <int> merge (vector<int> arr,int L1,int R1,int L2,int R2){
    vector <int> temp;
    
    while (L1<=R1 && L2<=R2){
        if (arr[L1]<=arr[L2]){
            temp.push_back(arr[L1]);
            L1++;
        } else{
            temp.push_back(arr[L2]);
            L2++;
        }
    }
    
    while (L1<=R1){
        temp.push_back(arr[L1]);
        L1++;
    }
    
    while (L2<=R2){
        temp.push_back(arr[L2]);
        L2++;
    }
    
    return temp;
    
}

vector <int> iterativeMergeSort(vector<int> arr){
    int n = arr.size();
    int len =1;
    while (len<n){
        int i=0;
        while(i<n){
            int L1 = i;
            int R1 = i+len-1;
            int L2 = i+len;
            int R2 = i+2*len-1;
            
            if (L2 >=n){
                break;
            }
            
            if(R2>=n){
                R2 = n-1;
            }
            
            vector <int> temp =merge(arr,L1,R1,L2,R2);
            
            for (int j =0; j<R2-L1+1;j++){
                arr[i+j] = temp[j];
            }
            i=i+2*len;
        }
        len = 2*len;
    }
    return arr;
}



int main()
{

    vector<int> values(10000);

    // Generate Random values
    auto f = []() -> int { return rand() % 10000; };

    // Fill up the vector
    vector <int> arr = {2,1};
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    for(int i: iterativeMergeSort(arr)){
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