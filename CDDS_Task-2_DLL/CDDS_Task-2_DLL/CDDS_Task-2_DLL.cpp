#include <iostream>
#include "DLList.h"


int main()
{
    std::cout << "-----Display of a Doubly Linked List-----" << std::endl;
    
    DLList list;
    DLList::node* head = NULL;

    int nodeTotal;

    std::cout << "" << std::endl;
    std::cout << "Program Begin" << std::endl;

    std::cout << "Doubly Linked List Display: " << std::endl;
    list.displayNodes(head);
    std::cout << "Total Nodes Currently: " << list.nodeTotal(&head) << std::endl;
    std::cout << "Empty List Check (1 = true, 0 = false): " << list.listEmpty(&head) << std::endl;
    std::cout << std::endl;

    std::cout << "Adding 6 nodes to the List:" << std::endl;
    list.insertEnd(&head, 5);
    list.insertFront(&head, 4);
    list.insertFront(&head, 3);
    /*
    list.insertFront(&head, 6);
    list.insertFront(&head, 8);
    list.insertFront(&head, 60);
    list.insertFront(&head, 63);
    list.insertFront(&head, 100);
    list.insertFront(&head, 20);
    */ 
    list.insertEnd(&head, 2);
    list.insertNode(head->next->next, 1);
    list.insertNode(&head, 3, 0);

    /*following the order of the inserted nodes it should be displayed as the following:
    insertEnd       5 = [5->NULL]
    insertFront     4 = [4->5->NULL]
    insertFront     3 = [3->4->5->NULL]
    insertEnd       2 = [3->4->5->2->NULL]
    insertNode(3)   1 = [3->4->5->1->2->NULL] (after the 3rd node = NULL->1->2->3->[]->...->NULL]
    insertNode(3)   0 = [3->4->5->1->0->2->NULL]

    Final order = 3->4->5->1->0->2->NULL
    */ 
    //^predictions

    std::cout << std::endl;
    std::cout << "Doubly Linked List Display AFTER adding NODES: " << std::endl;
    list.displayNodes(head);
    std::cout << "Total Nodes Currently: " << list.nodeTotal(&head) << std::endl;
    std::cout << "Empty List Check (1 = true, 0 = false): " << list.listEmpty(&head) << std::endl;
    std::cout << "First and Last Node Data: " << list.startNode(&head) <<  "...." << list.endNode(&head) << std::endl;
    std::cout << std::endl;
    
    nodeTotal = list.nodeTotal(&head);
    list.sortList(&head, nodeTotal);
    std::cout << "Doubly Linked List Display AFTER sorting NODES: " << std::endl;
    list.displayNodes(head);
    std::cout << "Total Nodes Currently: " << list.nodeTotal(&head) << std::endl;
    std::cout << "Empty List Check (1 = true, 0 = false): " << list.listEmpty(&head) << std::endl;
    std::cout << "First and Last Node Data: " << list.startNode(&head) << "...." << list.endNode(&head) << std::endl;
    std::cout << std::endl;

    std::cout << "deleting 2 NODES: " << std::endl;
    list.deleteNode(&head, 8);
    list.deleteNode(&head, head->next);
    /* Description:
    deleteNode  (3) = head->[0->1->2->{3}->4->5] => head->[0->1->2->->4->5] => head->[0->1->2->4->5]
        Deletes Node based on an integer position.
    deleteNode  (head) = head->[{0}->1->2->4->5] => head->[->1->2->4->5] => head->[1->2->4->5]
        Deletes Node based on pointer location.
    */
    std::cout << std::endl;
    std::cout << "Doubly Linked List Display AFTER deleting NODES: " << std::endl;
    list.displayNodes(head);
    std::cout << "Total Nodes Currently: " << list.nodeTotal(&head) << std::endl;
    std::cout << "Empty List Check (1 = true, 0 = false): " << list.listEmpty(&head) << std::endl;
    std::cout << "First and Last Node Data: " << list.startNode(&head) << "...." << list.endNode(&head) << std::endl;
    std::cout << std::endl;


    return 0;
}

