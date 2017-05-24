/*
* sigchld_handler - The kernel sends a SIGCHLD to the shell whenever
*     a child job terminates (becomes a zombie), or stops because it
*     received a SIGSTOP or SIGTSTP signal. The handler reaps all
*     available zombie children, but doesn't wait for any other
*     currently running children to terminate.
*/
void sigchld_handler(int sig)
 {
  /* Detect any terminated or stopped jobs, but don't wait on the others.
     Use while and waitpid and WNOHANG WUNTRACED
     If process was stopped, then mark at stopped.
     If the job was terminated then delete job.
  */

    /* Was the job stopped by the receipt of a signal?
       check status
    */

    /* Was the job terminated by the receipt of an uncaught signal?
       check status
    */

    /* Did the job terminate normally?
       check status
    */
  /*
  * Check for normal termination of the waitpid loop: Either
  * there were children, but no zombies (child_pid == 0), or there
  * were no children at all (child_pid == -1 and errno == ECHILD).
  */

  return;
 }
