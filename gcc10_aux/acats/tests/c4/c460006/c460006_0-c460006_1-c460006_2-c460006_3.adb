

     --==================================================================--


package body C460006_0.C460006_1.C460006_2.C460006_3 is

   procedure Inner_Proc (X : in out Grandchild_Type) is
   begin
      X.Second_Call := Grandchild_Inner;
   end Inner_Proc;

   -------------------------------------------------
   procedure Outer_Proc (X : in out Grandchild_Type) is
   begin
      X.First_Call := Grandchild_Outer;
      Inner_Proc ( Parent_Type'Class(X) );
   end Outer_Proc;

   -------------------------------------------------
   function ClassWide_Func return Parent_Type'Class is
      A : Grandchild_Type   := Grandchild_Value;
      X : Parent_Type'Class := Parent_Type(A); -- Value of X is still that of A.
   begin
      return X;
   end ClassWide_Func;

end C460006_0.C460006_1.C460006_2.C460006_3;
