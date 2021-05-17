

     --==================================================================--


package body CXC3005_0 is

   protected body Dynamic_Handler is
      procedure Handle_Interrupt is
      begin
         Was_Handled := True;
      end Handle_Interrupt;
   end Dynamic_Handler;

end CXC3005_0;
