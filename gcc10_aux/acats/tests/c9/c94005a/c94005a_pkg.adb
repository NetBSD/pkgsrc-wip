
with Impdef;
WITH REPORT; USE REPORT;
with Impdef;
PACKAGE BODY C94005A_PKG IS

     TASK BODY TT IS
          I : INTEGER := IDENT_INT (0);
     BEGIN
          ACCEPT E;
          FOR J IN 1 .. 30 LOOP
               I := IDENT_INT (I);
               delay Impdef.Minimum_Task_Switch;
          END LOOP;
          RESULT;   -- FAILURE IF THIS MESSAGE IS NOT WRITTEN.
     END TT;

END C94005A_PKG;
