#include <stdio.h>
#include <stdlib.h>

struct myarray
{
    int A[20];
    int lenght, size;
};

void swap(int *a , int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

// displaying my array
void display(struct myarray arr)
{
    int i;
    for (i = 0; i < arr.lenght; i++)
        printf(" %d ", arr.A[i]);
}
    
// get the value of a given index
int getarr(struct myarray arr, int index)
{
    if (index < arr.lenght && index >= 0)
        return arr.A[index];
}

// Setting a new value at given index
int setarr(struct myarray *arr, int index, int x)
{
    if (index >= 0 && index < arr->lenght)
        return arr->A[index] = x;
}

// maximum value of array
int maxarr(struct myarray arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.lenght; i++)
        if (arr.A[i] > max)
            max = arr.A[i];
    return max;
}

// minimun value of array
int minarr(struct myarray arr)
{
    int i, min = arr.A[0];
    for (i = 1; i < arr.lenght; i++)
        if (arr.A[i] < min)
            min = arr.A[i];
    return min;
}

// sum of all the elements of arrray
int sumarr(struct myarray arr)
{
    int i, total = 0;
    for (i = 0; i < arr.lenght; i++)
        total += arr.A[i];
    return total;
}


int sumarrRecusion(struct myarray *arr, int n)
{
    if(n < 0)
        return 0;
    return sumarrRecusion(arr->A , n-1) + arr->A[n];
}



// Average of all the elements in array
float avgarr(struct myarray arr)
{
    return (float)sumarr(arr) / arr.lenght;
}


// Reverse an array
int reversearr(struct myarray *arr)
{
    int *b;
    int i, j;
    b = (int *)malloc(arr->lenght * (sizeof(int)));

    for (i = arr->lenght - 1, j = 0; i >= 0, j < arr->lenght; i--, j++)
        b[j] = arr->A[i];
    for (i = 0; i < arr->lenght; i++)
        arr->A[i] = b[i];
    free(b);
}

int reverseinterchange(struct myarray *arr)
{
    int i, j, temp;
    for (i = 0, j = arr->lenght - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
        return temp;
    }
}


// Insert an element in sorted array
int insertsorted(struct myarray *arr, int x)
{
    int i = arr->lenght - 1;
    if (arr->lenght == arr->size)
        return -1;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->lenght++;
}


// check if array is sorted or not
int isSorted(struct myarray arr)
{
    int i;
    for (i = 0; i < arr.lenght - 1; i++)
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    return 1;
}


// Reearrange negative and positive
void reArrange(struct myarray *arr)
{
    int i = 0;
    int j = arr->lenght - 1;
    while (i < j)
    {
        while(arr->A[i] < 0)i++;
        while(arr->A[j] >= 0)j--;
        if(i < j)swap(&arr->A[i], &arr->A[j]);
    }
}



int main()
{
    struct myarray arr = {{4, 8, 10, 15, 18, 23, 29, 34, 40, 46}, 10, 20};

    // swap(2,5);
    // printf("\n get_Meathod %d \n ",getarr(arr,2));
    // printf("\n Set_Meathod %d \n ",setarr(&arr,8,88));
    // printf("\n max_meathod %d \n ",maxarr(arr));
    // printf("\n min_meathod %d \n ",minarr(arr));
    // printf("\n sum_meathod %d \n ",sumarr(arr));
    // printf("\n Sum of array in Recursion %d \n",sumarrRecusion(&arr , 10));
    // printf("\n average_meathod %f \n ",avgarr(arr));
    printf("\n reverse_array %d \n",reversearr(&arr));
    // printf("\n reverseInterchange meathod %d \n",reverseinterchange(&arr));
    // printf("\n sorted array insertioin %d \n",insertsorted(&arr,25));
    // printf("\n checking if array is sorted or not %d \n",isSorted(arr));

    // struct myarray arr2 = {{4, 8, -10, -15, -18, -23, -29, 34, 40, -46}, 10, 20};
    // reArrange(&arr2);
    // display(arr2);

    
    display(arr);
    printf("\n");

    return 0;
}