-- B854004.A
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
--     Check that a renames is illegal if the renamed entity requires
--     overriding.
--
-- TEST DESCRIPTION:
--      This rule was added by Ada 2005. This is necessary as renames are
--      "squirrelling" -- that is the rename the subprogram that is currently
--      visible. This is unlike normal calls, which always call the overridden
--      version even if that is hidden. Since an inherited subprogram can be
--      renamed this way, if the inherited subprogram requires overriding
--      (which means it cannot be called - it might be abstract, for instance,
--      and have no body), then we should not allow the renaming. (No point
--      in allowing the declaration of an entity that cannot be used.)
--
--      We declare a couple of tagged types and then declare an appropriate
--      extension to try the main reasons for an entity requiring overriding.
--
-- CHANGE HISTORY:
--     07 Sep 2018 RLB Created test.
--
package B854004A is
   -- Root types:

   type Root is abstract tagged null record;

   procedure Proc (Obj : in out Root) is abstract;

   function Func (Obj : in Root) return Boolean is abstract;

   function Count (Obj : in Root) return Natural;

   procedure Sink (Obj : in Root);

   type Root2 is tagged null record;

   function Empty_1 return Root2; -- Controlling result.

   function Empty_2 return access Root2; -- Controlling access result.

end B854004A;
