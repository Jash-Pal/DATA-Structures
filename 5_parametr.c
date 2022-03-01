#include <stdio.h>
#include <stdlib.h> // Always use <stdlib.h> while using dynamic memory allocation (malloc).

void swap(int *a, int *b)
{
    int s = *a;
    *a = *b;
    *b = s;
    free(a);
    free(b);                 // always free memory allocation from heap else memory leak will happen.
};

void myarr(int m[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n"
               " Array as vlaue : %d ",
               m[i]);
    };
};
/*
creating an array as an output in heap
int [] myfunc(int n)
{
     int *p;
     p = (int *)malloc(n * sizeof(int));
     return p;
};
*/

// passing structure as a parameter
struct rectangle
{
    int length;
    int breadth;
};

int area(struct rectangle r)
{
    return r.length * r.breadth;
};

// structure passing by address
void chnglen(struct rectangle *re, int c)
{
    re->length = c;
    free(re);                           // free memory allocation from heap.

};



int main()
{
    int x, y;
    x = 8; //  parameter passing by value.
    y = 9;
    printf("The value is : %d %d ", x, y);
    swap(&x, &y); // parameter passing by address.
    printf("\n"
           "swap by value : %d %d ",
           x, y);

    // passing array as a value
    int u[5] = {3, 5, 8, 2, 1};
    myarr(u, 5);
    /*
creating array as my output
 int *A;                                             // array can be changed only by address not by value.
 A = myfucn(5);
*/
    printf("\n");

    // structure parameter by value
    struct rectangle i = {20, 7};
    printf("\n"
           " Structuer by value : %d ",
           area(i));

    // structure parameter by address
    chnglen(&i, 10);
    printf("\n"
           " Structure by address : %d ",
           area(i));

    return 0;
}
