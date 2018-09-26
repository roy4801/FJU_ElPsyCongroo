/*
 * Easy single-link-list implmentation
 * Author: SunTalk
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include <bits/stdc++.h>

struct Node{
	int data;
	Node* next;
};

Node *head , *last , *temp;

void Insert( const int number ){
	
	Node *NewNode;
	NewNode = new Node;
	NewNode->data = number;

	if( !head ){
		
		NewNode->next = NULL;
		head = last = NewNode;

	} // end if(!head)

	else if( head == last ){

		if( ( NewNode -> data ) >= ( head -> data ) ){ // NewNode is bigger than head
			
			last = NewNode;
			head->next = last;
			last->next = NULL;

		}

		else if( ( NewNode -> data ) < ( last -> data ) ){  // NewNode is smaller than last

			head = NewNode;
			head->next = last;

		}

	} // end if only one node

	else{

		if( number < ( head -> data ) ){ // number is min in all data

			NewNode->next = head;
			head = NewNode;

		} // end number min

		else if( number > ( last -> data ) ){ // number is max in all data

			NewNode->next = NULL;
			last->next = NewNode;
			last = NewNode;

		}// end number max

		else{ // number is mid between head & last

			Node *i = head;
			Node *j = (head->next);
			while( j != NULL ){
				if( ( i -> data ) <= number &&  number <= ( j -> data ) ){
					i->next = NewNode;
					NewNode->next = j;
					break;	
				}
				i = i->next;
				j = j->next;
			} // end while

		} // end number between

	} // end if list have >= 2 node

} // end void insert

void Delete(const int number){

	Node *i = head;
	Node *j = head;

	while(1){

		if( number == ( i -> data ) ){

			if( head == last ){ // delete number is only one node in list
				
				head = last = NULL;
				break; // delete first data we finded

			} // end if delete only one node in list

			else if( i == head ){ // delete head

				head = i->next;
				break; // delete first data we finded

			} // end if delete head

			else if( i == last ){ // delete last

				last = j;
				last->next = NULL;
				break; // delete first data we finded

			} // end if delete last 

			else{ // delete other

				j->next = i->next;
				break; // delete first data we finded

			} // end if delete other

		} // end find data

		if( i == last )
			break;

		j=i;
		i=i->next;

	}

} // end void delete

void Print(){

	Node *i = head;
	int number;

	if( i == NULL )
		printf("NULL");

	while( i != NULL ){

		number = i->data;
		printf("%d ", number );

		if( i == last )
			break;

		i = i->next;

	} // end while

	printf("\n");

} // end print