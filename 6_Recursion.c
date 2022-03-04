#include <stdio.h>

// Tail Recursion.
void func1(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        func1(n - 1);
    };
};

// Head Recursion.
void func2(int m)
{
    if (m > 0)
    {
        func2(m - 1);
        printf("%d ", m);
    };
};

// Recursion in static variable.
int fun(int a)  
{
    static int x = 0;
    if (a > 0)
    {
        x++;
        return fun(a - 1) + x;
    };
    return 0;
};

// Double Recursion.
void fun2(int a)
{
    if (a > 0)
    {
        printf("%d ", a);
        fun2(a - 1);
        fun2(a - 1);
    };
};

// Indirect Recursion.
void fuA(int A)
{
    if (A > 0)
    {
        printf("%d ", A);
        fuB(A - 1);
    };
};

void fuB(int B)
{
    if (B > 1)
    {
        printf("%d ", B);
        fuA(B / 2);
    };
};

// Nested Recursion.
int fN(N)
{
    if (N > 100)
        return N - 10;
    return (fN(fN(N + 11))); 
};

// Sum of first N natual numbers.
int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
};

int sum1(int n)
{
    int i , s = 0;
    for(i=1 ; i<=n ; i++)
    {
        s = s + i;
    };
    return s;
};

int sum2(int n){
    return n*(n+1)/2;
}


// Factorial of a number.
int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n ;

};

int fact1(int n)
{
    int i, s= 1 ;
    for(i=1 ; i<=n ; i++)
         s = s * i;
    return s;
};


// Exponent m ^ n.
int po1(int m , int n)
{
    if (n == 0)
       return 1;
    return po1(m , n-1) * m ;
};

int po2(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return po2(m * m, n / 2);
    }
    else
    {
        return m * po2(m * m, n / 2);
    };
};


// Taylor series e ^ x.
float t(int x , int n)
{
    static float p = 1 , f = 1 ;
    float r;
    if (n == 0)
       return 1 ;
    else
        r = t(x , n-1);
        p = p * x;
        f = f * n;
    return r + p/f ;

};


float tl(int x, int n)
{
    float s = 1;
    int i;
    float numerator = 1;
    float denomenator = 1;

    for(i=1 ; i<=n ; i++)
    {
        numerator = numerator * x;
        denomenator = denomenator * i;
        s = s + numerator / denomenator;
    };
    return s;
};


float tr(int x , int n)
{
    static float s;
    if (n == 0)
        return s;
    s = 1 + x*s/n ;
    return tr(x , n-1) ;
};




// Fibonaci Series.
int fib(int n)
{
    if (n<=1)
        return n;
    return fib(n-2) + fib(n-1);
}



int fib2(int n)
{
    int a=0 ; int b=1 , i , s;

    if (n<=1)
        return n;

    for (i=2;i<=n;i++)
        {     
            s = a + b;
            a = b;
            b = s;
        }
    return s;
}

int a[10];                 
int fib3(int n)                              // memoization meathod
{
    if (n<=1)
    {
        a[n] = n;
        return n;
    }
    else
    {
        if (a[n-2] == -1)
        {
            a[n-2] = fib3(n-2);
        }
        if (a[n-1] == -1)
        {
            a[n-1] == fib3(n-1);
        }
        return a[n-2] + a[n-1];
    }
}


// Combination formula.
int com(int n , int r){
    int num = fact(n);
    int den = fact(r) * fact(n-r);
    return num/den;
}


int com1(int n,int r){
    if(n==r || r==0)
        return 1;
    return com1(n-1,r-1) + com1(n-1,r);
}


// Tower of Hanoi.
void TOH(int n, int a, int b, int c){
    if(n>0){
        TOH(n-1,a,c,b);
        printf("\n""Move disk from (%d,%d) tower",a,c);
        TOH(n-1,b,a,c);
    }
}






int main()
{
    // Tail Recursion.
    int x = 3;
    printf("Tail Recursion : ");
    func1(x);

printf("\n""\n");

    // Head Recursion.
    printf("Head Recursion : ");
    func2(x);

printf("\n""\n");

    // Recursion in static.
    int i = 5;
    printf("Recursion in Static : %d ",fun(i));

printf("\n""\n");

    // Double Recursion.
    printf("Double Recursion : ");
    fun2(x);

printf("\n""\n");

    // Indirect Recursion.
    printf("Indirect Recursion : ");
    fuA(20);

printf("\n""\n");

    // Nested Recursion.
    printf("Nested Recursion : ");
    printf("%d ",fN(95));
     
printf("\n""\n");
 
    // Sum of first 'N' natural numbers .
    printf("Sum of first 'N' natural numbers is : %d ",sum(5));
    printf("\n""Sum of first 'N' in loop : %d ",sum1(5));
    printf("\n""sum of 'N' natural numbers formula : %d ",sum2(10));

printf("\n""\n");

    // Factorial of a number.
    printf("Factorial of a number is : %d ",fact(5));
    printf("\n""Factorial in loops : %d ",fact1(5));

printf("\n""\n");
 
    // Exponent m ^ n.
    printf("Exponent in Recursion  : %d ",po1(2 , 9));
    printf("\n""Exponent formula : %d ", po2(2, 9));
 
printf("\n""\n");

    // Taylor series.
    printf("Taylor series : %f ",t(1 , 10));
    printf("\n""Taylor with loops : %f ",tl(1, 10));
    printf("\n""Taylor with formula : %f ",tr(1 , 10));

printf("\n""\n");

    // Fibonaci series.
    printf("Fibonaci series : %d ",fib(7));
    printf("\n""Fibonaci with loops : %d ",fib2(7));
    printf("\n""Fibonaci with formula : %d ",fib(7));                 // Memoization approach

printf("\n""\n");

    // Combination Formula.
    printf("combination formula Using Factorial : %d", com(5,2));
    printf("\n""combination Using Recursion : %d", com1(5,2));

printf("\n""\n");
    
    // Tower of Hanoi.
    TOH(3,1,2,3);

printf("\n""\n");

    return 0;
}

