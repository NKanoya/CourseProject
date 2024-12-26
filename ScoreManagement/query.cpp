//
// Created by pilip on 2024/12/25.
//
#include "stdio.h"
#include "list.h"
#include "print.h"

void traverseStudent(StudentNode * head){
    if(isListEmpty(head)){
        printHead();
        printf("\t\t(空)\t\t\n");
        return;
    }

    int len = listLength(head);
    StudentNode * current = head -> next;
    printHead();
    for(int j = 1;j <= len;j++){
        printStudent(current,j);
        current = current -> next;
    }
}

int query(char * base,char * key){
    int i = 0, flag = 0;

    // 遍历 base
    while(base[i] != '\0'){
        // key 首字符匹配
        if(base[i]==key[0]){
            int j = 0;

            // 遍历 key
            while(key[j] != '\0'){
                flag = 1;
                // 发现不同于key的字符，退出，查找失败
                if(key[j] != base[i]){
                    flag = 0;
                    i--;        // 重新查找该字符
                    break;
                }
                i++;j++;
            }
        }
        if(flag)    //查找成功，退出
            break;
        else   // 未查找成功，继续遍历
            i++;
    }

    return flag;
}

void queryByName(StudentNode * head,char * key){
    int num = 0;
    printHead();
    StudentNode * current = head -> next;
    while(current != NULL){
        if(query(current -> Name, key)){
            num++;
            printStudent(current,num);
        }
        current = current -> next;
    }
    if(num == 0)
        printf("\t\t(空)\t\t\n");

    printf("共查找到%d条数据。",num);
    return;

}