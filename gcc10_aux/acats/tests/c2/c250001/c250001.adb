
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-- no package body C250001_0 is required or allowed

------------------------------------------------------------------- C250001

with Report;
with C250001_0;
with Ada.Tags;

procedure C250001 is
  use C250001_0; 

  function Hex( N: Natural ) return String is
    S : String := "xxxx";
    T : String := "0123456789ABCDEF";
    V : Natural := N;
  begin
    for I in reverse 1..4 loop
      S(I) := T(V rem 16 +1);
      V := V / 16;
    end loop;
    return S;
  end Hex;

  procedure Match( Check : Wide_Character; Matching : Natural ) is
  begin
    if Wide_Character'Pos( Check ) /= Matching then
      Report.Failed( "Didn't match for " & Hex(Matching) );
    end if;
  end Match;

  type Value_List is array(Positive range <>) of Natural;

  procedure Match( Check : Wide_String; Matching : Value_List ) is
  begin
    if Check'Length /= Matching'Length then
      Report.Failed( "Check'Length /= Matching'Length" );
    else
      for I in Check'Range loop
        Match( Check(I), Matching(I) );
      end loop;
    end if;
  end Match;

begin  -- Main test procedure.

  Report.Test ("C250001", "Check that wide character literals " &
                          "are supported. Check that wide character " &
                          "string literals are supported" );

  Match (Sun, 16#263C#);

  Match (Male_Female_Suits,
         (16#2640#,16#2642#,16#2660#,16#2663#,16#2665#,16#2666#));

  Match (Greek_to_Me, (16#03A0#,16#03BB#,16#03AC#,16#03C4#,16#03C9#,16#03BD#));

 -- check catenations

  Match (Sun & Sun, (16#263C#,16#263C#));

  Match (Sun & Faces, (16#263C#,16#263A#,16#263B#));

  Match (Faces & Sun, (16#263A#,16#263B#,16#263C#));

  Match (Faces & Faces,
         (16#263A#,16#263B#,16#263A#,16#263B#));

  Report.Result;

end C250001;
