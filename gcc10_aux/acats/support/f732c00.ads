-- F732C00.A
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
-- FOUNDATION DESCRIPTION:
--      This foundation provides the basis for testing aspect Type_Invariant
--      on a tagged private type with unknown discriminants. Here, we hide
--      the aspect in the private part by putting it on the full type.
--
--      Note that a default-initialized object of type Change_Tagged_Type
--      will always fail an invariant check, but no such check is performed.
--      That's because AI12-0133-1 eliminated such checks if the
--      default-initialized object cannot be declared outside of the scope
--      of the package.
--
--      This foundation is based on a package for generating "Diagrams" for
--      bellringing. The type invariant is that each bell occurs once and only
--      once.
--
-- CHANGE HISTORY:
--      15 Jan 15   RLB     Created foundation by modifying F732A00.
--      13 Mar 15   RLB     Eliminated overlong lines.
--
--!
package F732C00 is

   pragma Assertion_Policy (Check);

   No_Of_Bells : constant := 8;

   type Bell_Range_Type is range 1 .. No_Of_Bells;

   type Change_Tagged_Type (<>) is tagged private;

   subtype Swappable_Bell_Range_Type is Bell_Range_Type
                                                range 1 .. No_Of_Bells - 1;

   subtype Number_Of_Pairs_To_Swap_Type is Bell_Range_Type range 1 ..
     No_Of_Bells / 2;

   type Pairs_To_Swap_Type is array (Number_Of_Pairs_To_Swap_Type range <>) of
     Swappable_Bell_Range_Type;

   type Bells_To_Swap_Type
     (Number_Of_Pairs_To_Swap : Number_Of_Pairs_To_Swap_Type) is record
      Pairs_To_Swap       : Pairs_To_Swap_Type (1 .. Number_Of_Pairs_To_Swap);
   end record;

   function Each_Bell_Occurs_Once (Change : Change_Tagged_Type) return
     Boolean;

   function And_Only_Once         (Change : Change_Tagged_Type) return
     Boolean;

   function Rounds return Change_Tagged_Type;

   function Invalid_Change return Change_Tagged_Type;

   procedure Hunt_For_One_Change
     (Change       : in out Change_Tagged_Type;
      Tenor_Behind : in     Boolean := True);

   function At_Lead_End (Change : in Change_Tagged_Type) return Boolean;

   procedure Grandsire_Change (Change : in out Change_Tagged_Type)
     with
       Pre => No_Of_Bells >= 5;

   procedure Broken_Grandsire_Change (Change : in out Change_Tagged_Type)
     with
       Pre => No_Of_Bells >= 5;

   function Swaps_Dont_Overlap (Bells_To_Swap : in Bells_To_Swap_Type) return
     Boolean;

   procedure Swap_Places
     (Change        : in out Change_Tagged_Type;
      Bells_To_Swap : in     Bells_To_Swap_Type)
     with
       Pre => Swaps_Dont_Overlap (Bells_To_Swap);

private

   type Change_Constrained_Type is array (Bell_Range_Type) of Bell_Range_Type;

   type Change_Tagged_Type is tagged record
      Data : Change_Constrained_Type := (others => Bell_Range_Type'First);
   end record
     with
       Type_Invariant => Each_Bell_Occurs_Once (Change_Tagged_Type) and
                         And_Only_Once         (Change_Tagged_Type);

end F732C00;
