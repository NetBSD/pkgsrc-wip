-- C731001.A
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
--     Check that inherited operations can be overridden, even when they are
--     inherited in a body.
--     The test cases here are inspired by the AARM examples given in
--     the discussion of AARM-7.3.1(7.a-7.v).
--     This discussion was confirmed by AI95-00035.
--
-- TEST DESCRIPTION
--     See AARM-7.3.1.
--
-- CHANGE HISTORY:
--      29 JUN 1999   RAD   Initial Version
--      23 SEP 1999   RLB   Improved comments, renamed, issued.
--      20 AUG 2001   RLB   Corrected 'verbose' flag.
--
--!

with Report; use Report; pragma Elaborate_All(Report);
package C731001_1 is
    pragma Elaborate_Body;
private
    procedure Check_String(X, Y: String);
    function Check_String(X, Y: String) return String;
        -- This one is a function, so we can call it in package specs.
end C731001_1;
