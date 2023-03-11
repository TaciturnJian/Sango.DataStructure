#pragma once

#include "Sango.Math.CodeHelper.h"

Number GetFunctionPX(Number *a, int count, Number x) {
	Number sum = a[0],
		x_times = x;

	for (int i = 1; i < count; i ++) {
		sum += a[i] * x_times;
		x_times *= x;
	}

	return sum;
}