#include <stdio.h>
#include <stdlib.h>

typedef int Element_TypeDef;
typedef struct _oLinkList{
    Element_TypeDef element;
    struct _oLinkList *next;
}LinkList_TypeDef;

typedef enum{
    SUCCESS = 0,
    EMPTY_POINTER = 1
}Err;

Err LinkList_Init(LinkList_TypeDef **list){
    *list = NULL;
}

void LinkList_Destory(LinkList_TypeDef *list){
    LinkList_TypeDef *temp = list;
    while(list != NULL){
        temp = list;
        list = list->next;
        free(temp);
    }
}

void LinkList_AddElm(LinkList_TypeDef **plist, Element_TypeDef elm){
    LinkList_TypeDef *list = *plist;
    if(list == NULL){
        *plist = (LinkList_TypeDef *)malloc(sizeof(LinkList_TypeDef));
        (*plist)->next = *plist;
        (*plist)->element = elm;
        return;
    }else{
        LinkList_TypeDef *temp = list;
        while(temp->next != list){
            temp = temp->next;
        }
        temp->next = (LinkList_TypeDef *)malloc(sizeof(LinkList_TypeDef));
        temp = temp->next;

        temp->element = elm;
        temp->next = list;
    }
}

void LinkList_ShowEle(LinkList_TypeDef *list){
    LinkList_TypeDef *temp;
    if(list == NULL){
        printf("None\n");
    }else{
        temp = list->next;
        printf("-----------------------------------------\n");
        while(temp != list){
            printf("%d\n", temp->element);
            temp = temp->next;
        }
        printf("-----------------------------------------\n");
    }
}

void func1(LinkList_TypeDef *list){
    LinkList_TypeDef *temp = list->next;
    while (temp->next->next != list){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = list;
}


void func2(LinkList_TypeDef *a, LinkList_TypeDef *b, int i, int len, int j){
    LinkList_TypeDef *temp = a, *next = NULL, *this = NULL, *tail = NULL;
/**********************************************************/
    temp = a;
    while(i -- && temp != NULL){
        this = temp;
        temp = temp->next;
    }

    while(len -- && temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
    this->next = next;
/************************************************************/
    temp = b;
    if(j == 1){
        next->next = b;
        b = a;
        return;
    }
    while(-- j - 1){
        temp = temp->next;
    }

    tail = a;
    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = temp->next;
    temp->next = a;
}


int main(){
    LinkList_TypeDef *list = NULL;
    int i = 0;
    LinkList_Init(&list);
    for(i = 0; i < 9; ++ i){
        LinkList_AddElm(&list, i);
    }
    LinkList_ShowEle(list);
    i = 3;
    while (-- i){
        printf("#");
    }
    
    return 0;
}
