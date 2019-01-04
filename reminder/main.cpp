#include "G20.h"

int main( void )
{
    ListNodePtr startPtr = NULL; /* initially there are no nodes */
    int choice; /* user's choice */
    ListNode listnode;
    listnode.title = (char *)malloc(sizeof(ListNode));
    listnode.reminder = (char *)malloc(sizeof(ListNode));
 
    instructions(); /* display the menu */
    printf( "=> " );
    scanf( "%d", &choice );
 
    /* loop while user does not choose 4 */
    while ( choice != 4 )
    {
 
        switch ( choice )
        {
        case 1:
            fflush(stdin);
            printf( "Enter the Title of the reminder(char): ");
            gets(listnode.title);
            printf( "Enter the Date (YYYY MM DD): ");
            scanf( "%d %d %d", &listnode.date.year, &listnode.date.month, &listnode.date.day );
            fflush(stdin);
            printf("Enter the Reminder: ");
            gets(listnode.reminder);
            printf("\n");
            insert( &startPtr, listnode);  /* insert item in list */
            printf("{+}Title: %s\n", listnode.title);
            printf("    - Date: %d/%02d/%02d\n", listnode.date.year, listnode.date.month, listnode.date.day);
            printf("    - Reminder: %s\n", listnode.reminder );
            printf("\n\n");
            break;
        case 2:
            /* if list is not empty */
            printList( startPtr );
            if ( !isEmpty( startPtr ) )
            {
                fflush(stdin);
                printf( "Enter Title to be deleted: " );
                gets(listnode.title);
 
                /* if character is found, remove it */
                if ( del( &startPtr, listnode.title ) )   /* remove item */
                {
                    printf( "\n%s is deleted from the list.\n", listnode.title );
                    printList( startPtr );
                } /* end if */
                else
                {
                    printf( "%s not found.\n\n", listnode.title );
                } /* end else */
            } /* end if */
            else
            {
                printf( "List is empty.\n\n" );
            } /* end else */
 
            break;
        default:
            printf( "Invalid choice.\n\n" );
            instructions();
            break;
        case 3:
            printList( startPtr );
            break;
        }
        instructions();
        printf( "=> " );
        scanf( "%d", &choice );
    } /* end while */
 
    printf( "End of run.\n" );
    return 0; /* indicates successful termination */
} /* end main */
