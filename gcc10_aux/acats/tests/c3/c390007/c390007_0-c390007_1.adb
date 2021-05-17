

     --==================================================================--


package body C390007_0.C390007_1 is

   procedure Outer_Proc (X : in out Param_Parent_Type) is
   begin
      X.Last_Call := Parent_Outer;
   end Outer_Proc;

   procedure Inner_Proc (X : in out Param_Parent_Type) is
   begin
      X.Last_Call := Parent_Inner;
   end Inner_Proc;

end C390007_0.C390007_1;
