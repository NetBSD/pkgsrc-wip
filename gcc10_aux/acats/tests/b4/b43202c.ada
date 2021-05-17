-- B43202C.ADA

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
-- CHECK THAT AN ARRAY AGGREGATE WITH AN OTHERS CHOICE IS
-- ILLEGAL:
--   A) AS AN OPERAND OF A PREDEFINED OPERATOR WHEN THE
--      CONTEXT SPECIFIES A CONSTRAINED ARRAY SUBTYPE.
--   B) AS THE EXPRESSION IN A MEMBERSHIP TEST WHEN THE
--      TYPE MARK DENOTES A CONSTRAINED OR UNCONSTRAINED ARRAY
--      TYPE.

-- EG  01/05/84

PROCEDURE B43202C IS

     TYPE TC IS (RED, GREEN, BLUE);
     TYPE T0 IS ARRAY(TC) OF INTEGER;
     TYPE T1 IS ARRAY(1 .. 2, TC) OF INTEGER;
     TYPE T2 IS ARRAY(TC) OF BOOLEAN;
     TYPE T3 IS ARRAY(INTEGER RANGE <>) OF INTEGER;

     A0 : T0 := (1, 1, 1);
     A1 : T1 := ((1, 1, 1), (2, 2, 2));
     A2 : T2 := (TC => TRUE);
     B2 : T2;
     BB : BOOLEAN;
     C1 : STRING(1 .. 4) := "ABCD";
     C2 : STRING(1 .. 8);

     PROCEDURE PROC1 (A1 : T2) IS
     BEGIN
          NULL;
     END PROC1;

BEGIN
     BB := A0 > (1, OTHERS => 0);                      -- ERROR: A.
     IF ( A1 /= (1 .. 2 => (BLUE => 0,
                            OTHERS => 1) ) ) THEN      -- ERROR: A.
        BB := A0 <= (GREEN => 0, OTHERS => 1);         -- ERROR: A.
     END IF;
     IF ( ( (RED => TRUE, OTHERS => FALSE) AND A2) =   -- ERROR: A.
            NOT ( A2 ) ) THEN
        B2 := A2 XOR (RED => TRUE, BLUE => FALSE,
                      OTHERS => TRUE);                 -- ERROR: A.
     END IF;
     C2 := C1 & (3 => 'A', 2 => 'B', OTHERS => '*');   -- ERROR: A.
     PROC1 (NOT (OTHERS => TRUE) );                    -- ERROR: A.
     PROC1 (A2 AND (OTHERS => TRUE) );                 -- ERROR: A.
     PROC1 ((OTHERS => TRUE) OR A2);                   -- ERROR: A.
     PROC1 (A2 XOR (OTHERS => FALSE) );                -- ERROR: A.
     BB := (1 .. 2 => (RED => 3, OTHERS => 4) ) IN T1; -- ERROR: B.
     BB := (1 .. 2 => (OTHERS => 1) ) NOT IN T1;       -- ERROR: B.
     BB := (OTHERS => (TC => 2) ) IN T1;               -- ERROR: B.
     BB := (OTHERS => 2) IN T3;                        -- ERROR: B.
     BB := (TC => TRUE, OTHERS => FALSE) NOT IN T2;    -- ERROR: B.
END B43202C;
