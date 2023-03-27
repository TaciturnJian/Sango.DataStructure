#pragma once

#include "Sango.Math.CodeHelper.h"

typedef int(*IntPointer);

/// <summary>
/// k��쳲��������е�n��(����k�ף�ǰk-1��Ϊ0����k��Ϊ1��֮��ÿһ�����ǰk��֮��) 
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

	Number *window = SangoMallocN(Number, k);			//��һ������
	ReturnXWhenNullPointer(-1, window);
	for (int i = 0; i < k - 1; i++) {					//��0
		window[i] = 0;
	}
	window[k - 1] = 1;									//��1

	for (int i = 0; i < x - k + 1; i++) {
		int window_sum = 0;								//��ʼ����
		for (int j = 0; j < k; j++) {
			window_sum += window[j];
		}
		window[i % k] = window_sum;						//����Visual Studio��֪Ϊ�Σ������������Ǵ�����������û����
	}

	Number result = window[x % k];
	free(window);
	return result;
}

