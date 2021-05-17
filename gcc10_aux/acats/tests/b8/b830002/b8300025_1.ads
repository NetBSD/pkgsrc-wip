-- B8300020.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687 and
--     F08630-91-C-0015, the U.S. Government obtained unlimited rights in the
--     software and documentation contained herein.  Unlimited rights are
--     defined in DFAR 252.227-7013(a)(19).  By making this public release,
--     the Government intends to confer upon all recipients unlimited rights
--     equal to those held by the Government.  These rights include rights to
--     use, duplicate, release or disclose the released technical data and
--     computer software in whole or in part, in any manner and for any purpose
--     whatsoever, and to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE
--     Check the requirements of the modified 8.3(26) from Technical
--     Corrigendum 1 (originally discussed as AI95-00150).
--     For a type extension declared in a child package, where the parent
--     type is declared in an ancestor package, it is illegal for the two
--     types to have duplicate component names.
--
-- TEST DESCRIPTION
--     We declare lots of types with illegal duplicate component names.
--
-- TEST FILES:
--      This test consists of the following files:
--      -> B8300020.A
--         B8300021.A
--         B8300022.A
--         B8300023.A
--         B8300024.A
--         B8300025.AM
--
-- PASS/FAIL CRITERIA:
--      Files B8300021.A, B8300022.A, B8300023.A, and B8300024.A contain errors.
--	All errors in these files must be detected to pass the test.
--
--
-- CHANGE HISTORY:
--      29 JUN 1999   RAD   Initial Version
--      23 SEP 1999   RLB   Revised to insure that units don't depend on other
--                          units containing errors.
--      24 SEP 1999   RLB   Removed broken test case.
--
--!

with Ada; use Ada;
package B8300025_1 is
    pragma Pure; -- OK

    type T2 is tagged private;
    type T3(Same_Name: Natural) is tagged private;

private

    type T2 is tagged
        record
            Same_Name: Integer;
        end record;

    type My_Char is ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                     'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                     'u', 'v', 'w', 'x', 'y', 'z');
    type My_String is array(Natural range <>) of My_Char;
    type T3(Same_Name: Natural) is tagged
        record
            Str: My_String(1..Same_Name);
        end record;

end B8300025_1;
