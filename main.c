#include "manage.h"

int main(void) {
    setInit();
    printf("WTF?");
    setAppend(1234, "munseokjoo", 100);
    setAppend(4567, "kimtangtang", 95);
    setAppend(8910, "leegungun", 94);
    getShowAll();

    return 0;
}