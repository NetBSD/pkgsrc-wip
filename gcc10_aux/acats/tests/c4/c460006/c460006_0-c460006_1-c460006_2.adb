

     --==================================================================--


package body C460006_0.C460006_1.C460006_2 is

   procedure Inner_Proc (X : in out Child_Type) is
   begin
      X.Second_Call := Child_Inner;
   end Inner_Proc;

   -------------------------------------------------
   procedure Outer_Proc (X : in out Child_Type) is
   begin
      X.First_Call := Child_Outer;
      Inner_Proc ( Parent_Type'Class(X) );
   end Outer_Proc;

end C460006_0.C460006_1.C460006_2;
