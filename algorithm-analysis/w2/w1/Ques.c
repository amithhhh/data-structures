#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binary_search(int*, int, int, int);
void plot_graph(double*, double*);
void linear_search(int*, int, int);
void selection_sort(int*, int);
int main() {
	int i = 10000, k = 0;
	double *time_taken = (double *) malloc(sizeof(double) * 100);
	double *stime_taken = (double *) malloc(sizeof(double) * 100);
	while (i <= 1000000) {
		printf("-----------------------------------------------------------\n");
		int *arr = (int *) malloc(i * sizeof(int));
		int *sarr = (int *) malloc(i * sizeof(int));
		for (int j = 0; j < i; j++) {
			arr[j] = j + 1;
			sarr[j] = j + 1;
		}
		clock_t start = clock();
		binary_search(arr, -1, 0, i - 1);
		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC;
		time_taken[k] = time; 
		printf("Size: %d  Time(Binary Search): %f seconds\n", i, time);
		clock_t s_start = clock();
                linear_search(sarr, i, -1);  
                clock_t s_end = clock();
                double s_time = (double)(s_end - s_start) / CLOCKS_PER_SEC;
                stime_taken[k] = s_time;
		printf("Size: %d  Time(Linear Search): %f seconds\n", i, s_time);
		k++; 
		free(arr);
		free(sarr);
		i += 10000;
		printf("-----------------------------------------------------------\n");
	}
	plot_graph(time_taken, stime_taken);
	return 0;
}

void linear_search(int *a, int size, int key) {
	for (int i = 0; i < size; i++) {
		if (a[i] == key) {
			return;
		}
	}
}

void binary_search(int *a, int key, int left, int right) {
	if (left > right) {
		return;
	} else {
		int mid = (left + right) / 2;
		if (a[mid] == key) {
			return;
		} else if (a[mid] < key) {
			binary_search(a, key, mid + 1, right);
		} else {
			binary_search(a, key, left, mid - 1);
		}
	}

}

void plot_graph(double *bubble, double *selection) {
	int x = 10000;
	FILE *gnuplot = popen("gnuplot -persistent", "w");
	fprintf(gnuplot,
        "set title 'Binary Search vs Linear Search'\n"
        "set xlabel 'Input Size'\n"
        "set ylabel 'Time (seconds)'\n"
        "plot '-' with lines title 'Binary Search', "
        "'-' with lines title 'Linear Search'\n"
    	);
	for (int i = 0; i <= 100; i++, x += 10000) {
		fprintf(gnuplot, "%d %f\n", x, bubble[i]);
	}
	fprintf(gnuplot, "e\n");
	x = 10000;
	for (int i = 0; i <= 100; i++, x += 10000) {
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
