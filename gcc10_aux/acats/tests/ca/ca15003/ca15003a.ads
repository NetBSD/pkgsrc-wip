-- CA15003.A
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
--
-- OBJECTIVE
--     Check the requirements of 10.1.5(4) and the modified 10.1.5(5)
--     from Technical Corrigendum 1. (Originally discussed as AI95-00136.)
--     Specifically:
--     Check that program unit pragma for a generic package are accepted
--     when given at the beginning of the package specification.
--     Check that a program unit pragma can be given for a generic
--     instantiation by placing the pragma immediately after the instantation.
--
-- TEST DESCRIPTION
--     This test checks the cases that are *not* forbidden by the RM,
--     and makes sure such legal cases actually work.
--
-- CHANGE HISTORY:
--      29 JUN 1999   RAD   Initial Version
--      08 JUL 1999   RLB   Cleaned up and added to test suite.
--      27 AUG 1999   RLB   Repaired errors introduced by me.
--
--!

with System;
package CA15003A is
    pragma Pure;

    type Big_Int is range -System.Max_Int .. System.Max_Int;
    type Big_Positive is new Big_Int range 1..Big_Int'Last;
end CA15003A;
