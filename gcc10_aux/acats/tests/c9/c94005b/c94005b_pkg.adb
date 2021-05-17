

with Impdef;
PACKAGE BODY C94005B_PKG IS

     TASK BODY TT IS
          LOCAL : INTEGER;
     BEGIN
          ACCEPT E (I : INTEGER) DO
               LOCAL := I;
          END E;
          delay Impdef.Clear_Ready_Queue;
                         -- Since the parent task is ready to run other than
                         -- waiting for termination, it will receive control
                         -- and continue if the error is present.
          GLOBAL := LOCAL;
     END TT;

END C94005B_PKG;
