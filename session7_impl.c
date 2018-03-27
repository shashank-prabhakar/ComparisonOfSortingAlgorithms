#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "session7_sort.h"

long int InsertionSort(Record* A, int n)
{
    int i, j;
    Record temp;
    long int comparisons = 0;
	
	for(i = 1;i<n;i++) 
    {
		temp.serialnumber = A[i].serialnumber;
		temp.score = A[i].score;
		j = i - 1;
		
		while(j >= 0 && ((++comparisons) && A[j].serialnumber > temp.serialnumber))
        {
			A[j+1].serialnumber = A[j].serialnumber;
			A[j+1].score = A[j].score;
			j = j - 1;
		}
		A[j+1].serialnumber = temp.serialnumber;
		A[j+1].score = temp.score;
	}
	
	return comparisons;
}


long int BubbleSort(Record* A, int n) 
{
	int i, j, noSwaps;
    Record temp;
	long int comparisons = 0;
	
	for(i=0; i<n-1; i++) 
    {

		for (j=0; j<=(n-2-i); j++) 
        {
			noSwaps = 1;
			if(++comparisons && A[j].serialnumber > A[j+1].serialnumber) 
            {
				temp.serialnumber = A[j].serialnumber;
				temp.score = A[j].score;
				A[j].serialnumber = A[j+1].serialnumber;
				A[j].score = A[j+1].score;
				A[j+1].serialnumber = temp.serialnumber;
				A[j+1].score = temp.score;
			    noSwaps = 0;
				
			}
			
		}
		if(noSwaps == 1) return comparisons;
		
	}	
	
	return comparisons;
}



long int SelectionSort(Record* A, int n) 
{
	int i, j, min;
    Record temp;
	long int comparisons = 0;
	
	for(i=0; i<n-1; i++)
	{

		min = i;
		for (j=i+1; j<n ; j++)
		{
			if(A[j].serialnumber < A[min].serialnumber)
			{
				min = j;
				
			}
			comparisons = comparisons + 1;
		}
		
		temp.serialnumber = A[i].serialnumber;
		temp.score = A[i].score;
		A[i].serialnumber = A[min].serialnumber;
		A[i].score = A[min].score;
		A[min].serialnumber = temp.serialnumber;
		A[min].score = temp.score;
	
	}
	
	return comparisons;
}


long int Merge(Record *A, int n, int m) 
{ 
	int i = 0, j = m, k = 0;
	static long int comparisons = 0;
	Record *B;
	
	B = (Record*)malloc(sizeof(Record) * n);
	
	while(i < m && j < n) 
    {
		
		if(++(comparisons) && (A[i].serialnumber <= A[j].serialnumber)) 
        {
			B[k].serialnumber = A[i].serialnumber;
			B[k].score = A[i].score;
			i = i+1;
			
		}
		
		else 
        {
			B[k].serialnumber = A[j].serialnumber;
			B[k].score = A[j].score;
			j = j+1;
		}
		k = k+1;
	}
	
	if(j == n) 
    {
		while(i <= m-1 && k <= n-1) 
        {
			B[k].score = A[i].score;
			B[k].serialnumber = A[i].serialnumber;
			k = k + 1;
			i = i + 1;
		}
	}
	
	else 
    {
		while(j <= n-1 && k <= n-1) 
        {
			B[k].score = A[j].score;
			B[k].serialnumber = A[j].serialnumber;
			k = k + 1;
			j = j + 1;
		}
	}

	for(int l=0; l<n; l++) 
    {
		A[l].score = B[l].score;
		A[l].serialnumber = B[l].serialnumber;
	}
	free(B);
	
	return comparisons;
}

long int MergeSort(Record* A, int n) 
{
	int m;
	long int result_comp = 0;
	
	if(n <= 1) return result_comp;
	
	m = n / 2;
	
	MergeSort(&A[0], m);
	MergeSort(&A[m], n-m);
	
	result_comp = Merge(A, n, m);
	
	return(result_comp);
}



void swap(Record* A, int x, int y) 
{
	Record *temp;//Temporary structure for swapping the records.
	
	temp = (Record*)malloc(sizeof(Record) * 1);
	
	temp[0].score = A[x].score;
	temp[0].serialnumber = A[x].serialnumber;

	A[x].score = A[y].score;
	A[x].serialnumber = A[y].serialnumber;

	A[y].score = temp[0].score;
	A[y].serialnumber = temp[0].serialnumber;

	
	free(temp);

	return;
}

void median_of_three(Record * Arr, int length) 
{
	int first_pos  = 0;
    int middle_pos = length % 2 ? length / 2 : (length / 2 - 1);//If 'len' is 'even', mid = len/2, otherwise mid = (len/2)-1(floor)
    int last_pos   = length - 1;

    int first  = Arr[first_pos].serialnumber;
    int middle = Arr[middle_pos].serialnumber;
    int last   = Arr[last_pos].serialnumber;
	
	if(middle < first) swap(Arr, first_pos, middle_pos);
	if(last < first) swap(Arr, last_pos, first_pos);
	if(last < middle) swap(Arr, last_pos, middle_pos);
	swap(Arr, middle_pos, first_pos);
	
	return;
}




int Partition(Record * Arr, Record * C, int n) 
{
		median_of_three(Arr, n);
				
		int p;//Pivot element
		int i, j;
		p = Arr[0].serialnumber;//Making first element as the pivot
		i = 1;//Beginning to end index pointer
		j = n - 1;//End to beginning index pointer
	
		while(i <= j) {
	
			//Loops until it finds the "serialnumber", greater than the pivot.
			while(i <= j && (++(C[0].serialnumber) && Arr[i].serialnumber <= p)) {
				i = i + 1;
				//qs_comp += 1;
				//res_arr[0].serialnumber += 1;
			}
			//qs_comp += 1;
			
			//Loops until it finds the "serialnumber", lesser than the pivot.
			while(i <= j && (++(C[0].serialnumber) && Arr[j].serialnumber >= p)) 
			{
				j = j - 1;
			}
		
			//When both i and j encountered a large and small id's respectively, then swap takes place among the id's.  
			if(i < j) 
			{
				swap(Arr, i, j);
				i = i + 1;
				j = j - 1;
			}
		
		}
	
		//When both i and j get inter-changed(i.e., cross-over), id at j is swapped with the pivot id.
		swap(Arr, 0, j);
		return j;
}

Record* QuickS(Record *A, Record *C, int n) 
{
	int s;
	//static long int res = 0;
	
	if(n <= 1) {
		//res= Partition(A, INT_MAX);
		return C;
	}
	s = Partition(A, C, n);
	C = QuickS(A, C, s);
	C = QuickS(&A[s+1], C,  n - s - 1);//(n-s"-1") because the element at the s position is in its sorted place all the time.
	
	//Alternate
	//res = Partition(A, INT_MAX);
	
	return C;
	//free(s_arr);
	
}

long int QuickSort(Record* A, int n) 
{
	Record *comp_arr, *res_ds;
	long int res_var;
	
	comp_arr = (Record*)malloc(sizeof(Record) * 1);
	comp_arr[0].serialnumber = 0;
	res_ds = QuickS(A, comp_arr, n);
	res_var = res_ds[0].serialnumber;
	free(comp_arr);
	return res_var;
}










