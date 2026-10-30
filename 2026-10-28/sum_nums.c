#include "stdio.h"


int main(void) {
	// Read numbers.txt, process it
	FILE* in = fopen("numbers.txt", "r");
	if (in == NULL) {
		printf("Failed to open numbers.txt\n");
		return 1;
	}
	
	int count = 0, total = 0, status, value;
	while ( (status = fscanf(in, "%d", &value)) == 1 ) {
		total += value;
		count++;
	}
	if ( status != EOF || ferror(in) ) {
		printf("Reading numbers.txt failed\n");
		return 1;
	}
	
	float avg = (float)total / count;
	
	//printf("%d\n%.2f\n", total, avg); // Testing
	
	status = fclose(in);
	if (status == EOF) {
		printf("Failed to close numbers.txt\n");
		return 1;
	}
	
	// Write to report.txt the results
	FILE* out = fopen("report.txt", "w");
	if (out == NULL) {
		printf("Failed to open report.txt\n");
		return 1;
	}
	
	int written = fprintf(out, "Total: %d\nAverage: %.2f\n", total, avg);
	status = fclose(out);
	if (written < 0) {
		printf("Failed to write to report.txt\n");
		return 1;
	}
	if (status == EOF) {
		printf("Failed to close report.txt\n");
		return 1;
	}
	
	printf("Success!\n");
	return 0;
}