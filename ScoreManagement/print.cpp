//
// Created by pilip on 2024/12/25.
//
#include "stdio.h"
#include "list.h"

extern StudentNode tempNode;

void printHead(){
    for(int i = 0;i < 18;i++)
        printf("\t");
    printf("成绩");
    printf("\n");
    printf("\t\t学号\t\t\t姓名\t\t\t");
    printf("性别\t出生日期\t\t");
    printf("程序\t高数\t物理\t外语\t");
    printf("平均分");
    printf("\n");
    fflush(stdout);

}

void printStudent(StudentNode * stu,int num){
    printf("%3d | \t",num);
    printf("%-15s\t",stu->IDNumber);
    printf("%-15s\t",stu->Name);
    switch(stu->sex){
        case 'f': printf("女\t\t");
        case 'm': printf("男\t\t");
    }
    printf("%4d-%2s-%2s\t",stu->birthday.year,stu->birthday.month,stu->birthday.day);
    for(int i = 0;i < 4;i++){
        printf("%3.1f\t",stu->score[i]);
    }
    printf("%3.1f",stu->average);
    printf("\n");
    fflush(stdout);
}

void inputStudent(){
    char c;
    //
    scanf("%s %s %c %d %s %s %f %f %f %f",
          tempNode.IDNumber,tempNode.Name,&tempNode.sex,
          &tempNode.birthday.year,tempNode.birthday.month,tempNode.birthday.day,
          &tempNode.score[0],&tempNode.score[1],&tempNode.score[2],&tempNode.score[3]
    );
    tempNode.average=NULL;
    tempNode.next=NULL;
    while ((c = getchar()) != '\n' && c != EOF) { /* 丢弃 */ }

}