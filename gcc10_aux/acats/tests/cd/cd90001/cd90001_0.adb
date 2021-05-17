
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body CD90001_0 is

  Check_List : constant array(1..8) of Eight_Bits
             := ( 1, 2, 4, 8, 16, 32, 64, 128 );

  Check_Enum : constant array(1..8) of User_Enums
             := ( One, Two, Four, Eight,
                  Sixteen, Thirty_Two, Sixty_Four, One_Twenty_Eight );

  procedure TC_Check_Case_1 is
    Mod_Value : Eight_Bits;
    Enum_Val  : User_Enums;
  begin
    for I in Check_List'Range loop

      if EB_2_UE(Check_List(I)) /= Check_Enum(I) then
        Report.Failed("EB => UE conversion failed");
      end if;

      if Check_List(I)          /= UE_2_EB(Check_Enum(I)) then
        Report.Failed ("EU => EB conversion failed");
      end if;

    end loop;
  end TC_Check_Case_1;

  procedure TC_Check_Case_2 is
    S: Signed_16;
    T,U: Signed_16;
    B: Bits_16;
    C,D: Bits_16;  -- allow for byte swapping
  begin
         --FDEC_BA98_7654_3210
    S := 2#0011_0000_0111_0111#;
    B := S16_2_B16( S );
    C := ( Character'Val(2#0011_0000#), Character'Val(2#0111_0111#) );
    D := ( Character'Val(2#0111_0111#), Character'Val(2#0011_0000#) );

    if (B /= C) and (B /= D) then
      Report.Failed("Int => Chararray conversion failed");
    end if;

    B := ( Character'Val(2#0011_1100#), Character'Val(2#0101_0101#) );
    S := B16_2_S16( B );
    T := 2#0011_1100_0101_0101#;
    U := 2#0101_0101_0011_1100#;

    if (S /= T) and (S /= U) then
      Report.Failed("Chararray => Int conversion failed");
    end if;

  end TC_Check_Case_2;

end CD90001_0;
