/***************************************************************************************************************************************************
*Author		:Shivanandu.K
*Date		:
*File		:validate.c
*Title		:Input validation
*Description	:Small helpers that keep re-prompting the user until a usable value is typed in,
			:so a stray keystroke can never crash or desync the menu loop.
****************************************************************************************************************************************************/
#include "inverted_search.h"

/* clears whatever is left on the input line, including the trailing
 * newline, so the next scanf() starts from a clean slate             */
static void clear_input_buffer(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		/* discard */
	}
}

/* reads the menu choice, only accepting 1-5 */
int get_valid_choice(void)
{
	int choice;

	while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5)
	{
		clear_input_buffer();
		printf("Invalid choice, please enter a number between 1 and 5\n");
	}

	clear_input_buffer();
	return choice;
}

/* reads the y/Y/n/N answer and returns it as a lower case 'y' or 'n' */
char get_continue_choice(void)
{
	char ans;

	while (scanf(" %c", &ans) != 1 || (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N'))
	{
		clear_input_buffer();
		printf("Please enter y/Y to continue or n/N to discontinue\n");
	}

	clear_input_buffer();
	return (char) tolower((unsigned char) ans);
}
