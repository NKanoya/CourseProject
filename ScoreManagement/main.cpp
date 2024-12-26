#include "stdio.h"
#include "list.h"
#include "print.h"
#include "query.h"


StudentNode tempNode;
static char command;
static int atHome = 1;
static char key[15];

void clearBuffer();

void homePage(){
    printf("\n\n欢迎使用学生成绩管理系统\n");
    printf("[a] 显示所有学生数据\n");
    printf("[b] 新增学生数据\n");
    printf("[c] 查询学生数据\n");
    //printf("[d] 统计数据\n");
    printf("[e] 退出\n");
    printf("\n");
    printf("输入字母进行操作:\n");
    fflush(stdout);
}

void endPage(){
    printf("\n回车返回主界面。\n");
    fflush(stdout);
    getchar();
}

char inputCommand(){
    char command, c;
    scanf("%c",&command);
    while ((c = getchar()) != '\n' && c != EOF) { /* 丢弃 */ }
    return command;
}

void showAllStudent(StudentNode* head){
    traverseStudent(head);
    atHome = 0;
}

void addNewStudent(StudentNode* head){
    printf("请选择在何处插入学生数据：\n");
    printf("[a] 末尾\n");
    printf("[b] 指定项前\n");
    printf("[e] 回到主界面\n");
    fflush(stdout);
    // 输入迷你指令符
    char com;
    scanf("%c",&com);
    clearBuffer();
    //验证输入
    while(com != 'a' && com != 'b' && com != 'e'){
        printf("输入不正确！请重试：\n");
        printf("请选择在何处插入学生数据：\n");
        printf("[a] 列表末尾\n");
        printf("[b] 指定位置\n");
        printf("[e] 回到主界面\n");
        fflush(stdout);
        scanf("%c",&com);
        clearBuffer();
    }

    // 'e' 退出
    if(com == 'e'){
        atHome = 1;
        return;
    }
    // 进入操作
    switch(com){
        // 插入到末尾
        case 'a':
            // 输入学生信息
            printf("请输入学生信息：\n");
            printf("格式：学生学号_姓名_性别_出生年_出生月_出生日_程序成绩_高数成绩_物理成绩_外语成绩\n");
            printf("_ 表示空格");
            fflush(stdout);
            inputStudent();
            // 插入结点
            insertNode(head, listLength(head)+1,tempNode);
            // 输入结果反馈
            printf("\n添加了1名新学生：\n");
            printHead();
            printStudent(getNode(head,listLength(head)),listLength(head));
            break;

            // 插入到指定项前
        case 'b':
            // 输入序号位置
            int num;
            printf("请输入要插入的序号位置，1 与 %d （含）之间的整数：\n",listLength(head)+1);
            fflush(stdout);
            scanf("%d",&num);
            clearBuffer();
            // 验证输入
            while(num > listLength(head)+1 && num <= 0){
                printf("无效序号！请重试：");fflush(stdout);
                scanf("%d",&num);
                clearBuffer();
            }

            // 输入学生信息
            printf("请输入学生信息：\n");
            printf("格式：学生学号_姓名_性别_出生年_出生月_出生日_程序成绩_高数成绩_物理成绩_外语成绩\n");
            printf("_ 表示空格");
            fflush(stdout);
            inputStudent();
            // 插入结点
            insertNode(head, num,tempNode);
            // 输入结果反馈
            printf("\n添加了1名新学生：\n");
            printHead();
            printStudent(getNode(head,num),num);
            break;
    }

    atHome = 0;
}

void queryStudent(StudentNode* head){
    printf("请输入要查找的关键字：");
    fflush(stdout);
    scanf("%s",key);
    clearBuffer();
    queryByName(head,key);
    atHome = 0;
}

int main() {

    StudentNode* head = iniStudentNode();
    printf("欢迎使用学生信息管理系统\n[Enter] 键继续");fflush(stdout);
    scanf("");
    clearBuffer();


    while(1){
        if(!atHome){
            endPage();
            atHome = 1;
            continue;
        }

        homePage();
        command = inputCommand();

        // 'e' 退出
        if(command == 'e')
            break;

        // 'command' 操作
        switch(command){
            case 'a':
                showAllStudent(head);
                break;
            case 'b':
                addNewStudent(head);
                break;
            case 'c':
                queryStudent(head);
                break;
            default:
                break;
        }
    }

    clearList(head);



    return 0;
}

//
void clearBuffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { /* 丢弃 */ }
    return;
}




// 示例输入：114614 Shaker m 2006 01 01 114 120 93 96
