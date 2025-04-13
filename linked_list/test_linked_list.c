#include <stdio.h>
#include <stdlib.h>

#include "linked_list.c"  // Include your implementation here

void test_linked_list( ) {
    printf( "Running linked list tests...\n" );

    // Initialize the linked list
    struct linked_list *list = init_linked_list( );

    // Test Case 1: Insert at head
    printf( "\nTest Case 1: Insert at head\n" );
    insert_at_head( list, 10 );  // List: 10
    insert_at_head( list, 20 );  // List: 20 -> 10
    insert_at_head( list, 30 );  // List: 30 -> 20 -> 10
    print_linked_list( list );

    // Test Case 2: Insert at tail
    printf( "\nTest Case 2: Insert at tail\n" );
    insert_at_tail( list, 40 );  // List: 30 -> 20 -> 10 -> 40
    insert_at_tail( list, 50 );  // List: 30 -> 20 -> 10 -> 40 -> 50
    print_linked_list( list );

    // Test Case 3: Insert at a valid position
    printf( "\nTest Case 3: Insert at a valid position\n" );
    insert_at_position( list, 25, 1 );  // List: 30 -> 25 -> 20 -> 10 -> 40 -> 50
    insert_at_position( list, 35, 2 );  // List: 30 -> 25 -> 35 -> 20 -> 10 -> 40 -> 50
    print_linked_list( list );

    // Test Case 4: Delete from head
    printf( "\nTest Case 4: Delete from head\n" );
    delete_from_head( list );  // List: 25 -> 35 -> 20 -> 10 -> 40 -> 50
    print_linked_list( list );

    // Test Case 5: Delete from tail
    printf( "\nTest Case 5: Delete from tail\n" );
    delete_from_tail( list );  // List: 25 -> 35 -> 20 -> 10 -> 40
    print_linked_list( list );

    // Test Case 6: Delete from a valid position
    printf( "\nTest Case 6: Delete from a valid position\n" );
    delete_from_position( list, 2 );  // List: 25 -> 35 -> 10 -> 40
    print_linked_list( list );

    // Test Case 7: Delete by value
    printf( "\nTest Case 7: Delete by value\n" );
    delete_by_value( list, 35 );   // List: 25 -> 10 -> 40
    delete_by_value( list, 100 );  // Value not in the list
    print_linked_list( list );

    // Test Case 8: Search by value
    printf( "\nTest Case 8: Search by value\n" );
    int pos1 = search_by_value( list, 10 );   // Should find at position 1
    int pos2 = search_by_value( list, 100 );  // Value not in the list
    printf( "Position of 10: %d\n", pos1 );
    printf( "Position of 100: %d\n", pos2 );

    // Test Case 9: Get value by position
    printf( "\nTest Case 9: Get value by position\n" );
    int val1 = get_value( list, 1 );  // Should return 10
    int val2 = get_value( list, 3 );  // Invalid position
    printf( "Value at position 1: %d\n", val1 );
    printf( "Value at position 3: %d\n", val2 );

    // Test Case 10: Handle operations on an empty list
    printf( "\nTest Case 10: Handle operations on an empty list\n" );
    delete_from_head( list );     // List: 10 -> 40
    delete_from_tail( list );     // List: 10
    delete_from_tail( list );     // List is now empty
    print_linked_list( list );    // Should print "The list is empty or not initialized."
    delete_from_head( list );     // Should print error message
    delete_by_value( list, 10 );  // Should print error message
    search_by_value( list, 10 );  // Should print error message
    get_value( list, 0 );         // Should print error message

    // Free the list
    free( list );

    printf( "\nAll tests completed!\n" );
}

int main( ) {
    test_linked_list( );
    return 0;
}

