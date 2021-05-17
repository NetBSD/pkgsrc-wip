-- C761011.A
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
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--    Check that if a Finalize propagates an exception, other Finalizes due
--    to be performed are performed.
--        Case 1: A Finalize invoked due to the end of execution of
--        a master. (Defect Report 8652/0023, as reflected in Technical
--        Corrigendum 1).
--        Case 2: A Finalize invoked due to finalization of an anonymous
--        object. (Defect Report 8652/0023, as reflected in Technical
--        Corrigendum 1).
--        Case 3: A Finalize invoked due to the transfer of control
--        due to an exit statement.
--        Case 4: A Finalize invoked due to the transfer of control
--        due to a goto statement.
--        Case 5: A Finalize invoked due to the transfer of control
--        due to a return statement.
--        Case 6: A Finalize invoked due to the transfer of control
--        due to raises an exception.
--
--
-- CHANGE HISTORY:
--    29 JAN 2001   PHL   Initial version
--    15 MAR 2001   RLB   Readied for release; added optimization blockers.
--                        Added test cases for paragraphs 18 and 19 of the
--                        standard (the previous tests were withdrawn).
--
--!
with Ada.Finalization;
use Ada.Finalization;
package C761011_0 is

    type Ctrl (D : Boolean) is new Ada.Finalization.Controlled with
        record
            Finalized : Boolean := False;
            case D is
                when False =>
                    C1 : Integer;
                when True =>
                    C2 : Float;
            end case;
        end record;

    function Create (Id : Integer) return Ctrl;
    procedure Finalize (Obj : in out Ctrl);
    function Was_Finalized (Id : Integer) return Boolean;
    procedure Use_It (Obj : in Ctrl);
       -- Use Obj to prevent optimization.

end C761011_0;
