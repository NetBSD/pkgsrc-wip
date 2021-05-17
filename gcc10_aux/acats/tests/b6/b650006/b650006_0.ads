-- B650006.A
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
--     Check that an extended return statement containing keyword constant
--     cannot omit an expression.
--
-- TEST DESCRIPTION:
--
--     We try returning constant return objects of types where an initializing
--     expression is not otherwise required. Since this is the same rule as
--     for stand-alone constants, we don't try to be very exhaustive.
--
--     This test checks the last sentence of 6.5(5/3).
--
-- CHANGE HISTORY:
--      30 Dec 2014   RLB   Created test, using the test for 6.5(5.7/3) -
--                          B650003 as a starting point.
--
--!
package B650006_0 is
    type Small is range -10 .. 10;
    subtype Tiny is Small range 1 .. 10;
    type Arr is array (Tiny) of Small;
    type Vis_Root is tagged record
        C : Character := 'A';
    end record;
    type Prv_Root is tagged private;
    Prv_Root_Obj : constant Prv_Root;
private
    type Prv_Root is tagged null record;
    Prv_Root_Obj : constant Prv_Root := (null record);
end;
