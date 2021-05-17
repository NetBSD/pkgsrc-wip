-- C761010.A
--
--                             Grant of Unlimited Rights
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
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
--     Check the requirements of the new 7.6(17.1/1) from Technical
--     Corrigendum 1 (originally discussed as AI95-00083).
--     This new paragraph requires that the initialization of an object with
--     an aggregate does not involve calls to Adjust.
--
-- TEST DESCRIPTION
--     We include several cases of initialization:
--        - Explicit initialization of an object declared by an
--          object declaration.
--        - Explicit initialization of a heap object.
--        - Default initialization of a record component.
--        - Initialization of a formal parameter during a call.
--        - Initialization of a formal parameter during a call with
--          a defaulted parameter.
--        - Lots of nested records, arrays, and pointers.
--     In this test, Initialize should never be called, because we
--     never declare a default-initialized controlled object (although
--     we do declare default-initialized records containing controlled
--     objects, with default expressions for the components).
--     Adjust should never be called, because every initialization
--     is via an aggregate.  Finalize is called, because the objects
--     themselves need to be finalized.
--     Thus, Initialize and Adjust call Failed.
--     In some of the cases, these procedures will not yet be elaborated,
--     anyway.
--
-- CHANGE HISTORY:
--      29 JUN 1999   RAD   Initial Version
--      23 SEP 1999   RLB   Improved comments, renamed, issued.
--      10 APR 2000   RLB   Corrected errors in comments and text, fixed
--                          discriminant error. Fixed so that Report.Test
--                          is called before any Report.Failed call. Added
--                          a marker so that the failed subtest can be
--                          determined.
--      26 APR 2000   RAD   Try to defeat optimizations.
--      04 AUG 2000   RLB   Corrected error in Check_Equal.
--      18 AUG 2000   RLB   Removed dubious main subprogram renames (see AI-172).
--      19 JUL 2002   RLB   Fixed to avoid calling comment after Report.Result.
--
--!

with Ada; use Ada;
with Report; use Report; pragma Elaborate_All(Report);
with Ada.Finalization;
package C761010_1 is
    pragma Elaborate_Body;
    function Square(X: Integer) return Integer;
private
    type TC_Control is new Ada.Finalization.Limited_Controlled with null record;
    procedure Initialize (Object : in out TC_Control);
    procedure Finalize (Object : in out TC_Control);
    TC_Finalize_Called : Boolean := False;
end C761010_1;
