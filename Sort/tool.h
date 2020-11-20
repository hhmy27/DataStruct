//
// Created by hmy on 2020/11/17.
//

#ifndef DATASTRUCT_TOOL_H
#define DATASTRUCT_TOOL_H

// only effect at A is int []
#define len(A) (sizeof(A)/sizeof(int))

#define fori(A) for(int i=0;i<len(A);i++)

#define iterateArray(A) fori(A)\
                        printf("%d ",A[i])

#define visitArray(A)  printf("%s: ",#A);iterateArray(A);printf("\n");

#define swap(i, j) {int temp=i;i=j;j=temp;}


#endif //DATASTRUCT_TOOL_H
