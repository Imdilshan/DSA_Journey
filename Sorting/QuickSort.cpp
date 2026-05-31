/*
 * Pick a pivot, swap elements with the help of pivot, return the final array
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void quicksort(vector<int> &arr, int low, int high){
        if(low < high){
           int partition = partitionf(arr, low, high);
           quicksort(arr, low, partition-1);
           quicksort(arr, partition+1, high);
        }
    }

    int partitionf(vector<int> &arr, int low, int high){

        int pivot = arr[low];
        int i = low, j = high;

        while(i < j){
            while (arr[i] <= pivot && i <= high - 1){
                i++;
            }
            while(arr[j] > pivot && j >= low + 1){
               j--;
            }
            if(i < j){
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }
    vector<int> sortArray(vector<int>& arr) {
        quicksort(arr, 0, arr.size()-1);
        return arr;
    }
};
