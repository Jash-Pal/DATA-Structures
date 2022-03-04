#include<stdio.h>
#include<stdlib.h>

struct myarray
{
    // int size,length;
    // int *A;
    int A[10],size,length;
};

void display(struct myarray arr)
{
    int i;
    printf("\n""My Elements are");
    for(i=0;i<arr.length;i++)
        printf(" %d ",arr.A[i]);
}


void append(struct myarray *arr,int x)
{
    if(arr->length < arr->size)
       arr->A[arr->length++] = x;
}


void insert(struct myarray *arr, int index, int x)
{
    if(index >= 0 && index <= arr->length)
    {
        int i;
        for(i=arr->length ; i>index ; i--)
        {
            arr->A[i] = arr->A[i-1]; 
        }
        arr->A[index] = x;
        arr->length++;
    }
}


void deleting(struct myarray *arr,int index)
{
    if(index <= arr->length)
    {
        int i;
        for(i=index ; i<arr->length-1 ;i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}



// Linear Search ...
void swap(int *a , int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int linear_search(struct myarray arr ,int key)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(key == arr.A[i])
           return i;
    }
    return -1;
}


int linear_transposition(struct myarray *arr , int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i],&arr->A[i-1]);
            return i-1;
        }
    }
    return -1;

}


int linear_front(struct myarray *arr, int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
    return -1;

}


// Binary search                                     (Numbers should be in Assending order);
int binary_search(struct myarray arr ,int key)
{
    int l,mid,h;
    l = 0;
    h = arr.length-1;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key <= arr.A[mid])
            h = mid-1;
        else if(key >= arr.A[mid])
            l = mid+1;
    }
    return -1;
}


int Recursion_binarysearch(int A[], int l, int h, int key)
{
    int mid;

    if(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key <= A[mid])
            return Recursion_binarysearch(A, l, mid-1, key);
        else
            return Recursion_binarysearch(A, mid+1, h, key);
    }
    return -1;
}








int main(){
    // struct myarray arr;
    // printf("Enter size of array :");
    // scanf("%d",&arr.size);
    // arr.A=(int *)malloc(arr.size*sizeof(int));
    // arr.length = 0;
    // int n,i;
    // printf("Enter numbers:");
    // scanf("%d",&n);

    // for(i=0;i<n;i++)
    //     scanf("%d",&arr.A[i]);
    // arr.length = n;


    struct myarray arr = {{1,8,32,41,52,83},10,6};

    // append(&arr,75);
    insert(&arr,4,1);
    deleting(&arr,3); 
    // printf("\n""Linear_search : %d ",linear_search(arr,5));
    // printf("\n""Linear_Transposition : %d ",linear_transposition(&arr,41));
    // printf("\n""Linear_Front : %d ",linear_front(&arr,83));
    // printf("Binary_search : %d ",binary_search(arr,32));
    // printf("Recursion_BinarySearch : %d ",Recursion_binarysearch(arr.A, 0, arr.length, 1));             
    display(arr);

return 0;
}