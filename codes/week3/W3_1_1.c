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
    Err err = SUCCESS;
    *list = (LinkList_TypeDef *)malloc(sizeof(LinkList_TypeDef));
    (*list)->next = NULL;
    return SUCCESS;
}

void LinkList_Destory(LinkList_TypeDef *list){
    LinkList_TypeDef *temp = list;
    while(list != NULL){
        temp = list;
        list = list->next;
        free(temp);
    }
}

Err LinkList_AddElm(LinkList_TypeDef *list, Element_TypeDef elm){
    Err err = SUCCESS;
    LinkList_TypeDef *temp = (LinkList_TypeDef *)malloc(sizeof(LinkList_TypeDef));
    temp->element = elm;
    temp->next = list->next;
    list->next = temp;
    return SUCCESS;
}

void LinkList_ShowEle(LinkList_TypeDef *list){
    LinkList_TypeDef *temp;
    if(list->next == NULL){
        printf("None\n");
    }else{
        temp = list->next;
        printf("-----------------------------------------\n");
        while(temp != NULL){
            printf("%d\n", temp->element);
            temp = temp->next;
        }
        printf("-----------------------------------------\n");
    }
}


void func1(LinkList_TypeDef *list){
    LinkList_TypeDef *p_this = NULL, *p_next = NULL, *p_prior = NULL;
    if(list->next == NULL){
        return;
    }
    p_prior = NULL;
    p_this = list->next;
    p_next = p_this->next;

    while (p_next != NULL){
        p_this->next = p_prior;

        p_prior = p_this;
        p_this = p_next;
        p_next = p_next->next;
    }
    p_this->next = p_prior;
    list->next = p_this;
}

void func2(LinkList_TypeDef *list){
    LinkList_TypeDef *p_this = NULL, *p_next = NULL;
    Element_TypeDef temp = 0;
    if(list->next == NULL){
        return;
    }
    p_this = list->next;
    p_next = p_this->next;
    while(p_next != NULL){

        temp = p_this->element;
        p_this->element = p_next->element;
        p_next->element = temp;

        p_this = p_next->next;
        if(p_this == NULL){
            return;
        }
        p_next = p_this->next;
    }
    
}


void func3(LinkList_TypeDef *a, LinkList_TypeDef *b, int i, int len, int j){
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
    while(-- j){
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
    LinkList_TypeDef *a = NULL, *b = NULL;
    int i = 0;
    LinkList_Init(&a);
    LinkList_Init(&b);
    for(i = 9; i > 0; -- i){
        LinkList_AddElm(a, i);
    }
    for(i = 100 + 9; i > 100; -- i){
        LinkList_AddElm(b, i);
    }
    LinkList_ShowEle(a);
    LinkList_ShowEle(b);

    func3(a->next, b->next, 5, 3, 4);
    LinkList_ShowEle(b);

    LinkList_Destory(a);
    LinkList_Destory(b);
}
