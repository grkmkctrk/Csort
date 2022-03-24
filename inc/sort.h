#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ll.h"

// Tools
int max(int *arr, int size);
int min(int *arr, int size);
void swap(int *a, int *b);
void print_array(int *array, int size);
    // merge tools
void merge(int *array, int left, int mid, int right);
    // quick tools
int partition(int *array, int left, int right);
    // heap tools
void heapify(int *array, int size, int i);

// Selection Sort - Time Complexity: O(n²)
void selection_sort(int *array, int size);

// Bubble Sort - Time Complexity: O(n²)
void bubble_sort_1(int *array, int size);
void bubble_sort_2(int *array, int size);
void bubble_sort_recursive(int *array, int size);

// Insertion Sort - Time Complexity: O(n²)
void insertion_sort(int *array, int size);
void insertion_sort_recursive(int *array, int size);

// Merge Sort - Time Complexity: O(n log n)
void merge_sort(int *array, int size);
void merge_sort_iterative(int *array, int size);

// Quick Sort - Time Complexity: O(n log n)
void quick_sort(int *array, int left, int right);
void quick_sort_iterative(int *array, int left, int right);

// Heap Sort - Time Complexity: O(n log n)
void heap_sort(int *array, int size);

// Counting Sort - Time Complexity: O(n)
void counting_sort(int *array, int size);
void counting_sort2(int *array, int size, int k);

// Radix Sort - Time Complexity: O(nk)
void radix_sort(int *array, int size);

// Bucket Sort - Time Complexity: O(n)
void bucket_sort(int *arr, int size, int numOfBuckets);

#endif