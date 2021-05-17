
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with TCTouch;
package body C761003_Support is
  type Pick_Rotation is mod 52;
  type Pick_String is array(Pick_Rotation) of Character;

  From : constant Pick_String  := "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                & "abcdefghijklmnopqrstuvwxyz";
  Recent_Pick : Pick_Rotation := Pick_Rotation'Last;

  function Pick_Char return Character is
  begin
    Recent_Pick := Recent_Pick +1;
    return From(Recent_Pick);
  end Pick_Char;

  function Invert(S:String) return String is
    T: String(1..S'Length);
  begin
    for SI in reverse S'Range loop
      T(S'Last - SI + 1) := S(SI);
    end loop;
    return T;
  end Invert;

  procedure Validate(Initcount   : Natural;
                     Testnumber  : Natural;
                     Check_Order : Boolean := True) is
    Number : constant String := Natural'Image(Testnumber);
  begin
    if Inits_Called /= Initcount then
      Report.Failed("Got" & Natural'Image(Inits_Called) & " inits, expected"
                    & Natural'Image(Initcount) & ", Subtest " & Number);
      TCTouch.Flush;
    else
      TCTouch.Validate(
        Invert(Inits_Order(1..Inits_Called)),
               "Subtest " & Number, Order_Meaningful => Check_Order );
    end if;
    Inits_Called := 0;  -- reset for the next batch
  end Validate;

end C761003_Support;
