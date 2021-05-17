
WITH REPORT, C93005E_PK1;
USE  REPORT, C93005E_PK1;
WITH SYSTEM; USE SYSTEM;
PROCEDURE C93005E IS


BEGIN

     TEST("C93005E", "TEST EXCEPTIONS TERMINATE NOT YET ACTIVATED " &
                     "TASKS");

     COMMENT("SUBTEST 3: TASK IN DECL PART OF PACKAGE SPEC");
     COMMENT("  THE TASKS DON'T DEPEND ON THE DECLARATIVE PART");
B31: DECLARE
          X : MNT;
     BEGIN
B32:      BEGIN
B33:           DECLARE
                    PACKAGE RAISES_EXCEPTION IS
                         TYPE ACC_MNT IS ACCESS MNT;
                         Y   : ACC_MNT := NEW MNT;
                         PTR : ACC_BAD_REC := NEW BAD_REC;
                    END RAISES_EXCEPTION;
               BEGIN  -- WOULD HAVE BEEN ACTIVATED HERE
                    FAILED("EXCEPTION NOT RAISED");
               EXCEPTION
                    WHEN OTHERS =>
                         FAILED ("EXCEPTION RAISED IN WRONG SCOPE");
               END B33;
          EXCEPTION
               WHEN CONSTRAINT_ERROR =>
                    COMMENT("SUBTEST 3 COMPLETED");
               WHEN OTHERS =>
                    FAILED ("WRONG EXCEPTION RAISED IN B32");
          END B32;
     END B31;

     CHECK;

     RESULT;

EXCEPTION
     WHEN OTHERS =>
          FAILED ("EXCEPTION NOT ABSORBED");
          RESULT;
END C93005E;
