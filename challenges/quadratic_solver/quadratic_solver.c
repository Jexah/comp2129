#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum
{
	SUCCESS, FAIL
} Status;

typedef struct Quadratic
{
	float a;
	float b;
	float c;
} Quadratic;

typedef struct Roots
{
	float x1;
	float x2;
} Roots;

Status verifyQuadratic(Quadratic *quad)
{
	if(quad->a == 0)
	{
		printf("'a' must be non-zero");
		return FAIL;
	}
	else if(quad->b == 0)
	{
		printf("'b' must be non-zero");
		return FAIL;
	}
	else if(quad->c == 0)
	{
		printf("'c' must be non-zero");
		return FAIL;
	}
	return SUCCESS;
}

Status solveRoots(Quadratic *quad, Roots *roots)
{
	if(pow(quad->b, 2) - 4*quad->a*quad->c < 0)
	{
		return FAIL;
	}
	roots->x1 = ((-quad->b) - sqrt(pow(quad->b, 2)-(4*quad->a*quad->c))) / (2*quad->a);
	roots->x2 = ((-quad->b) + sqrt(pow(quad->b, 2)-(4*quad->a*quad->c))) / (2*quad->a);
	return SUCCESS;
}

float getFloat(char *string)
{
	char *errorBuffer;
	*errorBuffer = 0;
	printf("YOLO111");
	float tmp = (float)(strtod(string, &errorBuffer));
	printf("YOLO222");
	printf("'%c'", *errorBuffer);
	if(*errorBuffer == ' ' || *errorBuffer == '\n' || *errorBuffer == 0)
	{
		printf("YOLO333");
		printf("'%f'", tmp);
		return tmp;
	}
	printf("Invalid input1");
	exit(FAIL);
}

Status getFloats(char *string, Quadratic *quad)
{
	printf("\n1");
	quad->a = getFloat(string);
	printf("\n2");
	char *firstSpace = strchr(string, ' ');
	if(firstSpace == NULL)
	{
		printf("Whoops1");
	}
	printf("\n3");
	printf("%p :: %p", string, firstSpace);
	quad->b = getFloat(firstSpace+1);
	printf("\n4");
	char *secondSpace = strchr(firstSpace+1, ' ');
	printf("\n5");
	quad->c = getFloat(secondSpace);
	printf("\n6");
	return SUCCESS;
}


int main(void)
{
	char buffer[25];
	if(fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		Quadratic quad = {0};
		Roots roots = {0};

		getFloats(buffer, &quad);

		printf("Pre-verify");

		if(verifyQuadratic(&quad) == FAIL)
		{
			printf("Failed to verify");
			return FAIL;
		}

		if(solveRoots(&quad, &roots) == FAIL)
		{
			printf("No roots");
			return(FAIL);
		}

		printf("X1: %.1f\n", roots.x1);
		if(roots.x1 != roots.x2)
		{
			printf("X2: %.1f", roots.x2);
		}
	}
	else
	{
		printf("'%s'Invalid input2", buffer);
		return FAIL;
	}
	return SUCCESS;
}
