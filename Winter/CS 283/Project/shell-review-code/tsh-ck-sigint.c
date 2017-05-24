/*
* sigint_handler - The kernel sends a SIGINT to the shell whenever the
*    user types ctrl-c at the keyboard.  Catch it and send it along
*    to the foreground job.
*/
void sigint_handler(int sig)
 {
    /* send SIGINT to the foreground job */
  return;
 }
