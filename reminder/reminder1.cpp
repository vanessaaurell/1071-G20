#include "head.h"

/* display program instructions to user */
void instructions( void )
{
    printf( "           ===  Enter your choice  ===\n"
            "____________________________________________________\n"
            "|                                                   |\n"
            "|   Enter 1 to make a new reminder.                 |\n"
            "|   Enter 2 to remove a reminder from the list.     |\n"
            "|   Enter 3 to show the list.                       |\n"
            "|   Enter 4 to end.                                 |\n"
            "|___________________________________________________|\n");
} /* end function instructions */
 
/* Insert a new value into the list in sorted order */
void insert( ListNode **sPtr, ListNode listnode)
{
    ListNodePtr newPtr; /* pointer to new node */
    ListNodePtr previousPtr; /* pointer to previous node in list */
    ListNodePtr currentPtr; /* pointer to current node in list */
 
    newPtr = (ListNode *) malloc( sizeof( ListNode ) ); /* create node */
    newPtr->reminder = (char *) malloc(sizeof(char) );
    newPtr->title = (char *) malloc(sizeof(char) );
 
    if ( newPtr != NULL )   /* is space available */
    {
        strcpy(newPtr->title, listnode.title);
        newPtr->date.year = listnode.date.year; /* place value in node */
        newPtr->date.month= listnode.date.month; /* place value in node */
        newPtr->date.day = listnode.date.day; /* place value in node */
        strcpy(newPtr->reminder, listnode.reminder);
        newPtr->nextPtr = NULL; /* node does not link to another node */
 
        previousPtr = NULL;
        currentPtr = *sPtr;
 
        /* loop to find the correct location in the list */
        while ( currentPtr != NULL && listnode.date.year > currentPtr->date.year)
        {
            previousPtr = currentPtr; /* walk to ...   */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */
 
        while ( currentPtr != NULL && listnode.date.month > currentPtr->date.month)
        {
            previousPtr = currentPtr; /* walk to ...   */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */
 
        while ( currentPtr != NULL && listnode.date.day > currentPtr->date.day)
        {
            previousPtr = currentPtr; /* walk to ...   */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */
 
        while ( currentPtr != NULL && listnode.title > currentPtr->title)
        {
            previousPtr = currentPtr; /* walk to ...   */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */
 
        /* insert new node at beginning of list */
        if ( previousPtr == NULL )
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } /* end if */
        else   /* insert new node between previousPtr and currentPtr */
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } /* end else */
    } /* end if */
    else
    {
        printf( "%c not inserted. No memory available.\n", listnode.date.year );
    } /* end else */
} /* end function insert */
 
/* Delete a list element */
int del( ListNodePtr *sPtr, char *title )
{
    ListNodePtr previousPtr; /* pointer to previous node in list */
    ListNodePtr currentPtr; /* pointer to current node in list */
    ListNodePtr tempPtr; /* temporary node pointer */
 
    /* delete first node */
    if  ( ! strcmp ( title,  (*sPtr)->title) )
    {
 
        tempPtr = *sPtr; /* hold onto node being removed */
        *sPtr = ( *sPtr )->nextPtr; /* de-thread the node */
        free( tempPtr ); /* free the de-threaded node */
        return (char)*title;
    } /* end if */
    else
    {
        previousPtr = *sPtr;
        currentPtr = ( *sPtr )->nextPtr;
 
        /* loop to find the correct location in the list */
        while ( currentPtr != NULL && ( strcmp ( title,  currentPtr->title ) ) )
        {
            previousPtr = currentPtr; /* walk to ...   */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */
 
        /* delete node at currentPtr */
        if ( currentPtr != NULL )
        {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free( tempPtr );
            return (char)*title;
        } /* end if */
    } /* end else */
    return '\0';
} /* end function delete */
 
/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
} /* end function isEmpty */
 
/* Print the list */
void printList( ListNodePtr currentPtr )
{
    /* if list is empty */
    int n=0;
    if ( currentPtr == NULL )
    {
        printf( "List is empty.\n\n" );
    } /* end if */
    else
    {
        printf( "_____________________________________________________\n"
                "|                                                    |\n"
                "|                 Reminder List:                     |\n"
                "|____________________________________________________|\n" );
 
        /* while not the end of the list */
        while ( currentPtr != NULL )
        {
            n++;
            printf("(%d) Title: %s\n", n, currentPtr->title);
            printf("     = Date: %d/%02d/%02d\n",currentPtr->date.year,currentPtr->date.month,currentPtr->date.day);
            printf("     = Reminder: %s\n", currentPtr->reminder );
            printf("\n\n");
            currentPtr = currentPtr->nextPtr;
        } /* end while */
    } /* end else */
} /* end function printList */
