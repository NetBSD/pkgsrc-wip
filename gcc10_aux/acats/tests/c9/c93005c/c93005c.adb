
WITH REPORT, C93005C_PK1;
USE  REPORT, C93005C_PK1;
WITH SYSTEM; USE SYSTEM;
PROCEDURE C93005C IS


BEGIN

     TEST("C93005C", "TEST EXCEPTIONS TERMINATE NOT YET ACTIVATED " &
                     "TASKS");

     COMMENT("SUBTEST 1: TASKS IN DECL PART OF A BLOCK AND A PACKAGE " &
             "SPEC");
     COMMENT("  THE TASKS DEPEND ON THE DECLARATIVE PART");
B1:  DECLARE
          X : MNT;
     BEGIN
B2:       BEGIN
B3:            DECLARE
                    TYPE ACC_MNT IS ACCESS MNT;
                    T1 : UNACTIVATED;
                    M2 : ACC_MNT := NEW MNT;

                    PACKAGE RAISES_EXCEPTION IS
                         T2 : UNACTIVATED;
                         M3 : ACC_MNT := NEW MNT;
                         I  : POSITIVE := IDENT_INT(0); -- RAISE
                                          -- CONSTRAINT_ERROR EXCEPTION
                    END RAISES_EXCEPTION;
                    USE RAISES_EXCEPTION;
               BEGIN  -- WOULD HAVE BEEN ACTIVATED HERE
                    IF EQUAL (I, I) THEN
                         FAILED ("EXCEPTION NOT RAISED");
                    END IF;
               EXCEPTION
                    WHEN OTHERS =>
                         FAILED ("EXCEPTION RAISED IN WRONG SCOPE");
               END B3;
          EXCEPTION
               WHEN CONSTRAINT_ERROR =>
                    COMMENT ("SUBTEST 1 COMPLETED");
               WHEN OTHERS =>
                    FAILED ("WRONG EXCEPTION RAISED IN B2");
          END B2;
     END B1;

     CHECK;

     RESULT;

EXCEPTION
     WHEN OTHERS =>
          FAILED ("EXCEPTION NOT ABSORBED");
          RESULT;
END C93005C;
