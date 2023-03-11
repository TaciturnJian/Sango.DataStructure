#include "Sango.CodeHelper.h"
#include "Sango.StringHelper.h"

#include "Sango.LinearList.h"

int reverse(int x) {
    double t = 0;
    while (x != 0) {
        t *= 10;
        t += x % 10;
        x /= 10;
    }

    printf("%lf ", t);
    if (t > 0x7fffffffu - 1 || t < -0x7fffffff) {
        return 0;
    }

    return (int)t;
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

int main() {

    LinearListPointer p = CreateLinearList(10);

    int t = 12;
    AppendCopiedElementIntoLinearList(p, &t);
    t -= 1;
    AppendCopiedElementIntoLinearList(p, &t);
    t += 10;
    AppendCopiedElementIntoLinearList(p, &t);
    t -= 333;
    AppendCopiedElementIntoLinearList(p, &t);


    ForEachElementInLinearList(p, printElement); putchar('\n');
    SortLinearList(p, compare);
    ForEachElementInLinearList(p, printElement); putchar('\n');
}

