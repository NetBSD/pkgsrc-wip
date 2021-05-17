-- B83004D3.ADA

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
--     SEE B83004D0M.ADA.

-- TEST FILES:
--      THIS TEST CONSISTS OF THE FOLLOWING FILES:
--         B83004D0M.ADA   MAIN PROCEDURE.
--         B83004D1.ADA    SUBUNIT PACKAGE BODY FOR MAIN PROCEDURE.
--         B83004D2.ADA    SUBUNIT PACKAGE BODY FOR MAIN PROCEDURE.
--      -> B83004D3.ADA    SUBUNIT PACKAGE BODY FOR MAIN PROCEDURE.

-- HISTORY:
--     TBN 07/25/88  CREATED ORIGINAL VERSION.
--     RDH 04/09/90  MODIFIED TEST TO ONLY HAVE ONE PACKAGE BODY
--                   IN EACH FILE.
--     RLB 09/13/99  UPDATED APPLICABILITY CRITERIA AND HEADERS FOR ADA 95.


SEPARATE (B83004D0M)
PACKAGE BODY PACK3 IS
     VAR3 : INTEGER := 3;
     CON3 : CONSTANT STRING := "HELLO";
     EXC3 : EXCEPTION;

     TYPE INT3 IS NEW INTEGER;
     SUBTYPE INT_SUBTYPE3 IS INTEGER RANGE 3..30;

     PACKAGE P3 IS
          X : INTEGER := 0;
     END P3;

     TASK T3;

     GENERIC
     FUNCTION FUN3 RETURN INTEGER;

     PROCEDURE PROC3 (X : IN INTEGER; Y : OUT BOOLEAN);

     T3 : INTEGER := 3;                                        -- ERROR:
     EXC3 : CONSTANT STRING := "HELLO";                        -- ERROR:
     CON3 : EXCEPTION;                                         -- ERROR:

     TYPE FUN3 IS NEW INTEGER;                                 -- ERROR:
     SUBTYPE P3 IS INTEGER RANGE 3..30;                        -- ERROR:

     PACKAGE INT_SUBTYPE3 IS                                   -- ERROR:
          X : INTEGER := 0;
     END INT_SUBTYPE3;

     TASK VAR3;                                                -- ERROR:

     GENERIC
     FUNCTION INT3 RETURN INTEGER;                             -- ERROR:

     PROCEDURE PROC3 (A : IN INTEGER; B: OUT BOOLEAN);         -- ERROR:

     TASK BODY T3 IS                            -- OPTIONAL ERR MESSAGE.
     BEGIN
          NULL;
     END T3;

     FUNCTION FUN3 RETURN INTEGER IS            -- OPTIONAL ERR MESSAGE.
     BEGIN
          RETURN 1;
     END FUN3;

     PROCEDURE PROC3 (X : IN INTEGER; Y : OUT BOOLEAN) IS   -- OPTIONAL
                                                       --  ERR MESSAGE.
     BEGIN
          IF X = 1 THEN
               Y := TRUE;
          ELSE
               Y := FALSE;
          END IF;
     END PROC3;

END PACK3;
