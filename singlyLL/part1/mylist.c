#include <stdio.h>
#include <stdlib.h>
/*
 *name: Carlos López 
 * UNI: Cal2266
 * desc lab 3 part1
 *
 */
/*
 * A node in a linked list.
 */
struct Node {
    void *data;
    struct Node *next;
};

/*
 * A linked list.  
 * 'head' points to the first node in the list.
 */
struct List {
    struct Node *head;
};

/*
 * Initialize an empty list.  
 */
static inline void initList(struct List *list)
{
    list->head = 0;
}

/*
 * In all functions below, the 'list' parameter is assumed to point to
 * a valid List structure.
 */

/*
 * Create a node that holds the given data pointer,
 * and add the node to the front of the list.
 *
 * Note that this function does not manage the lifetime of the object
 * pointed to by 'data'.
 * 
 * It returns the newly created node on success and NULL on failure.
 */
struct Node *addFront(struct List *list, void *data){
	struct Node *new = (struct Node*) malloc(sizeof(struct Node));
	if(new == NULL)
		return NULL; 
	else{
		if(list->head == 0){
			new->next = NULL;
			list->head = new;
			list->head->data = data; 
		}
		else{
			new->next = list->head;
			list->head = new;
			list->head->data = data; 
		}
		return new;		
	}
}
/*
 * Traverse the list, calling f() with each data item.
 */
void traverseList(struct List *list, void (*f)(void *)){
	
	struct Node *cur = list->head; 
	while(cur){
		f(cur->data);
		cur = cur->next;
	}
}

/*
 * Traverse the list, comparing each data item with 'dataSought' using
 * 'compar' function.  ('compar' returns 0 if the data pointed to by
 * the two parameters are equal, non-zero value otherwise.)
 *
 * Returns the first node containing the matching data, 
 * NULL if not found.
 */
struct Node *findNode(struct List *list, const void *dataSought,
	int (*compar)(const void *, const void *)){ 
	struct Node *retVal = NULL;
	struct Node *cur = list->head;
	while(cur){
		if(!(compar(cur->data, dataSought))){
		       retVal = cur;
		       break; 
		}
		cur = cur->next;
	}	
		return retVal; 	
}
/*
 * Flip the sign of the double value pointed to by 'data' by
 * multiplying -1 to it and putting the result back into the memory
 * location.
 */
void flipSignDouble(void *data){
	double *p = (double*)(data);
	*p = -1*(*p);
	data =p;		
}
/*
 * Compare two doube values pointed to by the two pointers.
 * Return 0 if they are the same value, 1 otherwise.
 */
int compareDouble(const void *data1, const void *data2){
	const double *p = (double*) data1;  
	const double *q = (double*) data2; 
	if(*p !=  *q)
		return 1; 
	else
		return 0; 
}
/*
 * Returns 1 if ithe list is empty, 0 otherwise.
 */
static inline int isEmptyList(struct List *list)
{
    return (list->head == 0);
}

/*
 * Remove the first node from the list, deallocate the memory for the
 * ndoe, and return the 'data' pointer that was stored in the node.
 * Returns NULL is the list is empty.
 */
void *popFront(struct List *list){
	if(list->head!=0){
		struct Node *tmp = list->head;
		list->head = tmp->next;
		tmp->next = NULL;
		void *p = tmp->data;
		free(tmp);
		return p;
	}
	else{
		return NULL;
	}
}
/*
 * Remove all nodes from the list, deallocating the memory for the
 * nodes.  You can implement this function using popFront().
 */
void removeAllNodes(struct List *list){
	void *p = popFront(list);
	if(p==NULL)// stops once list is empty  
		return;
	else{
		return removeAllNodes(list);
	}
}
/*
 * Create a node that holds the given data pointer,
 * and add the node right after the node passed in as the 'prevNode'
 * parameter.  If 'prevNode' is NULL, this function is equivalent to
 * addFront().
 *
 * Note that prevNode, if not NULL, is assumed to be one of the nodes
 * in the given ilist.  The behavior of this function is undefined if
 * prevNode does not belong in the given list.
 *
 * Note that this function does not manage the lifetime of the object
 * pointed to by 'data'. // By lifteime does it mean that it should held in the stack?
 * 
 * It returns the newly created node on success and NULL on failure.
 */
struct Node *addAfter(struct List *list, 
		struct Node *prevNode, void *data){
	if(prevNode != NULL){
		struct Node *new = (struct Node*)malloc(sizeof(struct Node));
		if(new != NULL){
			new->data = data; 
			new->next = prevNode->next;
			prevNode->next = new;
			return new;
		}
		else
			return NULL;
	}
	else
		return addFront(list, data);
}
/* 
 * Reverse the list.
 *
 * Note that this function reverses the list purely by manipulating
 * pointers.  It does NOT call malloc directly or indirectly (which
 * means that it does not call addFront() or addAfter()).
 *
 * Implementation hint: keep track of 3 consecutive nodes (previous,
 * current, next) and move them along in a while loop.  Your function
 * should start like this:


      struct Node *prv = NULL;
      struct Node *cur = list->head;
      struct Node *nxt;

      while (cur) {
          ......


 * And at the end, prv will end up pointing to the first element of
 * the reversed list.  Don't forget to assign it to list->head.
 */
void reverseList(struct List *list){	
	struct Node *prv = NULL;
	struct Node *cur = list->head;	
	struct Node *nxt;
		while(cur){//steps set nxt = cur next set nxt->next = prev then set

			nxt = cur->next;// sets nxt = the values whose ref should be the node that used to reference it
			cur->next = prv;
			prv = cur;
			cur = nxt;
		}		
		list->head = prv;
}


