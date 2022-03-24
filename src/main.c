#include "../inc/main.h"

int main(){

    int arr[10] = {45, 21, 54, 77, 24, 86, 12, 56, 89, 34};
    // int array1[6] = {7, 1, 9, 3, 8, 2};

    // selection_sort(array, 10);

    // bubble_sort_1(array, 10);
    // bubble_sort_2(array, 10);
    // bubble_sort_recursive(array, 10);

    // insertion_sort(array, 10);
    // insertion_sort_recursive(array, 10);

    // merge_sort(array, 10);
    // merge_sort_iterative(array1, 10);

    // quick_sort(array, 0, 5);
    // quick_sort_iterative(array, 0, 9);

    // heap_sort(array, 10);

    // counting_sort(array, 10);
    // counting_sort2(array, 10, 100);

    // radix_sort(array, 10);

    // bucket_sort(arr, 10, 10);

    // shell_sort(arr, 10);

    // comb_sort(arr, 10);

    pigeonhole_sort(arr, 10);

    print_array(arr, 10);



    return 0;
}