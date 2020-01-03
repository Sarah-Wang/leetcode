#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
	char *data;
	int max;
	int pos;
};

struct Stack *initStack(int size)
{
	struct Stack *stack;

	stack = calloc(1, sizeof(struct Stack));
	if (!stack) {
		printf("failed to calloc memory for stack\n");
		return NULL;
	}
	stack->max = size;
	stack->pos = -1;
	stack->data = calloc(size, sizeof(char));
	if (!stack->data) {
		printf("failed to calloc memory for stack data\n");
		free(stack);
		stack = NULL;
	}
	return stack;
}

int isStackEmpty(struct Stack *stack)
{
	return (stack->pos == -1);
}

int isStackFull(struct Stack *stack)
{
	return (stack->pos = stack->max - 1);
}

int pushStack(struct Stack *stack, char data)
{
	stack->pos++;
	stack->data[stack->pos] = data;
	return 0;
}

int popStack(struct Stack *stack)
{
	stack->pos--;
	return 0;
}

char getTop(struct Stack *stack)
{
	return stack->data[stack->pos];
}

void destroyStack(struct Stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->max = 0;
	stack->pos = 0;
	free(stack);
	stack = NULL;
}

char isValid(char *s)
{
	struct Stack *stack = NULL;
	char valid = 1;
	int i;
	char tmp;
	int len = strlen(s);

	if (len % 2)
		return 0;

	stack = initStack(len);
	if (!stack)
		return 0;
	for (i = 0; i < len; i++) {
		if (s[i] == '[' || s[i] == '{' || s[i] == '(')
			pushStack(stack, s[i]);
		else {
			if (isStackEmpty(stack)) {
				valid = 0;
				break;
			}
			tmp = getTop(stack);
			if (((s[i] == ']') && (tmp == '['))
				|| ((s[i] == '}') && (tmp == '{'))
				|| ((s[i] == ')') && (tmp == '(')))
				popStack(stack);
			else {
				valid = 0;
				break;
			}
		}
	}
	if (isStackEmpty(stack) == 0)
		valid = 0;

	destroyStack(stack);
	return valid;
}

char isValid_s(char *s)
{
	int len, i;
	int idx = 0;
	char *tmp = NULL;
	char valid = 1;

	len = strlen(s);
	if (len % 2)
		return 0;

	tmp = calloc(1, len / 2 + 1);
	for (i = 0; i < len; i++) {
		if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
			tmp[idx] = s[i];
			idx++;
		} else if (idx == 0) {
			valid = 0;
			break;
		} else if ((s[i] == ']' && tmp[idx - 1] == '[')
				|| (s[i] == '}' && tmp[idx - 1] == '{')
				|| (s[i] == ')' && tmp[idx - 1] == '('))
			idx--;
		else {
			valid = 0;
			break;
		}
	}
	if (idx != 0)
		valid = 0;
	free(tmp);
	tmp = NULL;
	return valid;
}

void main(void)
{
	char *s1 = "({}[)";
	char *s2 = "({}[])";

	printf("isValid-> %s\n", isValid(s1) ? "correct" : "incorrect");
	printf("isValid_s->: %s\n", isValid_s(s2) ? "correct" : "incorrect");
}
