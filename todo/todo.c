#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

void get_arg_from_command(char *start, int arg, char *buffer)
{
	for(int i = 0; i < arg; ++i)
	{
		if(i != arg)
		{
			start = strchr(start, ' ');
		}
	}
	while(*start != '\n' && *start != ' ' && (*buffer++ = *start++));
}

void print_list(struct list_head *head_ptr)
{
	int current_line = 1;
	printf("%d. %s\n", current_line, head_ptr->data);
	struct list_head *current_ptr = head_ptr->next;
	while(current_ptr != head_ptr)
	{
		current_line++;
		printf("%d. %s\n", current_line, current_ptr->data);
	}
}

void populate_list(struct list_head *head_ptr)
{
	FILE *todo = fopen("todo.txt", "r");
	char buf[128];
	while(fgets(buf, sizeof(buf), todo))
	{
		struct list_head *element = malloc(sizeof(struct list_head));
		element->data = malloc(sizeof(buf));
		strcpy(element->data, buf);
		list_add(element, head_ptr);
		printf("Prev: %s\nCurrent: %s\nNext: %s\n", element->prev->data, element->data, element->next->data);
	}
}

int main(void)
{
	struct list_head list;
	list_init(&list);
	populate_list(&list);
	//print_list(&list);

	printf("\n> ");

	char buf[128];
	char last_command [128];

	while(fgets(buf, sizeof(buf), stdin))
	{
		strcpy(last_command, buf);

		char arg[128] = {0};
		get_arg_from_command(buf, 0, arg);
		printf("'%s'\n", arg);
		if(strcmp(arg, "help") == 0)
		{
			printf("help, new, delete, move, undo\n");
		}
		else if(strcmp(arg, "new") == 0)
		{
			//fprintf(todo, "%s", strchr(buf, ' ')+1);
		}
		else if(strcmp(arg, "move") == 0)
		{
			// move
		}
		else if(strcmp(arg, "delete") == 0)
		{
			// delete
		}
		else if(strcmp(arg, "undo") == 0)
		{
			// undo
		}
		printf("\n> ");
	}

    return 0;
}
