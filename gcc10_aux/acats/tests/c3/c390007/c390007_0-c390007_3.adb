

     --==================================================================--


package body C390007_0.C390007_3 is

   procedure Outer_Proc (X : in out Convert_Parent_Type) is
   begin
      X.First_Call := Parent_Outer;
      Inner_Proc (Root_Type'Class(X));  -- Redispatch.
   end Outer_Proc;

   procedure Inner_Proc (X : in out Convert_Parent_Type) is
   begin
      X.Second_Call := Parent_Inner;
   end Inner_Proc;

end C390007_0.C390007_3;
