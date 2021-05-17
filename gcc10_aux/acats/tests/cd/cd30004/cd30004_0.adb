
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
with Report;
with Impdef;
package body CD30004_0 is

  procedure TC_Check_Values is
  begin

    if Bits_2'Size /= 2 then
      if Impdef.Validating_Annex_C then
         Report.Failed("Bits_2'Size not 2 bits");
      else -- Recommended levels of support are not binding.
         Report.Comment("Bits_2'Size not 2 bits");
      end if;
    end if;

    if Bits_14'Size /= 14 then
      if Impdef.Validating_Annex_C then
         Report.Failed("Bits_14'Size not 14 bits");
      else
         Report.Comment("Bits_14'Size not 14 bits");
      end if;
    end if;

    if Bits_3'Size /= 3 then
      if Impdef.Validating_Annex_C then
         Report.Failed("Bits_3'Size not 3 bits");
      else
         Report.Comment("Bits_3'Size not 3 bits");
      end if;
    end if;

    if Bits_5'Size /= 5 then
      if Impdef.Validating_Annex_C then
         Report.Failed("Bits_5'Size not 5 bits");
      else
         Report.Comment("Bits_5'Size not 5 bits");
      end if;
    end if;

    if Character'Size /= 8 then
      Report.Failed("Character'Size not 8 bits");
    end if;

    if Wide_Character'Size /= 16 then
      Report.Failed("Wide_Character'Size not 16 bits");
    end if;

  end TC_Check_Values;

  type Spec_Bits_2 is ( Zeroth_Bit, Fiercest_Bit, Secants_Bit, Threadless_Bit );
  for Spec_Bits_2'Size use 2;                            -- ANX-C RQMT.

  type Spec_Bits_3 is range 0..2**3-1;
  for Spec_Bits_3'Size use 3;                            -- ANX-C RQMT.

  type Spec_Bits_5 is range -2**4+1..2**4-1;  -- allow for 1's comp
  for Spec_Bits_5'Size use 5;                            -- ANX-C RQMT.

  type Spec_Bits_14 is mod 2**14;
  for Spec_Bits_14'Size use 14;                          -- ANX-C RQMT.

  type Spec_Record is new Check_Record;
  for Spec_Record'Size use 64;                           -- ANX-C RQMT.

  procedure TC_Check_Specified_Sizes is

  begin

    if Spec_Record'Size /= 64 then
      Report.Failed("Spec_Record'Size not 64 bits");
    end if;

    if Spec_Bits_2'Size /= 2 then
      Report.Failed("Spec_Bits_2'Size not 2 bits");
    end if;

    if Spec_Bits_14'Size /= 14 then
      Report.Failed("Spec_Bits_14'Size not 14 bits");
    end if;

    if Spec_Bits_3'Size /= 3 then
      Report.Failed("Spec_Bits_3'Size not 3 bits");
    end if;

    if Spec_Bits_5'Size /= 5 then
      Report.Failed("Spec_Bits_5'Size not 5 bits");
    end if;

  end TC_Check_Specified_Sizes;

end CD30004_0;
