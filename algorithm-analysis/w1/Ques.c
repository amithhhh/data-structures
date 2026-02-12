#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int*, int);
void plot_graph(double*, double*);
void selection_sort(int*, int);
int main() {
	int i = 10000, k = 0;
	srand(time(NULL));
	double *time_taken = (double *) malloc(sizeof(double) * 11);
	double *stime_taken = (double *) malloc(sizeof(double) * 11);
	while (i <= 100000) {
		printf("-----------------------------------------------------------\n");
		int *arr = (int *) malloc(i * sizeof(int));
		int *sarr = (int *) malloc(i * sizeof(int));
		for (int j = 0; j < i; j++) {
			int num = rand();
			arr[j] = num;
			sarr[j] = num;
		}
		clock_t start = clock();
		bubble_sort(arr, i);
		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC;
		time_taken[k] = time; 
		printf("Size: %d  Time(Bubble sort): %f seconds\n", i, time);
		clock_t s_start = clock();
                selection_sort(sarr, i);  
                clock_t s_end = clock();
                double s_time = (double)(s_end - s_start) / CLOCKS_PER_SEC;
                stime_taken[k] = s_time;
		printf("Size: %d  Time(Selection sort): %f seconds\n", i, s_time);
		k++; 
		free(arr);
		free(sarr);
		i += 10000;
		printf("-----------------------------------------------------------\n");
	}
	plot_graph(time_taken, stime_taken);
	return 0;
}

void bubble_sort(int *a, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

			}
		}
	}
}

void plot_graph(double *bubble, double *selection) {
	int x = 10000;
	FILE *gnuplot = popen("gnuplot -persistent", "w");
	fprintf(gnuplot,
        "set title 'Bubble Sort vs Selection Sort'\n"
        "set xlabel 'Input Size'\n"
        "set ylabel 'Time (seconds)'\n"
        "plot '-' with lines title 'Bubble Sort', "
        "'-' with lines title 'Selection Sort'\n"
    	);
	for (int i = 0; i <= 10; i++, x += 10000) {
		fprintf(gnuplot, "%d %f\n", x, bubble[i]);
	}
	fprintf(gnuplot, "e\n");
	x = 10000;
	for (int i = 0; i <= 10; i++, x += 10000) {
                fprintf(gnuplot, "%d %f\n", x, selection[i]);
        }
	fprintf(gnuplot, "e\n");
	fflush(gnuplot);
	pclose(gnuplot);
}

void selection_sort(int *a, int size) {
	for (int i = 0; i < size; i++) {
		int min = a[i];
		int pos = i;
		for (int j = i; j < size; j++) {
			if (a[j] < min) {
				min = a[j];
				pos = j;
			}
		}
		int temp = a[i];
		a[i] = a[pos];
		a[pos] = temp;

	}
}
