-- C83024E1M.ADA

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
--     CHECK THAT A DECLARATION IN THE DECLARATIVE REGION OF A GENERIC
--     PACKAGE HIDES AN OUTER DECLARATION OF A HOMOGRAPH. ALSO CHECK
--     THAT THE OUTER DECLARATION IS DIRECTLY VISIBLE IN BOTH
--     DECLARATIVE REGIONS BEFORE THE DECLARATION OF THE INNER HOMOGRAPH
--     AND THE OUTER DECLARATION IS VISIBLE BY SELECTION AFTER THE INNER
--     HOMOGRAPH DECLARATION, IF THE GENERIC PACKAGE BODY IS SEPARATELY
--     COMPILED, BUT NOT AS A SUBUNIT.

-- APPLICABILITY CRITERIA:
--     THIS TEST IS APPLICABLE TO IMPLEMENTATIONS THAT SUPPORT SEPARATE
--     COMPILATIONS OF GENERIC SPECIFICATIONS AND BODIES.

-- SEPARATE FILES ARE:
--     C83024E0.ADA -- GENERIC PACKAGE SPECIFICATIONS.
--     C83024E1M.ADA - (THIS FILE) GENERIC PACKAGE BODIES AND
--                     MAIN PROGRAM.

-- HISTORY:
--     BCB 08/30/88  CREATED ORIGINAL TEST.
-- PWN 11/30/94 ADDED A PROCEDURE TO KEEP PACKAGE BODIES LEGAL.

PACKAGE BODY C83024E_P1 IS

     PROCEDURE REQUIRE_BODY IS
     BEGIN
       NULL;
     END;

     PACKAGE BODY C83024E_PACK1 IS
     BEGIN
          IF A /= IDENT_INT(3) THEN
               FAILED ("INCORRECT VALUE FOR INNER HOMOGRAPH - 1");
          END IF;

          IF C83024E_P1.A /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE FOR OUTER HOMOGRAPH - 2");
          END IF;

          IF C83024E_P1.B /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE FOR OUTER VARIABLE - 3");
          END IF;

          IF C /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE FOR INNER VARIABLE - 4");
          END IF;

          IF X /= IDENT_INT(2) THEN
               FAILED ("INCORRECT VALUE PASSED IN - 5");
          END IF;

          IF EQUAL(1,1) THEN
               X := A;
          ELSE
               X := C83024E_P1.A;
          END IF;
     END C83024E_PACK1;
END C83024E_P1;
