#include <iostream>
#include "DLList.h"


int main()
{
    std::cout << "-----Display of a Doubly Linked List-----" << std::endl;
    
    DLList list;

    int nodeTotal;

    std::cout << "" << std::endl;
    std::cout << "Program Begin" << std::endl;

    std::cout << "Doubly Linked List Display: " << std::endl;
    list.displayNodes();
    std::cout << "Total Nodes Currently: " << list.nodeTotal() << std::endl;
    std::cout << "Empty List Check (1 = true, 0 = false): " << list.Empty() << std::endl;
    std::cout << std::endl;

    std::cout << "Adding nodes to the List:" << std::endl;
    list.insertEnd(5);
    list.insertFront(4);
    list.insertFront(3);
    /*
    list.insertFront(&head, 6);
    list.insertFront(&head, 8);
    list.insertFront(&head, 60);
    list.insertFront(&head, 63);
    list.insertFront(&head, 100);
    list.insertFront(&head, 20);
    */ 
    list.insertEnd(2);
    list.insertNode(2, 1);
    list.insertNode(3, 0);

    list.insertNode(600, 7000); //test case: if position is set too high, it places it at the end

    list.insertEnd(50);

    //list.insertNode(list.nodeTotal(), 666);

    //list.insertNode(0, 666);

    /*following the order of the inserted nodes it should be displayed as the following:
    insertEnd       5 = [5->NULL]
    insertFront     4 = [4->5->NULL]
    insertFront     3 = [3->4->5->NULL]
    insertEnd       2 = [3->4->5->2->NULL]
    insertNode(3)   1 = [3->4->5->1->2->NULL] (after the 3rd node = NULL->1->2->3->[]->...->NULL]
    insertNode(3)   0 = [3->4->5->1->0->2->NULL]

    Final order = 3->4->5->1->0->2->NULL

    TEST CASE       
    insertNode(600) 7000 = [3->4->5->1->0->2->7000->NULL] (Puts Node at last available spot)

    Final Order + Test Case = [3->4->5->1->0->2->7000->NULL]
    */ 
    //^predictions

    std::cout <<
        list.NodeData(0) << " : " <<
        list.NodeData(list.nodeTotal()) << " : " <<
        list.NodeData(500) << " : " <<
        list.NodeData(5) << std::endl;

    std::cout << std::endl;
    std::cout << "Doubly Linked List Display AFTER adding NODES: " << std::endl;
    list.displayNodes();
    std::cout << "Total Nodes Currently: " << list.nodeTotal() << std::endl;
    std::cout << "Empty List Check (1 = true, 0 = false): " << list.Empty() << std::endl;
    std::cout << "First and Last Node Data: " << list.startNode() <<  "...." << list.endNode() << std::endl;
    std::cout << std::endl;
    
    nodeTotal = list.nodeTotal();
    list.sortList(nodeTotal);
    std::cout << "Doubly Linked List Display AFTER sorting NODES: " << std::endl;
    list.displayNodes();
    std::cout << "Total Nodes Currently: " << list.nodeTotal() << std::endl;
    std::cout << "Empty List Check (1 = true, 0 = false): " << list.Empty() << std::endl;
    std::cout << "First and Last Node Data: " << list.startNode() << "...." << list.endNode() << std::endl;
    std::cout << std::endl;

    std::cout << "deleting 2 NODES: " << std::endl;
    list.deleteNodeN(5);
    list.deleteNodeP(60);
    list.deleteFront();
    list.deleteEnd();
    std::cout << "TESTING if it will delete node while being out of range of List: " << std::endl;
    list.deleteNodeN(7); //examples of delete request not going through 
    list.deleteNodeP(600);


    /* Description:
    deleteNode  (3) = head->[0->1->2->{3}->4->5] => head->[0->1->2->->4->5] => head->[0->1->2->4->5]
        Deletes Node based on an integer position.
    deleteNode  (head) = head->[{0}->1->2->4->5] => head->[->1->2->4->5] => head->[1->2->4->5]
        Deletes Node based on pointer location.
    */
    std::cout << std::endl;
    std::cout << "Doubly Linked List Display AFTER deleting NODES: " << std::endl;
    list.displayNodes();
    std::cout << "Total Nodes Currently: " << list.nodeTotal() << std::endl;
    std::cout << "Empty List Check (1 = true, 0 = false): " << list.Empty() << std::endl;
    std::cout << "First and Last Node Data: " << list.startNode() << "...." << list.endNode() << std::endl;
    std::cout << std::endl;

    list.clearAllNodes();

    std::cout << "Doubly Linked List Display AFTER clearing all NODES: " << std::endl;
    list.displayNodes();
    std::cout << "Total Nodes Currently: " << list.nodeTotal() << std::endl;
    std::cout << "Empty List Check (1 = true, 0 = false): " << list.Empty() << std::endl;
    std::cout << "First and Last Node Data: " << list.startNode() << "...." << list.endNode() << std::endl;
    std::cout << std::endl;

    std::cout << "----------------------------" << std::endl;
    std::cout << "Program END" << std::endl;

    getchar();

    return 0;
}

