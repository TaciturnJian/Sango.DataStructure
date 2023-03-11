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
