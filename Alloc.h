/********************************************************************************
*Alloc.h contains macros designed to simplify and standardize the form of       *
*functions the used in dynamic memory allocation, excluding free().             *
*                                                                               *
*The goal here is to make it so the programmer does not have to remember the    *
*different syntax associated with malloc(), calloc, and realloc(). In addition, *
*Alloc.h includes three macros geared towards allocating memory for objects     *
*that the programmer wishes to be null-terminated. Descriptions of all six      *
*macros are found underneath their definitions.                                 *
*                                                                               *
*Syntax has been simplified by replacing the function-dependent variable lists  *
*with a standdardized one: Amount, Variable. The programmer should pass the     *
*amount of memory slots they wish to allocate as Amount, and the pointer to     *
*which the memory should be allocated as Variable.                              *
*                                                                               *
*Last updated: 08/30/2020                                                       *
*By: Ben Canon                                                                  *
********************************************************************************/

#ifndef Alloc_h
#define Alloc_h

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
