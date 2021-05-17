

     --==================================================================--


package body C460006_0.C460006_1 is

   procedure Inner_Proc (X : in out Parent_Type) is
   begin
      X.Second_Call := Parent_Inner;
   end Inner_Proc;

   -------------------------------------------------
   procedure Outer_Proc (X : in out Parent_Type) is
   begin
      X.First_Call := Parent_Outer;
      Inner_Proc ( Parent_Type'Class(X) );
   end Outer_Proc;

end C460006_0.C460006_1;
