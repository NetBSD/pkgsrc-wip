-- B730008.A
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
--      Check that a tagged partial view and its completion must have
--      the same set of interfaces.
--
-- TEST DESCRIPTION:
--      We declare a variety of interfaces and types with those interfaces,
--      then make sure that the completions have exactly the same set of
--      interfaces. We try each kind of completion.
--
--      This test is checking 7.3(7.3/2), the so-called "no hidden interfaces"
--      rule (but the rule also requires "no missing interfaces" as well).
--
-- CHANGE HISTORY:
--      07 Jun 05   H K     Initial version.
--      30 Dec 13   RLB     Created from three submitted tests and several
--                          additional cases.
--
package B730008A is
   type Iface is interface;
   procedure Foo (X : Iface) is abstract;

   type L_Iface is limited interface;

   type S_Iface is synchronized interface;

   type Parent_1 is tagged null record;

   type Parent_2 is new Parent_1 and Iface with null record;
   procedure Foo (X : Parent_2) is null;

   type Parent_3 is new Parent_1 and L_Iface with null record;

end B730008A;
