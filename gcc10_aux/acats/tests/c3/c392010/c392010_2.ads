


----------------------------------------------------------------- C392010_2

with C392010_0;
with C392010_1;
package C392010_2 is

  Lev2_Level_0_Global_Object : aliased C392010_0.Tagtype_Level_0
                        := ( Ch_Item => 'f' );  ---------------------------- f

  type Tagtype_Level_2 is new C392010_1.Tagtype_Level_1 with record
    Another_Int_Item : Integer;
  end record;

  type Access_Tagtype_Level_2 is access all Tagtype_Level_2;

  -- the following procedures are inherited by the above declaration:
  --I   procedure Proc_1( P: Tagtype_Level_2 );
  --I
  --I   procedure Proc_2( P: Tagtype_Level_2 );
  --I
  --I   procedure Proc_w_Ap_and_Cp( AP : C392010_0.Access_Procedure;
  --I                               Cp : Tagtype_Level_2 );
  --I
  --I   procedure Proc_w_Ap_and_Cp_w_Def
  --I             (AP: C392010_0.Access_Procedure := C392010_0. Proc_2'Access;
  --I              CP: Tagtype_Level_2 := A_Default_Value );
  --I
  --I   procedure Proc_w_Cp_Ap( Cp_Ap : access Tagtype_Level_2 );
  --I
  --I   procedure Proc_w_Non( Cp_Ap    : access Tagtype_Level_2;
  --I                         NonCp_Ap : access C392010_0.Tagtype_Level_0
  --I                           := C392010_0.Level_0_Global_Object'Access );

  -- the following functions require overriding due to the above declaration:
  --R   function Func_w_Cp_Ap_and_Cr( Cp_Ap : access Tagtype_Level_2 )
  --R            return Tagtype_Level_2;
  --R
  --R   function A_Default_Value
  --R            return Access_Tagtype_Level_2;

  -- so we override the interesting ones to check the objective:
--     Check that a subprogram with parameters of distinct tagged types may
--     be primitive for only one type (i.e. the other tagged types must be
--     declared in other packages). Check that the subprogram does not
--     dispatch for the other type(s).

  procedure Proc_w_Non( Cp_Ap    : access Tagtype_Level_2;
                        NonCp_Ap : access C392010_0.Tagtype_Level_0
                                   := Lev2_Level_0_Global_Object'Access );

  function Func_w_Non( Cp_Ap : access Tagtype_Level_2;
                    NonCp_Ap : access C392010_0.Tagtype_Level_0
                                      := Lev2_Level_0_Global_Object'Access )
           return C392010_1.Access_Tagtype_Level_1;

  -- and override the other functions that require overriding
  function Func_w_Cp_Ap_and_Cr( Cp_Ap : access Tagtype_Level_2 )
           return Tagtype_Level_2;

  function A_Default_Value return Tagtype_Level_2;

end C392010_2;
