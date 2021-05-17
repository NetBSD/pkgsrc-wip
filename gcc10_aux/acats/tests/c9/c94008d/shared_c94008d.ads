-- C94008D.ADA

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
-- CHECK CORRECT OPERATION OF SELECT WITH TERMINATE ALTERNATIVE WHEN
-- EXECUTED FROM AN INNER BLOCK WITH OUTER DEPENDING TASKS.

-- JEAN-PIERRE ROSEN 03-MAR-84
-- JRK 4/7/86
-- JBG 9/4/86 ELIMINATED SHARED VARIABLES; ADDED GENERIC UNIT/SUBUNIT
-- PWN 09/11/94  REMOVED PRAGMA PRIORITY FOR ADA 9X.

-- GENERIC UNIT FOR DOING UPDATES OF SHARED VARIABLES
GENERIC
     TYPE HOLDER_TYPE IS PRIVATE;
     TYPE VALUE_TYPE IS PRIVATE;
     INITIAL_VALUE : HOLDER_TYPE;
     WITH PROCEDURE SET (HOLDER : OUT HOLDER_TYPE;
                         VALUE  : IN  HOLDER_TYPE) IS <>;
     WITH PROCEDURE UPDATE (HOLDER : IN OUT HOLDER_TYPE;
                            VALUE  : IN  VALUE_TYPE) IS <>;
PACKAGE SHARED_C94008D IS
     PROCEDURE SET (VALUE : IN HOLDER_TYPE);
     PROCEDURE UPDATE (VALUE : IN VALUE_TYPE);
     FUNCTION GET RETURN HOLDER_TYPE;
END SHARED_C94008D;
