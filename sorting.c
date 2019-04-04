//
// Created by Colin Cassens on 2019-04-01.
//

#include "sorting.h"

//Function Declarations
void merge_split(long * Array, int lb, int ub);
void put_together(long * Array, int lb, int up, int mid);
//

///
/// Functions
///

//MERGE SORT Working
void Merge_Sort(long * Array, int Size)
{
    merge_split(Array, 0, Size-1);
}

void merge_split(long * Array, int lb, int ub)
{
    if(lb >= ub){
        return;
    }
    int mid = (lb+ub)/2;
    merge_split(Array, lb, mid);
    merge_split(Array, mid+1, ub);
    put_together(Array, lb, ub, mid);
    return;
}

void put_together(long * Array, int lb, int ub, int mid)
{
    //CHECK for Malloc fail in large cases and fix that issue
    long * left = malloc((mid-lb+1) * sizeof(long));
    long * right = malloc((ub-mid) *sizeof(long));
    memcpy(&left[0], &Array[lb], sizeof(long) * (mid-lb+1));
    memcpy(&right[0], &Array[mid+1], sizeof(long)*(ub-mid));
    int i = lb;
    int j = mid + 1;
    int k;
    for(k = lb; k<= ub; k++){
        //Neither are finished
        if(i <= mid && j <= ub){
            if(left[i-lb] <= right[j-(mid+1)]){
                Array[k] = left[i-lb];
                i++;
            }
            else{
                Array[k] = right[j-(mid+1)];
                j++;
            }
        }
        //Left array is finished
        else if(i > mid && j <= ub){
            Array[k] = right[j-(mid+1)];
            j++;
        }
        //Right array is finished
        else if(i <= mid && j > ub) {
            Array[k] = left[i-lb];
            i++;
        }
    }
    free(left);
    free(right);
    return;
}
