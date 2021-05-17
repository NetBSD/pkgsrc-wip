
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-- there is no package body CD30007_0

----------------------------------------------------------------- CD30007_1

with CD30007_0;
package CD30007_1 is

   -- Contains types to check.

   type Check_Enum_Type is (Zero, One, Two)
      with Size => Smallest_Unsigned_Enum_Size;            -- ANX-C RQMT.

   type Check_Int_Type is range -63 .. 63
      with Size => Smallest_Signed_Int_Size;               -- ANX-C RQMT.

   type Check_Mod_Type is mod 256
      with Size => Smallest_Unsigned_Mod_Size;             -- ANX-C RQMT.

   type Derived_Enum is new CD30007_0.Basic_Enum
      with Size => CD30007_0.Specified_Enum_Size;          -- ANX-C RQMT.

   type Derived_Int is new CD30007_0.Basic_Int
      with Size => CD30007_0.Specified_Int_Size;           -- ANX-C RQMT.

   type Pack_Enum is (A1, B1, C1, D1, E1, F1, G1)
      with Size => CD30007_0.Specified_Enum_Size;          -- ANX-C RQMT.

   type Pack_Int is range -125 .. 125
      with Size => CD30007_0.Specified_Int_Size;           -- ANX-C RQMT.

   type Private_Enum is private;

   PE_Value : constant Private_Enum;

   type Private_Int is private;

   PI_Value : constant Private_Int;

   Smallest_Unsigned_Enum_Size : constant := 2;

   Smallest_Signed_Int_Size : constant := 7;

   Smallest_Unsigned_Mod_Size : constant := 8;

private

   type Private_Enum is (A2, B2, C2, D2, E2, F2, G2)
      with Size => CD30007_0.Specified_Enum_Size;          -- ANX-C RQMT.

   PE_Value : constant Private_Enum := D2;

   type Private_Int is range -125 .. 125
      with Size => CD30007_0.Specified_Int_Size;           -- ANX-C RQMT.

   PI_Value : constant Private_Int := -87;

end CD30007_1;
