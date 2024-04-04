#include<stdio.h>
#include<stdlib.h>
int main(){
int*ptr1;
int*ptr2;
int *array;
int a=0;
ptr1 = (int*)malloc(7 * sizeof(int));
array = (int*)malloc(7 * sizeof(int));
ptr2 = (int*)malloc(7 * sizeof(int));
printf("\nEnter number of elements in 1st Pointer:");
for (int i = 0; i <7 ; i++){
scanf("%d",&ptr1[i]);}
for (int i = 0; i <7 ; i++){
printf("%d\t", ptr1[i]);
ptr2[i]=ptr1[i];}
ptr1=realloc(ptr1,6);
printf("\nEnter number of elements in 2nd pointer:");
for (int i = 0; i <6 ; i++){
scanf("%d",&ptr1[i]);}
for (int i = 0; i <6 ; i++){
printf("%d\t", ptr1[i]);}
int num=0;
for (int i =0 ; i<7;i++){
for (int j =0; j<6;j++){
if( ptr1[i] == ptr2[j]){
array[num] = ptr2[j];
num=num+1;}}}
printf("\n");
for (int i = 0; i <num; i++){
printf("%d\t", array[i]);}
printf(" \nNumber of Dublicates %d\t", num);
return 0;}