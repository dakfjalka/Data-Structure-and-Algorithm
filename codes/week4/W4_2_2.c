#include <stdio.h>
#include <stdlib.h>

typedef int Element_TypeDef;

typedef struct _oQueue{
    Element_TypeDef element;
    struct _oQueue *next;
}Queue_TypeDef;

void Queue_Init(Queue_TypeDef **tail){
    (*tail) = (Queue_TypeDef *)malloc(sizeof(Queue_TypeDef));
    (*tail)->element = -1;
    (*tail)->next = *tail;
}

void Queue_Destory(Queue_TypeDef *queue){
    Queue_TypeDef *temp = queue;
    while(temp != NULL && temp->next != queue){
        temp = temp->next;
    }
    temp->next = NULL;
    while(queue != NULL){
        temp = queue->next;
        free(queue);
        queue = temp;
    }
}

void Queue_EnQueue(Queue_TypeDef **tail, Element_TypeDef element){
    Queue_TypeDef *temp_head = NULL;
    if(tail == NULL || *tail == NULL){
        printf("tail is NULL!!!\n");
        return;
    }else{
        temp_head = (*tail)->next;
        (*tail)->next = (Queue_TypeDef *)malloc(sizeof(Queue_TypeDef));
        *tail = (*tail)->next;
        
        (*tail)->next = temp_head;
        (*tail)->element = element;
        return;
    }
}

void Queue_DeQueue(Queue_TypeDef **tail, Element_TypeDef *element){
    Queue_TypeDef *head = NULL;
    head = (*tail)->next->next;
    if(element != NULL){
        *element = head->element;
    }
    (*tail)->next->next = head->next;
    if(*tail == head){
        *tail = (*tail)->next;
    }
    free(head);
}

void Queue_Print(Queue_TypeDef *tail){
    Queue_TypeDef *head = tail->next->next;
    while(head != tail->next){
        printf("%d\n", head->element);
        head = head->next;
    }
}

int main(){
    int i = 0;
    Queue_TypeDef *tail = NULL;
    Queue_Init(&tail);
    for(i = 0; i < 9 ; ++ i){
        Queue_EnQueue(&tail, i + 1);
    }
    Queue_Print(tail);
    printf("------------------------------\n");
    Queue_DeQueue(&tail, NULL);
    Queue_Print(tail);
    printf("------------------------------\n");
    Queue_EnQueue(&tail, 999);
    Queue_Print(tail);

    Queue_Destory(tail);
    return 0;
}