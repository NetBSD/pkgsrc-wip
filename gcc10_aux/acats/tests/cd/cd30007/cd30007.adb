
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-- there is no package body CD30007_1

------------------------------------------------------------------- CD30007

with Report;
with Length_Check;                      -- Contains a call to 'Report.Failed'.
with CD30007_0, CD30007_1;
procedure CD30007 is

   Minimum_Enum_Size : Integer :=
      Report.Ident_Int(CD30007_0.Specified_Enum_Size);

   Minimum_Int_Size  : Integer :=
      Report.Ident_Int(CD30007_0.Specified_Int_Size);

   procedure Check_1 is new Length_Check (CD30007_1.Check_Enum_Type);
   procedure Check_2 is new Length_Check (CD30007_1.Check_Int_Type);
   procedure Check_3 is new Length_Check (CD30007_1.Check_Mod_Type);
   procedure Check_4 is new Length_Check (CD30007_1.Derived_Enum);
   procedure Check_5 is new Length_Check (CD30007_1.Derived_Int);
   procedure Check_6 is new Length_Check (CD30007_1.Pack_Enum);
   procedure Check_7 is new Length_Check (CD30007_1.Pack_Int);
   procedure Check_8 is new Length_Check (CD30007_1.Private_Enum);
   procedure Check_9 is new Length_Check (CD30007_1.Private_Int);

   use type CD30007_1.Check_Int_Type;

begin

   Report.Test ("CD30007", "Check that the implementation supports " &
                           "specifying Sizes for types, including full " &
                           "types for private types, using aspect " &
                           "specifications");
   Check_1 (CD30007_1.Two,
            CD30007_1.Smallest_Unsigned_Enum_Size,
            "Check_Enum_Type");
   Check_2 (-25, CD30007_1.Smallest_Signed_Int_Size, "Check_Int_Type");
   Check_3 (12, CD30007_1.Smallest_Unsigned_Mod_Size, "Check_Mod_Type");
   Check_4 (CD30007_1.D, CD30007_0.Specified_Enum_Size, "Derived_Enum");
   Check_5 (66, CD30007_0.Specified_Int_Size, "Derived_Int");
   Check_6 (CD30007_1.D1, CD30007_0.Specified_Enum_Size, "Pack_Enum");
   Check_7 (99, CD30007_0.Specified_Int_Size, "Pack_Int");
   Check_8 (CD30007_1.PE_Value, CD30007_0.Specified_Enum_Size, "Private_Enum");
   Check_9 (CD30007_1.PI_Value, CD30007_0.Specified_Int_Size, "Private_Int");

   if CD30007_1.Derived_Enum'Size /= Minimum_Enum_Size then
      Report.Failed ("Derived_Enum'Size should not be different than" &
                     Integer'Image(Minimum_Enum_Size) & ". Actual Size is" &
                     Integer'Image(CD30007_1.Derived_Enum'Size));
   end if;

   if CD30007_1.Derived_Int'Size /= Minimum_Int_Size then
      Report.Failed ("Derived_Int'Size should not be different than" &
                     Integer'Image(Minimum_Int_Size) & ". Actual Size is" &
                     Integer'Image(CD30007_1.Derived_Int'Size));
   end if;

   if CD30007_1.Pack_Enum'Size /= Minimum_Enum_Size then
      Report.Failed ("Pack_Enum'Size should not be different than" &
                     Integer'Image(Minimum_Enum_Size) & ". Actual Size is" &
                     Integer'Image(CD30007_1.Pack_Enum'Size));
   end if;

   if CD30007_1.Pack_Int'Size /= Minimum_Int_Size then
      Report.Failed ("Pack_Int'Size should not be different than" &
                     Integer'Image(Minimum_Int_Size) & ". Actual Size is" &
                     Integer'Image(CD30007_1.Derived_Int'Size));
   end if;

   if CD30007_1.Private_Enum'Size /= Minimum_Enum_Size then
      Report.Failed ("Private_Enum'Size should not be different than" &
                     Integer'Image(Minimum_Enum_Size) & ". Actual Size is" &
                     Integer'Image(CD30007_1.Private_Enum'Size));
   end if;

   if CD30007_1.Private_Int'Size /= Minimum_Int_Size then
      Report.Failed ("Private_Int'Size should not be different than" &
                     Integer'Image(Minimum_Int_Size) & ". Actual Size is" &
                     Integer'Image(CD30007_1.Private_Int'Size));
   end if;

   Report.Result;

end CD30007;

