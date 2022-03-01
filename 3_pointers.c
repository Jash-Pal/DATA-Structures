#include <stdio.h>  
#include <stdlib.h>                                  // TODO : for dynamic memory allocation in heap (malloc).


struct rectangle
{
   int len ; int brdth;
};




int main() 
{
   int s = 19;
   int *x = &s;
   float *y;

printf("static pointer %d",*x);
printf("\n");


y = (float *)malloc(3 * sizeof(float));                              // TODO : for allocating memory in heap.

// static object Accessing a struct.
struct rectangle a = {8 , 9};
printf("\n""Area of rectangel %d ",a.len * a.brdth);
printf("\n");

// static object Changing struct value through ('.').
a.len = (25);
a.brdth = (4);
printf("\n""New area %d",a.len * a.brdth);
printf("\n");


// static object Using pointer to access struct.
struct rectangle *p = &a; 
printf("\n""Befor Pointer rectangle %d",p->len * p->brdth);
printf("\n");

(*p).len = 10;                                                         // (*p) to access struct through pointer.
p->brdth = 20;                                                        //  (->) to access struct through pointer.
printf("\n After Pointer rectangle %d \n",p->len * (*p).brdth);



// Dynamic object allocation in heap using malloc.
struct rectangle *m ;
m = (struct rectangle*)malloc(sizeof(struct rectangle));              // (malloc) to allocate dynamic memory in heap.
m->len = 1;
m->brdth = 9;
printf("\n""Dynamic pointer allocation %d",m->len * m->brdth);
printf("\n");


free(x);                                                           // for deleting the memory alocation in heap.
free(m);

 
return 0;
}
