#include <stdio.h>

struct rectangle
{
   int len ; int brdth;
};

struct card
{
    int face;
    int shape;
    int colour;
};



int main()
{
// Accessing a struct.
struct rectangle a = {8 , 9};
printf("Area of rectangel %d ",a.len * a.brdth);

// Changing struct value through.
a.len = (25);
a.brdth = (4);
printf("\n""New area %d",a.len * a.brdth);

printf("\n");

struct card mycard[52] = {{2,1,0} ,{5,0,1} ,{10,0,0}};
printf("%d \n",mycard[0].face);
printf("%d \n",mycard[0].shape);
printf("%d \n",mycard[0].colour);
printf("%d \n",mycard[1].shape);

    return 0;
}

