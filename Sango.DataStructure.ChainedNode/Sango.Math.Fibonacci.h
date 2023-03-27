#pragma once

#include "Sango.Math.CodeHelper.h"

typedef int(*IntPointer);

/// <summary>
/// k阶斐波那契数列第n项(定义k阶：前k-1项为0，第k项为1，之后每一项都等于前k项之和) 
/// T(n) = O(xk)
/// S(n) = O(k)
/// </summary>
/// <param name="x"></param>
/// <param name="k"></param>
/// <returns></returns>
Number GetKStepFibonacci(int x, int k) {
	if (x < k - 1 || k < 1) {
		return 0;
	}

	Number *window = SangoMallocN(Number, k);			//拿一个窗口
	ReturnXWhenNullPointer(-1, window);
	for (int i = 0; i < k - 1; i++) {					//置0
		window[i] = 0;
	}
	window[k - 1] = 1;									//置1

	for (int i = 0; i < x - k + 1; i++) {
		int window_sum = 0;								//开始滑动
		for (int j = 0; j < k; j++) {
			window_sum += window[j];
		}
		window[i % k] = window_sum;						//这里Visual Studio不知为何，报错力！但是代码运行起来没问题
	}

	Number result = window[x % k];
	free(window);
	return result;
}

