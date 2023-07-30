#include <iostream>
#include "DLList.h"
//CONSTRUCTOR and DESTRUCTOR-------------------
DLList::DLList() {

}
DLList::~DLList() {
	//Destructor
}
//---------------------------------------------

//Node insert/add functions---------------------------------------------------------+
void DLList::insertFront(struct node** head, int data) {
	
	struct node* NewNode = new node;

	NewNode->data = data;
	
	NewNode->next = (*head);
	/*the reason NewNode->next is set to head : 
	insertFront(&head, 2) 
	0->1->2->3		|0 is considered head and will be after 2 when inserted as shown.
	2->0->1->2->3	|as can be seen 0 is now behind 2 and 2 is the new head.*/
	NewNode->prev = NULL;
	//set previous to NULL to signify it is the HEAD/START/FRONT. :O  <- shock
	if ((*head) != NULL) {
		(*head)->prev = NewNode;
	}	
	/*if head which is the now the next node[NewNode->Head]
	and now head needs to link back to NewNode if it has a 
	value and isn't NULL: [NewNode <- Head] 
	In the end [NewNode <=> Head]*/
	(*head) = NewNode;
	//NewNode is Declared as the HEAD
	std::cout << "Node inserted at FRONT with data -> " << data << std::endl;
}

void DLList::insertEnd(struct node** head, int data) {
	
	struct node* NewNode = new node;

	NewNode->data = data;

	NewNode->next = NULL;

	struct node* temp = *head;

	if (*head == NULL) { //Head node is NULL, true: NewNode is declared the HEAD, since it is first Node
		NewNode->prev = NULL;
		*head = NewNode;
		return;
	}

	while (temp->next != NULL) { //loops through nodes until found original END node
		temp = temp->next;
	}

	temp->next = NewNode;
	//makes original node Point 'next' value at NewNode
	NewNode->prev = temp;
	//and sets previous to original end node.
	std::cout << "Node inserted at END with data -> " << data << std::endl;
}

void DLList::insertNode(struct node* prev_node, int data) {
	
	if (prev_node == NULL) {
		std::cout << "Previous node CANNOT be NULL" << std::endl;
		return;
	}

	struct node* NewNode = new node;

	NewNode->data = data;

	//1:
	NewNode->next = prev_node->next; 
	prev_node->next = NewNode;

	//2:
	NewNode->prev = prev_node;


	//3:
	if (NewNode->next != NULL) {
		NewNode->next->prev = NewNode;
	}

	/*	0:	[Prev_node]	<=>	[prev_node->next]

		1:	[NewNode]	->	[prev_node->next] (NewNode points to original (prev_node) NEXT node)
			[Prev_node]	->	[NewNode] (previous points to NewNode)

		2:	[Prev_node] <=>	[NewNode]	->	[prev_node->next] (NewNode points to prev_node as well as the next node)
			
		3:a	[Prev_node]	<=>	[NewNode]<=>[prev_node->next]
		If NewNode->next does not = NULL meaning it is a Node

		3:b	[Prev_node]	<=>	[NewNode]->[prev_node->next(NULL)]
		if NewNode->next does = NULL then it is now at the END, so it is the NEW END
	*/
	std::cout << "Node inserted at [" << prev_node << "] with data -> " << data << std::endl;
}

void DLList::insertNode(struct node** head, int pos, int data) {

	if (*head == NULL || pos <= 0) {
		return;
	}

	struct node* temp = *head;

	if (temp->next == NULL) {
		deleteNode(head, temp);
		return;
	}

	for (int i = 0; temp->next != NULL && i < pos; i++) {
		if (temp) {
			temp = temp->next;
		}
	}
	//for loop which checks if next is Not NULL or i is within Position Bounds

	insertNode(temp, data);
	//uses other insertNode to not duplicate code
}
//-------------------------------------------------------------------------------------------------



//Node Deletion Functions--------------------------------------------------------------------------
void DLList::deleteNode(struct node** head, struct node* del_node) {

	if (*head == NULL || del_node == NULL) {
		return;
	}
	//1
	if (*head == del_node) {
		*head = del_node->next;
	}
	//2
	if (del_node->prev != NULL) {
		del_node->prev->next = del_node->next;
	}
	//3
	if (del_node->next != NULL) {
		del_node->next->prev = del_node->prev;
	}
	/*
	del = del_node
	1:
	[head/del]<=>[del->next]....
	head and delete are the same meaning head has to point to del->next
	
	2:
	[!NULL] <=> [del] ==> (del->prev->next =)[!NULL->next = del->next]
	It sets the Previous node's next ndoe value to equal deletes next node value

	3:
	[del] <=> [!NULL] ==> (del->next->prev =)[!NULL->prev = del->prev]
	It sets the Next node's prev node value to equal deletes previos node value

	Successfully removing the Node
	*/

	std::cout << " - Deleted Node... [" << del_node->data << "]" << std::endl;
	free(del_node);
	//then freeing the node from memory entirely
}

//this function works the exact same as the insert node integer position but it doesn't delete the end node if too high;
void DLList::deleteNode(struct node** head, int pos) {
	int i = 0;
	if (*head == NULL || pos <= 0) {
		return;
	}

	struct node* temp = *head;

	if (temp->next == NULL) {
		deleteNode(head, temp);
		return;
	}

	for (i = 0; temp->next != NULL && i < pos; i++) {
		if (temp) {
			temp = temp->next;
		}
	}

	if (temp->next == NULL && i != pos) {
		std::cout << "ERROR: Delete Request Out Of RANGE" << std::endl;
		return;
	}
	
	std::cout << "Deleting Node... " << pos;

	deleteNode(head, temp);
	//uses other delete function using the found temporary function
}
//--------------------------------------------------------------------------------------------------


//Node Detail Functions-----------------------------------------------------------------------------

//returns total number of nodes
int DLList::nodeTotal(struct node** head) {
	
	if ((*head) == NULL) {
		return 0;
	}

	int count = 0;

	struct node* temp = *head;

	while (temp != NULL) { //loop counts how many nodes it has passed untill it becomes NULL
		count++;
		temp = temp->next;
	} 

	return count;
}

bool DLList::listEmpty(struct node** head) {
	if (*head == NULL) { 
		return true;
	}
	return false;
	//head should always have a value if even if 1 node is added, 
	//if not then it will be NULL, meaning it is empty

}
//returns start node data
int DLList::startNode(struct node** head) {
	if (*head == NULL) {
		std::cout << "NO Nodes || NULL" << std::endl;
		return NULL;
	}
	return (*head)->data;
}
//returns endnode data
int DLList::endNode(struct node** head) {
	
	if ((*head) == NULL) {
		std::cout << "NO Nodes || NULL" << std::endl;
		return 0;
	}

	int returnNum = 0;

	struct node* temp = *head;

	while (temp->next != NULL) { //loops until the next node IS NULL indicating it is the END node
		temp = temp->next;
	}

	returnNum = temp->data;
	
	return returnNum;
}

void DLList::displayNodes(struct node* head) {

	struct node* last;
	
	while (head != NULL) {
		std::cout << head->data << "->";
		last = head;
		head = head->next;
	}
	if (head == NULL) {
		std::cout << "NULL\n";
	}
}

//returns Node data, with integer input
int DLList::NodeData(struct node** head, int pos) {

	if (*head == NULL || pos <= 0) {
		return 0;
	}

	struct node* temp = *head;

	int counter = 0;

	for (int j = 1; temp != NULL && j < pos; j++) { 
		if (temp) {
			temp = temp->next;
		}
	}

	if (temp == NULL) {
		return 0;
	}

	int jeb = temp->data;

	return jeb;
}
//-------------------------------------------------------------------------------------------------



//Sort
void DLList::sortList(struct node** head, int nodeTotal) {

	if ((*head) == NULL || (*head)->next == NULL) {
		return;
	}
	
	int tempNum;
	struct node* temp1 = *head;
	struct node* temp2 = temp1->next; //having 2 separate temp nodes allows for an easier sort

	//this program uses a bubble sort algorithm to sort the list
	for (int i = 0; i < nodeTotal - 1; i++) {
		temp2 = temp1;
		for (int j = 0; j < nodeTotal - i; j++) {
			if (temp1->data > temp2->data) {
				tempNum = temp1->data;
				temp1->data = temp2->data;
				temp2->data = tempNum;
			}
			temp2 = temp2->next; 
		}
		temp1 = temp1->next;
	}

	//the bubble sort algorithm moves the node data between different each node rather 
	//than moving the nodes themself.
}


//Clear List
void DLList::clearAllNodes(struct node** head) {

	struct node* temp = new node;

	while ((*head) != NULL) {
		temp = (*head);
		(*head) = (*head)->next;
		free(temp);
	}

	std::cout << "All nodes are deleted successfully.\n";
	//a Clear function used to clear all associated nodes to help clear memory.
}