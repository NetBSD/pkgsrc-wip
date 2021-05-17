

     --==================================================================--


package body CXC3006_0 is

   protected body Dynamic is
      procedure Handler is
      begin
         Was_Handled := True;
      end Handler;

      procedure Reset is
      begin
         Was_Handled := False;
      end Reset;

      function Handled return Boolean is
      begin
         return Was_Handled;
      end Handled;
   end Dynamic;

end CXC3006_0;
