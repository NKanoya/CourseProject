//
// Created by pilip on 2024/12/25.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "list.h"
#define nodeSize sizeof(StudentNode)


StudentNode * iniStudentNode(){
    StudentNode * head = (StudentNode*) malloc(nodeSize);	//malloc()为头结点动态分配内存

    if( head == NULL ){
        printf("创建失败");
        return NULL;			//内存分配失败时退出函数
    }

    head -> next = NULL;		//只含有头结点，因此头结点后件指针指向NULL
    return head;
}

StudentNode * createNewNode(StudentNode tempNode, StudentNode * next){
    StudentNode * node = (StudentNode*) malloc(nodeSize);

    if( node == NULL ){
        printf("创建失败");
        return NULL;			//内存分配失败时退出函数
    }

    strcpy(node -> IDNumber , tempNode.IDNumber);
    strcpy(node -> Name , tempNode.Name);
    node -> sex = tempNode.sex;
    //
    strcpy(node -> birthday.day , tempNode.birthday.day);
    node -> birthday.year = tempNode.birthday.year;
    strcpy(node -> birthday.month , tempNode.birthday.month);
    //
    int notNULL_Num = 0, sum = 0;
    for(int i = 0;i < 4;i++){
        node -> score[i] = tempNode.score[i];
        if(node -> score[i] > 0){
            notNULL_Num++;
            sum += node -> score[i];
        }
    }
    node -> average = sum/notNULL_Num;

    node -> next = next;
    return node;
}


int insertNode(StudentNode * head, int number, StudentNode tempNode) {
    if (number < 1) 		// 检查插入位置是否有效
        return 1;  			// 位置无效

    StudentNode * current = head;
    for (int i = 1; i < number; ++i) {	// 访问到指定的节点位置
        if(current->next == NULL){
            return 1;
        }
        current = current->next;
    }

    StudentNode * newNode = createNewNode(tempNode,current->next);  	// 创建新节点，新结点的next设为原来(n-1)处结点的next
    current->next = newNode;									// (n-1)处结点的next指向新结点
    return 0;
}

int isListEmpty(StudentNode *head){
    return( head->next == NULL );
}

void clearList(StudentNode* head) {
    StudentNode* current = head->next;  // 从头结点的下一个节点开始
    StudentNode* temp;

    // 遍历链表并释放所有节点
    while (current != NULL) {
        temp = current;
        current = current->next;  // 保存下一个节点
        free(temp);  // 释放当前节点
    }

    // 释放头结点（哑结点）
    free(head);
}

int listLength(StudentNode *head){
    StudentNode *p = head->next;
    int i=0;
    while (p!=NULL){
        i++;
        p=p->next;
    }
    return(i);
}

StudentNode * getNode(StudentNode * head,int num){
    if(num > listLength(head) || num <= 0)
        return NULL;
    int i;
    StudentNode * current = head;
    for(i = 0;i < num;i++){
        current = current -> next;
    }
    return current;
}


int popNode(StudentNode * head){
    if(isListEmpty(head))  // 链表为空时不能弹出节点
        return 1;

    StudentNode* current = head->next;  // 从头结点的下一个节点开始
    StudentNode* prev = NULL;  // 用来记录当前节点的前一个节点

    // 遍历链表找到最后一个节点
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // 释放尾节点
    free(current);
    // 更新倒数第二个节点的 next 指针为 NULL
    if (prev != NULL) {
        prev->next = NULL;
    }
    return 0;
}

int shiftNode(StudentNode * head){
    if(isListEmpty(head))  // 如果链表为空则返回
        return 1;

    StudentNode * temp = head->next;  // 保存第一个节点
    head->next = head->next->next;  // 更新 head->next 为下一个节点
    free(temp);  // 释放原来的第一个节点
    return 0;
}

int deleteNode(StudentNode* head, int number){
    if(number < 0 || number > listLength(head))  // 防止越界
        return 1;

    if(number == listLength(head)){
        popNode(head);
        return 0;
    }

    int i;
    StudentNode * current = head;
    for(i = 0; i < number - 1; i++){
        current = current->next;
    }

    StudentNode * temp = current->next;  // 暂时保存要删除的节点
    current->next = current->next->next;  // 修改当前节点的 next
    free(temp);  // 释放要删除的节点
    return 0;
}