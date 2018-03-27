#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "session7_sort.h"


double time_elapsed(struct timespec *start, struct timespec *end);

int main(int argc, char const *argv[])
{
    struct timespec start, end;
	Record *arr, *arrcopy;
	int n, i, j;
	long int insert_comp, bubble_comp, selec_comp, merge_comp, quick_comp = 0;
	double insert_time,bubble_time,selec_time,merge_time,quick_time;

    scanf("%d",&n); //input the size



    arr = (Record*)malloc(sizeof(Record) * n);
	arrcopy = (Record*)malloc(sizeof(Record) * n);

    //INSERTION SORT
    for(i=0; i<n; i++)
		scanf("%ld %d", &(arr[i].serialnumber), &(arr[i].score));
	
	for(j=0; j<n; j++) 
	{
		arrcopy[j].serialnumber = arr[j].serialnumber;
		arrcopy[j].score = arr[j].score;
	}
	clock_gettime(CLOCK_REALTIME, &start);
	insert_comp = InsertionSort(arrcopy, n);
	clock_gettime(CLOCK_REALTIME, &end);
	insert_time = time_elapsed(&start, &end);



    //BUBBLE SORT
    //for(i=0; i<n; i++)
		//scanf("%ld %d", &(arr[i].serialnumber), &(arr[i].score));
	
	for(j=0; j<n; j++) 
	{
		arrcopy[j].serialnumber = arr[j].serialnumber;
		arrcopy[j].score = arr[j].score;
	}
	clock_gettime(CLOCK_REALTIME, &start);
	bubble_comp = BubbleSort(arrcopy, n);
	clock_gettime(CLOCK_REALTIME, &end);
	bubble_time = time_elapsed(&start, &end);


    //SELECTION SORT
    //for(i=0; i<n; i++)
		//scanf("%ld %d", &(arr[i].serialnumber), &(arr[i].score));
	
	for(j=0; j<n; j++) 
	{
		arrcopy[j].serialnumber = arr[j].serialnumber;
		arrcopy[j].score = arr[j].score;
	}
	clock_gettime(CLOCK_REALTIME, &start);
	selec_comp = SelectionSort(arrcopy, n);
	clock_gettime(CLOCK_REALTIME, &end);
	selec_time = time_elapsed(&start, &end);



    //MERGE SORT
    //for(i=0; i<n; i++)
		//scanf("%ld %d", &(arr[i].serialnumber), &(arr[i].score));
	
	for(j=0; j<n; j++) 
	{
		arrcopy[j].serialnumber = arr[j].serialnumber;
		arrcopy[j].score = arr[j].score;
	}
	clock_gettime(CLOCK_REALTIME, &start);
	merge_comp = MergeSort(arrcopy, n);
	clock_gettime(CLOCK_REALTIME, &end);
	merge_time = time_elapsed(&start, &end);

    //QUICK SORT!!!!!!!!!!!!!!

	/*for(i=0; i<n; i++)
		scanf("%ld %d", &(arr[i].serialnumber), &(arr[i].score));
	
	for(j=0; j<n; j++) 
	{
		arrcopy[j].serialnumber = arr[j].serialnumber;
		arrcopy[j].score = arr[j].score;
	}*/
	clock_gettime(CLOCK_REALTIME, &start);
	quick_comp = QuickSort(arr, n);
	clock_gettime(CLOCK_REALTIME, &end);
	quick_time = time_elapsed(&start, &end);

	printf("\n\n");
    printf("Insertion Sort: %ld comparisons, %lf seconds\n", insert_comp, insert_time);
	printf("Bubble Sort: %ld comparisons, %lf seconds\n", bubble_comp, bubble_time);
	printf("Selection Sort: %ld comparisons, %lf seconds\n", selec_comp, selec_time);
	printf("Merge Sort: %ld comparisons, %lf seconds\n", merge_comp, merge_time);
	printf("Quick Sort: %ld comparisons, %lf seconds\n", quick_comp, quick_time);
	printf("\n\n");


	free(arrcopy);
	free(arr);

	return 0;
}



double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	//tv_sec has the time elasped in seconds
	t = (end->tv_sec - start->tv_sec);
	//tv_nsec has the time elasped in nano seconds
	//Final time will be precise with nano seconds
	t += ((end->tv_nsec - start->tv_nsec) * 0.000000001);
	return t;
}