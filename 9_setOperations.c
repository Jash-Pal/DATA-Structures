#include <stdio.h>
#include <stdlib.h>

struct myarray
{
    int A[10];
    int lenght, size;
};


// for displaying the elements of an array.
void display(struct myarray arr1)
{
    for (int i = 0; i < arr1.lenght; i++)
        printf(" %d ", arr1.A[i]);
};



// Merging an sorted arrray.
struct myarray *merge(struct myarray *arr1, struct myarray *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct myarray *arr3 = (struct myarray *)malloc(sizeof(struct myarray));

    while (i < arr1->lenght && j < arr2->lenght)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->lenght; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->lenght; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->lenght = arr1->lenght + arr2->lenght;
    arr3->size = 15;

    return arr3;
};



// Union of an sorted array.
struct myarray *Union(struct myarray *arr1, struct myarray *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct myarray *arr3 = (struct myarray *)malloc(sizeof(struct myarray));

    while (i < arr1->lenght && j < arr2->lenght)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else // else means if both array have equal elements (6, 15);
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < arr1->lenght; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->lenght; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->lenght = k;
    arr3->size = 10;

    return arr3;
};



// Intersection of an sorted array.
struct myarray *Intersection(struct myarray *arr, struct myarray *arrr)
{
    int i, j, k;
    i = j = k = 0;
    struct myarray *arrr3 = (struct myarray *)malloc(sizeof(struct myarray));

    while (i < arr->lenght && j < arrr->lenght)
    {
        if (arr->A[i] < arrr->A[j])
            i++;
        else if (arrr->A[j] < arr->A[i])
            j++;
        else
        {
            arrr3->A[k++] = arr->A[i++];
            j++;
        }
    }

    arrr3->lenght = k;
    arrr3->size = 10;

    return arrr3;
};



// Difference in an sorted array (A-B).
struct myarray *difference(struct myarray *arr1, struct myarray *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct myarray *arr3 = (struct myarray *)malloc(sizeof(struct myarray));

    while (i < arr1->lenght && j < arr2->lenght)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1->lenght; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->lenght = k;
    arr3->size = 10;

    return arr3;
};












int main()
{
    struct myarray arr1 = {{2, 6, 10, 15, 26}, 5, 10};
    struct myarray arr2 = {{3, 6, 7, 15, 20}, 5, 10};
    struct myarray *arr3;

    // arr3 = merge(&arr1, &arr2);
    // arr3 = Union(&arr1, &arr2);
    // arr3 = Intersection(&arr1, &arr2);
    arr3 = difference(&arr1, &arr2);

    display(*arr3);
    printf("\n");

    return 0;
    
}