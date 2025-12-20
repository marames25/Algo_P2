#include <bits/stdc++.h>
using namespace std;

int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i; 
    }
    return -1; 
}

int recursiveSearch(const vector<int>& arr, int target, int index = 0) {
    if (index >= arr.size()) 
        return -1;
    if (arr[index] == target) 
        return index;
    return recursiveSearch(arr, target, index + 1);
}

int binarySeachIterative(vector<int>& v,int target){
    int low = 0, high = v.size()-1;
    while(low <= high){
        int middle =(low+high)/2;
        if(v[middle] == target)
            return middle;
        else if(v[middle] < target)
            low = middle+1;
        else
            high = middle-1;
    }
    return -1;
}

int binarySearchRecursive(vector<int>& v,int target,int low,int high){
    if(low > high)
        return -1;
    int middle =(low+high)/2;
     if(v[middle] == target)
            return middle;
        else if(v[middle] < target)
            return binarySearchRecursive(v,target,middle+1,high);
        else
            return binarySearchRecursive(v,target,low,middle-1);



}



int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target value to search for: ";
    cin >> target;
    vector<int> arr2 = arr;
    sort(arr2.begin(),arr2.end());
    cout << "\n--- Sequential Search ---\n";
    int iterativeResult = sequentialSearch(arr, target);
    int recursiveResult = recursiveSearch(arr, target);

    if (iterativeResult != -1)
        cout << "Iterative Sequential Search: Found at index " << iterativeResult << endl;
    else 
        cout << "Iterative Sequential Search: Not found" << endl;

    if (recursiveResult != -1)
        cout << "Recursive binary Search: Found at index " << recursiveResult << endl;
    else
        cout << "Recursive binary Search: Not found" << endl;


    
    cout << "\n--- Binary Search ---\n";

   
    int iterativeBinary = binarySeachIterative(arr2, target);
    int recursiveBinary = binarySearchRecursive(arr2, target,0,arr2.size()-1);

        

    if (iterativeBinary != -1)
        cout << "Iterative Sequential Search: Found at index " << iterativeBinary << endl;
    else 
        cout << "Iterative Sequential Search: Not found" << endl;

    if (recursiveBinary != -1)
        cout << "Recursive Sequential Search: Found at index " << recursiveBinary << endl;
    else
        cout << "Recursive Sequential Search: Not found" << endl;



    return 0;
}





