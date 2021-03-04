# Ponteiros

| Operator    | Description    | Example    |
|---------------- | --------------- | --------------- |
| &    | returns the address of the variable    | ```&a```  |
| *    | Pointer to a variable    |  ``` int *a```    |


codigo de exemplo: 

```c

#include <stdio.h>

main() {

   int a = 4;
   short b;
   double c;
   int* ptr;

   /* example of sizeof operator */
   printf("Line 1 - Size of variable a = %d\n", sizeof(a) );
   printf("Line 2 - Size of variable b = %d\n", sizeof(b) );
   printf("Line 3 - Size of variable c= %d\n", sizeof(c) );

   /* example of & and * operators */
   ptr = &a;	/* 'ptr' now contains the address of 'a'*/
   printf("value of a is  %d\n", a);
   printf("*ptr is %d.\n", *ptr);

   /* example of ternary operator */
   a = 10;
   b = (a == 1) ? 20: 30;
   printf( "Value of b is %d\n", b );

   b = (a == 10) ? 20: 30;
   printf( "Value of b is %d\n", b );
}
```

output:
``` 
Line 1 - Size of variable a = 4
Line 2 - Size of variable b = 2
Line 3 - Size of variable c= 8
value of a is  4
*ptr is 4.
Value of b is 30
Value of b is 20

```


### ETC: 

não faz difereça os seguintes usos: 

```
  int* ptr;
  int * ptr;
  int *ptr;
``` 
é tudo igual, mas recomendase: __int *ptr;__
