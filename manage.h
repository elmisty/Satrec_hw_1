#ifndef __MANAGE_H__
#define __MANAGE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stddef.h>

#define MAX_LEN     32
#define MAX_SUB     12

/*
    Subject info
*/
enum subject {
    국어 = 0,
    영어,
    수학,
    과학,
    사회,
    역사,
    중국어,
    일본어,
    한문,
    음악,
    미술,
    체육,
    기술가정,
    도덕,
    정보
};

/*
    Student information
*/
struct _StudentInfo {
    unsigned int   ui_stu_num; // primary key
    char           c_stu_name[MAX_LEN + 1];
    unsigned int   ui_subject;
    unsigned int   ui_score;

    struct _StudentInfo *ptr_next;
    struct _StudentInfo *ptr_prev;
};
typedef struct _StudentInfo StudentInfo;

#define INFO_ARGUMENT   unsigned int ui_num, char *c_name, unsigned int ui_subject, unsigned int ui_score
#define INFO_MALLOC     (StudentInfo *)malloc(sizeof(StudentInfo))

StudentInfo *sptr_head, *sptr_tail;

void setInit();
int setAddStuInfo(int i_num, char* c_name, int i_score);
int setAppend(INFO_ARGUMENT);
int setDelete(StudentInfo *sptr_tmp);
StudentInfo *getNode(int ui_stu_num);
void getShowAll();


#endif