
with Impdef;
WITH REPORT; USE REPORT;
PRAGMA ELABORATE (REPORT);
with Impdef;
PACKAGE BODY C94004C_PKG IS

     TASK BODY TT IS
          I : INTEGER := IDENT_INT (Integer(Impdef.Clear_Ready_Queue+1.0));
     BEGIN
          ACCEPT E;
          COMMENT ("DELAY LIBRARY TASK FOR LONG TIME");
          DELAY DURATION(I);
          -- MAIN PROGRAM SHOULD NOW BE TERMINATED.
          RESULT;
          -- USE LOOP FOR SELECTIVE WAIT WITH TERMINATE.
          LOOP
               SELECT
                    ACCEPT E;
               OR
                    TERMINATE;
               END SELECT;
          END LOOP;
          -- FAILS IF JOB HANGS UP WITHOUT TERMINATING.
     END TT;

END C94004C_PKG;
