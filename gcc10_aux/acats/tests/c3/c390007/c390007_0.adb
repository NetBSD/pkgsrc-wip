

     --==================================================================--


package body C390007_0 is

   procedure ClassWide_Proc (X : in out Root_Type'Class) is
   begin
      Inner_Proc (X);
   end ClassWide_Proc;

end C390007_0;
