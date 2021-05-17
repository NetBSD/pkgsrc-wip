
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
package body C392010_0 is

  procedure Proc_1( P: Tagtype_Level_0 ) is
  begin
    TCTouch.Touch('A');  --------------------------------------------------- A
    TCTouch.Touch(P.Ch_Item);  -- depends on the value passed -------------- ?
  end Proc_1;

  procedure Proc_2( P: Tagtype_Level_0 ) is
  begin
    TCTouch.Touch('B');  --------------------------------------------------- B
    TCTouch.Touch(P.Ch_Item);  -- depends on the value passed -------------- ?
  end Proc_2;

  function A_Default_Value return Tagtype_Level_0 is
  begin
    return (Ch_Item => 'z');  ---------------------------------------------- z
  end A_Default_Value;

  procedure Proc_w_Ap_and_Cp( Ap : Access_Procedure;
                              Cp : Tagtype_Level_0 ) is
  begin
    TCTouch.Touch('C');  --------------------------------------------------- C
    Ap.all( Cp );
  end Proc_w_Ap_and_Cp;

  procedure Proc_w_Ap_and_Cp_w_Def( AP : Access_Procedure := Proc_2'Access;
                                    Cp : Tagtype_Level_0
                                       := A_Default_Value ) is
  begin
    TCTouch.Touch('D');  --------------------------------------------------- D
    Ap.all( Cp );
  end Proc_w_Ap_and_Cp_w_Def;

  procedure Proc_w_Cp_Ap( Cp_Ap : access Tagtype_Level_0 ) is
  begin
    TCTouch.Touch('E');  --------------------------------------------------- E
    TCTouch.Touch(Cp_Ap.Ch_Item);  -- depends on the value passed ---------- ?
  end Proc_w_Cp_Ap;

  function Func_w_Cp_Ap_and_Cr( Cp_Ap : access Tagtype_Level_0 )
           return Tagtype_Level_0 is
  begin
    TCTouch.Touch('F');  --------------------------------------------------- F
    TCTouch.Touch(Cp_Ap.Ch_Item);  -- depends on the value passed ---------- ?
    return ( Ch_Item => 'b' );  -------------------------------------------- b
  end Func_w_Cp_Ap_and_Cr;

end C392010_0;
