

     --==================================================================--


package body CXC3007_0 is

   protected body Dynamic is
      procedure Handler1 is
      begin
         Was_Handled := True;
      end Handler1;

      procedure Handler2 is
      begin
         Was_Handled := True;
      end Handler2;
   end Dynamic;

end CXC3007_0;
