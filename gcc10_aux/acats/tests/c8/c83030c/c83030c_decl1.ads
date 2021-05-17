-- C83030C.ADA

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
--     CHECK THAT WITHIN A GENERIC SUBPROGRAM BODY COMPILED AS A SUBUNIT
--     IN THE SAME COMPILATION, NON-HOMOGRAPH SUBPROGRAMS DECLARED
--     OUTSIDE THE GENERIC UNIT, AND HAVING THE SAME IDENTIFIER, ARE NOT
--     HIDDEN.

-- HISTORY:
--     JET 10/17/88  CREATED ORIGINAL TEST.
--     BCB 10/03/90  ADDED "PRAGMA ELABORATE (REPORT);".

WITH REPORT; USE REPORT;
PRAGMA ELABORATE (REPORT);
PACKAGE C83030C_DECL1 IS
     GLOBAL : INTEGER := IDENT_INT(INTEGER'FIRST);
     SWITCH : BOOLEAN := TRUE;

     PROCEDURE C83030C_PROC1;
     PROCEDURE C83030C_PROC1 (X : INTEGER);
     PROCEDURE C83030C_PROC2;
     PROCEDURE C83030C_PROC2 (X : INTEGER);
     FUNCTION C83030C_FUNC3 RETURN INTEGER;
     FUNCTION C83030C_FUNC3 RETURN BOOLEAN;
     FUNCTION C83030C_FUNC3 (X : INTEGER) RETURN INTEGER;
     FUNCTION C83030C_FUNC4 RETURN INTEGER;
     FUNCTION C83030C_FUNC4 RETURN BOOLEAN;
END C83030C_DECL1;
