//merge sort leido de un fichero de texto que tiene dos lineas la primera es un numero q es el numero
//de elementos de la lista y el segundo los numeros separados por espacios
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int * merge_sort(int * list1, int *list2, int size, int size2){
	int * array_final=malloc((size+size2)*sizeof(int));
	int cont=0;
	int last_j=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size2;j++){
            if(list1[i]<0){
				array_final[cont]=list1[i];
                list2[last_j]=100;
				cont++;
				break;
            }
            if(list2[last_j]<0){
				array_final[cont]=list1[i];
                list1[i]=100;
				cont++;
				break;
            }
            /*if(last_j=size2){
                break;
            }*/
			if(list1[i]<=list2[last_j]){
				array_final[cont]=list1[i];
                list1[i]=100;
				cont++;
				break;
			}
			else{
                array_final[cont]=list2[last_j];
                list2[last_j]=100;
                cont++;
                last_j++;
                for(int k=last_j;k<size2-last_j;k++){
                    if(list2[k]<=list1[i]){
                        array_final[cont]=list2[k];
                        list2[k]=100;
                        cont++; 
                        last_j++;
                    }
                }
			}
		}
	}
    for(int l=0;l<size;l++){
        if(list1[l]!=100){
            array_final[cont]=list1[l];
        }
    }
    for(int l=0;l<size2;l++){
        if(list2[l]!=100){
            array_final[cont]=list2[l];
        } 
    }
	for(int i=0;i<size+size2;i++){
        if(array_final[i]!=0){
            printf("%d",array_final[i]);
		    printf("         ------------\n");
        }
	}
	printf(":::::::::::::::::::NEW FINAL:::::::::::::::::::::\n");
	return array_final;
}
int main(){
    int lista1[1]={5};
    int size=sizeof(lista1)/sizeof(lista1[0]);
    int lista2[1]={6};
    int size2=sizeof(lista2)/sizeof(lista2[0]);
    merge_sort(lista1,lista2,size,size2);
    return 0;
}