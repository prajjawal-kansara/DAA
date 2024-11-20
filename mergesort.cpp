#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2]; //temp arrays

    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[mid+1+i];
    }

    int i=0;   //pointers
    int j=0;
    int k=l;   //for traversing
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            k++; i++;
        }
        else{
            arr[k] = b[j];
            k++; j++;
        }
    }
    while(i<n1){
        arr[k] = a[i];
        k++; i++;
    }

    while(j<n2){
        arr[k] = b[j];
        k++; j++;
    }
}
void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int main(){
   int arr[] = {12, 11, 13, 5, 6};
   mergesort(arr,0,4);
   for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
   return 0;
}




#include <vector>
#include <functional> // For std::function
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // A lambda function for recursive quick sort
        std::function<void(int, int)> quickSort = [&](int left, int right) {
            // Base case: If the current segment is empty or a single element, no need to sort
            if (left >= right) {
                return;
            }

            // Initialize pointers for partitioning process
            int pivotIndex = left + (right - left) / 2; // Choose middle element as pivot
            int pivotValue = nums[pivotIndex];
            int i = left - 1;
            int j = right + 1;
          
            // Partition the array into two halves
            while (i < j) {
                // Increment i until nums[i] is greater or equal to pivot
                do {
                    i++;
                } while (nums[i] < pivotValue);

                // Decrement j until nums[j] is less or equal to pivot
                do {
                    j--;
                } while (nums[j] > pivotValue);

                // If i and j haven't crossed each other, swap the elements
                if (i < j) {
                    std::swap(nums[i], nums[j]);
                }
            }

            // Recursively apply the same logic to the left and right halves of the array
            quickSort(left, j);     // Apply quicksort to the left subarray
            quickSort(j + 1, right); // Apply quicksort to the right subarray
        };

        // Start the quick sort from the first to the last element
        quickSort(0, nums.size() - 1);

        // Return the sorted array
        return nums;
    }
    int main() {
    Solution solution;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> sortedNums = solution.sortArray(nums);

    for(int num : sortedNums) {
        cout << num << " ";
    }
    return 0;
}

};