#include "cshell.h"

/**
  * signal_handler - Handles the signals
  * @sig_id: Identifier of the signal to handle
  *
  * Return: Nothing to returns
  */
void signal_handler(int sig_id)
{
	if (sig_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);

}
