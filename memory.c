#include "martins.h"

/**
 * mfree - free a pointers
 * @asq: address to pointer
 * Return: Alwasys 0
 */

int mfree(void **asq)
{
	while (asq && *asq)
	{
		free(*asq);
		*asq = NULL;
		return (1);
	}
	return (0);
}

