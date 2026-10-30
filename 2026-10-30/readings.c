#include "readings.h"

struct Reading add_readings(struct Reading a, struct Reading b) {
	a.temp += b.temp;
	return a;
}

void print_readings(const struct Reading arr[], int length) {
	for (int i = 0; i < length; i++) {
		struct Reading curr = arr[i];
		printf("%d:\t%d\tdegrees %c\n", curr.id, curr.temp, curr.unit);
	}
}

int readings_to_arr(FILE* in, struct Reading arr[], int length) {
	int status, i=0;
	struct Reading curr;
	while ( (status = fscanf(in, "%d %d %c",
			&curr.id, &curr.temp, &curr.unit)) == 3
			&& i < length ) {
		arr[i] = curr;
		i++;
	}
	
	if ( (status != EOF && i != length) || ferror(in) ) {
		return 0;
	}
	
	return 1;
}