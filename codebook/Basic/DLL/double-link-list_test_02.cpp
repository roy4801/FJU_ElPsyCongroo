#include "epk_double-link-list.h"

using namespace std;

int main(int argc, char const *argv[])
{// test for action mix & cut
	
	#ifdef DBG
	freopen("DLL_02.in","r",stdin);
	freopen("DLL_02.out","w",stdout);
	#endif

	Node *one_h , *one_l;
	Node *two_h , *two_l;

	one_h = one_l = two_h = two_l = NULL;

	char kind,type;
	int number;

	while( ~scanf("%c %c %d ", &kind , &type , &number) ){
		// printf("%c %c %d\n",kind,type,number );
		if( kind == 'O'){ // list_one
			
			head = one_h;
			last = one_l;

			if( type == 'I' )
				Insert(number);
			else if( type == 'D' )
				Delete(number);
			else if( type == 'P' ){
			
				if( number == 0 ){
					printf("One_Head:");
					Print_H();
				}
				else if( number == 1 ){
					printf("One_Last:");
					Print_L();
					printf("\n");
				}
				
			} // end if print

			one_h = head;
			one_l = last;

		} // end if kind One

		else if( kind == 'T'){ // list_two

			head = two_h;
			last = two_l;

			if( type == 'I' )
				Insert(number);
			else if( type == 'D' )
				Delete(number);
			else if( type == 'P' ){
			
				if( number == 0 ){
					printf("Two_Head:");
					Print_H();
				}
				else if( number == 1 ){
					printf("Two_Last:");
					Print_L();
					printf("\n");
				}
			} // end if print

			two_h = head;
			two_l = last;

		} // end if kind Two

		else if( kind == 'M' ){ // ( M ,O ,0 ) one = one+two , two=null

			Mix( one_h , one_l , two_h , two_l );
			two_h = two_l = NULL;
			printf("Mix_Head:");
			Print_H();
			printf("Mix_Last:");
			Print_L();
			printf("\n");
			one_h = head;
			one_l = last;

		} // end if kind Mix

		else if( kind == 'C' ){ // [ ( C ,O ,0 ) one - two , two = null ] or [ ( C ,T ,0 ) two - one , one = null ]

			if( type == 'O' ){
				
				Cut( one_h , one_l , two_h , two_l );
				printf("Cut_One_Head:");
				Print_H();
				printf("Cut_One_Last:");
				Print_L();
				printf("\n");
				two_h = two_l =NULL;
				one_h = head;
				one_l = last;

			} // end if type O

			else if( type == 'T' ){

				Cut( two_h , two_l , one_h , one_l );
				printf("Cut_Two_Head:");
				Print_H();
				printf("Cut_Two_Last:");
				Print_L();
				printf("\n");
				one_h = one_l =NULL;
				two_h = head;
				two_l = last;
			
			} // end if type T

		} // end if kind C

	} // end while

	return 0;
}