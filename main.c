#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **newArray(char **s, int n, int *len) {
	char** a = (char**)malloc(sizeof(char*) * n);
	int i;
	for(i = 0; i < n; i ++)
	{
		a[i] = (char*)malloc(sizeof(char)*(len[i]+1));
		int k = 0;
		while (k<len[i])
		{
			a[i][k] = s[i][k];
			k++;
		}
		a[i][k] = '\0';
	}
	return a;
}

void swap(char **str1, char **str2)
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void bubbleSort(char **s, int n){
    int i,j;

	for (i = 0 ; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(s[j], s[j + 1]) > 0){
                swap(&s[j], &s[j + 1]);
            }
        }
    }
}

void insertionSort(char **s, int n ){
    int i, j;
    char *x;
    for(i = 1; i < n; i ++){
        j = i;
        x = s[i];
        while ((j > 0) && (strcmp(x, s[j-1]) < 0)){
            s[j] = s[j - 1];
            j --;
        }
        s[j] = x;
    }
}

void quickSort(char **s, int len)
{
    int i, pvt=0;

    if (len <= 1)
        return;

    swap(s+((int)rand() % len), s+len-1);

    for (i=0;i<len-1;++i)
    {
        if (strcmp(s[i], s[len-1]) < 0)
            swap(s+i, s+pvt++);
    }

    swap(s+pvt, s+len-1);

    quickSort(s, pvt++);
    quickSort(s+pvt, len - pvt);
}


void merge(char **arr, int low, int mid, int high)
{
    int nL= mid-low+1;
    int nR= high-mid;

    char** L=malloc(sizeof(char *)*nL);
    char** R=malloc(sizeof(char *)*nR);
    int i, j, k;

    for (i = 0; i < nL; i++)
    {
        L[i] = arr[low+i];
    }

    for (j = 0; j < nR; j++)
    {
        R[j] = arr[mid+j+1];
    }

    i = 0;
    j = 0;
    k = low;

    while(i<nL&&j<nR)
    {
        if(strcmp(L[i],R[j])<0)
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i<nL)
    {
        arr[k++] = L[i++];
    }
    while (j<nR)
    {
        arr[k++] = R[j++];
    }
    free(L);
    free(R);
}

void mergeSort(char **arr,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(int argc, char** argv)
{
    const int n = atoi(argv[1]);
    char const* const fileName = argv[2];

    FILE* file = fopen (fileName, "r");

    int* len = (int*) malloc(sizeof(int) * n);

    int i;

    for (i=0; i<n; i++) {
        len[i] = 0;
    }

    i = 0;
    char c;

    while (((c = fgetc(file)) != EOF) && (i < n)) {
        if (c != '\n') {
            len[i]++;
        } else {
            i++;
        }
    }


    char** s = (char**) malloc(sizeof(char*) * n);
    rewind(file);


    for (i = 0; i < n; i++) {
        s[i] = (char*) malloc(sizeof(char) * (len[i]+1));

        int k = 0;

        while (((c = fgetc(file)) != '\n')&&(c != EOF)){
            s[i][k++] = c;
        }
        s[i][k] = '\0';
    }

    char **bubbleArray = newArray(s, n, len);
    char **insertionArray = newArray(s, n, len);
    char **quickArray = newArray(s, n, len);
    char **mergeArray = newArray(s, n, len);

    free(len);

    bubbleSort(bubbleArray, n);
    insertionSort(insertionArray, n);
    quickSort(quickArray, n);
    mergeSort(mergeArray, 0, n-1);

    printf("------Source array---------\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
    printf("----------------------\n");


    printf("------Bubble Sort---------\n");
    for( i = 0; i < n; i++ ) {
        printf("%s\n", bubbleArray[i]);
        free(bubbleArray[i]);
    }
    free(bubbleArray);
    printf("----------------------\n");

    printf("------Insertion Sort---------\n");
    for( i = 0; i < n; i++ ) {
        printf("%s\n", insertionArray[i]);
        free(insertionArray[i]);
    }
    free(insertionArray);
    printf("----------------------\n");


    printf("------Quick Sort---------\n");
    for( i = 0; i < n; i++ ) {
        printf("%s\n", quickArray[i]);
        free(quickArray[i]);
    }
    free(quickArray);
    printf("----------------------\n");


    printf("------Merge Sort---------\n");
    for( i = 0; i < n; i++ ) {
        printf("%s\n", mergeArray[i]);
        free(mergeArray[i]);
    }
    free(mergeArray);
    printf("----------------------\n");


    fclose(file);
    return 0;
}
