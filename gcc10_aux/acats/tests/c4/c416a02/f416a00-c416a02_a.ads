-- C416A02.A
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
-- OBJECTIVE:
--     Check that the name specified for a Constant_Indexing or
--     Variable_Indexing aspect can refer to a set of overloaded functions.
--     (Case B: overloaded on result types)
--
--     Check that if a function used by an inherited Constant_Indexing or
--     Variable_Indexing is overloaded (with a different profile), the
--     overloaded function can be called by a generalized indexing.
--
--     Check that if a function used by an inherited Constant_Indexing or
--     Variable_Indexing is overridden, the overridden function is called
--     by a generalized indexing.
--
--     Check that a generalized indexing can be used for an object of a derived
--     type that inherits the Constant_Indexing or Variable_Indexing aspect
--     from its parent type.
--
-- TEST DESCRIPTION:
--     The foundation is a sprite-drawing package. We derive a new type from
--     it, adding new and overridden CRef and VRef operations. The main
--     subprogram defines several sprites in a window and tests operations
--     on them, using both the old and new generalized indexing operations.
--
-- CHANGE HISTORY:
--     13 May 2015   RLB   Created test.
--     14 May 2015   RLB   Added an additional objective (already tested).
--     14 Aug 2015   RLB   Changed the package of New_Window to be a child
--                         so that the parent components are visible in the
--                         body.
--     30 Sep 2015   RLB   Corrected "sC" item to use the Kind VRef.

package F416A00.C416A02_A is
   type New_Window is new F416A00.Window with private;

   Missing_Error : exception renames F416A00.Missing_Error;

   overriding
   function CRef (W : in New_Window; N : in Name) return Sprite;

   overriding
   function VRef (W : aliased in out New_Window; N : in Name)
      return F416A00.Ref_Rec;

   not overriding
   function CRef (W : in New_Window; N : in Name) return Kind;

   type K_Ref_Rec (D : access Kind) is null record
      with Implicit_Dereference => D;

   not overriding
   function VRef (W : aliased in out New_Window; N : in Name)
      return K_Ref_Rec;

   -- inherits the following:
   --function CRef (W : in New_Window; X, Y : in Natural) return Sprite;
   --
   --function VRef (W : aliased in out New_Window; X, Y : in Natural)
   --   return F416A00.Ref_Rec;

private
   type New_Window is new F416A00.Window with null record;
end F416A00.C416A02_A;
