-- BD8004C.TST

--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED 
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE 
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
-- OBJECTIVE:
--     IF A PROCEDURE CONTAINS MACHINE CODE STATEMENTS, THEN NO OTHER
--     FORM OF STATEMENT IS ALLOWED.

-- APPLICABILITY CRITERIA:
--     THIS TEST IS APPLICABLE ONLY TO IMPLEMENTATIONS THAT SUPPORT THE
--     MACHINE CODE STATEMENTS.  IF SUCH STATEMENTS ARE NOT SUPPORTED,
--     THE "WITH" CLAUSE MUST BE REJECTED.

-- MACRO SUBSTITUTION:
--     THE MACRO MACHINE_CODE_STATEMENT IS A VALID MACHINE CODE
--     STATEMENT THAT IS DEFINED IN THE PACKAGE MACHINE_CODE.  IF THE
--     IMPLEMENTATION DOES NOT SUPPORT MACHINE CODE THEN USE THE
--     ADA NULL STATEMENT (I.E. NULL; ).

-- HISTORY:
--     LDC  06/15/88 CREATED ORIGINAL TEST.
--     RJW  02/28/90 MODIFIED CHECK FOR ASSIGNMENT STATEMENT.
--     THS  09/20/90 ADDED CASES FOR 'IF', 'CASE', 'ABORT', AND 'GOTO'.

WITH MACHINE_CODE;                                     -- N/A => ERROR.
USE MACHINE_CODE;

PROCEDURE BD8004C IS

     TASK TSK IS
          ENTRY ENT;
     END TSK;

     INT       : INTEGER;
     FLAG      : BOOLEAN;
     RAISE_ERR : EXCEPTION;

     TASK BODY TSK IS
     BEGIN
          ACCEPT ENT DO
              NULL;
          END;
     END TSK;

     PROCEDURE CHECK_BLOCK IS
     BEGIN
          Asm_Insn'(Asm ("nop"));
          BEGIN                                        -- ERROR:
               NULL;
          END;
     END CHECK_BLOCK;

     PROCEDURE DO_NOTHING IS
     BEGIN
          NULL;
     END DO_NOTHING;

     PROCEDURE CHECK_CALL IS
     BEGIN
         Asm_Insn'(Asm ("nop"));
         DO_NOTHING;                                   -- ERROR:
     END CHECK_CALL;

     PROCEDURE CHECK_DELAY IS
     BEGIN
         DELAY 2.0;                                    -- ERROR:
         Asm_Insn'(Asm ("nop"));
     END CHECK_DELAY;

     PROCEDURE CHECK_ENTRY IS
     BEGIN
          TSK.ENT;                                     -- ERROR:
          Asm_Insn'(Asm ("nop"));
     END CHECK_ENTRY;

     PROCEDURE CHECK_LOOP IS
     BEGIN
          Asm_Insn'(Asm ("nop"));
          LOOP                                         -- ERROR:
               NULL;
          END LOOP;
     END;

     PROCEDURE CHECK_NULL IS
     BEGIN
          NULL;                                        -- ERROR:
          Asm_Insn'(Asm ("nop"));
     END CHECK_NULL;

     PROCEDURE CHECK_RAISE IS
     BEGIN
          Asm_Insn'(Asm ("nop"));
          RAISE RAISE_ERR;                             -- ERROR:
     END CHECK_RAISE;

     PROCEDURE CHECK_RETURN IS
     BEGIN
          Asm_Insn'(Asm ("nop"));
          RETURN;                                      -- ERROR:
     END CHECK_RETURN;

     PROCEDURE CHECK_ASSIGNMENT IS
     BEGIN
          Asm_Insn'(Asm ("nop"));
          INT := 5;                                    -- ERROR:
     END;

     PROCEDURE CHECK_IF IS
     BEGIN
          Asm_Insn'(Asm ("nop"));
          IF TRUE THEN                                 -- ERROR:
               NULL;
          END IF;
     END CHECK_IF;

     PROCEDURE CHECK_CASE IS
     BEGIN
          Asm_Insn'(Asm ("nop"));
          CASE FLAG IS                                 -- ERROR:
               WHEN TRUE  =>
                    NULL;
               WHEN FALSE =>
                    NULL;
          END CASE;
     END CHECK_CASE;

     PROCEDURE CHECK_GOTO IS
     BEGIN
          <<LABEL>>
          Asm_Insn'(Asm ("nop"));
          GOTO LABEL;                                  -- ERROR:
     END CHECK_GOTO;

     PROCEDURE CHECK_ABORT IS
     BEGIN
          Asm_Insn'(Asm ("nop"));
          ABORT TSK;                                   -- ERROR:
     END CHECK_ABORT;

BEGIN
     NULL;
END BD8004C;
