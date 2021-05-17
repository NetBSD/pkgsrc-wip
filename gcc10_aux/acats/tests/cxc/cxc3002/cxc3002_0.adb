

     --==================================================================--


package body CXC3002_0 is

   protected body Handler_Type is
      procedure Handle_Interrupt is
      begin
         Was_Handled := True;
      end Handle_Interrupt;
   end Handler_Type;

end CXC3002_0;
