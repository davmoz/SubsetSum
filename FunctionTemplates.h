//
// Created by quartie on 2018-05-22.
//

#pragma once

template<typename T>
void swapThem(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int partition(T arr[], int start, int end)
{
    T tempObj = arr[start];
    int pivot = start;
    for (int i = start + 1; i < end; i++)
    {
        if (arr[i] < tempObj)
        {
            swapThem(arr[pivot + 1], arr[i]);
            pivot++;
        }
    }
    swapThem(arr[start], arr[pivot]);
    return pivot;
}

template<typename T>
void quickSort(T arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot);
        quickSort(arr, pivot + 1, end);
    }
}