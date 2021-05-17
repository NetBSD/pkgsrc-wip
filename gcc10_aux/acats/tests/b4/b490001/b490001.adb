

     --==================================================================--

with System;

procedure B490001 is

   --
   -- Enumeration types:
   --

   type Enum is (Eh, Bee, Sea);  -- Range of Enum'Val is 0..2.

   type Rec is record
      Name: String (1 .. 20);
   end record;

   type Slots is array (1 .. 3) of Rec;

   -- Enum'Succ, Enum'Val, and Enum'Pred below are all static functions.
   -- RM 4.9(22);6.0.  Slots'Last is a static expression. RM 4.9(8);6.0.

   Last_Enum  : constant Enum := Enum'Pred(Enum'Succ(Sea));           -- ERROR:
                                        -- Static expression fails Range_Check.

   Penultimate: constant Enum := Enum'Pred(Enum'Val(Slots'Last));     -- ERROR:
                                        -- Static expression fails Range_Check.

   --
   -- Modular types:
   --

   type Modular_Type is mod 5;  -- Range of subtype is 0..4.
                                -- 'Modulus = 5.

   UnivInt    : constant := 10;
   ModVar     : Modular_Type;

   The_Mod    : Modular_Type := Modular_Type(5);                      -- ERROR:
                                        -- Static expression fails Range_Check.

   Mod_Value  : Modular_Type := Modular_Type'Modulus;                 -- ERROR:
                                        -- Static expression fails Range_Check.

   High_Mod   : Modular_Type := (Modular_Type'Modulus - 1);           -- ERROR:
                                        -- Static expression fails Range_Check.


   -- If execution of predefined op of modular type is outside base
   -- range, result is reduced to a value within the base range:

   Mod_Const  : constant Modular_Type := 4;
   Dbl_Value  : Modular_Type := 2*Mod_Const;                          -- OK.


   --
   -- String types:
   --

   type My_String is array (1 .. 4) of Character;

   S1 : constant My_String    := "High";   -- Static constant.
   S2 : constant My_String    := "Drye";    -- Static constant.

   S3 : constant My_String := S1 & S2;                       -- ERROR:

   S4 : constant My_String := My_String'("High") & S2;       -- ERROR:

   S1S : constant String    := "High";   -- Static constant.
   S2S : constant String    := "Dry";    -- Static constant.

   S3M : constant My_String := My_String (S1S & S2S);           -- OK:
                                                                -- Not Static

   S4M : constant My_String := My_String(S1S) & My_String(S1S); -- OK:
                                                                -- Not Static

   --
   -- Signed integer types:
   --

   type My_Int is range -128 .. 127;
   subtype My_Int_Sub is My_Int range -100 .. 100;

   Int1    : My_Int := -128;                                          -- OK.

   Int3    : My_Int := 115;                                           -- OK.

   SubInt1 : constant My_Int_Sub := -128;                             -- OK.
                                 -- But raises Constraint_Error at run-time.

   SubInt3 : constant My_Int_Sub := 115;                              -- OK.
                                 -- But raises Constraint_Error at run-time.

   type C_String_5 is array (0 .. 4) of Character;
   Scale : C_String_5;

   Start_Fraction : constant My_Int := My_Int(1/Scale'Last);          -- OK.

   End_Fraction   : constant My_Int := 1/My_Int(Scale'First);         -- ERROR:
                                     -- Static expression fails Division_Check.


   --
   -- Floating point types:
   --

   type My_Float is digits System.Max_Base_Digits; -- Unconstrained subtype.

   -- Range of an unconstrained scalar subtype is the base range of its
   -- type. Thus, My_Float'Last = My_Float'Base'Last:

   My_Float_Last : constant := My_Float'Last;
   Out_Of_Range  : constant := My_Float_Last + 1.0;

   Flt1 : My_Float := Out_Of_Range;                                   -- ERROR:
                      -- Static expression outside base range of expected type.

   Flt2 : Float := (Float'Base'First - 1.0);                          -- ERROR:
                      -- Static expression outside base range of expected type.


   --
   -- Fixed point types:
   --

   type My_Fixed is delta System.Fine_Delta range -1.0 .. 1.0;

   FixFirst : constant := My_Fixed'Base'First;
   FixLast  : constant := My_Fixed'Base'Last;

   How_Many : My_Fixed;


begin -- B490001.

   --
   -- Modular type:
   --

   ModVar := UnivInt;                                                 -- ERROR:
                      -- Static expression outside base range of expected type.

   --
   -- Fixed point type:
   --

   How_Many := FixLast - FixFirst;                                    -- ERROR:
                      -- Static expression outside base range of expected type.

end B490001;
