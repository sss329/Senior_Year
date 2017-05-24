/*
* builtin_cmd - If the user has typed a built-in command then execute
*    it immediately.
*/
int builtin_cmd(char **argv)
 {
  char *cmd = argv[0];

  if (!strcmp(cmd, "jobs"))
   {
    /* jobs command */
    listjobs(jobs);
    return 1;
   }

    /* bg and fg commands */
    do_bgfg(argv);
  return 0; /* not a builtin command */
 }
