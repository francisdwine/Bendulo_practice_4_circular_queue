#ifndef EXERCISE1_H
#define EXERCISE1_H

#include "CircularArrayQ.h"

/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list);

/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list);

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);


int get_queue_length(CircularArrayQueue list){
	int count=0;
	if((list.rear+1)%MAX!=list.front){
		count=1;
		while(list.front!=list.rear){
			list.front=(list.front+1)%MAX;
			count++;
		}
	}
	
	return count;
	
}
PersonLinkedList get_all_females(CircularArrayQueue list){
	PersonLinkedList myLL=NULL;
	int count=get_queue_length(list),i=0;
	printf("%d",count);
	while(i<count){
		if(list.data[list.front].sex=='f'){
			enqueue(&list,list.data[list.front]);
			insert_first_LL(&myLL,list.data[list.front]);
			dequeue(&list);
		
		}
		else{
			enqueue(&list,list.data[list.front]);
			dequeue(&list);
		
		}
		i++;
	}
	return myLL;
}
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
	int count=get_queue_length(*list);
	PersonDynamicArrayList AllMale;
	init_DAL(&AllMale);
	int i=0;
	while(i<count){
		if(list->data[list->front].sex=='m'){
			insert_first_DAL(&AllMale,list->data[list->front]);
			list->front=(list->front+1)%MAX;			
			count--;
		}
		else{
			list->rear=(list->rear+1)%MAX;
			list->data[list->rear]=list->data[list->front];
			list->front=(list->front+1)%MAX;
			i++;
		}
	}
	return AllMale;
	
}
#endif
