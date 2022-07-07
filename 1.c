//merge sort leido de un fichero de texto que tiene dos lineas la primera es un numero q es el numero
//de elementos de la lista y el segundo los numeros separados por espacios
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int merge_sort(int * list1, int *list2){
	int size=sizeof(list1)/sizeof(int);
	int size2=sizeof(list2)/sizeof(int);
	int * array_final=malloc((size+size2)*sizeof(int));
	for(int i=0;i<size;i++){
		if(list1[i]>list2[i]){
			array_final[i]=list1[i];
		}
		else{
			list1[i]=array_final[i];
		}
	}
	return 0;
}

int * divide(int * list,int size){
	//7
	int res=size/2;//3.5
	int val1=trunc(res);//3
	int val2=size-val1;//7-3=4
	int lista1[val1];
	int lista2[val2];
	//int * lista1=malloc(val1*sizeof(int));
	//int * lista2=malloc(val2*sizeof(int));
	for(int i=0;i<val1;i++){
		lista1[i]=list[i];
		printf("%d %d\n",i,lista1[i]);
	}
	if(val1!=1){
		divide(lista1,val1);
	}
	for(int i=val1;i<size;i++){
		lista2[i-val1]=list[i];
		printf("%d %d\n",i-val1,lista2[i-val1]);
	}
	if(val2!=1){
		divide(lista2,val2);
	}
	
	return 0;
}
int main(){
	int ejemp[8]={5,6,2,9,10,8,1,7};
	int size_r=sizeof(ejemp)/sizeof(int);//cambiar por leer fichero
	int * a=malloc(size_r*sizeof(int));
	for(int i=0;i<size_r;i++){
		a[i]=ejemp[i];
	}
	divide(ejemp,size_r);
	return 0;
}

