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


//MERGE SORT Not Working
void Merge_Sort(long * Array, int Size)
{
    merge_split(Array, 0, Size-1);
}

void merge_split(long * Array, int lb, int ub)
{
    if(lb >= ub){
        return;
    }
    int mid = lb+ub/2;
    merge_split(Array, lb, mid);
    merge_split(Array, mid+1, ub);
    put_together(Array, lb, ub, mid);
    return;
}

void put_together(long * Array, int lb, int ub, int mid)
{
    long * left = calloc(mid-lb+1, sizeof(long));
    long * right = calloc(ub-mid, sizeof(long));
    memcpy(&left[0], &Array[lb], mid-lb+1);
    memcpy(&right[0], &Array[mid+1], ub-mid);
    int i = lb;
    int j = mid + 1;
    int k;
    for(k = lb; k<= ub; k++){
        //Neither are finished
        if(i <= mid && j <= ub){
            if(left[i] <= right[j]){
                Array[k] = left[i];
                i++;
            }
            else{
                Array[k] = right[j];
                j++;
            }
        }
        //Left array is finished
        else if(i > mid && j <= ub){
            Array[k] = right[j];
            j++;
        }
        //Right array is finished
        else if(i <= mid && j > ub) {
            Array[k] = left[i];
            i++;
        }
    }
    free(left);
    free(right);
    return;
}
