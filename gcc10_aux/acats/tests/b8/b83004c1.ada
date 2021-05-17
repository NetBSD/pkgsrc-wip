-- B83004C1.ADA

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

-- HISTORY:
--     TBN 07/25/88  CREATED ORIGINAL TEST.
--     RDH 04/09/90  CHANGED TO A MULTI-FILE TEST SO THE PACKAGES WOULD
--                   BE IN DIFFERENT FILES.

PACKAGE B83004C1 IS
-- CASE B:
     GENERIC
     PACKAGE PACK2 IS
          TYPE INT2 IS PRIVATE;
     PRIVATE
          VAR2 : INTEGER := 2;
          CON2 : CONSTANT STRING := "HELLO";
          EXC2 : EXCEPTION;

          TYPE INT2 IS NEW INTEGER;
          SUBTYPE INT_SUBTYPE2 IS INTEGER RANGE 2..20;

          PACKAGE P2 IS
               X : INTEGER := 0;
          END P2;

          TASK T2;

          GENERIC
          FUNCTION FUN2 RETURN INTEGER;

          GENERIC
          PROCEDURE PROC2 (X : IN INTEGER; Y : OUT BOOLEAN);
     END PACK2;
END B83004C1;

PACKAGE BODY B83004C1 IS
     PACKAGE BODY PACK2 IS SEPARATE;
END B83004C1;

SEPARATE (B83004C1)
PACKAGE BODY PACK2 IS

     EXC2 : INTEGER := 2;                                      -- ERROR:
     P2 : CONSTANT STRING := "HELLO";                          -- ERROR:
     INT2 : EXCEPTION;                                         -- ERROR:

     TYPE VAR2 IS NEW INTEGER;                                 -- ERROR:
     SUBTYPE CON2 IS INTEGER RANGE 2..20;                      -- ERROR:

     PACKAGE T2 IS                                             -- ERROR:
          X : INTEGER := 0;
     END T2;

     TASK FUN2;                                                -- ERROR:

     GENERIC
     FUNCTION INT_SUBTYPE2 RETURN INTEGER;                     -- ERROR:

     PROCEDURE PROC2 (A : IN INTEGER; B : OUT BOOLEAN);        -- ERROR:


     TASK BODY T2 IS
     BEGIN
          NULL;
     END T2;

     FUNCTION FUN2 RETURN INTEGER IS
     BEGIN
          RETURN 1;
     END FUN2;

     PROCEDURE PROC2 (X : IN INTEGER; Y : OUT BOOLEAN) IS
     BEGIN
          IF X = 1 THEN
               Y := TRUE;
          ELSE
               Y := FALSE;
          END IF;
     END PROC2;

END PACK2;
