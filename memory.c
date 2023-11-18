#include "shell.h"
/**
 *@brief Frees the memory allocated for a pointer and sets it to NULL.
 *
 *This function takes a pointer to a pointer and frees the memory it points to
 *using the standard library function free(). After freeing the memory, it sets
 *the original pointer to NULL to avoid any potential dangling references.
 *
 *@param ptr A pointer to a pointer to be freed.
 *@return 1 if the memory is successfully freed, 0 otherwise.
 */
int freemem(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}

	return (0);
}
