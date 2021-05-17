

     --==================================================================--


package body C390007_0.C390007_1.C390007_2 is

   procedure Outer_Proc (X : in out Param_Derived_Type) is
      Y : Root_Type'Class := X;
   begin
      Inner_Proc (Y);  -- Redispatch.
      Root_Type'Class (X) := Y;
   end Outer_Proc;

   procedure Inner_Proc (X : in out Param_Derived_Type) is
   begin
      X.Last_Call := Derived_Inner;
   end Inner_Proc;

end C390007_0.C390007_1.C390007_2;
