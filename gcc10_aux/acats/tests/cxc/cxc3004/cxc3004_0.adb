

     --==================================================================--


package body CXC3004_0 is

   protected body Static_Handler is
      procedure Handle_Interrupt is
      begin
         Was_Handled := True;
         raise User_Exception;                        -- Raises User_Exception.
         Was_Abandoned := False;
      end Handle_Interrupt;

      function Handled return Boolean is
      begin
         return Was_Handled;
      end Handled;

      function Abandoned return Boolean is
      begin
         return Was_Abandoned;
      end Abandoned;
   end Static_Handler;

end CXC3004_0;
