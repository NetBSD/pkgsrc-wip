
WITH REPORT, C93005D_PK1, C93005D_ENQUEUE;
USE  REPORT, C93005D_PK1;
WITH SYSTEM; USE SYSTEM;
PROCEDURE C93005D IS


BEGIN

     TEST("C93005D", "TEST EXCEPTIONS TERMINATE NOT YET ACTIVATED " &
                     "TASKS");

     COMMENT("SUBTEST 2: TASKS IN DECL PART OF A BLOCK AND A PACKAGE " &
             "SPEC");
     COMMENT("  THE TASKS DEPEND ON THE DECLARATIVE PART");
     COMMENT("  OTHER TASKS HAVE BEEN ENQUEUED ON THE TASKS' ENTRIES");
B21: DECLARE
          X : MNT;
     BEGIN
B22:      BEGIN
B23:           DECLARE
                    TYPE ACC_MNT IS ACCESS MNT;
                    T1 : UNACTIVATED;
                    Y  : ACC_MNT := NEW MNT;

                    PACKAGE HAS_UNACTIVATED IS
                         T2 : UNACTIVATED;
                         Z  : ACC_MNT := NEW MNT;
                         PACKAGE ENQUEUE1 IS NEW C93005D_ENQUEUE(T1);
                         PACKAGE ENQUEUE2 IS NEW C93005D_ENQUEUE(T2);
                         I : POSITIVE := IDENT_INT(0); -- RAISE
                                         -- CONSTRAINT_ERROR EXCEPTION.
                    -- TERMINATES T1 AND T2 AND INDIRECTLY THE 2 T3'S
                    END HAS_UNACTIVATED;
                    USE HAS_UNACTIVATED;
               BEGIN  -- WOULD HAVE BEEN ACTIVATED HERE
                    IF EQUAL (I, I) THEN
                         FAILED ("EXCEPTION NOT RAISED");
                    END IF;
               EXCEPTION
                    WHEN OTHERS =>
                         FAILED ("EXCEPTION RAISED IN WRONG SCOPE");
               END B23;
          EXCEPTION
               WHEN CONSTRAINT_ERROR =>
                    COMMENT("SUBTEST 2 COMPLETED");
               WHEN OTHERS =>
                    FAILED ("WRONG EXCEPTION RAISED IN B22");
          END B22;
     END B21;

     CHECK;

     RESULT;

EXCEPTION
     WHEN OTHERS =>
          FAILED ("EXCEPTION NOT ABSORBED");
          RESULT;
END C93005D;
