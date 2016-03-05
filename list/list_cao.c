/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Description:
 *                                                                             *
 * Author: Yuanqi Cao (John)                                                   *
 *                                                                             *
 * Other source files, if any, one per line, starting on the next line:        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    void *value;
    struct node *next;
} Node;


typedef struct list{
    Node * header;
    Node * tailer;
    int length;
} List;

Node *create_empty_node();
Node *create_node(void *value);
Node *app_end_list_node(List * , Node*);
List *init_list();
void append_to_list(List* , Node* );
void print_list(List*);

int main(int argc, char **argv) {
    char* array[4] = {"This ", "is ", "good ", "time "};
    List* list = init_list();
    for (int i = 0; i < 4; i++) {
        Node *node = create_node(array[i]);
        append_to_list(list, node);
    }
    print_list(list);
    return EXIT_SUCCESS;
}


/* Crete node and return its address */
Node *create_empty_node(){
     Node *const address = malloc(sizeof(Node));
     address -> value = NULL;
     address -> next = NULL;
    return address;
}

/* create node with node 's value */
Node *create_node(void *value){
    Node *node = create_empty_node();
    node -> value = value;
    return node;
};

/* Initialize the list */
List *init_list(){
    List* new_list = malloc(sizeof(List));
    Node *header = create_empty_node();
    new_list -> header = header;
    new_list -> length = 0;
    return new_list;
};

/* append to the list with node */
void append_to_list(List* list, Node* node){
    Node *header = list -> header;
    while(header -> next != NULL){
        header = header -> next;
    }
    header -> next = node;
    list -> length += 1;
}

/* Print the list out to the console */
void print_list(List* list){
    int length = list -> length;
    Node * header = list -> header;
    for (int i = 0; i < length; i++) {
        header = header -> next;
        printf("%s\n", header -> value );
    }
}
