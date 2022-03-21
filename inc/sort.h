#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Tools
void swap(int *a, int *b);
void print_array(int *array, int size);
    // merge tools
void merge(int *array, int left, int mid, int right);
    // quick tools
int partition(int *array, int left, int right);

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


#endif