#include "../inc/sort.h"

// Begin of Tools
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

// End of Tools
    // selection_sort
void selection_sort(int *array, int size){

    if(size <= 1) {
        printf("out of range\n");
        return;
    }

    int i, j, min_index;
    for(i = 0; i < size; i++){
        min_index = i;
        for(j = i + 1; j < size; j++){
            if(array[j] < array[min_index]){
                min_index = j;
            }
        }
        swap(&array[i], &array[min_index]);
    }
    printf("[selection_sort]\n");
}

    // bubble_sort
void bubble_sort_1(int *array, int size){

    if(size <= 1) {
        printf("out of range\n");
        return;
    }

    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size - 1; j++){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
    printf("[bubble_sort_1]\n");
}

void bubble_sort_2(int *array, int size){
    
    if(size <= 1) {
        printf("out of range\n");
        return;
    }

    int i, j;
    bool swapped;
    for(i = 0; i < size; i++){
        swapped = false;
        for(j = size - 1; j > i; j--){
            if(array[j] < array[j - 1]){
                swap(&array[j], &array[j - 1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
    printf("[bubble_sort_2]\n");
}

void bubble_sort_recursive(int *array, int size){

    if(size <= 1) {
        printf("[bubble_sort_recursive]\n");
        return;
    }
    if(size > 1) {
        for(int i = 0; i < size - 1; i++) // O(n)
            if(array[i] > array[i + 1])
                swap(&array[i], &array[i + 1]);
        
        bubble_sort_recursive(array, size - 1); // (size - 1) Big O notation is O(n)
    }
}

    // insertion_sort
void insertion_sort(int *array, int size){
    
    if(size <= 1) {
        printf("out of range\n");
        return;
    }

    int i, j;
    for(i = 1; i < size; i++){
        j = i - 1;
        while(j >= 0 && array[j] > array[j + 1]){
            swap(&array[j], &array[j + 1]);
            j--;
        }
    }
    printf("[insertion_sort]\n");
}

void insertion_sort_recursive(int *array, int size){
    
        if(size <= 1) {
            printf("[insertion_sort_recursive]\n");
            return;
        }
        else{
            if(size > 1) {
                insertion_sort_recursive(array, size - 1); // (size - 1) Big O notation is O(n)
                int j = size - 2;
                while(j >= 0 && array[j] > array[j + 1]){
                    swap(&array[j], &array[j + 1]);
                    j--;
                }
            }
    }
}

    // merge_sort
void merge(int *array, int left, int mid, int right){
        
        // find half of the array and create two temp arrays that represent left and right
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[n1], R[n2];
        
        // copy data to temp arrays L and R
        for(i = 0; i < n1; i++){
            L[i] = array[left + i];
        }
        for(j = 0; j < n2; j++){
            R[j] = array[mid + 1 + j];
        }

        // merge the temp arrays back into array
        i = 0;
        j = 0;
        k = left;
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                array[k] = L[i];
                i++;
            }
            else{
                array[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n1){
            array[k] = L[i];
            i++;
            k++;
        }
        while(j < n2){
            array[k] = R[j];
            j++;
            k++;
        }
}

void merge_sort(int *array, int size){
        int mid;
        if(size > 1){
            mid = size / 2;
            merge_sort(array, mid); // split left half
            merge_sort(array + mid, size - mid); // split right half
            merge(array, 0, mid - 1, size - 1); // every time merge two halves
        }
}

void merge_sort_iterative(int *array, int size){

    int curr_size;
    int left_start;

    if(size <= 1) {
        printf("[insertion_sort_recursive]\n");
        return;
    }
    for(curr_size = 1; curr_size <= size - 1; curr_size = 2 * curr_size){
        for(left_start = 0; left_start < size - 1; left_start += 2 * curr_size){
            int mid = left_start + curr_size - 1;
            int right_end = left_start + 2 * curr_size - 1;
            if(right_end > size - 1){
                right_end = size - 1;
            }
            merge(array, left_start, mid, right_end);
        }
    }
}

    // quick_sort
int partition(int *array, int left, int right){
    // divede the array into two parts
    // getting highest index of the array as pivot
    int pivot = array[right];
    int i = left - 1;
    int j;
    for(j = left; j < right; j++){
        if(array[j] <= pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return (i + 1);
}

void quick_sort(int *array, int left, int right){
    
    /*
        Sort breif:
        quick_sort(array, 0, size - 1) creates
        a subarray of array[0] to array[size - 1]

        assume that left side of array is {3, 8, 2}
        - quick_sort(array, 0, 2) array will be {3, 8, 2} -> {2, 3, 8}
        - quick_sort(array, 0, 1) array will be {2, 3} -> {2, 3}
        - quick_sort(array, 0, 1) array will be {2} -> {2}
        - quick_sort(array, 0, 0) array will be {}
        final form of left side is {2, 3, 8}
        and then it returns.
        assume that right side of array is {7, 1, 9}
        left will be 3 because it is pivote index
        - quick_sort(array, 3, 3) will be {7, 1, 9} -> {}

    */
    
    if(left < right){
        int pivot = partition(array, left, right);
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}