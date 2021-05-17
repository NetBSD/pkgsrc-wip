

     --==================================================================--


with CXC3009_1;

with Ada.Interrupts;

with ImpDef.Annex_C;
with Report;
procedure CXC3009 is
   package AI renames Ada.Interrupts;
begin -- CXC3009.

   Report.Test ("CXC3009", "Check that an exception propagated from " &
                "a handler invoked by an interrupt has no effect. "   &
                "Check that the exception causes further execution "  &
                "of the handler to be abandoned");


   ImpDef.Annex_C.Enable_Interrupts;  -- Enable interrupts, if necessary.



-- (1) Attach Dynamic_Handler.Handle_Interrupt to the interrupt
--     identified by Interrupt_To_Generate:

   AI.Attach_Handler (CXC3009_1.Dynamic_Handler.Handle_Interrupt'Access,
                      ImpDef.Annex_C.Interrupt_To_Generate);

   begin

-- (2) Generate the interrupt:

      ImpDef.Annex_C.Generate_Interrupt;
      delay ImpDef.Annex_C.Wait_For_Interrupt;

-- (3) Constraint_Error is raised within the interrupt handler.

-- (4) Verify that Dynamic_Handler.Handle_Interrupt was called, and that its
--     execution was abandoned when the exception was raised:

      if not CXC3009_1.Was_Handled then
         Report.Failed ("Handler in Dynamic_Handler was not called");
      elsif not CXC3009_1.Dynamic_Handler.Abandoned then
         Report.Failed ("Execution of handler in Dynamic_Handler was " &
                        "not abandoned");
      end if;

-- (5) Verify that the exception has no effect:

   exception
      when Constraint_Error =>
         Report.Failed ("Constraint_Error propagated from " &
                        "Dynamic_Handler was raised");
      when others           =>
         Report.Failed ("Unexpected exception was propagated from " &
                        "Dynamic_Handler and raised");
   end;

   Report.Result;

end CXC3009;
