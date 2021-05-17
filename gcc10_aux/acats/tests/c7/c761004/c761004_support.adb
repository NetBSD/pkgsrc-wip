
with Report;
with TCTouch;
package body C761004_Support is
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
    TI: Positive := 1;
  begin
    for SI in reverse S'Range loop
      T(TI) := S(SI);
      TI := TI +1;
    end loop;
    return T;
  end Invert;

  procedure Validate(Initcount: Natural; Testnumber:Natural) is
    Number : constant String := Natural'Image(Testnumber);
  begin
    if Inits_Called /= Initcount then
      Report.Failed("Wrong number of inits, Subtest " & Number);
      TCTouch.Flush;
    else
      TCTouch.Validate(
        Invert(Inits_Order(1..Inits_Called)),
               "Subtest " & Number, True);
    end if;
  end Validate;

end C761004_Support;
