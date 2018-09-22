/*
 * Easy double-link-list implmentation
 * Author: SunTalk
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include <bits/stdc++.h>

struct Node{
	int data;
	Node* next;
	Node* pre;
};

Node *head, *last , *temp; // head is min , last is max

void Insert(const int number){

	Node *NewNode;
	NewNode = new Node;
	NewNode->data = number;

	if(!head){ // head is NULL

		NewNode->pre = NewNode->next = NULL;
		head = last = NewNode;

	} // end if(!head)

	else if( head == last ){ // list have one node

		if( ( NewNode -> data ) >= ( head -> data ) ){ // NewNode is bigger than head

			last = NewNode;
			last->pre = head;
			last->next = NULL;
			head->next = last;

		}
		else if( ( NewNode -> data ) < ( last -> data ) ){ // NewNode is smaller than last

			head = NewNode;
			head->pre = NULL;
			head->next = last;
			last->pre = head;

		}

	} // end if( head == last )
	else{ // list have >= 2 nodes

		if( number <= ( head -> data ) ){ // number is min in all data

			temp=head;
			head=NewNode;
			NewNode=temp;
			head->pre = NULL;
			head->next = NewNode;
			NewNode->pre = head;

		} // end number min

		else if( number >= ( last -> data ) ){ // number is max in all data

			temp=last;
			last=NewNode;
			NewNode=temp;
			last->next = NULL;
			last->pre = NewNode;
			NewNode->next = last;

		}// end number max

		else{ // number is mid between head & last

			Node *i = head;
			Node *j = (head->next);
			while(1){
				if( ( i -> data ) <= number &&  number <= ( j -> data ) ){
					i->next = NewNode;
					j->pre = NewNode;
					NewNode->pre = i;
					NewNode->next = j;
					break;
					
				}
				i = i->next;
				j = j->next;
			} // end while

		} // end number between

	} // end if list have >= 2 node

} // end void insert

void Delete(const int number){ // if want to delete all data for this number , annotation break
	
	Node *i = head;
	
	while(1){
		
		if( number == ( i -> data ) ){ // find it
			
			if( ( i -> pre ) == NULL && ( i -> next ) == NULL ){ // list has only one node

				head = last = NULL;
				break; // delete first data we finded
			
			}// end if delete only one node

			else if( ( i -> pre ) == NULL ){ // delete head

				head = i->next;
				head->pre = NULL;
				break; // delete first data we finded

			} // end if delete head 

			else if( ( i -> next ) == NULL ){ // delete last

				last = i->pre;
				last->next = NULL;
				break; // delete first data we finded

			} // end if delete last

			else{ // delete other

				(i->pre)->next = i->next;
				(i->next)->pre = i->pre;
				break; // delete first data we finded

			} // end if delete mid

		} // end find data

		if( i == last ) // already find all
			break;

		i = i->next;

	} // end while

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