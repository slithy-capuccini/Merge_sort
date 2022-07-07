//merge sort leido de un fichero de texto que tiene dos lineas la primera es un numero q es el numero
//de elementos de la lista y el segundo los numeros separados por espacios
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int remove_element(int** array, int sizeOfArray, int indexToRemove)
{
    int* temp = malloc((sizeOfArray - 1) * sizeof(int)); // allocate an array with a size 1 less than the current one
    memmove(temp,*array,(indexToRemove+1)*sizeof(int)); // copy everything BEFORE the index
    memmove(temp+indexToRemove,(*array)+(indexToRemove+1),(sizeOfArray - indexToRemove)*sizeof(int)); // copy everything AFTER the inde
    free (*array);
    *array = temp;
    return 0;

}

int merge_sort(int * list1, int *list2, int size, int size2){
	size--;
	size2--;
	int * array_final=malloc((size+size2)*sizeof(int));
	int cont=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size2;j++){
			if(list1[i]<=list2[j]){
				array_final[cont]=list1[i];
				remove_element(&list1,size,i);
				i--;
				size--;
				cont++;
				break;
			}
			else{
				array_final[cont]=list2[j];
				remove_element(&list2,size2,j);
				j--;
				size2--;
				cont++;
			}
		}
	}
	if(size==0){
		array_final[cont]=list1[0];
}
else{
	array_final[cont]=list2[0];
}
for(int i=0;i<size+size2;i++){
	printf("%d",array_final[i]);
	printf("         ------------\n");
}
printf(":::::::::::::::::::NEW FINAL:::::::::::::::::::::\n");
return 0;
}

int * divide(int * list,int size){
	//7
	int res=size/2;//3.5
	int val1=trunc(res);//3
	int val2=size-val1;//7-3=4
	int lista1[val1];
	int lista2[val2];
	int active_merge1=0;
	int active_merge2=0;
	if(val1==1){
		active_merge1=1;
	}
	if(val2==1){
		active_merge2=1;
	}
	//int * lista1=malloc(val1*sizeof(int));
	//int * lista2=malloc(val2*sizeof(int));

	memmove(lista1,list,(val1)*sizeof(int));
	memmove(lista2,list+val1,(size-val1)*sizeof(int));
	for(int i=0;i<val1;i++){
		//lista1[i]=list[i];
		//printf("%d %d\n",i,lista1[i]);
	}
	if(active_merge1==0){
		divide(lista1,val1);
	}
	for(int i=val1;i<size;i++){
		//lista2[i-val1]=list[i];
		//printf("%d %d\n",i-val1,lista2[i-val1]);
	}
	if(active_merge2==0){
		divide(lista2,val2);
	}
	merge_sort(lista1,lista2,val1,val2);
	return 0;
}
int main(){
	int ejemp[8]={6,5,2,9,10,8,1,7};
	int size_r=sizeof(ejemp)/sizeof(int);//cambiar por leer fichero
	int * a=malloc(size_r*sizeof(int));
	for(int i=0;i<size_r;i++){
		a[i]=ejemp[i];
	}
	divide(ejemp,size_r);
	return 0;
}