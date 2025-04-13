
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
    // The list could be empty but not unintialized
    if ( list == NULL ) {
        printf( "The list is not initialized.\n" );
        return -1;
    }

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
    // The list could be empty but not unintialized
    if ( list == NULL ) {
        printf( "The list is not initialized.\n" );
        return -1;
    }

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
        printf( "The position entered is invalid for insertion.\n" );
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

int delete_from_tail( struct linked_list *list ) {
    // The list could not be empty nor unintialized
    if ( list == NULL || list->size == 0 ) {
        printf( "The list is empty or not initialized.\n" );
        return -1;
    }

    // Handle single node list
    if ( list->size == 1 ) {
        free( list->tail );
        list->head = list->tail = NULL;
    } else {
        struct node *old_node = list->tail;

        struct node *cursor = list->head;
        while ( cursor->next != list->tail ) {
            cursor = cursor->next;
        }

        cursor->next = NULL;
        free( old_node );
    }

    list->size--;

    return 0;
}

int delete_from_position( struct linked_list *list, int position ) {
    // The list could not be empty nor unintialized
    if ( list == NULL || list->size == 0 ) {
        printf( "The list is empty or not initialized.\n" );
        return -1;
    }

    // The position needs to be valid for deletion
    if ( position < 0 || position >= list->size ) {
        printf( "The position entered is invalid for deletion.\n" );
        return -1;
    }

    if ( position == 0 ) {
        return delete_from_head( list );
    }

    if ( position == list->size - 1 ) {
        return delete_from_tail( list );
    }

    int counter         = 0;
    struct node *cursor = list->head;

    while ( counter < position - 1 ) {
        cursor = cursor->next;
        counter++;
    }

    // Now we are in the node just before the one to be deleted
    struct node *old_node = cursor->next;
    cursor->next          = cursor->next->next;
    free( old_node );
    list->size--;

    return 0;
}

int delete_by_value( struct linked_list *list, int value ) {
    // The list could not be empty nor unintialized
    if ( list == NULL || list->size == 0 ) {
        printf( "The list is empty or not initialized.\n" );
        return -1;
    }

    struct node *cursor      = list->head;
    struct node *prev_cursor = NULL;

    while ( cursor != NULL ) {
        if ( cursor->value == value ) {
            break;
        }
        prev_cursor = cursor;
        cursor      = cursor->next;
    }

    if ( cursor == NULL ) {
        printf( "The value is not found.\n" );
        return -1;
    }

    // Handle deletion
    if ( cursor == list->head ) {
        return delete_from_head( list );
    } else if ( cursor == list->tail ) {
        return delete_from_tail( list );
    } else {
        prev_cursor->next = cursor->next;
        free( cursor );
        list->size--;
    }

    return 0;
}

int print_linked_list( struct linked_list *list ) {
    // The list could not be empty nor unintialized
    if ( list == NULL || list->size == 0 ) {
        printf( "The list is empty or not initialized.\n" );
        return -1;
    }

    struct node *cursor = list->head;
    while ( cursor != NULL ) {
        printf( "Node: %d\n", cursor->value );
        cursor = cursor->next;
    }

    return 0;
}

int search_by_value( struct linked_list *list, int value ) {
    // The list could not be empty nor unintialized
    if ( list == NULL || list->size == 0 ) {
        printf( "The list is empty or not initialized.\n" );
        return -1;
    }

    int position        = 0;
    struct node *cursor = list->head;
    while ( cursor != NULL ) {
        if ( cursor->value == value ) {
            return position;
        }
        position++;
        cursor = cursor->next;
    }

    printf( "The value %d is not found in the list.\n", value );
    return -1;
}

int get_value( struct linked_list *list, int position ) {
    // The list could not be empty nor unintialized
    if ( list == NULL || list->size == 0 ) {
        printf( "The list is empty or not initialized.\n" );
        return -1;
    }

    // The position needs to be valid for read
    if ( position < 0 || position >= list->size ) {
        printf( "The position entered is invalid for read.\n" );
        return -1;
    }

    int counter         = 0;
    struct node *cursor = list->head;
    while ( cursor != NULL ) {
        if ( counter == position ) {
            printf( "Value at position %d is %d.\n", position, cursor->value );
            return cursor->value;
        }
        counter++;
        cursor = cursor->next;
    }

    // This point should never be reached if the list and position are valid.
    return -1;
}


