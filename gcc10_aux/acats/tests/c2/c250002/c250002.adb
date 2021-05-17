
------------------------------------------------------------------- C250002

with Report;
with C250002_0;
with C250002_Á;

with Ada.Tags;

procedure C250002 is
  use C250002_0; 

  My_Task: C250002_Á.C2_Â;

  function Hex( N: Natural ) return String is
    S : String := "xx";
    T : String := "0123456789ABCDEF";
  begin
    S(1) := T(N  /  16 +1);
    S(2) := T(N mod 16 +1);
    return S;
  end Hex;

  procedure Match( Check : Character; Matching : Natural ) is
  begin
    if Check /= Character'Val( Matching ) then
      Report.Failed( "Didn't match for " & Hex(Matching) );
    end if;
  end Match;

  type Value_List is array(Positive range <>) of Natural;

  procedure Match( Check : String; Matching : Value_List ) is
  begin
    if Check'Length /= Matching'Length then
      Report.Failed( "Check'Length /= Matching'Length" );
    else
      for I in Check'Range loop
        Match( Check(I), Matching(I - Check'First + Matching'First) );
      end loop;
    end if;
  end Match;

  TC_Count : Natural := 0;

begin  -- Main test procedure.

  Report.Test ("C250002", "Check that characters above ASCII.Del can be " &
                          "used in identifiers, character literals and " &
                          "strings" );

  Report.Comment( Ada.Tags.Expanded_Name(Tagged_À_Id'Tag) );

  for Specials in C250002_Á.Enum loop
    TC_Count := TC_Count +1;
  end loop;

  if TC_Count /= 6 then
    Report.Failed("Expected 6 literals in Enum");
  end if;

  Match( X_Char_A2, 16#A2# );

  Match(X_Char_A3_Through_A9,
         (16#A3#,16#A4#,16#A5#,16#A6#,16#A7#,16#A8#,16#A9#) );

  -- check catenations

  Match( X_Char_A2 & X_Char_A2, (16#A2#,16#A2#) );

  Match( X_Char_A2 & X_Char_AA_AB, (16#A2#,16#AA#,16#AB#) );

  Match( X_Char_AA_AB & X_Char_A2, (16#AA#,16#AB#,16#A2#) );

  Match( X_Char_AA_AB & X_Char_AA_AB,
         (16#AA#,16#AB#,16#AA#,16#AB#) );

  My_Task.C2_Ã;

  Report.Result;

end C250002;
