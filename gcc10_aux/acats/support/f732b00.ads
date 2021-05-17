-- F732B00.A
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
--      on a private type and accesses to that private type.
--
--      Note that a default-initialized object of type
--      Change_Discriminated_Type will always fail an invariant check. We do
--      this to test 7.3.2(10/4).
--
--      This foundation is based on a package for generating "Diagrams" for
--      bellringing. The type invariant is that each bell occurs once and only
--      once.
--
-- CHANGE HISTORY:
--      25 Dec 14   JAC     Initial pre-release version.
--      20 Jan 15   JAC     Second pre-release version.
--      09 Apr 15   RLB     Fixed formatting problems; removed uses of Text_IO.
--      10 Apr 15   RLB     Added operations on access-to-priv.
--
--!
package F732B00 is

   pragma Assertion_Policy (Check);

   Max_No_Of_Bells : constant := 16;

   No_Of_Bells : constant := 8;

   type Bell_Range_Type is range 1 .. Max_No_Of_Bells;

   type Change_Discriminated_Type (No_Of_Bells : Bell_Range_Type) is private
     with
       Type_Invariant => Each_Bell_Occurs_Once (Change_Discriminated_Type) and
                         And_Only_Once         (Change_Discriminated_Type);

   subtype Swappable_Bell_Range_Type is Bell_Range_Type range 1 ..
     No_Of_Bells - 1;

   subtype Number_Of_Pairs_To_Swap_Type is Bell_Range_Type range 1 ..
     No_Of_Bells / 2;

   type Pairs_To_Swap_Type is array (Number_Of_Pairs_To_Swap_Type range <>) of
     Swappable_Bell_Range_Type;

   type Bells_To_Swap_Type
     (Number_Of_Pairs_To_Swap : Number_Of_Pairs_To_Swap_Type) is record
      Pairs_To_Swap : Pairs_To_Swap_Type (1 .. Number_Of_Pairs_To_Swap);
   end record;

   function Each_Bell_Occurs_Once (Change : Change_Discriminated_Type) return
     Boolean;

   function And_Only_Once         (Change : Change_Discriminated_Type) return
     Boolean;

   function Rounds_With_Default_Initialisation
      return Change_Discriminated_Type;

   function Rounds return Change_Discriminated_Type;

   function Invalid_Change return Change_Discriminated_Type;

   procedure Print_Change (Change : Change_Discriminated_Type);

   procedure Hunt_For_One_Change
     (Change       : in out Change_Discriminated_Type;
      Tenor_Behind : in     Boolean := True);

   function At_Lead_End (Change : in Change_Discriminated_Type) return Boolean;

   procedure Grandsire_Change (Change : in out Change_Discriminated_Type)
     with
       Pre => No_Of_Bells >= 5;

   procedure Invalid_Grandsire_Change
     (Change : in out Change_Discriminated_Type)
     with
       Pre => No_Of_Bells >= 5;

   function Swaps_Dont_Overlap (Bells_To_Swap : in Bells_To_Swap_Type) return
     Boolean;

   procedure Swap_Places
     (Change        : in out Change_Discriminated_Type;
      Bells_To_Swap : in     Bells_To_Swap_Type)
     with
       Pre => Swaps_Dont_Overlap (Bells_To_Swap);

   -- Operations to test access-to-private-with-invariants. Note that we
   -- try similar operations with an anonymous access type and with
   -- a named access type.

   type Access_to_Change is access all Change_Discriminated_Type;

   type Change_Kind is (Valid, Invalid);

   procedure Reset_Change (Change : not null access Change_Discriminated_Type;
                           Kind   : in Change_Kind);
      -- Adjust Change as specified by Kind.

   type Get_Change_Kind is (Param_Invalid, Result_Invalid, Result_is_Param,
                            Result_Other_Valid);

   function Get_Change (Change : Access_to_Change;
                        Kind   : in Get_Change_Kind) return Access_to_Change;
      -- Get a Change value, what happens depends on Kind.

   function Create_Change (Kind : in Change_Kind)
      return not null access Change_Discriminated_Type;
      -- Create a Change value as specified by Kind.

private

   type Change_Array_Type is array (Bell_Range_Type range <>) of
     Bell_Range_Type
      with Default_Component_Value => Bell_Range_Type'First;
      -- Note: Any default-initialized object will fail an invariant check,
      -- no matter where it is used.

   type Change_Discriminated_Type (No_Of_Bells : Bell_Range_Type) is record
      Change : Change_Array_Type (Bell_Range_Type range 1 .. No_Of_Bells);
   end record
     with Dynamic_Predicate =>
       (for all Bell_Number in Bell_Range_Type range 1 .. No_Of_Bells =>
          Change_Discriminated_Type.Change (Bell_Number) <= No_Of_Bells);

end F732B00;
