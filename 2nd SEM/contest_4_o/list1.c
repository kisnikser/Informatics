#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct Nod{
	char * data;
	struct Nod * next;
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
}

void insertL(List *lst, void * data){
	if( !lst->head){
		lst->head =  calloc(1, sizeof(Node));
		lst->tail = lst->head;
		lst->head->data= data;
		return;
	}
	Node * p = calloc(1, sizeof(Node));
	p->data = data;
	p->next = 0;
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
// поск элемента перед
Node * findL(List * lst, char z){
//	Node *tmp = 0;
	Node * prev = lst->head;
	if( *(prev->data) == z)
		return prev;

	while (prev != lst->tail)
	{
		if( *(prev->next->data) == z)
			return prev;
		prev = prev->next;
	}
	return 0;
};

// Вставить элемет перед
void insertBefore(List * lst, Node *point, void *data)
{
    if (!point)
        return;

    if(!lst->head)
    {
        lst->head = calloc(1, sizeof(Node));
        lst->tail = lst->head;
        lst->head->data = data;
        lst->head->next = 0;
        return;
    }

    Node * find = lst->head;
    Node * p = calloc(1, sizeof(Node));
    p->data = data;

    if (find == point)
    {
        lst->head = p;
        lst->head->next = point;
        return;
    }

    find = find->next;

    while (find != lst->tail)
    {
        if (find->next == point)
        {
            if (point == lst->head->next)
            {
                p->next = point;
                lst->head->next = p;
                return;
            }
            p->next = point;
            find->next = p;
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

    if(!lst->head)
    {
        lst->head = calloc(1, sizeof(Node));
        lst->tail = lst->head;
        lst->head->data = data;
        lst->head->next = 0;
        return;
    }

    Node * find = lst->head;
    Node * p = calloc(1, sizeof(Node));
    p->data = data;

    while (find)
    {
        if (find == point)
        {
            if (point == lst->tail)
            {
                lst->tail->next = p;
                lst->tail = p;
                lst->tail->next = 0;
                return;
            }
            p->next = point->next;
            point->next = p;
            return;
        }
        find = find->next;
    }

    return;
}

void deleteL(List *lst, Node * del){
	if(!del)
		return;
	Node *prev = lst->head;
	if( del == lst->head)
	{
		lst->head = lst->head->next;
		free(prev);
		return;
	}
	if(del->next == lst->tail)
	{
		free(lst->tail);
		del->next = 0;
		lst->tail = del;
		return;
	}
	Node * deleted = del->next;
	del->next = deleted->next;
	free(deleted);
};

int main(){
	char array[7] = {2, 4, 7, 8, 12, 44, 3};
	char ardel[7] = { 3, 8, 12, 44, 2, 4, 7};
    char data1 = 33;
    char data2 = 66;
	List *lst = createList();
	for( int i = 0 ; i < 7; i++)
		insertL(lst, array + i);
	printList(lst);
    insertBefore(lst, lst->head, &data1);
    printList(lst);
    insertAfter(lst, lst->head, &data2);
    printList(lst);
	/*Node *get = findL(lst, 12);
	if(get)
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
	deleteL(lst, get);
	printList(lst);

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

	destroyList(lst);
}
