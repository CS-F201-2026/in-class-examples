#include "readings.h"
#include "stdio.h"

#define NUM_READINGS 100

int main(void) {
	FILE* in = fopen("readings.txt", "r");
	if (in == NULL) {
		printf("Failed to open numbers.txt\n");
		return 1;
	}
	
	struct Reading readings[NUM_READINGS];
	if (!readings_to_arr(in, readings, NUM_READINGS)) {
		printf("Failed to print all readings\n");
		return 1;
	}
	
	int status = fclose(in);
	if (status == EOF) {
		printf("Failed to close readings.txt\n");
		return 1;
	}
	
	print_readings(readings, NUM_READINGS);
	
	return 0;
}