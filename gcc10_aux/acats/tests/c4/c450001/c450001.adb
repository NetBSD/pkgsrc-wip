
------------------------------------------------------------------- C450001

with Report;
with C450001_0;
with TCTouch;
procedure C450001 is
  use C450001_0;

  BR : constant String := " produced the wrong result";

  procedure Is_T(B:Boolean;S:String) renames TCTouch.Assert;
  procedure Is_F(B:Boolean;S:String) renames TCTouch.Assert_Not;

  Whole_8_A, Whole_8_B, Whole_8_C : C450001_0.Unsigned_8_Bit;

  Short_8_A, Short_8_B, Short_8_C : C450001_0.Unsigned_Edge_8;

  Over_8_A, Over_8_B, Over_8_C : C450001_0.Unsigned_Over_8;

begin  -- Main test procedure. C450001

  Report.Test ("C450001", "Check that operations on modular types " &
                          "perform correctly." );


  -- the cases for the whole 8 bit type are pretty simple

  Whole_8_A :=                             2#00000000#;
  Whole_8_B :=                             2#11111111#;

  Is_T((ID(Whole_8_A) and ID(Whole_8_B)) = 2#00000000#,"8 bit and" & BR);
  Is_T((ID(Whole_8_A)  or ID(Whole_8_B)) = 2#11111111#,"8 bit  or" & BR);
  Is_T((ID(Whole_8_A) xor ID(Whole_8_B)) = 2#11111111#,"8 bit xor" & BR);

  Whole_8_A :=                             2#00001111#;
  Whole_8_B :=                             2#11111111#;

  Is_T((ID(Whole_8_A) and ID(Whole_8_B)) = 2#00001111#,"8 bit and" & BR);
  Is_T((ID(Whole_8_A)  or ID(Whole_8_B)) = 2#11111111#,"8 bit  or" & BR);
  Is_T((ID(Whole_8_A) xor ID(Whole_8_B)) = 2#11110000#,"8 bit xor" & BR);

  Whole_8_A :=                             2#10101010#;
  Whole_8_B :=                             2#11110000#;

  Is_T((ID(Whole_8_A) and ID(Whole_8_B)) = 2#10100000#,"8 bit and" & BR);
  Is_T((ID(Whole_8_A)  or ID(Whole_8_B)) = 2#11111010#,"8 bit  or" & BR);
  Is_T((ID(Whole_8_A) xor ID(Whole_8_B)) = 2#01011010#,"8 bit xor" & BR);

  -- the cases for the partial 8 bit type involve subtracting the modulus
  -- from results that exceed the modulus.
  -- hence, any of the following operations that exceed 2#11111110# must
  -- have 2#11111111# subtracted from the result; i.e. where you would
  -- expect to see 2#11111111# as in the above operations, the correct
  -- result will be 2#00000000#.  Note that 2#11111111# is not a legal
  -- value of type C450001_0.Unsigned_Edge_8.

  Short_8_A :=                             2#11100101#;
  Short_8_B :=                             2#00011111#;

  Is_T((ID(Short_8_A) and ID(Short_8_B)) = 2#00000101#,"8 short and 1" & BR);
  Is_T((ID(Short_8_A)  or ID(Short_8_B)) = 2#00000000#,"8 short  or 1" & BR);
  Is_T((ID(Short_8_A) xor ID(Short_8_B)) = 2#11111010#,"8 short xor 1" & BR);

  Short_8_A :=                             2#11110000#;
  Short_8_B :=                             2#11111110#;

  Is_T((ID(Short_8_A) and ID(Short_8_B)) = 2#11110000#,"8 short and 2" & BR);
  Is_T((ID(Short_8_A)  or ID(Short_8_B)) = 2#11111110#,"8 short  or 2" & BR);
  Is_T((ID(Short_8_A) xor ID(Short_8_B)) = 2#00001110#,"8 short xor 2" & BR);

  Short_8_A :=                             2#10101010#;
  Short_8_B :=                             2#01010101#;

  Is_T((ID(Short_8_A) and ID(Short_8_B)) = 2#00000000#,"8 short and 3" & BR);
  Is_T((ID(Short_8_A)  or ID(Short_8_B)) = 2#00000000#,"8 short  or 3" & BR);
  Is_T((ID(Short_8_A) xor ID(Short_8_B)) = 2#00000000#,"8 short xor 3" & BR);

  Short_8_A :=                             2#10101010#;
  Short_8_B :=                             2#11111110#;

  Is_T((ID(Short_8_A) and ID(Short_8_B)) = 2#10101010#,"8 short and 4" & BR);
  Is_T((ID(Short_8_A)  or ID(Short_8_B)) = 2#11111110#,"8 short  or 4" & BR);
  Is_T((ID(Short_8_A) xor ID(Short_8_B)) = 2#01010100#,"8 short xor 4" & BR);

  -- the cases for the over 8 bit type have similar issues to the short type
  -- however the bit patterns are a little different.  The rule is to subtract
  -- the modulus (258) from any resulting value equal or greater than the
  -- modulus       -- note that 258 =    2#100000010#

  Over_8_A :=                            2#100000000#;
  Over_8_B :=                            2#011111111#;

  Is_T((ID(Over_8_A) and ID(Over_8_B)) = 2#000000000#,"8 over and" & BR);
  Is_T((ID(Over_8_A)  or ID(Over_8_B)) = 2#011111101#,"8 over  or" & BR);
  Is_T((ID(Over_8_A) xor ID(Over_8_B)) = 2#011111101#,"8 over xor" & BR);

  Over_8_A :=                            2#100000001#;
  Over_8_B :=                            2#011111111#;

  Is_T((ID(Over_8_A) and ID(Over_8_B)) = 2#000000001#,"8 over and" & BR);
  Is_T((ID(Over_8_A)  or ID(Over_8_B)) = 2#011111101#,"8 over  or" & BR);
  Is_T((ID(Over_8_A) xor ID(Over_8_B)) = 2#011111100#,"8 over xor" & BR);



  Whole_8_A := 128;
  Whole_8_B := 255;

  Is_T(ID(Whole_8_A) /= ID(Whole_8_B), "8 /=" & BR);
  Is_F(ID(Whole_8_A)  = ID(Whole_8_B), "8  =" & BR);

  Is_T(ID(Whole_8_A) <= ID(Whole_8_B), "8 <=" & BR);
  Is_T(ID(Whole_8_A) <  ID(Whole_8_B), "8 < " & BR);

  Is_F(ID(Whole_8_A) >= ID(Whole_8_B), "8 >=" & BR);
  Is_T(ID(Whole_8_A) >  ID(Whole_8_B + 7), "8 > " & BR);

  Is_T(ID(Whole_8_A)     in ID(100)..ID(200), "8 in" & BR);
  Is_F(ID(Whole_8_A) not in ID(100)..ID(200), "8 not in" & BR);

  Is_F(ID(Whole_8_A)     in ID(200)..ID(250), "8 in" & BR);
  Is_T(ID(Whole_8_A) not in ID(200)..ID(250), "8 not in" & BR);

  Short_8_A := 127;
  Short_8_B := 254;

  Is_T(ID(Short_8_A) /= ID(Short_8_B), "short 8 /=" & BR);
  Is_F(ID(Short_8_A)  = ID(Short_8_B), "short 8  =" & BR);

  Is_T(ID(Short_8_A) <= ID(Short_8_B), "short 8 <=" & BR);
  Is_T(ID(Short_8_A) <  ID(Short_8_B), "short 8 < " & BR);

  Is_F(ID(Short_8_A) >= ID(Short_8_B), "short 8 >=" & BR);
  Is_F(ID(Short_8_A) >  ID(Short_8_B), "short 8 > " & BR);

  Is_T(ID(Short_8_A)     in ID(100)..ID(200), "8 in" & BR);
  Is_F(ID(Short_8_A) not in ID(100)..ID(200), "8 not in" & BR);

  Is_F(ID(Short_8_A)     in ID(200)..ID(250), "8 in" & BR);
  Is_T(ID(Short_8_A) not in ID(200)..ID(250), "8 not in" & BR);


  Whole_8_A := 1;
  Whole_8_B := 254;
  Short_8_A := 1;
  Short_8_B := 2;

  Whole_8_C := ID(Whole_8_A) + ID(Whole_8_B);
  Is_T(Whole_8_C = C450001_0.Unsigned_8_Bit'Last, "8 binary + 1" & BR);

  Whole_8_C := Whole_8_C + ID(Whole_8_A);
  Is_T(Whole_8_C = C450001_0.Unsigned_8_Bit'First, "8 binary + 2" & BR);

  Whole_8_C := ID(Whole_8_A) - ID(Whole_8_A);
  Is_T(Whole_8_C = 0, "8 binary -" & BR);

  Whole_8_C := Whole_8_C - ID(Whole_8_A);
  Is_T(Whole_8_C = C450001_0.Unsigned_8_Bit'Last, "8 binary + 3" & BR);

  Short_8_C := ID(Short_8_A) + ID(C450001_0.Unsigned_Edge_8'Last);
  Is_T(Short_8_C = C450001_0.Unsigned_Edge_8'First, "Short binary + 1" & BR);

  Short_8_C := Short_8_A + ID(Short_8_A);
  Is_T(Short_8_C = ID(Short_8_B), "Short binary + 2" & BR);

  Short_8_C := ID(Short_8_A) - ID(Short_8_A);
  Is_T(Short_8_C = 0, "Short 8 binary -" & BR);

  Short_8_C := Short_8_C - ID(Short_8_A);
  Is_T(Short_8_C = C450001_0.Unsigned_Edge_8'Last, "Short binary + 3" & BR);


  Whole_8_C := ( + ID(Whole_8_B) );
  Is_T(Whole_8_C = 254, "8 unary +" & BR);

  Whole_8_C := ( - ID(Whole_8_A) );
  Is_T(Whole_8_C = C450001_0.Unsigned_8_Bit'Last, "8 unary -" & BR);

  Whole_8_C := ( - ID(0) );
  Is_T(Whole_8_C = 0, "8 unary -0" & BR);

  Short_8_C := ( + ID(C450001_0.Unsigned_Edge_8'Last) );
  Is_T(Short_8_C = 254, "Short 8 unary +" & BR);

  Short_8_C := ( - ID(Short_8_A) );
  Is_T(Short_8_C = C450001_0.Unsigned_Edge_8'Last, "Short 8 unary -" & BR);


  Whole_8_A := 20;
  Whole_8_B := 255;

  Whole_8_C := ID(Whole_8_A) * ID(Whole_8_B); -- 5100 = 19*256 + 236 (256-20)
  Is_T(Whole_8_C = 236, "8 *" & BR);

  Short_8_A := 9;
  Short_8_B := 254;

  Short_8_C := ID(Short_8_A) * ID(Short_8_B); -- 2286 = 8*255 + 246 (255-9)
  Is_T(Short_8_C = 246, "short 8 *" & BR);

  Over_8_A := 12;
  Over_8_B := 86;

  Over_8_C := ID(Over_8_A) * ID(Over_8_B); -- 1032 = 4*258 + 0
  Is_T(Over_8_C = 0, "over 8 *" & BR);


  Whole_8_A := 255;
  Whole_8_B := 4;

  Whole_8_C := ID(Whole_8_A) / ID(Whole_8_B);
  Is_T(Whole_8_C = 63, "8 /" & BR);

  Short_8_A := 253;
  Short_8_B := 127;

  Short_8_C := ID(Short_8_A) / ID(Short_8_B);
  Is_T(Short_8_C = 1, "short 8 / 1" & BR);

  Short_8_C := ID(Short_8_A) / ID(126);
  Is_T(Short_8_C = 2, "short 8 / 2" & BR);


  Whole_8_A := 255;
  Whole_8_B := 254;

  Whole_8_C := ID(Whole_8_A) rem ID(Whole_8_B);
  Is_T(Whole_8_C = 1, "8 rem" & BR);

  Short_8_A := 222;
  Short_8_B := 111;

  Short_8_C := ID(Short_8_A) rem ID(Short_8_B);
  Is_T(Short_8_C = 0, "short 8 rem" & BR);


  Whole_8_A := 99;
  Whole_8_B := 9;

  Whole_8_C := ID(Whole_8_A) mod ID(Whole_8_B);
  Is_T(Whole_8_C = 0, "8 mod" & BR);

  Short_8_A := 254;
  Short_8_B := 250;

  Short_8_C := ID(Short_8_A) mod ID(Short_8_B);
  Is_T(Short_8_C = 4, "short 8 mod" & BR);


  Whole_8_A := 99;

  Whole_8_C := abs Whole_8_A;
  Is_T(Whole_8_C = ID(99), "8 abs" & BR);

  Short_8_A := 254;

  Short_8_C := ID( abs Short_8_A );
  Is_T(Short_8_C = 254, "short 8 abs" & BR);


  Whole_8_B :=        2#00001111#;

  Whole_8_C := not Whole_8_B;
  Is_T(Whole_8_C = ID(2#11110000#), "8 not" & BR);

  Short_8_B :=     2#00001111#;                      -- 15

  Short_8_C := ID( not Short_8_B );                  -- 254 - 15
  Is_T(Short_8_C = 2#11101111#, "short 8 not" & BR); -- 239


  Whole_8_A := 2;

  Whole_8_C := Whole_8_A ** 7;
  Is_T(Whole_8_C = ID(128), "2 ** 7, whole 8" & BR);

  Whole_8_C := Whole_8_A ** 9;
  Is_T(Whole_8_C = ID(0), "2 ** 9, whole 8" & BR);

  Short_8_A := 4;

  Short_8_C := ID( Short_8_A ) ** 4;
  Is_T(Short_8_C = 1, "4 ** 4, short" & BR);

  Over_8_A := 4;

  Over_8_C := ID( Over_8_A ) ** 4;
  Is_T(Over_8_C = 256, "4 ** 4, over" & BR);

  Over_8_C := ID( Over_8_A ) ** 5; -- 1024 = 3*258 + 250
  Is_T(Over_8_C = 250, "4 ** 5, over" & BR);


  C450001_0.Loop_Check;

  Report.Result;

end C450001;
