//
//  main.c
//  DeleteNodeDoubleList
//
//  Created by chenyufeng on 16/3/3.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  实现在不带头节点的双向非循环链表中删除一个节点
 （1）删除pos位置的节点；
 （2）判断x是否在链表中，存在则删除之；
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//初始化不带头结点的非循环双向链表
void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，链表初始化完成\n",__FUNCTION__);
}

//创建非循环双向链表
Node *createList(Node *pNode){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;
    pInsert->prior = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;

    if (pInsert->element <= 0) {

        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0) {
        if (pNode == NULL) {
            pNode = pInsert;
            pMove = pNode;
        }else{

            pMove->next = pInsert;
            pInsert->prior = pMove;
            pMove = pMove->next;
        }

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;
        pInsert->prior = NULL;
        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行，建立链表成功\n",__FUNCTION__);

    return pNode;
}

//打印非循环双向链表
void printList(Node *pNode){

    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//返回不带头节点的双向链表的长度
int sizeList(Node *pNode){

    int i = 0;
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，长度为0\n",__FUNCTION__);
        return 0;
    }else{

        while (pNode != NULL) {
            i++;
            pNode = pNode->next;
        }
        printf("%s函数执行，链表长度为%d\n",__FUNCTION__,i);
        return i;
    }
}

//删除pos位置的节点
Node *deletePosList(Node *pNode,int pos){
    //注意需要单独考虑第一个节点和最后一个节点

    int i = 1;
    int size = sizeList(pNode);
    Node *pMove;
    pMove = pNode;

    //链表为空
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，删除节点失败\n",__FUNCTION__);
        return pNode;
    }

    //链表只有一个节点，删除第一个节点
    if (pos == 1 && size == 1) {

        free(pNode);
        pNode = NULL;
        printf("%s函数执行，删除pos=%d位置的节点成功\n",__FUNCTION__,pos);
        return NULL;
    }

    //链表节点大于1，删除第一个节点
    if (pos == 1) {

        pNode = pNode->next;
        pNode->prior = NULL;
        free(pMove);
        pMove = NULL;
        printf("%s函数执行，删除pos=%d位置的节点成功\n",__FUNCTION__,pos);
        return pNode;
    }

    while (pMove != NULL) {
        if (i == pos && pos != size) {

            pMove->prior->next = pMove->next;
            pMove->next->prior = pMove->prior;
            free(pMove);
            pMove->next = NULL;

            printf("%s函数执行，删除pos=%d位置的节点成功\n",__FUNCTION__,pos);
            return pNode;
        }

        if (i == pos && pos == size) {
            pMove->prior->next = NULL;
            free(pMove);
            pMove = NULL;
            printf("%s函数执行，删除pos=%d位置的节点成功\n",__FUNCTION__,pos);
            return pNode;
        }

        i++;
        pMove = pMove->next;
    }

    printf("%s函数执行，删除pos=%d位置的节点失败\n",__FUNCTION__,pos);
    return pNode;
}

//判断x是否在链表中，存在则删除之
Node *deleteValueList(Node *pNode,int x){

    Node *pMove;
    pMove = pNode;
    int size = sizeList(pNode);

    //原链表为空
    if (pNode == NULL) {
        printf("%s函数执行，原链表为空，删除节点失败\n",__FUNCTION__);
        return NULL;
    }

    //删除的是第一个节点，并且链表长度为1
    if (pNode->element == x && size == 1) {

        free(pNode);
        pNode = NULL;
        printf("%s函数执行，删除值为%d节点成功\n",__FUNCTION__,x);
        return pNode;
    }

    //单独考虑删除第一个节点的情况,且链表长度大于1
    if (pNode->element == x) {
        pNode = pNode->next;
        free(pNode->prior);
        pNode->prior = NULL;

        printf("%s函数执行，删除值为%d节点成功\n",__FUNCTION__,x);
        return pNode;
    }

    while (pMove != NULL) {
        //要删除的节点不是最后一个
        if (pMove->element == x && pMove->next != NULL) {

            pMove->prior->next = pMove->next;
            pMove->next->prior = pMove->prior;
            free(pMove);
            pMove = NULL;
            printf("%s函数执行，删除值为%d节点成功\n",__FUNCTION__,x);
            return pNode;
        }

        //要删除的是最后一个节点
        if (pMove->element == x && pMove->next == NULL) {

            pMove->prior->next = NULL;
            free(pMove);
            pMove = NULL;
            printf("%s函数执行，删除值为%d节点成功\n",__FUNCTION__,x);
            return pNode;
        }
        pMove = pMove->next;
    }

    printf("%s函数执行，删除值为%d节点失败\n",__FUNCTION__,x);
    return pNode;
}

int main(int argc, const char * argv[]) {

    Node *pList;
    
    initList(pList);
    printList(pList);
    
    pList = createList(pList);
    printList(pList);
    
    pList = deletePosList(pList,1);
    printList(pList);

    pList = deleteValueList(pList,5);
    printList(pList);
    
    return 0;
}














