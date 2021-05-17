-- B641002.A
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
-- OBJECTIVE:
--      Check the actual parameter corresponding to an explicitly aliased
--      parameter cannot violate any of the applicable legality rules.
--
-- TEST DESCRIPTION:
--
--      We verify that each of the applicable legality rules is checked:
--
--      (A) The actual parameter is not a non-aliased view of an untagged
--          object nor a untagged value. (6.4.1(6/3)).
--      (B) If the formal parameter's subtype F is untagged, and the nominal
--          subtype of the actual does not statically match F, then F
--          must be unconstrained, discriminated in its full view,
--          and unconstrained in any partial view. (6.4.1(6.1-6.2/3)).
--      (C) For a function call, the accessibility level for the actual
--          object must not be statically deeper than the accessibility level
--          of the master of the call.
--
-- Note that (C) can only fail if the master of the call is not the same as the
-- master of the point in the source where the call occurs. (When it is the
-- same, it's not possible to declare a more local object that would fail the
-- check.) Thus, the cases that are of interest are those defined by bullets
-- 3.10.2(10.2-10.4/3). We try examples based on the first two of those
-- bullets. (Author's note: access discriminants make my head hurt, thus I
-- didn't try the third bullet. The primary point here is to verify that the
-- check is made in some case, rather than all cases.)
--
-- CHANGE HISTORY:
--      04 Dec 13   RLB     Initial version.
--      26 Mar 14   RLB     Renamed for ACATS, fixed minor errors.
--!
package B641002_A is

    type Root is tagged null record;

    type Int is range -100 .. 100;

    subtype Nat is Int range 0 .. Int'Last;

    type P1 is private; -- Constrained partial view.

    type P2 (<>) is private; -- Unconstrained partial view.

    type P3 (<>) is private; -- Unconstrained partial view.

    type P4 is tagged private; -- Tagged type, constrained partial view.

    procedure ProcI (P : aliased in Int);

    procedure Proc1 (P : aliased in P1);

    procedure Proc2 (P : aliased in P2);

    procedure Proc3 (P : aliased in P3);

    procedure Proc4 (P : aliased in P4);

    type LRec (A : access constant Int) is limited null record;

    type A_Rec is access all LRec;

    function Constructor (P : aliased in Int) return LRec;

    type A_Int is access constant Int;

private

    type P1 (D : Int := 1) is record -- Unconstrained full view, constrained partial view.
       C1 : Character;
    end record;

    type P2 (D : Int) is record -- Unconstrained partial and full view.
       C1 : Character;
    end record;

    type P3 is array (Positive range <>) of Int; -- Unconstrained partial and full view,
                                                 -- but not discriminated.

    type P4 is tagged null record;

    subtype CP1 is P1(1);
    subtype CP2 is P2(1);
    subtype CP3 is P3(1..4);

end B641002_A;
