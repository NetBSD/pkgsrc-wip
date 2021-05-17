

     --==================================================================--


with ImpDef.Annex_C;
package CXC3006_1 is

   protected Static is
      procedure Handler;
      pragma Attach_Handler ( Handler, ImpDef.Annex_C.Interrupt_To_Generate );

      procedure Reset;
      function  Handled return Boolean;
   private
      Was_Handled: Boolean := False;
   end Static;

end CXC3006_1;
