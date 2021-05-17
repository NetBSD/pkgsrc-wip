-- B95094A.ADA

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
-- CHECK THAT AN ENTRY FAMILY NAME IS NOT OVERLOADABLE.

-- JWC 7/22/85
-- JRK 10/1/85

PROCEDURE B95094A IS

     TYPE NEWINT IS NEW INTEGER;

     TASK T IS

          ENTRY E (1 .. 10) (X : IN INTEGER);      -- OK: INITIAL
                                                   --     DECLARATION.

          ENTRY E (1 .. 10) (X : OUT INTEGER);     -- ERROR: ILLEGAL
                                                   --        OVERLOAD.
          ENTRY E (1 .. 10) (X : IN OUT INTEGER);  -- ERROR: ILLEGAL
                                                   --        OVERLOAD.
          ENTRY E (0 .. 5) (X : IN INTEGER);       -- ERROR: ILLEGAL
                                                   --        OVERLOAD.
          ENTRY E (1 .. 10) (X : IN NEWINT);       -- ERROR: ILLEGAL
                                                   --        OVERLOAD.
          ENTRY E (1 .. 10) (X : IN INTEGER;
                             Y : IN OUT INTEGER);  -- ERROR: ILLEGAL
                                                   --        OVERLOAD.
          ENTRY E ('A' .. 'Z') (Y : IN CHARACTER); -- ERROR: ILLEGAL
                                                   --        OVERLOAD.
          ENTRY E (Z : IN BOOLEAN);                -- ERROR: ILLEGAL
                                                   --        OVERLOAD.

     END T;

     TASK BODY T IS
     BEGIN
          NULL;
     END T;

BEGIN
     NULL;
END B95094A;
