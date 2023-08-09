#include <iostream>
#include "DLList.h"
//CONSTRUCTOR and DESTRUCTOR-------------------
DLList::DLList() {

}
DLList::~DLList() {
	clearAllNodes();
}
//---------------------------------------------

//Node insert/add functions---------------------------------------------------------+
void DLList::insertFront(int data) {
	
	struct node* NewNode = new node;

	NewNode->data = data;

	if (Empty()) {
		head = end = NewNode;
	}
	else {
		NewNode->next = head;
		/*the reason NewNode->next is set to head :
		insertFront(&head, 2)
		0->1->2->3		|0 is considered head and will be after 2 when inserted as shown.
		2->0->1->2->3	|as can be seen 0 is now behind 2 and 2 is the new head.*/
		NewNode->prev = nullptr;
		//set previous to nullptr to signify it is the HEAD/START/FRONT. :O  <- shock
		if (head != nullptr) {
			head->prev = NewNode;
		}
		head = NewNode;
		/*if head which is the now the next node[NewNode->Head]
		and now head needs to link back to NewNode if it has a
		value and isn't nullptr: [NewNode <- Head]
		In the end [NewNode <=> Head]*/
	}

	//NewNode is Declared as the HEAD
	std::cout << "Node inserted at FRONT with data -> " << data << std::endl;
}

void DLList::insertEnd(int data) {
	
	struct node* NewNode = new node;
	NewNode->data = data;
	if (Empty()) {
		head = end = NewNode;
	}
	else {
		NewNode->next = nullptr;
		NewNode->prev = end;
		end->next = NewNode;
		end = NewNode;
	}
	
	std::cout << "Node inserted at END with data -> " << data << std::endl;
}

void DLList::insertNode(int pos, int data) {

	if (Empty() || pos < 0) {
		return;
	}
	if (pos >= nodeTotal()) {
		insertEnd(data);
	}
	else if ( pos == 0){
		insertFront(data);
	}
	else {
		node* prev_node = head;

		for (int i = 0; prev_node->next != nullptr && i < pos; i++) {
			if (prev_node) {
				prev_node = prev_node->next;
			}
		}
		//for loop which checks if next is Not nullptr or i is within Position Bounds

		node* temp = new node;
		temp->data = data;

		//1:
		temp->next = prev_node->next;
		prev_node->next = temp;

		//2:
		temp->prev = prev_node;

		//3:
		if (temp->next != nullptr) {
			temp->next->prev = temp;
		}

		/*	0:	[Prev_node]	<=>	[prev_node->next]

			1:	[NewNode]	->	[prev_node->next] (NewNode points to original (prev_node) NEXT node)
				[Prev_node]	->	[NewNode] (previous points to NewNode)

			2:	[Prev_node] <=>	[NewNode]	->	[prev_node->next] (NewNode points to prev_node as well as the next node)

			3:a	[Prev_node]	<=>	[NewNode]<=>[prev_node->next]
			If NewNode->next does not = nullptr meaning it is a Node

			3:b	[Prev_node]	<=>	[NewNode]->[prev_node->next(nullptr)]
			if NewNode->next does = nullptr then it is now at the END, so it is the NEW END
		*/
	}

	std::cout << "Node inserted with data -> " << data << std::endl;

}
//-------------------------------------------------------------------------------------------------



//Node Deletion Functions--------------------------------------------------------------------------
void DLList::deleteNodeP(int pos) {
	int i = 0;
	if (Empty() || pos < 0 || pos > nodeTotal()) {
		std::cout << "Number Not in Range, Range is 0 - " << nodeTotal() << std::endl;
		return;
	}

	node* temp = head;

	for (i = 0; temp != end && i < pos; i++) {
		if (temp) {
			temp = temp->next;
		}
	}

	if (temp->next == nullptr && i != pos) {
		std::cout << "ERROR: Delete Request Out Of RANGE" << std::endl;
		return;
	}
	
	std::cout << "Deleting Node... " << pos;

	//1
	if (head == temp) {
		head = temp->next;
	}
	//2
	if (temp->prev != NULL) {
		temp->prev->next = temp->next;
	}
	//3
	if (temp->next != nullptr) {
		temp->next->prev = temp->prev;
	}
	/*
	del = del_node
	1:
	[head/del]<=>[del->next]....
	head and delete are the same meaning head has to point to del->next

	2:
	[!nullptr] <=> [del] ==> (del->prev->next =)[!nullptr->next = del->next]
	It sets the Previous node's next node value to equal deletes next node value

	3:
	[del] <=> [!nullptr] ==> (del->next->prev =)[!nullptr->prev = del->prev]
	It sets the Next node's prev node value to equal deletes previos node value

	Successfully removing the Node
	*/

	std::cout << " - Deleted Node... [" << temp->data << "]" << std::endl;
	delete(temp);
	//then freeing the node from memory entirely
}

void DLList::deleteNodeN(int num) {
	int counter = 0;

	if (Empty()) {
		return;
	}

	node* temp = head;
	displayNodes();

	while (temp != NULL) {
		if (temp->data == num) {
			break;
		}
		temp = temp->next;
		counter++;
	}

	if (temp == nullptr) {
		std::cout << "Number " << num <<" could NOT be FOUND" << std::endl;
		return;
	}
	
	deleteNodeP(counter);

}

void DLList::deleteFront() {
	if (Empty()) {
		return;
	}
	node* delF = new node;
	delF = head;
	head = head->next;
	if (head != nullptr) {
		head->prev = nullptr;
	}
	else {
		end = nullptr;	
	}
	std::cout << "deleted current front node " << delF->data << std::endl;
	delete(delF);
}

void DLList::deleteEnd() {
	if (Empty()) {
		return;
	}
	node* delE = new node;
	delE = end;
	end = end->next;
	if (end != nullptr) {
		end->prev = nullptr;
	}
	else {
		head = nullptr;
	}
	std::cout << "deleted current end node " << delE->data << std::endl;
	delete(delE);
}
//--------------------------------------------------------------------------------------------------


//Node Detail Functions-----------------------------------------------------------------------------

//returns total number of nodes
int DLList::nodeTotal() {
	
	if (head == nullptr) {
		return 0;
	}

	int count = 0;

	node* temp = head;

	while (temp != nullptr) { //loop counts how many nodes it has passed untill it becomes nullptr
		count++;
		temp = temp->next;
	} 

	return count;
}

bool DLList::Empty() {
	if (head == nullptr) { 
		return true;
	}
	return false;
	//head should always have a value if even if 1 node is added, 
	//if not then it will be nullptr, meaning it is empty
}

//returns start node data
int DLList::startNode() {
	if (head == nullptr) {
		std::cout << "NO Nodes || nullptr" << std::endl;
		return -1;
	}
	return head->data;
}

//returns endnode data
int DLList::endNode() {
	
	if (head == nullptr) {
		std::cout << "NO Nodes || nullptr" << std::endl;
		return -1;
	}

	int returnNum = 0;

	returnNum = end->data;
	
	return returnNum;
}

void DLList::displayNodes() {

	node* Current = head;

	while (Current != nullptr) {
		std::cout << Current->data;
		if (Current->next != nullptr) {
			std::cout << "<=>";
		}
		else {
			std::cout << "->";
		}
		Current = Current->next;
	}
	if (Current == nullptr) {
		std::cout << "nullptr\n";
	}
}

//returns Node data, with integer input
int DLList::NodeData(int pos) {

	if (head == nullptr || pos < 0 || pos > nodeTotal()) {
		std::cout << "ERROR" << std::endl;
		return -1;
	}
	if (pos == 0) {
		return startNode();
	}
	else if (pos == nodeTotal()) {
		return endNode();
	}
	else {
		node* temp = head;

		int counter = 0;

		for (int j = 1; temp != NULL && j < pos; j++) {
			if (temp) {
				temp = temp->next;
			}
		}

		int jeb = temp->data;

		return jeb;
	}
}
//-------------------------------------------------------------------------------------------------



//Sort
void DLList::sortList(int nodeTotal) {

	if (head == nullptr || head->next == nullptr) {
		std::cout << "No Values or Not enough Values needed to sort" << std::endl;
		return;
	}
	
	int tempNum;
	node* temp1 = head;
	node* temp2 = temp1->next; //having 2 separate temp nodes allows for an easier sort

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
void DLList::clearAllNodes() {

	node* del = head;
	std::cout << "deleting node: ";
	while (head != nullptr) {
		del = head;
		head = head->next;
		std::cout  << del->data;
		delete(del);
	}

	std::cout << "All nodes are deleted successfully.\n";
	//a Clear function used to clear all associated nodes to help clear memory.
}