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
/// 返回能构成的最长回文串
/// </summary>
/// <param name="input">提供的字符数目</param>
/// <returns>malloc申请的内存，由你来free</returns>
char *makeLongestString(const char *input) {
    int length = 0;
    int total[128] = { 0 };                //存放每个字符数出来的数量

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

    char 随意的一个奇数字符 = -1;
    for (int i = 0; i < 128; i++) {
        int count = total[i];
        for (int j = 0; j < count / 2; j++) {
            result[result_index] = i;
            result_index++;
        }

        if (total[i] % 2 == 1) {
            随意的一个奇数字符 = i;
        }
    }

    int left_copy_index = result_index - 1;
    if (随意的一个奇数字符 != -1) {
        result[result_index] = 随意的一个奇数字符;
        result_index++;
    }

    for (; left_copy_index >= 0; result_index++,left_copy_index--) {
        result[result_index] = result[left_copy_index];
    }

    result[result_index] = 0;

    return result;
}
