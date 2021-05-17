-- B83004D0M.ADA

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
--     OF PARTS OF A GENERIC PACKAGE, WHEN THE BODY IS A SEPARATELY
--     COMPILED SUBUNIT:
--          A) VISIBLE-BODY.
--          B) PRIVATE-BODY.
--          C) BODY-BODY.

-- TEST FILES:
--      THIS TEST CONSISTS OF THE FOLLOWING FILES:
--      -> B83004D0M.ADA   MAIN PROCEDURE.
--         B83004D1.ADA    SUBUNIT PACKAGE BODY FOR MAIN PROCEDURE.
--         B83004D2.ADA    SUBUNIT PACKAGE BODY FOR MAIN PROCEDURE.
--         B83004D3.ADA    SUBUNIT PACKAGE BODY FOR MAIN PROCEDURE.

-- APPLICABILITY CRITERIA:
--     THIS TEST IS APPLICABLE TO ALL ADA 95 IMPLEMENTATIONS.

-- HISTORY:
--     TBN 07/25/88  CREATED ORIGINAL VERSION.
--     RDH 04/09/90  MODIFIED TEST TO ONLY HAVE ONE PACKAGE BODY IN
--                   EACH FILE.
--     LDC 10/10/90  REDUCED ARRAY RANGES.
--     RLB 09/13/99  UPDATED APPLICABILITY CRITERIA AND HEADERS FOR ADA 95.

PROCEDURE B83004D0M IS

-- CASE A:
     GENERIC
     PACKAGE PACK1 IS
          VAR1 : INTEGER := 1;
          CON1 : CONSTANT STRING := "HELLO";
          EXC1 : EXCEPTION;

          TYPE INT IS NEW INTEGER;
          SUBTYPE INT_SUBTYPE IS INTEGER RANGE 1..10;

          PACKAGE P IS
               X : INTEGER := 0;
          END P;

          TASK T;

          GENERIC
          FUNCTION FUN RETURN INTEGER;

          PROCEDURE PROC1 (X : IN INTEGER; Y : OUT BOOLEAN);
     END PACK1;


     PACKAGE BODY PACK1 IS SEPARATE;


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

          PROCEDURE PROC2 (X : IN INTEGER; Y : OUT BOOLEAN);
     END PACK2;


     PACKAGE BODY PACK2 IS SEPARATE;


-- CASE C:
     GENERIC
     PACKAGE PACK3 IS
          NEW_VAR : BOOLEAN;
          TYPE ARR1 IS ARRAY (1..3) OF CHARACTER;
          TYPE ARR2 IS ARRAY (1..2) OF ARR1;
          TYPE ARR3 IS ARRAY (1..3) OF ARR2;
          TYPE ARR4 IS ARRAY (1..2) OF ARR3;
          TYPE ARR5 IS ARRAY (1..3) OF ARR4;
          TYPE ARR6 IS ARRAY (1..2) OF ARR5;
          ARRAY_OBJECT : ARR6;

     END PACK3;


     PACKAGE BODY PACK3 IS SEPARATE;


BEGIN
     NULL;
END B83004D0M;
