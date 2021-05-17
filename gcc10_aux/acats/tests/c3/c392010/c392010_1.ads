
----------------------------------------------------------------- C392010_1

with C392010_0;
package C392010_1 is

  type Tagtype_Level_1 is new C392010_0.Tagtype_Level_0 with record
    Int_Item : Integer;
  end record;

  type Access_Tagtype_Level_1 is access all Tagtype_Level_1'Class;

  -- the following procedures are inherited by the above declaration:
  --I   procedure Proc_1( P: Tagtype_Level_1 );
  --I
  --I   procedure Proc_2( P: Tagtype_Level_1 );
  --I
  --I   procedure Proc_w_Ap_and_Cp( AP : C392010_0.Access_Procedure;
  --I                               Cp : Tagtype_Level_1 );
  --I
  --I   procedure Proc_w_Ap_and_Cp_w_Def
  --I             ( AP : C392010_0.Access_Procedure := Proc_2'Access;
  --I               Cp : Tagtype_Level_1 := A_Default_Value );
  --I
  --I   procedure Proc_w_Cp_Ap( Cp_Ap : access Tagtype_Level_1 );
  --I

  -- the following functions require overriding due to the above declaration:
  --R   function A_Default_Value return Tagtype_Level_1;
  --R
  --R   function Func_w_Cp_Ap_and_Cr( Cp_Ap : access Tagtype_Level_1 )
  --R            return Tagtype_Level_1;

  -- so, in the interest of testing dispatching, we override them all:
     -- except Proc_1 and Proc_2

  procedure Proc_w_Ap_and_Cp( AP : C392010_0.Access_Procedure;
                              Cp : Tagtype_Level_1 );

  function A_Default_Value return Tagtype_Level_1;

  procedure Proc_w_Ap_and_Cp_w_Def(
              AP : C392010_0.Access_Procedure := C392010_0.Proc_2'Access;
              Cp : Tagtype_Level_1 := A_Default_Value );

  procedure Proc_w_Cp_Ap( Cp_Ap : access Tagtype_Level_1 );

  function Func_w_Cp_Ap_and_Cr( Cp_Ap : access Tagtype_Level_1 )
           return Tagtype_Level_1;

  -- to test the objective:
--     Check that a subprogram dispatches correctly when it has
--     access parameters that are not controlling.

  procedure Proc_w_Non( Cp_Ap    : access Tagtype_Level_1;
                        NonCp_Ap : access C392010_0.Tagtype_Level_0
                             := C392010_0.Level_0_Global_Object'Access );

  function Func_w_Non( Cp_Ap : access Tagtype_Level_1;
                    NonCp_Ap : access C392010_0.Tagtype_Level_0
                             := C392010_0.Level_0_Global_Object'Access )
           return Access_Tagtype_Level_1;

  Level_1_Global_Object : aliased Tagtype_Level_1
                        := ( Int_Item => 0,
                             Ch_Item  => 'c' );  --------------------------- c

end C392010_1;
