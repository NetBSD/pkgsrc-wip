-- B650003
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
--*
--
-- OBJECTIVE:
--
--     If the result subtype of a function is class-wide, check that the
--     accessibility level of the type of the return expression cannot be
--     statically deeper than the master that elaborated the function.
--
-- TEST DESCRIPTION:
--
--     We try returning objects of type declared at various nesting levels.
--     Note that a type declared at an inner or parallel nesting level is
--     not visible, and thus can only occur at run-time when returned from
--     another class-wide function.
--
-- CHANGE HISTORY:
--      26 Sep 2007   RLB   Created test.
--
--!
package B650003_0 is
    type Vis_Root is tagged null record;
    type Prv_Root is tagged private;
    Prv_Root_Obj : constant Prv_Root;
    type Intf is limited interface;
private
    type Prv_Root is tagged null record;
    Prv_Root_Obj : constant Prv_Root := (null record);
end;
