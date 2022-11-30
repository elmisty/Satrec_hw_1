#include "manage.h"

int main(void) {
    StudentInfo *foundNode = NULL;
    unsigned int ui_ret_stnum = 0;
    setInit();
    setAppend(1234, "munseokjoo", 국어, 100);
    setAppend(4567, "kimtangtang", 영어, 95);
    setAppend(8910, "leegungun", 수학, 94);
    setAppend(8981, "parkgeunman", 사회, 85);
    getShowAll();

    foundNode = getNode(8981);
    printf("FOUND! : %s\r\n", foundNode->c_stu_name);
    ui_ret_stnum = setDelete(foundNode);
    printf("DELETE! : %d\r\n", ui_ret_stnum);
    getShowAll();

    return 0;
}