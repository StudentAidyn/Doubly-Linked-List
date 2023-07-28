#include <iostream>
#include "DLList.h"

DLList::DLList() {

}


DLList::~DLList() {
	//Destructor



}

void DLList::insertFront(struct node** head, int data) {
	
	struct node* NewNode = new node;

	NewNode->data = data;

	NewNode->next = (*head);

	NewNode->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = NewNode;


	(*head) = NewNode;

	std::cout << "Node inserted at FRONT with data -> " << data << std::endl;

}

void DLList::insertEnd(struct node** head, int data) {
	
	struct node* NewNode = new node;

	NewNode->data = data;

	NewNode->next = NULL;

	struct node* temp = *head;


	if (*head == NULL) {
		NewNode->prev = NULL;
		*head = NewNode;
		return;
	}

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = NewNode;

	NewNode->prev = temp;

	std::cout << "Node inserted at END with data -> " << data << std::endl;
	//free(temp);

}

void DLList::insertNode(struct node* prev_node, int data) {
	
	if (prev_node == NULL) {
		std::cout << "Previous node CANNOT be NULL" << std::endl;
		return;
	}

	struct node* NewNode = new node;

	NewNode->data = data;

	NewNode->next = prev_node->next;
	prev_node->next = NewNode;

	NewNode->prev = prev_node;

	if (NewNode->next != NULL)
		NewNode->next->prev = NewNode;
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

	for (int i = 0; temp != NULL && i < pos; i++) {
		if (temp) {
			temp = temp->next;
		}

	}

	if (temp == NULL) {
		return;
	}

	insertNode(temp, data);
}

void DLList::deleteNode(struct node** head, struct node* del_node) {

	if (*head == NULL || del_node == NULL) {
		return;
	}

	if (*head == del_node) {
		*head = del_node->next;
	}

	if (del_node->prev != NULL) {
		del_node->prev->next = del_node->next;
	}

	if (del_node->next != NULL) {
		del_node->next->prev = del_node->prev;
	}
	std::cout << " - Deleted Node... [" << del_node->data << "]" << std::endl;
	free(del_node);
}

void DLList::deleteNode(struct node** head, int pos) {

	if (*head == NULL || pos <= 0) {
		return;
	}

	struct node* temp = *head;

	if (temp->next == NULL) {
		deleteNode(head, temp);
		return;
	}

	for (int i = 0; temp != NULL && i < pos; i++) {
		if (temp) {
			temp = temp->next;
		}
		
	}

	

	if (temp == NULL) {
		return;
	}
	
	std::cout << "Deleting Node... " << pos;

	deleteNode(head, temp);
}

int DLList::nodeTotal(struct node** head) {
	
	if ((*head) == NULL) {
		return 0;
	}

	int count = 0;

	struct node* temp = *head;

	while (temp != NULL) {
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
}

int DLList::startNode(struct node** head) {
	if (*head == NULL) {
		std::cout << "NO First Node || NULL" << std::endl;
		return NULL;
	}
	return (*head)->data;
}

int DLList::endNode(struct node** head) {
	int returnNum = 0;

	struct node* temp = *head;

	while (temp->next != NULL) {
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
	if (head == NULL)
		std::cout << "NULL\n";
}


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
		//counter++;
		//std::cout << counter << std::endl;
		
	}

	if (temp == NULL) {
		return 0;
	}

	int jeb = temp->data;

	return jeb;
}

void DLList::sortList(struct node** head, int nodeTotal) {

	if ((*head) == NULL || (*head)->next == NULL) {
		return;
	}

	int tempNum;
	struct node* temp1 = *head;
	struct node* temp2 = temp1->next;

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

}
