

     --==================================================================--


with Ada.Interrupts;
package CXC3003_1 is

   protected type Handler_Type (ID: Ada.Interrupts.Interrupt_ID) is
      procedure Handle_Interrupt;
      pragma Attach_Handler( Handle_Interrupt, ID );

      function Handled return Boolean;
   private
      Was_Handled : Boolean := False;
   end Handler_Type;

end CXC3003_1;
