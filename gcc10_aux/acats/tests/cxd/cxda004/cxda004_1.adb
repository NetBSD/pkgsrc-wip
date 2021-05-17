
with Ada.Interrupts;
with System;
with Report;
with ImpDef;
with ImpDef.Annex_C;
package body CXDA004_1 is

      protected Releaser is
         procedure Release_It;
         pragma Interrupt_Handler (Release_It);
         pragma Attach_Handler (Release_It, 
                  ImpDef.Annex_C.Interrupt_To_Generate);
      end Releaser;

      protected body Releaser is
         procedure Release_It is
         begin
            Interrupt_Count := Interrupt_Count + 1;
            Ada.Synchronous_Task_Control.Set_True (SO);
         end Release_It;
      end Releaser;

      procedure Make_Body_Legal is
      begin null; end;
end CXDA004_1;
