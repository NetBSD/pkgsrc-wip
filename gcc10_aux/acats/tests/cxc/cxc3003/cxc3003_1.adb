

     --==================================================================--


package body CXC3003_1 is

   protected body Handler_Type is
      procedure Handle_Interrupt is
      begin
         Was_Handled := True;
      end Handle_Interrupt;

      function Handled return Boolean is
      begin
         return Was_Handled;
      end Handled;
   end Handler_Type;


end CXC3003_1;
