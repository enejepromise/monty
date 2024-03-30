#include "monty.h"

/**
 * free_glbs - frees all global variables and exits
 * @flag: checks for exit success or failure
 *
 * Return: void
 */
void free_glbs(int flag)
{
	/* check if globals are defined and free them */
	if (glbs != NULL)
	{
		if (glbs->blck != NULL)
			free(glbs->blck);

		if (glbs->file != NULL)
			fclose(glbs->file);

		free(glbs);
	}
	/* checks exit status */
	if (flag == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
