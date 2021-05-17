
with B354001_0;
with System;
procedure B354001 is

  type Largest_Possible_Integer is range System.Min_Int..System.Max_Int;

  type Max_Binary    is mod System.Max_Binary_Modulus;
  type Over_Binary   is mod System.Max_Binary_Modulus*2;          -- ERROR:
                                                         -- value too large

  Half_Max    : constant := System.Max_Binary_Modulus / 2;
  Valid_Value : constant := Half_Max / 2;

  type Mod_Half_Max     is mod Half_Max;

  type Four_Bits is mod B354001_0.Half_Dollar;                    -- ERROR:
                        -- nonstatic expression used for modular type bound
  type Bit_Counter is mod Integer'Size;                           -- OK
  type Arithmetic is mod ( ( 3 + Integer( B354001_0.Number )));   -- OK

  type Sour_Bits is mod B354001_0.Number;                         -- ERROR:
                                          -- modular type bound not integer

  type Mod_0 is mod 0;                                            -- ERROR:
                     -- zero used for modulus, value must be greater than 0

  type Mod_2                  is mod 2;                           -- OK
  type Mod_3                  is mod 3;                           -- OK
  type Mod_128                is mod 128;                         -- OK
  type Mod_15                 is mod 15;                          -- OK
  type Sixteen_Bits           is mod 2**16;                       -- OK

  type Max_NonBinary          is mod System.Max_Nonbinary_Modulus;-- OK
  type LessThan_Max_NonBinary is
                             mod System.Max_Nonbinary_Modulus -1; -- OK
  type MoreThan_Max_NonBinary is
                 mod (System.Max_Nonbinary_Modulus +2)/2 * 2 + 1; -- ERROR:
                                                         -- value too large

  procedure UserLike(Param: Natural) is
    type Mod_By_Param is mod Param;                               -- ERROR:
                        -- nonstatic expression used for modular type bound

    Negative_Value : constant := 100 - 200;
    type Mod_Negative_Value is mod Negative_Value;                -- ERROR:
                                        -- negative number used for modulus

    JPR_Constant : constant Sixteen_Bits := Negative_Value;       -- ERROR:
                                     -- value outside of base range of type
    Sweet : Sixteen_Bits;
  begin
    Sweet := Negative_Value;                                      -- ERROR:
                                     -- value outside of base range of type
  end UserLike;

  AMB, BMB, CMB   : Max_Binary := 16#F00D#;
  H1,H2           : Mod_Half_Max := 1;
  LMBA,LMBB       : LessThan_Max_NonBinary := 1;

begin  -- Main test procedure.

  AMB := AMB or CMB;                                              -- OK
  AMB := AMB and 16#BEEF#;                                        -- OK
  AMB := AMB xor BMB;                                             -- OK

  AMB := AMB or else CMB;                                         -- ERROR:
                -- short circuit control form not defined for modular types

  AMB := AMB and then 16#F1D0#;                                   -- ERROR:
                -- short circuit control form not defined for modular types

  LMBA := LMBA or else 16#00DD#;                                  -- ERROR:
                -- short circuit control form not defined for modular types

  LMBA := LMBA and then LMBB;                                     -- ERROR:
                -- short circuit control form not defined for modular types

  if Valid_Value in Mod_Half_Max then                             -- OK
    H1 := H1 + Valid_Value;
  elsif Valid_Value not in Mod_Half_Max then                      -- OK
    H1 := H1 - Valid_Value;
  end if;

end B354001;
