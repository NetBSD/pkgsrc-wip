-- BC60003.A
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
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- OBJECTIVE:
--     Check that the actual subprogram for a formal abstract subprogram
--     is a dispatching operation of the controlling type or the
--     actual type corresponding to the controlling type of the formal
--     subprogram.
--
-- TEST DESCRIPTION:
--     The commented out subtests (marked ERROR: ??) are not allowed by the
--     wording of the Standard, but could (and perhaps should) be allowed
--     as they are analogous to legal cases that happen in nested instances.
--     The question has been sent to the ARG for a decision. [Note: Those
--     test cases and the "use all type" make this an Ada2012-only test.]
--
-- CHANGE HISTORY:
--     18 May 2015   RLB   Created test.
--     26 May 2015   RLB   Commented out test cases in question until/if
--                         the ARG decides on a result.

package BC60003_A is

    type Root is tagged private;

    procedure P1 (P : in out Root);

    procedure P2 (P : access Root);

    procedure P3 (P : in out Root'Class);

    function F (P : in Root) return Boolean;

    function F2 (P : in Root'Class) return Boolean;

    function Construct return Root;

    function Build return Root'Class;

    package Nested is
        procedure Not_Prim_P (P : in out Root);

        function Not_Prim_F (P : in Root) return Boolean;

        function Not_Prim_Const return Root;
    end Nested;

private
    type Root is tagged null record;
end BC60003_A;
