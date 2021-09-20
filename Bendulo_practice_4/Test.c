#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Exercise1.h"

int main(void) 
{
    // To do code logic here.
    CircularArrayQueue myq;
    init_array_queue(&myq);
    Person p=createPerson("francis",'m',"Cebu");
   enqueue(&myq,p);
   enqueue(&myq,createPerson("Muta",'f',"London"));
   enqueue(&myq,createPerson("BigShaq",'f',"London"));
enqueue(&myq,createPerson("inefficientcoder",'m',"Siquijor"));
   enqueue(&myq,createPerson("Shocker",'m',"OLLI"));
  
   PersonLinkedList femaleLL=get_all_females(myq);
   
  
   display_LL(femaleLL);
   PersonDynamicArrayList Males=remove_all_males(&myq);
   display_DAL(Males);
    
    return 0;
}
