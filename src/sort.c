#include "../inc/sort.h"

// Begin of Tools
int max(int* arr, int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    // printf("%d\n", max);
    return max;
}

int min(int* arr, int size){
    int min = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    // printf("%d\n", min);
    return min;
}

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

        assume that left side of array is {7, 1, 9, 3, 8, 2}

        In pivot:
        - most right element of array will be selected as pivot
        - pivot will be placed in the correct position in the array
        (7 <= 2) {7, 1, 9, 3, 8, 2} i=-1 j = 0
        (1 <= 2) {1, 7, 9, 3, 8, 2} i=0  j = 1
        (9 <= 2) {1, 7, 9, 3, 8, 2} i=0  j = 2
        (3 <= 2) {1, 7, 9, 3, 8, 2} i=0  j = 3
        (8 <= 2) {1, 7, 9, 3, 8, 2} i=0  j = 4
        out of loop: {1, 2, 9, 3, 8, 7}
    */
    
    if(left < right){
        int pivot = partition(array, left, right);
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

void quick_sort_iterative(int *array, int left, int right){
    // push left and right to stack
    // pop left and right from stack
    // if left < right
        // push left and right to stack
        // pivot = partition(array, left, right)
        // push pivot - 1 and pivot + 1 to stack
    
    int stack[right - left + 1];
    int top = -1;
    stack[++top] = left;  // 0
    stack[++top] = right; // 1

    while(top >= 0){
        right = stack[top--]; // 0
        left = stack[top--];  //-1
        if(left < right){
            int pivot = partition(array, left, right);
            
            if(pivot - 1 > left){
                stack[++top] = left;
                stack[++top] = pivot - 1;
            }
            if(pivot + 1 < right){
                stack[++top] = pivot + 1;
                stack[++top] = right;
            }
        }
    }
}

    // heap_sort
void heapify(int *array, int size, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < size && array[left] > array[largest]){
        largest = left;
    }
    if(right < size && array[right] > array[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

void heap_sort(int *array, int size){
    int i;
    for(i = size / 2 - 1; i >= 0; i--){
        heapify(array, size, i);
    }
    for(i = size - 1; i >= 0; i--){
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

    // counting_sort
void counting_sort(int *array, int size){

    int i;
    int max = array[0];
    int min = array[0];
    for(i = 1; i < size; i++){
        if(array[i] > max){
            max = array[i];
        }
        if(array[i] < min){
            min = array[i];
        }
    }
    int k = max - min + 1;
    int count[k];
    int output[size];
    for(i = 0; i < k; i++){
        count[i] = 0;
    }
    for(i = 0; i < size; i++){
        count[array[i] - min]++;
    }
    for(i = 1; i < k; i++){
        count[i] += count[i - 1];
    }
    for(i = size - 1; i >= 0; i--){
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }
    for(i = 0; i < size; i++){
        array[i] = output[i];
    }
}

void counting_sort2(int *array, int size, int k){

    int i;
    int count[k + 1];
    int output[size];
    for(i = 0; i <= k; i++){
        count[i] = 0;
    }
    for(i = 0; i < size; i++){
        count[array[i]]++;
    }
    for(i = 1; i <= k; i++){
        count[i] += count[i - 1];
    }
    for(i = size - 1; i >= 0; i--){
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for(i = 0; i < size; i++){
        array[i] = output[i];
    }
}

    // radix_sort
void radix_sort(int *array, int size){
    int i;
    int max = array[0];
    int min = array[0];
    for(i = 1; i < size; i++){
        if(array[i] > max){
            max = array[i];
        }
        if(array[i] < min){
            min = array[i];
        }
    }
    int k = max - min + 1;
    int count[k];
    int output[size];
    for(i = 0; i < k; i++){
        count[i] = 0;
    }
    for(i = 0; i < size; i++){
        count[array[i] - min]++;
    }
    for(i = 1; i < k; i++){
        count[i] += count[i - 1];
    }
    for(i = size - 1; i >= 0; i--){
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }
    for(i = 0; i < size; i++){
        array[i] = output[i];
    }
}

    // bucket_sort
void bucket_sort(int *arr, int size, int numOfBuckets){

    int max_value = max(arr, size);
    int min_value = min(arr, size);

    int range = ((max_value - min_value) / numOfBuckets)+1;    

    // linked list and allocate memory

    ll_node_t* buckets[numOfBuckets];

    for(int i = 0; i < numOfBuckets; i++){
        buckets[i] = NULL;
    }


    for(int i = 0; i < size; i++){
        float bucket_index =  (((float) arr[i] - min_value) / range) - (arr[i] - min_value) / range; 
        
        if(bucket_index == 0 && arr[i] != min_value){
            ll_insert_tail(&buckets[(int) ((arr[i] - min_value) / range) - 1], arr[i]);
        }else{
            ll_insert_tail(&buckets[(int) ((arr[i] - min_value) / range)], arr[i]);
        }
    }

    for(int i = 0; i < numOfBuckets; i++){
        if(ll_size(buckets[i]) != 0){
            ll_sort(&buckets[i]);
        }
    }

    // gather them back
    int index = 0;
    for(int i = 0; i < numOfBuckets; i++){
        ll_node_t* current = buckets[i];
        while(current != NULL){
            arr[index] = current->data;
            current = current->next;
            index++;
        }
    }
}