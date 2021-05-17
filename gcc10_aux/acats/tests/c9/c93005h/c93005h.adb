
WITH REPORT, C93005H_PK1;
USE  REPORT, C93005H_PK1;
WITH SYSTEM; USE SYSTEM;
PROCEDURE C93005H IS


BEGIN

     TEST("C93005H", "TEST EXCEPTIONS TERMINATE NOT YET ACTIVATED " &
                     "TASKS");

     COMMENT("SUBTEST 6: TASK IN STATEMENT PART OF PACKAGE");
     COMMENT("  THE TASKS DON'T DEPEND ON THE DECLARATIVE PART");
B61: DECLARE
          X : MNT;

          PACKAGE P IS
               Y : MNT;
          END P;

          PACKAGE BODY P IS
               PTR : ACC_BAD_REC;
               Z   : MNT;
          BEGIN
               PTR := NEW BAD_REC;
               FAILED("EXCEPTION NOT RAISED");
          EXCEPTION
               WHEN CONSTRAINT_ERROR =>
                    NULL;
               WHEN OTHERS =>
                    FAILED ("WRONG EXCEPTION RAISED IN P");
          END P;

     BEGIN
          COMMENT ("SUBTEST 6: COMPLETED");
     EXCEPTION
          WHEN OTHERS =>
               FAILED ("EXCEPTION NOT ABSORBED");
     END B61;

     CHECK;

     RESULT;

EXCEPTION
     WHEN OTHERS =>
          FAILED ("EXCEPTION NOT ABSORBED");
          RESULT;
END C93005H;
