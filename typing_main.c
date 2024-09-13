#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typing_prob.c"
void show()
{
    if(head == NULL) {
        printf("\n");
        return;
    }
    Node *now = head->ptr_to_next_node;
    while(now != head)
    {
        printf("%c ", now->character);
        now = now->ptr_to_next_node;
    }
    printf("\n");
}
int n, intype, num;
char buf[7];
int main()
{
    scanf("%d",&n);
    head = (Node*)malloc(sizeof(Node));
    head->ptr_to_next_node = head->ptr_to_prev_node = head;
    cursor = tail = head;
    while(n--)
    {
        scanf("%s",buf);
        if(!strcmp(buf,"insert"))
        {
            getchar();
            scanf("%c",&intype);
            insert(&cursor, intype); 
        }
        else if(!strcmp(buf,"deletion"))
        {
            deletion(&cursor); 
        }
        else if(!strcmp(buf,"backspace"))
        {
            backspace(&cursor); 
        }
        else if(!strcmp(buf,"go_left"))
        {
            scanf("%d", &num);
            go_left(&cursor, num); 
        }
        else if(!strcmp(buf,"go_right"))
        {
            scanf("%d", &num);
            go_right(&cursor, num); 
        }
        else if(!strcmp(buf,"go_home"))
        {
            go_home(&cursor); 
        }
        else if(!strcmp(buf,"go_end"))
        {
            go_end(&cursor); 
        }
        else if(!strcmp(buf,"show"))
        {
            show();
        }
    }
    return 0;
}