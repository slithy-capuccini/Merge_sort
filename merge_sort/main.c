//merge sort leido de un fichero de texto que tiene dos lineas la primera es un numero q es el numero
//de elementos de la lista y el segundo los numeros separados por espacios
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
int remove_element(int** array, int sizeOfArray, int indexToRemove)
{
    int* temp = malloc((sizeOfArray - 1) * sizeof(int)); // allocate an array with a size 1 less than the current one
    memmove(temp,*array,(indexToRemove+1)*sizeof(int)); // copy everything BEFORE the index
    memmove(temp+indexToRemove,(*array)+(indexToRemove+1),(sizeOfArray - indexToRemove)*sizeof(int)); // copy everything AFTER the inde
    free (*array);
    *array = temp;
    return 0;

}
*/
int * merge_sort(int * list1, int *list2, int size, int size2){
	int * array_final=malloc((size+size2)*sizeof(int));
	int cont=0;
	int last_j=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size2;j++){
            if(list1[i]<0){
				array_final[cont]=list1[i];
                list2[last_j]=100000000;
				cont++;
				break;
            }
            if(list2[last_j]<0){
				array_final[cont]=list1[i];
                list1[i]=100000000;
				cont++;
				break;
            }
            /*if(last_j=size2){
                break;
            }*/
			if(list1[i]<=list2[last_j]){
				array_final[cont]=list1[i];
                list1[i]=100000000;
				cont++;
				break;
			}
			else{
                array_final[cont]=list2[last_j];
                list2[last_j]=100000000;
                cont++;
                last_j++;
                for(int k=last_j;k<size2-last_j;k++){
                    if(list2[k]<=list1[i]){
                        array_final[cont]=list2[k];
                        list2[k]=100000000;
                        cont++;
                        last_j++;
                    }
                }
			}
		}
	}
    for(int l=0;l<size;l++){
        if(list1[l]!=100000000){
            array_final[cont]=list1[l];
        }
    }
    for(int l=0;l<size2;l++){
        if(list2[l]!=100000000){
            array_final[cont]=list2[l];
        }
    }
	for(int i=0;i<size+size2;i++){
        if(array_final[i]!=0){
            printf("%d",array_final[i]);
		    printf("         ------------\n");
        }
	}
	free(array_final);
	printf(":::::::::::::::::::NEW FINAL:::::::::::::::::::::\n");
	return array_final;
}

int * divide(int * list,int size){
	//7
	int res=size/2;//3.5
	int val1=trunc(res);//3
	int val2=size-val1;//7-3=4
    int * lista1=malloc(val1*sizeof(int));
	int * lista2=malloc(val2*sizeof(int));
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
		lista1=divide(lista1,val1);
	}
	if(active_merge2==0){
		lista2=divide(lista2,val2);
	}
	return merge_sort(lista1,lista2, val1,val2);;
}
int main(){
	int ejemp[8]={6,5,2,19,16,7,1,8};
	int size_r=sizeof(ejemp)/sizeof(int);//cambiar por leer fichero
	int * a=malloc(size_r*sizeof(int));
	for(int i=0;i<size_r;i++){
		a[i]=ejemp[i];
	}
	divide(ejemp,size_r);
	return 0;
}
