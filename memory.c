#include "simple_shell.h"

/**
* my_malloc - Allocate memory using malloc and handle errors.
* @size: Size of the memory to allocate.
* Return: Pointer to the allocated memory.
*/
void *my_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/**
* my_realloc - Reallocate memory using realloc and handle errors.
* @ptr: Pointer to the previously allocated memory.
* @size: New size of the memory.
* Return: Pointer to the reallocated memory.
*/
void *my_realloc(void *ptr, size_t size)
{
	void *new_ptr = realloc(ptr, size);

	if (new_ptr == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	return (new_ptr);
}

/**
* my_free - Free allocated memory using free.
* @ptr: Pointer to the memory to free.
*/
void my_free(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
	}
}
