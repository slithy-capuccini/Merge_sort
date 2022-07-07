//merge sort leido de un fichero de texto que tiene dos lineas la primera es un numero q es el numero
//de elementos de la lista y el segundo los numeros separados por espacios
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<assert.h>
#include<time.h>
int remove_element(int** array, int sizeOfArray, int indexToRemove)
{
    int* temp = malloc((sizeOfArray - 1) * sizeof(int)); // allocate an array with a size 1 less than the current one
    memmove(temp,*array,(indexToRemove+1)*sizeof(int)); // copy everything BEFORE the index
    memmove(temp+indexToRemove,(*array)+(indexToRemove+1),(sizeOfArray - indexToRemove)*sizeof(int)); // copy everything AFTER the inde
    free (*array);
    *array = temp;
    return 0;

}
int * merge_sort(int * list1, int *list2, int size, int size2){
	int * array_final=malloc((size+size2)*sizeof(int));
	int cont=0;
	int last_j=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size2;j++){
            if(last_j==size2+1){
                array_final[cont]=list1[i];
                break;
            }
            if( list1[i]==0 || list2[last_j]==0){
                break;
            }
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
                //printf("1-%d es menor o igual que %d y ocupa la pos %d\n",list1[i],list2[last_j],cont);
				array_final[cont]=list1[i];
                list1[i]=100;
				cont++;
				break;
			}
			else{
                //printf("2-%d es menor o igual que %d y ocupa la pos %d\n",list2[last_j],list1[i],cont);
                array_final[cont]=list2[last_j];
                list2[last_j]=100;
                cont++;
                last_j++;
                for(int k=last_j;k<size2-last_j;k++){
                    //printf("3-%d es menor o igual que %d y ocupa la pos %d\n",list2[k],list1[i],cont);
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
    for(int u=0;u<size;u++){
        if(list1[u]!=100){
            array_final[cont]=list1[u];
            cont++;
        } 
    }
    for(int l=0;l<size2;l++){
        if(list2[l]!=100){
            array_final[cont]=list2[l];
            cont++;
        } 
    }
	return array_final;
}
int maxValue(int myArray[], size_t size) {
    assert(myArray && size);
    size_t i;
    int maxValue = myArray[0];

    for (i = 1; i < size; ++i) {
        if ( myArray[i] > maxValue ) {
            maxValue = myArray[i];
        }
    }
    return maxValue;
}
int * divide(int * list,int size){
	int res=size/2;
	int val1=trunc(res);
	int val2=size-val1;
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
	memmove(lista1,list,(val1)*sizeof(int));
	memmove(lista2,list+val1,(size-val1)*sizeof(int));
	if(active_merge1==0){
		lista1=divide(lista1,val1);
	}
	if(active_merge2==0){
		lista2=divide(lista2,val2);
	}
	return merge_sort(lista1,lista2, val1,val2);;
}
int * read_file(){
    FILE *o=fopen("data.dat","r");
    int size;
    int i=0;
    int * ejemplo;
    char line[50];
    if((o=fopen("data.dat","r"))!=NULL)
    {
        fscanf(o,"%d",&size);
        int * ejemplo=malloc(size*sizeof(int)); 
        while (fgets(line, 50, o) != NULL) {
            const char delimiter[2] = ",";
            char* token = strtok(line, delimiter);
            while(token!=NULL){
                ejemplo[i]=atoi(token);
                token=strtok(NULL,delimiter);
                i++;
            }
        }

        return ejemplo;
    }
    fclose(o);
}
int main(){
    int size;
    FILE *o=fopen("data.dat","r");
    if((o=fopen("data.dat","r"))!=NULL)
    {
        fscanf(o,"%d",&size);
    }
    size++;
    int *a =read_file();
    remove_element(&a,size,0);
    size--;
    for(int i=0;i<size;i++){
        printf("%d %d\n",i, a[i]);
    }
	int * final_array=divide(a,size);
    printf(":::::::::::::::::::NEW FINAL:::::::::::::::::::::\n");
	for(int i=0;i<size;i++){
        if(final_array[i]!=0){
            printf("%d %d",i,final_array[i]);
		    printf("         ------------\n");
        }
	}
    return 0;
}