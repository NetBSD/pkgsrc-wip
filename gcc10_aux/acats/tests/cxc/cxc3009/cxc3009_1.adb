

     --==================================================================--


package body CXC3009_1 is

   function TC_Set_Handled_Flag return Integer is
   begin
      Was_Handled := True;
      return -1;
   end TC_Set_Handled_Flag;


   protected body Dynamic_Handler is
      procedure Handle_Interrupt is
         Local : Positive := TC_Set_Handled_Flag;   -- Raises Constraint_Error.
      begin
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
   end Dynamic_Handler;

end CXC3009_1;
