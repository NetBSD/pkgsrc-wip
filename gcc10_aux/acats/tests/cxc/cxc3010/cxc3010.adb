
with Ada.Interrupts;
with ImpDef.Annex_C;
with Report;
with CXC3010_0;
with CXC3010_1;
procedure CXC3010 is
   Interrupt_Id    : constant Ada.Interrupts.Interrupt_Id :=
                                 Impdef.Annex_C.Interrupt_To_Generate;
   A_Handler : CXC3010_0.Device_Interface_T
      (Int_Id => Interrupt_Id);
   New_Handler : Ada.Interrupts.Parameterless_Handler :=
      CXC3010_1.Alternate_Device_Interface.Handler'Access;
   Outcome : Boolean := False; -- Set to True if handler handled interrupt

begin
   Report.Test ("CXC3010", "Testing the effect of detaching an interrupt " &
                           "handler attached by an aspect");
   if Ada.Interrupts.Is_Attached (Interrupt_Id) then
      -- Handler is attached we can continue
      Impdef.Annex_C.Generate_Interrupt;
      delay ImpDef.Annex_C.Wait_For_Interrupt;
      A_Handler.Check (Outcome);
      if Outcome then
         begin
            Ada.Interrupts.Detach_Handler (Interrupt_Id);
            -- Not allowed C.3.2(21/3):
            -- Handler is not detached and Program_Error is raised.
            Report.Failed ("Detach_Handler did not raise exception");
         exception
            when Program_Error =>
               Report.Comment ("Program_Error raised as expected by Detach_Handler");
         end;
         begin
            Ada.Interrupts.Attach_Handler (New_Handler,
                                           Interrupt_Id);
                -- Not allowed C.3.2(21/3):
                -- Handler is not attached and Program_Error is raised.
            Report.Failed ("Attach_Handler did not raise exception");
         exception
            when Program_Error =>
               Report.Comment ("Program_Error raised as expected by Attach_Handler");
         end;
         declare
            Old_Handler : Ada.Interrupts.Parameterless_Handler;
         begin
            Ada.Interrupts.Exchange_Handler (Old_Handler,
                                             New_Handler,
                                             Interrupt_Id);
                -- Not allowed C.3.2(21/3):
                -- Handler is not exchanged and Program_Error is raised.
            Report.Failed ("Exchange_Handler did not raise exception");
         exception
            when Program_Error =>
               Report.Comment ("Program_Error raised as expected by " &
                               "Exchange_Handler");
         end;
      else
         Report.Failed ("Handler was attached but interrupt was not handled");
      end if;
   else
      Report.Failed ("Implementation has not attached the handler as required");
   end if;
   Report.Result;
end CXC3010;

