/*
* eval - Evaluate the command line that the user has just typed in
*
* If the user has requested a built-in command (quit, jobs, bg or fg)
* then execute it immediately. Otherwise, fork a child process and
* run the job in the context of the child. If the job is running in
* the foreground, wait for it to terminate and then return.  Note:
* each child process must have a unique process group ID so that our
* background children don't receive SIGINT (SIGTSTP) from the kernel
* when we type ctrl-c (ctrl-z) at the keyboard.
*/

 void eval(char *cmdline)
 {
  /* Parse command line */
  bg = parseline(cmdline, argv);
  if (!builtin_cmd(argv))
   {

    /*
    * Block SIGCHLD, SIGINT, and SIGTSTP
    * signals until we can add the job to the job list. This
    * eliminates some nasty races between adding a job to the job
    * list and the arrival of SIGCHLD, SIGINT, and SIGTSTP signals.
    */

    /* Create a child process */
        (pid = fork()
    /* Child  process */
    if (pid == 0)
     {
      /* Each new job must get a new process group ID so that the kernel doesn't
         send ctrl-c and ctrl-z signals to all of the shell's jobs */
    setpgid(0, 0)
    execve(argv[0], argv, environ)
     }

    /* Parent process */
    /* Parent adds the job, and then unblocks signals so that
       the signals handlers can run again */

    if (!bg) waitfg(pid);
   }
  return;
 }
