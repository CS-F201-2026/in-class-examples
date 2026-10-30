#include <stdio.h>

int main(void) {
	FILE* in = fopen("note.txt", "r");
	if (in == NULL) {
		fprintf(stderr, "Could not read file.\n");
		return 1;
	}
	
	// Invariant: We have a valid file stream in
	int chars = 0, newlines = 0;
	int ch;
	while ( (ch = fgetc(in)) != EOF ) {
		// Invariant: We have a character in ch
		chars++;
		if (ch == '\n') newlines++;
	}
	
	// Invariant: ch == EOF
	int read_failed =  ferror(in);
	int close_failed = fclose(in) == EOF;
	if (read_failed || close_failed) {
		fprintf(stderr, "Could not properly finish.\n");
		return 1;
	}
	
	printf("Chars: %d\tNewlines: %d\n", chars, newlines);
	
	return 0;
}