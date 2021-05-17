

     --==================================================================--


package body C390007_0.C390007_3.C390007_4 is

   procedure Outer_Proc (X : in out Convert_Derived_Type) is
   begin
      X.First_Call := Derived_Outer;
      Inner_Proc (Root_Type'Class(X));  -- Redispatch.
   end Outer_Proc;

   procedure Inner_Proc (X : in out Convert_Derived_Type) is
   begin
      X.Second_Call := Derived_Inner;
   end Inner_Proc;

end C390007_0.C390007_3.C390007_4;
