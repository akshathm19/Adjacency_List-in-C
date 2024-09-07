#include<stdio.h>
#include<stdlib.h>

int no_of_ver = 0;
struct _node_
{
	int data;
	struct _node_ *next;
};

typedef struct _node_ Node;

void add_edge(Node my_array[],int src,int dest)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	int i;
	new_node->data = dest;
	new_node->next = NULL;
	for(i=0;i<no_of_ver;i++)
	{
		if(my_array[i].data == src)
		{
			Node *temp = &my_array[i];
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			break;
		}
	}

}

int main()
{
	FILE *file;
	char c;
	int i,j;

	file=fopen("list.txt","r");
	for(c=getc(file);c!=EOF;c=getc(file))
	{
		if(c=='\n')
			no_of_ver ++;
	}
	fclose(file);

	//create array of vertex
	Node array[no_of_ver];

	for(i=0;i<no_of_ver;i++)
	{
		array[i].data = i;
		array[i].next = NULL;
	}

	file = fopen("list.txt","r");

	int **adj_matrix = (int **)malloc(sizeof(int *) * no_of_ver);
	for(i=0;i<no_of_ver;i++)
	{
		adj_matrix[i] = (int *)malloc(sizeof(int) * no_of_ver);
	}

	//read the matrix
	for(i=0;i<no_of_ver;i++)
	{
		for(j=0;j<no_of_ver;j++)
		{
			fscanf(file,"%d",&adj_matrix[i][j]);
		}

	}
	fclose(file);

	for(i=0;i<no_of_ver;i++)
	{
		for(j=0;j<no_of_ver;j++)
		{
			//printf("%d%d -> %d",i,j.adj[i][j]);
			printf("%d",adj_matrix[i][j]);
	}
	printf("\n");
	}

	for(i=0;i<no_of_ver;i++)
	{
		for(j=0;j<no_of_ver;j++)
		{
			if(adj_matrix[i][j] == 1)
			{
				add_edge(array,i,j);
			}
		}
	}

	for(i=0;i<no_of_ver;i++)
	{
		Node *cur = &array[i];
		printf("List %d->",i);
		cur = cur->next;
		while(cur != NULL)
		{
			printf("%d -> ",cur->data);
			cur = cur->next;
		}
		printf("NULL\n");
	}

}



