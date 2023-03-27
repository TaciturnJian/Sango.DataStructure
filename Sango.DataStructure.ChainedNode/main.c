#include <stdio.h>

#include "Sango.LinearList.Extension.h"
#include "Sango.StringHelper.h"
#include "约瑟夫环.h"

int reverse(int x) {
    double t = 0;
    while (x != 0) {
        t *= 10;
        t += x % 10;
        x /= 10;
    }

    return (int)t == t? (int)t : 0;
}

CompareResult compare(ElementPointer a, ElementPointer b) {
    if (*a > *b) {
        return MORE;
    }
    else if (*a == *b) {
        return EQUAL;
    }
    else {
        return LESS;
    }
}

void printElement(ElementPointer e) {
    printf("%d ", *e);
}

#define TEST(str) {char* result = makeLongestString(str);printf(">>%s\n: %s\n",str,result);free(result);}

int main() {
    TEST("aaabbbcccdddedg");
    TEST("jjkkiiuuuutttttdgfwwe");

    LinearListPointer p = CreateLinearList(1000);

    int a[10] = { 3,1,7,2,4,8,4 };
    约瑟夫环(a, 7);

    int t;
    for (int i = 0; i < 999; i++) {
        t = (i * 73 / 3 + i * 23 / 2) % 100;
        AppendCopiedElementIntoLinearList(p, &t);
    }

    ForEachElementInLinearList(p, printElement); putchar('\n');
    SortLinearList(p, compare);
    ForEachElementInLinearList(p, printElement); putchar('\n');
}

