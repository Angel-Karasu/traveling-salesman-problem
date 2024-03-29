#include "utilities.h"

void merge(couple arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    couple L[n1], R[n2];
    for (int i=0; i<n1; i++) L[i] = arr[left+i];
    for (int j=0; j<n2; j++) R[j] = arr[mid+j+1];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].y <= R[j].y) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(couple arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void static_sort() {
    init_path();
    
    couple array[NB_POINTS-1];
    for (int i=0; i<NB_POINTS-1; i++) {
        couple c = {path[i], distance_points[starting_point][path[i]]};
        array[i] = c;
    }
    
    merge_sort(array, 0, NB_POINTS-2);
    
    for(int i=0; i<NB_POINTS-1; i++) path[i] = array[i].x;
    copy_path_to_min_path();
    show_min_path("Static sort");
}