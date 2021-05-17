

WITH REPORT;
USE  REPORT;
WITH CC3605A_PACK;
USE  CC3605A_PACK;

PROCEDURE CC3605A IS

     SUBTYPE ZERO_TO_TEN IS INTEGER
          RANGE IDENT_INT (0) .. IDENT_INT (10);

     SUBTYPE ONE_TO_FIVE IS INTEGER
          RANGE IDENT_INT (1) .. IDENT_INT (5);

     SUBPRG_ACT : BOOLEAN := FALSE;
BEGIN
     TEST
          ("CC3605A", "CHECK THAT SOME DIFFERENCES BETWEEN THE " &
                      "FORMAL AND THE ACTUAL PARAMETERS DO NOT " &
                      "INVALIDATE A MATCH");

----------------------------------------------------------------------
-- DIFFERENT PARAMETER NAMES
----------------------------------------------------------------------

     DECLARE

          PROCEDURE ACT_PROC (DIFF_NAME_PARM : ONE_TO_FIVE) IS
          BEGIN
               SUBPRG_ACT := TRUE;
          END ACT_PROC;

          GENERIC

               WITH PROCEDURE PASSED_PROC (PARM : ONE_TO_FIVE);

          PROCEDURE GEN_PROC;

          PROCEDURE GEN_PROC IS
          BEGIN
               PASSED_PROC (ONE_TO_FIVE'FIRST);
          END GEN_PROC;

          PROCEDURE INST_PROC IS NEW GEN_PROC (ACT_PROC);
     BEGIN
          INST_PROC;
          IF NOT SUBPRG_ACT THEN
               FAILED
                    ("DIFFERENT PARAMETER NAMES MADE MATCH INVALID");
          END IF;
     END;

----------------------------------------------------------------------
-- DIFFERENT PARAMETER CONSTRAINTS
----------------------------------------------------------------------

     DECLARE

          PROCEDURE ACT_PROC (PARM : ONE_TO_FIVE) IS
          BEGIN
               SUBPRG_ACT := TRUE;
          END ACT_PROC;

          GENERIC

               WITH PROCEDURE PASSED_PROC (PARM : ZERO_TO_TEN);

          PROCEDURE GEN_PROC;

          PROCEDURE GEN_PROC IS
          BEGIN
               PASSED_PROC (ONE_TO_FIVE'FIRST);
          END GEN_PROC;

          PROCEDURE INST_PROC IS NEW GEN_PROC (ACT_PROC);
     BEGIN
          SUBPRG_ACT := FALSE;
          INST_PROC;
          IF NOT SUBPRG_ACT THEN
               FAILED
                    ("DIFFERENT PARAMETER CONSTRAINTS MADE MATCH " &
                     "INVALID");
          END IF;
     END;

----------------------------------------------------------------------
-- ONE PARAMETER CONSTRAINED (ARRAY)
----------------------------------------------------------------------

     DECLARE

          TYPE ARR_TYPE IS ARRAY (INTEGER RANGE <>) OF BOOLEAN;

          SUBTYPE ARR_CONST IS ARR_TYPE (ONE_TO_FIVE'FIRST ..
               ONE_TO_FIVE'LAST);

          PASSED_PARM : ARR_CONST := (OTHERS => TRUE);

          PROCEDURE ACT_PROC (PARM : ARR_CONST) IS
          BEGIN
               SUBPRG_ACT := TRUE;
          END ACT_PROC;

          GENERIC

               WITH PROCEDURE PASSED_PROC (PARM : ARR_TYPE);

          PROCEDURE GEN_PROC;

          PROCEDURE GEN_PROC IS
          BEGIN
               PASSED_PROC (PASSED_PARM);
          END GEN_PROC;

          PROCEDURE INST_PROC IS NEW GEN_PROC (ACT_PROC);
     BEGIN
          SUBPRG_ACT := FALSE;
          INST_PROC;
          IF NOT SUBPRG_ACT THEN
               FAILED
                    ("ONE ARRAY PARAMETER CONSTRAINED MADE MATCH " &
                     "INVALID");
          END IF;
     END;

----------------------------------------------------------------------
-- ONE PARAMETER CONSTRAINED (RECORDS)
----------------------------------------------------------------------

     DECLARE

          TYPE REC_TYPE (BOL : BOOLEAN) IS
               RECORD
                    SUB_A : INTEGER;
                    CASE BOL IS
                         WHEN TRUE =>
                              DSCR_A : INTEGER;

                         WHEN FALSE =>
                              DSCR_B : BOOLEAN;

                    END CASE;
               END RECORD;

          SUBTYPE REC_CONST IS REC_TYPE (TRUE);

          PASSED_PARM : REC_CONST := (TRUE, 1, 2);

          PROCEDURE ACT_PROC (PARM : REC_CONST) IS
          BEGIN
               SUBPRG_ACT := TRUE;
          END ACT_PROC;

          GENERIC

               WITH PROCEDURE PASSED_PROC (PARM : REC_TYPE);

          PROCEDURE GEN_PROC;

          PROCEDURE GEN_PROC IS
          BEGIN
               PASSED_PROC (PASSED_PARM);
          END GEN_PROC;

          PROCEDURE INST_PROC IS NEW GEN_PROC (ACT_PROC);
     BEGIN
          SUBPRG_ACT := FALSE;
          INST_PROC;
          IF NOT SUBPRG_ACT THEN
               FAILED
                    ("ONE RECORD PARAMETER CONSTRAINED MADE MATCH " &
                     "INVALID");
          END IF;
     END;

----------------------------------------------------------------------
-- ONE PARAMETER CONSTRAINED (ACCESS)
----------------------------------------------------------------------

     DECLARE

          TYPE ARR_TYPE IS ARRAY (INTEGER RANGE <>) OF BOOLEAN;

          SUBTYPE ARR_CONST     IS ARR_TYPE (ONE_TO_FIVE'FIRST ..
               ONE_TO_FIVE'LAST);

          TYPE ARR_ACC_TYPE IS ACCESS ARR_TYPE;

          SUBTYPE ARR_ACC_CONST IS ARR_ACC_TYPE (1 .. 3);

          PASSED_PARM : ARR_ACC_TYPE := NULL;

          PROCEDURE ACT_PROC (PARM : ARR_ACC_CONST) IS
          BEGIN
               SUBPRG_ACT := TRUE;
          END ACT_PROC;

          GENERIC

               WITH PROCEDURE PASSED_PROC (PARM : ARR_ACC_TYPE);

          PROCEDURE GEN_PROC;

          PROCEDURE GEN_PROC IS
          BEGIN
               PASSED_PROC (PASSED_PARM);
          END GEN_PROC;

          PROCEDURE INST_PROC IS NEW GEN_PROC (ACT_PROC);
     BEGIN
          SUBPRG_ACT := FALSE;
          INST_PROC;
          IF NOT SUBPRG_ACT THEN
               FAILED
                    ("ONE ACCESS PARAMETER CONSTRAINED MADE MATCH " &
                     "INVALID");
          END IF;
     END;

----------------------------------------------------------------------
-- ONE PARAMETER CONSTRAINED (PRIVATE)
----------------------------------------------------------------------

     DECLARE
          PASSED_PARM : PRI_CONST;

          PROCEDURE ACT_PROC (PARM : PRI_CONST) IS
          BEGIN
               SUBPRG_ACT := TRUE;
          END ACT_PROC;

          GENERIC

               WITH PROCEDURE PASSED_PROC (PARM : PRI_TYPE);

          PROCEDURE GEN_PROC;

          PROCEDURE GEN_PROC IS
          BEGIN
               PASSED_PROC (PASSED_PARM);
          END GEN_PROC;

          PROCEDURE INST_PROC IS NEW GEN_PROC (ACT_PROC);
     BEGIN
          SUBPRG_ACT := FALSE;
          INST_PROC;
          IF NOT SUBPRG_ACT THEN
               FAILED
                    ("ONE PRIVATE PARAMETER CONSTRAINED MADE MATCH " &
                     "INVALID");
          END IF;
     END;

----------------------------------------------------------------------
-- PRESENCE (OR ABSENCE) OF AN EXPLICIT "IN" MODE
----------------------------------------------------------------------

     DECLARE

          PROCEDURE ACT_PROC (PARM : INTEGER) IS
          BEGIN
               SUBPRG_ACT := TRUE;
          END ACT_PROC;

          GENERIC

               WITH PROCEDURE PASSED_PROC (PARM : IN INTEGER);

          PROCEDURE GEN_PROC;

          PROCEDURE GEN_PROC IS
          BEGIN
               PASSED_PROC (1);
          END GEN_PROC;

          PROCEDURE INST_PROC IS NEW GEN_PROC (ACT_PROC);
     BEGIN
          SUBPRG_ACT := FALSE;
          INST_PROC;
          IF NOT SUBPRG_ACT THEN
               FAILED
                     ("PRESENCE OF AN EXPLICIT 'IN' MODE MADE MATCH " &
                     "INVALID");
          END IF;
     END;

----------------------------------------------------------------------
-- DIFFERENT TYPE MARKS
----------------------------------------------------------------------

     DECLARE

          SUBTYPE MARK_1_TYPE IS INTEGER;

          SUBTYPE MARK_2_TYPE IS INTEGER;

          PROCEDURE ACT_PROC (PARM1 : IN MARK_1_TYPE) IS
          BEGIN
               SUBPRG_ACT := TRUE;
          END ACT_PROC;

          GENERIC

               WITH PROCEDURE PASSED_PROC (PARM2 : MARK_2_TYPE);

          PROCEDURE GEN_PROC;

          PROCEDURE GEN_PROC IS
          BEGIN
               PASSED_PROC (1);
          END GEN_PROC;

          PROCEDURE INST_PROC IS NEW GEN_PROC (ACT_PROC);
     BEGIN
          SUBPRG_ACT := FALSE;
          INST_PROC;
          IF NOT SUBPRG_ACT THEN
               FAILED ("DIFFERENT TYPE MARKS MADE MATCH INVALID");
          END IF;
     END;
     RESULT;
END CC3605A;
