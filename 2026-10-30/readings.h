#ifndef READINGS_H
#define READINGS_H

#include "stdio.h"

struct Reading {
	int id;
	int temp;
	char unit;
};

// Add the temperatures of two readings
// Precondition: a.unit == b.unit
struct Reading add_readings(struct Reading a, struct Reading b);

void print_readings(const struct Reading arr[], int length);

// Precondition: in is not null
int readings_to_arr(FILE* in, struct Reading arr[], int length);

#endif