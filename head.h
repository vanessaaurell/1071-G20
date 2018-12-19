#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
    int year;
    int month;
    int day;
};
 
/* self-referential structure */
struct ListNode
{
    char *title;             // Reminder Title
    Date date;   // Reminder Date
    char *reminder;   //Reminder
    ListNode *nextPtr; /* pointer to next node*/
}; /* end structure listNode */
 
//typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */
typedef ListNode *ListNodePtr;
void instructions(void);
void insert( ListNode **sPtr, ListNode listnode);
int del( ListNodePtr *sPtr, char *title );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
