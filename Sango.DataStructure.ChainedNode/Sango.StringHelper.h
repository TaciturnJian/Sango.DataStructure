#pragma once

char fitString(char *a, char *b, int length) {
    while (length-- > 0) {
        if (*a != *b) {
            return 0;
        }
        else if (*a == 0) {
            return 1;
        }

        a++;
        b++;
    }

    return 1;
}

/// <summary>
/// �����ܹ��ɵ�����Ĵ�
/// </summary>
/// <param name="input">�ṩ���ַ���Ŀ</param>
/// <returns>malloc������ڴ棬������free</returns>
char *makeLongestString(const char *input) {
    int length = 0;
    int total[128] = { 0 };                //���ÿ���ַ�������������

    while (*input != 0) {
        total[*input]++;
        input++;
        length++;
    }

#ifdef SANGO_DEBUG
    for (int i = 0; i < 128; i++) {
        printf("%d ", total[i]);
    }
#endif

    char *result = SangoMallocN(char, length+1);
    ReturnXWhenNullPointer(0, result);
    int result_index = 0;

    char �����һ�������ַ� = -1;
    for (int i = 0; i < 128; i++) {
        int count = total[i];
        for (int j = 0; j < count / 2; j++) {
            result[result_index] = i;
            result_index++;
        }

        if (total[i] % 2 == 1) {
            �����һ�������ַ� = i;
        }
    }

    int left_copy_index = result_index - 1;
    if (�����һ�������ַ� != -1) {
        result[result_index] = �����һ�������ַ�;
        result_index++;
    }

    for (; left_copy_index >= 0; result_index++,left_copy_index--) {
        result[result_index] = result[left_copy_index];
    }

    result[result_index] = 0;

    return result;
}
