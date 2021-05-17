-- C94005B.ADA

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
-- CHECK THAT IF A TASK TYPE IS DECLARED IN A LIBRARY PACKAGE, ANY
--   BLOCKS, SUBPROGRAMS, OR TASKS THAT DECLARE OBJECTS OF THAT TYPE
--   DO WAIT FOR TERMINATION OF SUCH OBJECTS.
-- SUBTESTS ARE:
--   (A)  IN A MAIN PROGRAM BLOCK.
--   (B)  IN A LIBRARY FUNCTION.
--   (C)  IN A MAIN PROGRAM TASK BODY.

-- THIS TEST CONTAINS SHARED VARIABLES AND RACE CONDITIONS.

-- JRK 10/8/81
-- SPS 11/2/82
-- SPS 11/21/82
-- JWC 11/15/85    MADE THE LIBRARY PACKAGE NAME UNIQUE, C94005B_PKG.
-- PWN 01/31/95    REMOVED PRAGMA PRIORITY FOR ADA 9X.
-- RLB 06/28/19    Replaced excessive delays with Impdef constants.


WITH SYSTEM; USE SYSTEM;
PACKAGE C94005B_PKG IS

     GLOBAL : INTEGER;

     TASK TYPE TT IS
          ENTRY E (I : INTEGER);
     END TT;

END C94005B_PKG;
