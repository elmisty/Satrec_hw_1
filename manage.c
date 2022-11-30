#include "manage.h"

void setInit() {
    sptr_head = NULL;
    sptr_tail = NULL;
}

int setAppend(INFO_ARGUMENT) {
    StudentInfo *sptr_tmp_stuinfo = (StudentInfo *)malloc(sizeof(StudentInfo));

    sptr_tmp_stuinfo->ui_stu_num  = ui_num;
    memcpy(sptr_tmp_stuinfo->c_stu_name, c_name, MAX_LEN);
    sptr_tmp_stuinfo->ui_subject  = ui_subject;
    sptr_tmp_stuinfo->ui_score    = ui_score;

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

    return 0;
}

int setDelete(StudentInfo *sptr_tmp) {
    StudentInfo *sptr_tmp_prev = sptr_tmp->ptr_prev;
    unsigned int ui_ret_stnum = sptr_tmp->ui_stu_num;

    if (sptr_tmp == sptr_head && sptr_tmp == sptr_tail) {
        sptr_head = NULL;
        sptr_tail = NULL;
    }
    else if (sptr_tmp == sptr_tail) {
        sptr_tail = sptr_tmp->ptr_prev;
        sptr_tail->ptr_next = NULL;
    }
    else if (sptr_tmp == sptr_head) {
        sptr_head = sptr_head->ptr_next;
        sptr_head->ptr_prev = NULL;
    }
    else {
        sptr_tmp_prev->ptr_next = sptr_tmp->ptr_next;
        sptr_tmp->ptr_next->ptr_prev = sptr_tmp->ptr_prev;
    }

    return ui_ret_stnum;
}

StudentInfo *getNode(int ui_stu_num) {
    StudentInfo *sptr_tmp = sptr_head;

    while(sptr_tmp != NULL) {
        if(sptr_tmp->ui_stu_num) {
            return sptr_tmp;
        }
        sptr_tmp = sptr_tmp->ptr_next;
    }
    return NULL;
}

void getShowAll()
{
    int i = 0;
    int s = 0;

    StudentInfo *ptr_Stu = sptr_head;

    while(ptr_Stu != NULL) {
        printf("%4d %2d %10s\r\n", ptr_Stu->ui_stu_num, ptr_Stu->ui_subject, ptr_Stu->c_stu_name);
        ptr_Stu = ptr_Stu->ptr_next;
    }
    printf("\n");
}