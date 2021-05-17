
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
with Report;
package body C392010_2 is

  procedure Proc_w_Non( Cp_Ap    : access Tagtype_Level_2;
                          NonCp_Ap : access C392010_0.Tagtype_Level_0
                                   := Lev2_Level_0_Global_Object'Access ) is
  begin
    TCTouch.Touch('M');  --------------------------------------------------- M
    TCTouch.Touch(Cp_Ap.Ch_Item);  ----- depends on the value passed ------- ?
    TCTouch.Touch(NonCp_Ap.Ch_Item);  -- depends on the value passed ------- ?
  end Proc_w_Non;

  function A_Default_Value return Tagtype_Level_2 is
  begin
     return ( Another_Int_Item | Int_Item => 0, Ch_Item  => 'x' );  -------- x
  end A_Default_Value;

  Own : aliased Tagtype_Level_2
                 := ( Another_Int_Item | Int_Item => 4, Ch_Item => 'g' );

  function Func_w_Non( Cp_Ap : access Tagtype_Level_2;
                             NonCp_Ap : access C392010_0.Tagtype_Level_0
                                      := Lev2_Level_0_Global_Object'Access )
           return C392010_1.Access_Tagtype_Level_1 is
  begin
    TCTouch.Touch('N');  --------------------------------------------------- N
    TCTouch.Touch(Cp_Ap.Ch_Item);  ----- depends on the value passed ------- ?
    TCTouch.Touch(NonCp_Ap.Ch_Item);  -- depends on the value passed ------- ?
    return Own'Access;  ---------------------------------------------------- g
  end Func_w_Non;

  function Func_w_Cp_Ap_and_Cr( Cp_Ap : access Tagtype_Level_2 )
           return Tagtype_Level_2 is
  begin
    TCTouch.Touch('P');  --------------------------------------------------- P
    TCTouch.Touch(Cp_Ap.Ch_Item);  ----- depends on the value passed ------- ?
    return ( Another_Int_Item | Int_Item => 5, Ch_Item => 'h' );  ---------- h
 end Func_w_Cp_Ap_and_Cr;

end C392010_2;
