#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
 // |data1->|

typedef struct Nod{
	char * data;
	struct Nod * next, * prev;
}Node;

typedef struct Lst{
	Node *head;
	Node *tail;
}List;

List * createList(){
	List * tmp = calloc(1, sizeof(List));
	return tmp;
};

void printList(List *lst){
	printf("print:\n");
	Node *p = lst->head;
	while( p ){
		if(p->next)
			printf("%hhu->", *(p->data));
		else
			printf("%hhu\n", *(p->data));
		p = p->next;
	}
	printf("end\n");
}

void insertL(List *lst, void * data){
	if( !lst->head){
		Node * newN =  calloc(1, sizeof(Node));
		newN->data = data;
		newN->prev = 0;
		newN->next = 0;
		lst->tail = newN;
		lst->head = newN;
		return;
	}
	Node * p = calloc(1, sizeof(Node));
	p->data = data;
	p->next = 0;
	p->prev = lst->tail;
	lst->tail->next = p;
	lst->tail = p;

};

List *  destroyList(List * lst){
	Node *p = lst->head;
	Node * prev = 0;
	while( p )
	{
		prev = p;
		p = p->next;
		free(prev);
	}
	free(lst);
	return 0;
};
// поск элемента
Node * findL(List * lst, char z){
//	Node *tmp = 0;
	Node * fnd = lst->head;
//	if( *(prev->data) == z)
//		return prev;

	while (fnd != 0)
	{
		if( *(fnd->data) == z)
			return fnd;
		fnd = fnd->next;
	}
	return 0;
};

// Вставить элемет перед
void insertBefore(List * lst, Node *point, void *data)
{
    if (!point)
        return;

    if (!lst->head)
    {
        Node * newN =  calloc(1, sizeof(Node));
        newN->data = data;
        newN->prev = 0;
        newN->next = 0;
        lst->tail = newN;
        lst->head = newN;
        return;
    }

    Node * newN = calloc(1, sizeof(Node));
    newN->data = data;

    if (point == lst->head)
    {
        newN->next = lst->head;
        lst->head->prev = newN;
        lst->head = newN;
        lst->head->prev = 0;
        return;
    }

    Node * find = lst->head;

    while (find != lst->tail)
    {
        if (find->next == point)
        {
            find->next = newN;
            newN->prev = find;
            newN->next = point;
            point->prev = newN;
            return;
        }
        find = find->next;
    }

    return;
}

// Вставить после.
void insertAfter(List *lst, Node *point, void *data)
{
    if (!point)
        return;

    if (!lst->head)
    {
        Node * newN =  calloc(1, sizeof(Node));
        newN->data = data;
        newN->prev = 0;
        newN->next = 0;
        lst->tail = newN;
        lst->head = newN;
        return;
    }

    Node * newN = calloc(1, sizeof(Node));
    newN->data = data;

    if (point == lst->tail)
    {
        newN->prev = lst->tail;
        lst->tail->next = newN;
        lst->tail = newN;
        lst->tail->next = 0;
        return;
    }

    Node * find = lst->head;

    while (find != lst->tail)
    {
        if (find == point)
        {
            newN->prev = find;
            newN->next = find->next;
            find->next->prev = newN;
            find->next = newN;
            return;
        }
        find = find->next;
    }

    return;
}

void deleteL(List *lst, Node * del){
//	printf("del: %p %hhu\n", del, *(del->data));
	if(!del)
		return;
	if(del == lst->head && del == lst->tail)
	{
		printf("head-tail\n");
		lst->head = 0;
		lst->tail = 0;
		free(del);
		del = 0;
		return;
	}
	if ( del == lst->head)
	{
		lst->head = lst->head->next;
		printf("head: %hhu\n", *(lst->head->data));
		lst->head->prev = 0;
		free(del);
		del = 0;
		return;
	}
	if (del == lst->tail)
	{
		lst->tail = lst->tail->prev;
		lst->tail->next = 0;
		free(del);
		del = 0;
		return;
	}
	Node * pred, * sled;
	pred = del->prev;
	sled = del->next;
	pred->next = sled;
	sled->prev = pred;
	free(del);
	del = 0;
};

int main(){
	char array[7] = {2, 4 , 7, 8, 12, 44, 3};
	char ardel[7] = { 3, 8, 12, 44, 2, 4, 7};
    char data1 = 33;
    char data2 = 66;
	List *lst = createList();
	for( int i = 0 ; i < 7; i++)
		insertL(lst, array + i);
	printList(lst);
	Node *second = lst->head->next->next;
	Node *prv = second->prev;
	printf("prv: %hhu\n", *(prv->data));
/*	Node *get = findL(lst, 12);
	deleteL(lst, get);
	printList(lst);
	get = findL(lst, 2);
	deleteL(lst, get);
	printList(lst);
	get = findL(lst, 3);
	deleteL(lst, get);
	printList(lst);
/*	if(get)
		printf("get: %hhu\n", *(get->data));
	get = findL(lst, 102);
	if(get)
		printf("get: %hhu\n", *(get->data));
	else
		printf("No\n");
	get = findL(lst, 2);
	printf("get: %hhu\n", *(get->data));
	deleteL(lst, get);
	printList(lst);
	get = findL(lst, 3);
	printf("get: %hhu\n", *(get->data));
//	deleteL(lst, get);
//	printList(lst);
*/
	/*Node *get = 0;
	for( int i = 0; i < 7; i++)
	{
		get = findL(lst, ardel[i]);
		if(get)
			printf("find: %hhu get: %hhu\n", ardel[i], *(get->data));
		else
			printf("find: %hhu No\n", ardel[i]);
		deleteL(lst, get);
		printList(lst);
	}*/
    //insertBefore(lst, lst->tail, &data1);
    //printList(lst);
    insertAfter(lst, lst->head->next, &data2);
    printList(lst);

	destroyList(lst);
}
