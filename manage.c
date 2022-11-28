#include "manage.h"

void setInit() {
    sptr_head = NULL;
    sptr_tail = NULL;
}

int setAppend(INFO_ARGUMENT) {
    StudentInfo *sptr_tmp_stuinfo = (StudentInfo *)malloc(sizeof(StudentInfo));

    sptr_tmp_stuinfo->i_stu_num  = i_num;
    memcpy(sptr_tmp_stuinfo->c_stu_name, c_name, MAX_LEN);
    sptr_tmp_stuinfo->i_score    = i_score;

    if(sptr_head == NULL && sptr_tail == NULL) {
        sptr_head = sptr_tmp_stuinfo;
        sptr_tail = sptr_tmp_stuinfo;
        sptr_tmp_stuinfo->ptr_next = NULL;
        sptr_tmp_stuinfo->ptr_prev = NULL;
    }
    else {
        sptr_tmp_stuinfo->ptr_prev = sptr_tail;
        sptr_tail->ptr_next = sptr_tmp_stuinfo;
        sptr_tail = sptr_tmp_stuinfo;
    };
}

void getShowAll()
{
    int i = 0;
    int s = 0;

    StudentInfo *ptr_Stu = sptr_head;
    printf("test\r\n");

    while(ptr_Stu != NULL) {
        printf("%4d %10s\r\n", ptr_Stu->i_stu_num, ptr_Stu->c_stu_name);
        ptr_Stu = ptr_Stu->ptr_next;
    }
    printf("\n");
}