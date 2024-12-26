//
// Created by pilip on 2024/12/25.
//

#ifndef MARK_MANAGEMENT_LIST_H
#define MARK_MANAGEMENT_LIST_H

struct date{
    int year;
    char month[3];
    char day[3];
};

typedef struct St1 {
    char IDNumber[16];		    //学号
    char Name[16];			    //姓名
    char sex;				    //性别（f代表“女”，m代表“男”）
    struct date birthday ;		//生日
    float score[4];			    //四门课成绩
    float average;			    //平均分
    struct St1 *next;
} StudentNode;

// functions

StudentNode * iniStudentNode();
StudentNode * createNewNode(StudentNode tempNode, StudentNode * next);
int insertNode(StudentNode * head, int number, StudentNode tempNode);
int isListEmpty(StudentNode *head);
int listLength(StudentNode *head);
void clearList(StudentNode* head);
StudentNode * getNode(StudentNode * head,int num);
int popNode(StudentNode * head);
int shiftNode(StudentNode * head);
int deleteNode(StudentNode* head, int number);



#endif //MARK_MANAGEMENT_LIST_H
