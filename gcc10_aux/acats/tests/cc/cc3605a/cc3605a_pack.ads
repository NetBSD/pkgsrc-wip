-- CC3605A.ADA

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
--     CHECK THAT SOME DIFFERENCES BETWEEN THE FORMAL AND THE
--     ACTUAL SUBPROGRAMS DO NOT INVALIDATE A MATCH.
--          1)  CHECK DIFFERENT PARAMETER NAMES.
--          2)  CHECK DIFFERENT PARAMETER CONSTRAINTS.
--          3)  CHECK ONE PARAMETER CONSTRAINED AND THE OTHER
--               UNCONSTRAINED (WITH ARRAY, RECORD, ACCESS, AND
--               PRIVATE TYPES).
--          4)  CHECK PRESENCE OR ABSENCE OF AN EXPLICIT "IN" MODE
--               INDICATOR.
--          5)  DIFFERENT TYPE MARKS USED TO SPECIFY THE TYPE OF
--               PARAMETERS.

-- HISTORY:
--     LDC 10/04/88  CREATED ORIGINAL TEST.

PACKAGE CC3605A_PACK IS

     SUBTYPE INT IS INTEGER RANGE -100 .. 100;

     TYPE PRI_TYPE (SIZE : INT) IS PRIVATE;

     SUBTYPE PRI_CONST IS PRI_TYPE (2);

PRIVATE

     TYPE ARR_TYPE IS ARRAY (INTEGER RANGE <>) OF BOOLEAN;

     TYPE PRI_TYPE (SIZE : INT) IS
          RECORD
               SUB_A : ARR_TYPE (1 .. SIZE);
          END RECORD;

END CC3605A_PACK;
