
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct linked_list {
    struct node *head;
    struct node *tail;
    int size;
};

struct linked_list *init_linked_list( ) {
    struct linked_list *ll = ( struct linked_list * )malloc( sizeof( struct linked_list ) );
    ll->head               = NULL;
    ll->tail               = NULL;
    ll->size               = 0;

    return ll;
};

int insert_at_head( struct linked_list *list, int value ) {
    struct node *new_node = ( struct node * )malloc( sizeof( struct node ) );

    if ( new_node == NULL ) {
        printf( "Failed to allocate memory for a new node. Insertion failed.\n" );
        return -1;
    }

    new_node->value = value;

    if ( list->size > 0 ) {
        new_node->next = list->head;
        list->head     = new_node;
    } else {
        new_node->next = NULL;
        list->head = list->tail = new_node;
    }

    list->size++;

    return 0;
}

int insert_at_tail( struct linked_list *list, int value ) {
    struct node *new_node = ( struct node * )malloc( sizeof( struct node ) );

    if ( new_node == NULL ) {
        printf( "Failed to allocate memory for a new node. Insertion failed.\n" );
        return -1;
    }

    new_node->value = value;
    new_node->next  = NULL;

    if ( list->size > 0 ) {
        list->tail->next = new_node;
        list->tail       = new_node;
    } else {
        list->head = list->tail = new_node;
    }

    list->size++;

    return 0;
}

int insert_at_position( struct linked_list *list, int value, int position ) {
    // The list could be empty but not unintialized
    if ( list == NULL ) {
        printf( "The list is not initialized.\n" );
        return -1;
    }

    if ( position < 0 || position > list->size ) {
        printf( "The position entered is invalid.\n" );
        return -1;
    }

    if ( position == 0 ) {
        return insert_at_head( list, value );
    }

    if ( position == list->size ) {
        return insert_at_tail( list, value );
    }

    struct node *new_node = ( struct node * )malloc( sizeof( struct node ) );
    if ( new_node == NULL ) {
        printf( "Failed to allocate memory for a new node. Insertion failed.\n" );
        return -1;
    }

    new_node->value = value;

    // Traverse the list to find the node before the desired position
    int counter         = 0;
    struct node *cursor = list->head;
    while ( counter < position - 1 ) {
        cursor = cursor->next;
        counter++;
    }

    new_node->next = cursor->next;
    cursor->next   = new_node;

    list->size++;

    return 0;
}

int delete_from_head( struct linked_list *list ) {
    // The list could not be empty nor unintialized
    if ( list == NULL || list->size == 0 ) {
        printf( "The list is empty or not initialized.\n" );
        return -1;
    }

    struct node *old_head = list->head;
    list->head            = old_head->next;
    list->size--;

    if ( list->size == 0 ) {
        list->tail = NULL;
    }

    free( old_head );

    return 0;
}

void delete_from_tail( struct linked_list *list ) {
}

void delete_from_position( struct linked_list *list, int position ) {
}

void delete_by_value( struct linked_list *list, int value ) {
}

void print_linked_list( struct linked_list *list ) {
}

int search_by_value( struct linked_list *list ) {
}

int get_value( struct linked_list *list ) {
}

int main( ) {
}

