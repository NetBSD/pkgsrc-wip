-- B83004C2M.ADA

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
--     CHECK THAT HOMOGRAPHS ARE FORBIDDEN IN ANY OF THESE COMBINATIONS
--     OF PARTS OF A GENERIC PACKAGE, WHEN THE BODY IS A SUBUNIT:
--          A) VISIBLE-BODY.
--          B) PRIVATE-BODY.
--          C) BODY-BODY.

-- SEPARATE FILES ARE:
--     B83004C0    PACKAGE SPEC AND BODY PACK1
--     B83004C1    PACKAGE SPEC AND BODY PACK2
--     B83004C2M   MAIN PROCEDURE, PACKAGE SPEC AND BODY PACK3

-- HISTORY:
--     TBN 07/25/88  CREATED ORIGINAL TEST.
--     RDH 04/09/90  CHANGED TO A MULTI-FILE TEST SO THE PACKAGES WOULD
--                   BE IN DIFFERENT FILES.
--     LDC 10/10/90  REDUCED ARRAY RANGES.

PACKAGE B83004C2 IS
-- CASE C:
     GENERIC
          TYPE FUNNY_TYPE IS PRIVATE;
     PACKAGE PACK3 IS
          NEW_VAR : BOOLEAN;
          TYPE ARR1 IS ARRAY (1..2) OF CHARACTER;
          TYPE ARR2 IS ARRAY (1..2) OF ARR1;
          TYPE ARR3 IS ARRAY (1..2) OF ARR2;
          TYPE ARR4 IS ARRAY (1..2) OF ARR3;
          TYPE ARR5 IS ARRAY (1..2) OF ARR4;
          TYPE ARR6 IS ARRAY (1..2) OF ARR5;
          ARRAY_OBJECT : ARR6;

          FUNCTION FUNNY (A : FUNNY_TYPE) RETURN FUNNY_TYPE;

     END PACK3;
END B83004C2;

PACKAGE BODY B83004C2 IS
     PACKAGE BODY PACK3 IS SEPARATE;
END B83004C2;

SEPARATE (B83004C2)
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

     GENERIC
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


     FUNCTION FUNNY (A : FUNNY_TYPE) RETURN FUNNY_TYPE IS
     BEGIN
          RETURN A;
     END FUNNY;

     TASK BODY T3 IS
     BEGIN
          NULL;
     END T3;

     FUNCTION FUN3 RETURN INTEGER IS
     BEGIN
          RETURN 1;
     END FUN3;

     PROCEDURE PROC3 (X : IN INTEGER; Y : OUT BOOLEAN) IS
     BEGIN
          IF X = 1 THEN
               Y := TRUE;
          ELSE
               Y := FALSE;
          END IF;
     END PROC3;

END PACK3;

PROCEDURE B83004C2M IS
BEGIN
     NULL;
END B83004C2M;
