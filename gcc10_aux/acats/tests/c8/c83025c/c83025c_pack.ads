-- C83025C.ADA

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
--     CHECK THAT A DECLARATION IN A DECLARATIVE REGION OF A GENERIC
--     SUBPROGRAM HIDES AN OUTER DECLARATION OF A HOMOGRAPH. ALSO CHECK
--     THAT THE OUTER DECLARATION IS DIRECTLY VISIBLE IN BOTH
--     DECLARATIVE REGIONS BEFORE THE DECLARATION OF THE INNER HOMOGRAPH
--     AND THE OUTER DECLARATION IS VISIBLE BY SELECTION AFTER THE INNER
--     HOMOGRAPH DECLARATION, IF THE GENERIC SUBPROGRAM BODY IS COMPILED
--     AS A SUBUNIT IN THE SAME COMPILATION.

-- HISTORY:
--     BCB 09/01/88  CREATED ORIGINAL TEST.

WITH REPORT; USE REPORT;
PRAGMA ELABORATE(REPORT);
PACKAGE C83025C_PACK IS
     Y : INTEGER := IDENT_INT(5);
     Z : INTEGER := Y;

     GENERIC
          TYPE T IS PRIVATE;
          X : T;
     FUNCTION GEN_FUN RETURN T;

     A : INTEGER := IDENT_INT(2);
     B : INTEGER := A;

     OBJ : INTEGER := IDENT_INT(3);

     FLO : FLOAT := 5.0;

     TYPE ENUM IS (ONE, TWO, THREE, FOUR);

     EOBJ : ENUM := ONE;

     GENERIC
          Y : FLOAT := 2.0;
     PROCEDURE INNER (X : IN OUT INTEGER);

     GENERIC
          Y : BOOLEAN := TRUE;
     PROCEDURE INNER2 (X : IN INTEGER := A;
                       A : IN OUT INTEGER);

     GENERIC
          Y : ENUM := ONE;
     FUNCTION INNER3 (X : INTEGER; Z : ENUM := Y) RETURN INTEGER;

     GENERIC
          Y : ENUM;
     FUNCTION INNER4 (X : INTEGER; Z : ENUM := Y) RETURN INTEGER;

     GENERIC
          Y : CHARACTER := 'A';
     PROCEDURE INNER5 (X : IN OUT INTEGER; F : IN FLOAT;
                       Z : CHARACTER := Y);
END C83025C_PACK;
