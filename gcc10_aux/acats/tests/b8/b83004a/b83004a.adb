-- B83004A.ADA

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
--     OF PARTS OF A GENERIC PACKAGE: VISIBLE-VISIBLE, VISIBLE-PRIVATE,
--     VISIBLE-BODY, PRIVATE-PRIVATE, PRIVATE-BODY, BODY-BODY.

-- HISTORY:
--     VCL  02/07/88  CREATED ORIGINAL TEST.

PROCEDURE B83004A IS
BEGIN

-- CHECK VISIBLE-VISIBLE.

     DECLARE
          GENERIC
          PACKAGE GPACK1 IS
               TYPE H1 IS RANGE 1..10;

          -- THE HOMOGRAPHS.

               SUBTYPE H1 IS STRING(1..5);          -- ERROR: HOMOGRAPH.

               PACKAGE H1 IS END H1;                -- ERROR: HOMOGRAPH.

               TYPE ENUM3 IS (ENUM31, ENUM32);
               FUNCTION ENUM31 RETURN ENUM3;        -- ERROR: HOMOGRAPH.
          END GPACK1;

          PACKAGE BODY GPACK1 IS
               FUNCTION ENUM31 RETURN ENUM3 IS  -- OPTIONAL ERR MESSAGE:
               BEGIN                            --  BODY OF AN
                    RETURN ENUM32;              --  INVALID FUNCTION.
               END ENUM31;
          END GPACK1;
     BEGIN
          NULL;
     END;

-- CHECK VISIBLE-PRIVATE.

     DECLARE
          GENERIC
          PACKAGE GPACK2 IS
               SUBTYPE H1 IS INTEGER RANGE 1..10;

          PRIVATE
          -- THE HOMOGRAPHS.

               TYPE H1 IS DIGITS 5 RANGE -1.0..1.0;        -- ERROR:
                                                           -- HOMOGRAPH.

               TASK H1;                             -- ERROR: HOMOGRAPH.

               PROCEDURE PROC1 (P1 : INTEGER; P2 : STRING);
               PROCEDURE PROC1 (P3 : INTEGER; P4 : STRING);   -- ERROR:
                                                           -- HOMOGRAPH.
          END GPACK2;

          PACKAGE BODY GPACK2 IS
               PROCEDURE PROC1 (P1 : INTEGER;   -- OPTIONAL ERR MESSAGE:
                                P2 : STRING) IS
               BEGIN
                    NULL;
               END PROC1;

               PROCEDURE PROC1 (P3 : INTEGER;   -- OPTIONAL ERR MESSAGE:
                                P4 : STRING) IS   --  BODY OF AN
               BEGIN                              --  INVALID PROCEDURE.
                    NULL;
               END PROC1;

          END GPACK2;
     BEGIN
          NULL;
     END;

-- CHECK VISIBLE-BODY.

     DECLARE
          GENERIC
          PACKAGE GPACK3 IS
               H1 : CONSTANT := 8.0;
          END GPACK3;

          PACKAGE BODY GPACK3 IS

          -- THE HOMOGRAPHS.

               H1 : CONSTANT BOOLEAN := TRUE;       -- ERROR: HOMOGRAPH.

               TASK TYPE H1;                        -- ERROR: HOMOGRAPH.

               FUNCTION FUNC1 (P1 : INTEGER; P2 : STRING)
                                             RETURN BOOLEAN;
               FUNCTION FUNC1 (P3 : INTEGER;                   -- ERROR:
                               P4 : STRING)                -- HOMOGRAPH.
                                    RETURN BOOLEAN;

          -- REQUIRED BODIES.

               TASK BODY H1 IS                  -- OPTIONAL ERR MESSAGE:
               BEGIN                            --  BODY OF AN INVALID
                    NULL;                       --  TASK TYPE.
               END H1;

               FUNCTION FUNC1 (P1 : INTEGER;    -- OPTIONAL ERR MESSAGE:
                               P2 : STRING)
                               RETURN BOOLEAN IS
               BEGIN
                    RETURN FALSE;
               END FUNC1;

               FUNCTION FUNC1 (P3 : INTEGER;    -- OPTIONAL ERR MESSAGE:
                               P4 : STRING)          --  BODY OF INVALID
                               RETURN BOOLEAN IS     --  FUNCTION.
               BEGIN
                    RETURN FALSE;
               END FUNC1;

          END GPACK3;
     BEGIN
          NULL;
     END;

-- CHECK PRIVATE-PRIVATE.

     DECLARE
          GENERIC
          PACKAGE GPACK4 IS
          PRIVATE
               H1 : CONSTANT BOOLEAN := TRUE;

          -- THE HOMOGRAPHS.

               H1 : CONSTANT := 8.0;                -- ERROR: HOMOGRAPH.

               GENERIC                              -- ERROR: HOMOGRAPH.
               PROCEDURE H1;
          END GPACK4;

          PACKAGE BODY GPACK4 IS
               PROCEDURE H1 IS                  -- OPTIONAL ERR MESSAGE:
               BEGIN                            --  BODY OF AN INVALID
                    NULL;                       --  GENERIC PROCEDURE.
               END H1;
          END GPACK4;
     BEGIN
          NULL;
     END;

-- CHECK PRIVATE-BODY.

     DECLARE
          GENERIC
          PACKAGE GPACK5 IS
          PRIVATE
               H1 : EXCEPTION;
          END GPACK5;

          PACKAGE BODY GPACK5 IS

          -- THE HOMOGRAPHS.

               H1 : INTEGER;                        -- ERROR: HOMOGRAPH.

               GENERIC                              -- ERROR: HOMOGRAPH.
               FUNCTION H1 RETURN BOOLEAN;

          -- REQUIRED BODY.

               FUNCTION H1 RETURN BOOLEAN IS     -- OPTIONAL ERR MESSGE:
               BEGIN                             --  BODY OF AN INVALID
                    RETURN FALSE;                --  GENERIC FUNCTION.
               END H1;

          END GPACK5;
     BEGIN
          NULL;
     END;

-- CHECK BODY-BODY.

     DECLARE
          GENERIC
          PACKAGE GPACK6 IS
          END GPACK6;

          PACKAGE BODY GPACK6 IS
               H1 : INTEGER;

          -- THE HOMOGRAPHS.

               H1 : EXCEPTION;                      -- ERROR: HOMOGRAPH.

               GENERIC                              -- ERROR: HOMOGRAPH.
               PACKAGE H1 IS END H1;
          END GPACK6;
     BEGIN
          NULL;
     END;
END B83004A;
