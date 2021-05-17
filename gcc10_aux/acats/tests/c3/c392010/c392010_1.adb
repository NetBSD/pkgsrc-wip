
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
package body C392010_1 is

  procedure Proc_w_Ap_and_Cp( AP : C392010_0.Access_Procedure;
                              Cp : Tagtype_Level_1 ) is
  begin
    TCTouch.Touch('G');  --------------------------------------------------- G
    Ap.All( C392010_0.Tagtype_Level_0( Cp ) );
  end Proc_w_Ap_and_Cp;

  procedure Proc_w_Ap_and_Cp_w_Def(
              AP : C392010_0.Access_Procedure := C392010_0.Proc_2'Access;
              Cp : Tagtype_Level_1 := A_Default_Value )
  is
  begin
    TCTouch.Touch('H');  --------------------------------------------------- H
    Ap.All( C392010_0.Tagtype_Level_0( Cp ) );
  end Proc_w_Ap_and_Cp_w_Def;

  procedure Proc_w_Cp_Ap( Cp_Ap : access Tagtype_Level_1 ) is
  begin
    TCTouch.Touch('I');  --------------------------------------------------- I
    TCTouch.Touch(Cp_Ap.Ch_Item);  -- depends on the value passed ---------- ?
  end Proc_w_Cp_Ap;

  function A_Default_Value return Tagtype_Level_1 is
  begin
    return ( Int_Item => 0, Ch_Item  => 'y' );  ---------------------------- y
  end A_Default_Value;

  function Func_w_Cp_Ap_and_Cr( Cp_Ap : access Tagtype_Level_1 )
           return Tagtype_Level_1 is
  begin
    TCTouch.Touch('J');  --------------------------------------------------- J
    TCTouch.Touch(Cp_Ap.Ch_Item);  -- depends on the value passed ---------- ?
    return ( Int_Item => 2, Ch_Item => 'd' );  ----------------------------- d
  end Func_w_Cp_Ap_and_Cr;

  procedure Proc_w_Non( Cp_Ap    : access Tagtype_Level_1;
                        NonCp_Ap : access C392010_0.Tagtype_Level_0
                          := C392010_0.Level_0_Global_Object'Access ) is
  begin
    TCTouch.Touch('K');  --------------------------------------------------- K
    TCTouch.Touch(Cp_Ap.Ch_Item);  ----- depends on the value passed ------- ?
    TCTouch.Touch(NonCp_Ap.Ch_Item);  -- depends on the value passed ------- ?
  end Proc_w_Non;

  Own_Item : aliased Tagtype_Level_1 := ( Int_Item => 3, Ch_Item => 'e' );

  function Func_w_Non( Cp_Ap : access Tagtype_Level_1;
                    NonCp_Ap : access C392010_0.Tagtype_Level_0
                             := C392010_0.Level_0_Global_Object'Access )
           return Access_Tagtype_Level_1 is
  begin
    TCTouch.Touch('L');  --------------------------------------------------- L
    TCTouch.Touch(Cp_Ap.Ch_Item);  ----- depends on the value passed ------- ?
    TCTouch.Touch(NonCp_Ap.Ch_Item);  -- depends on the value passed ------- ?
    return Own_Item'Access;  ----------------------------------------------- e
  end Func_w_Non;

end C392010_1;
