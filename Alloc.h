

#ifndef ALLOC_H
#define ALLOC_H


#include <stdlib.h>
/*This header contains the prototypes for malloc(), calloc(), and realloc().*/

#define Alloc(Amount, Variable) malloc((Amount) * sizeof(Variable))
/*Calls malloc(), which allocates Amount slots of size sizeof(Variable).*/
#define Ralloc(Amount, Variable) realloc(Variable, (Amount) * sizeof(Variable))
/*Calls realloc(), used to resize the allocated memory, which allocates Amount
    slots of size sizeof(Variable). A temporary pointer should be used, as is
    standard with realloc().*/
#define Calloc(Amount, Variable) calloc((Amount), sizeof(Variable))
/*Calls calloc(), which allocates Amount slots of size sizeof(Variable) and
    initializes each slot with the value of zero.*/

#define Salloc(Amount, Variable) malloc((Amount) + 1, sizeof(Variable))
#define Sralloc(Amount, Variable) realloc(Variable, ((Amount) + 1) * sizeof(Variable))
#define Scalloc(Amount, Variable) calloc((Amount) + 1, sizeof(Variable))
/*The macros above are essentially repeats of the three before, but they allocate
    one more slot than Amount. This is useful for storing strings, or tables. Each
    macro is named by simply adding an S to the beginning.*/

#define ALLOCATION_FAILURE NULL
/*The succcess of any of these macros should NEVER be assumed. Always check if
    the returned pointe is null. You can use this definition to make things more
    explicit to those who read your code.*/

#endif /* Alloc_h */
