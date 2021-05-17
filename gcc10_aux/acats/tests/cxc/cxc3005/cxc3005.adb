

     --==================================================================--


with CXC3005_0;
with CXC3005_1;

with Ada.Interrupts;

with Report;
procedure CXC3005 is

begin -- CXC3005.

   Report.Test ("CXC3005", "Check that Program_Error is raised if the " &
                "interrupt passed to Is_Attached, Current_Handler, "    &
                "Attach_Handler, Exchange_Handler, or Detach_Handler "  &
                "is reserved");


   if CXC3005_1.Reserved_Interrupt_Found then

      -- ===========
      -- Is_Attached:
      -- ===========

      declare
         use CXC3005_1;
      begin
         if Ada.Interrupts.Is_Attached (Reserved_Interrupt) then
            Avoid_Optimization (Reserved_Interrupt);
         end if;
         Report.Failed ("Is_Attached: Program_Error was not raised");
      exception
         when Program_Error => -- Expected result.
            null;
         when others        =>
            Report.Failed ("Is_Attached: Unexpected exception raised");
      end;


      -- ===============
      -- Current_Handler:
      -- ===============

      declare
         Handler : Ada.Interrupts.Parameterless_Handler;

         use CXC3005_1;
      begin
         Handler := Ada.Interrupts.Current_Handler (Reserved_Interrupt);
         Avoid_Optimization (Handler);
         Report.Failed ("Current_Handler: Program_Error was not raised");
      exception
         when Program_Error => -- Expected result.
            null;
         when others        =>
            Report.Failed ("Current_Handler: Unexpected exception raised");
      end;


      -- ==============
      -- Attach_Handler:
      -- ==============

      declare
         Handler : Ada.Interrupts.Parameterless_Handler :=
                   CXC3005_0.Dynamic_Handler.Handle_Interrupt'Access;

         use CXC3005_1;
      begin
         Ada.Interrupts.Attach_Handler (Handler, Reserved_Interrupt);
         Avoid_Optimization (Handler);
         Report.Failed ("Attach_Handler: Program_Error was not raised");
      exception
         when Program_Error => -- Expected result.
            null;
         when others        =>
            Report.Failed ("Attach_Handler: Unexpected exception raised");
      end;


      -- ================
      -- Exchange_Handler:
      -- ================

      declare
         Old     : Ada.Interrupts.Parameterless_Handler;
         Handler : Ada.Interrupts.Parameterless_Handler :=
                   CXC3005_0.Dynamic_Handler.Handle_Interrupt'Access;

         use CXC3005_1;
      begin
         Ada.Interrupts.Exchange_Handler (Old, Handler, Reserved_Interrupt);
         Avoid_Optimization (Handler);
         Report.Failed ("Exchange_Handler: Program_Error was not raised");
      exception
         when Program_Error => -- Expected result.
            null;
         when others        =>
            Report.Failed ("Exchange_Handler: Unexpected exception raised");
      end;


      -- ==============
      -- Detach_Handler:
      -- ==============

      declare
         use CXC3005_1;
      begin
         Ada.Interrupts.Detach_Handler (Reserved_Interrupt);
         Avoid_Optimization (Reserved_Interrupt);
         Report.Failed ("Detach_Handler: Program_Error was not raised");
      exception
         when Program_Error => -- Expected result.
            null;
         when others        =>
            Report.Failed ("Detach_Handler: Unexpected exception raised");
      end;

   else
      Report.Not_Applicable ("No reserved interrupts found");
   end if;


   Report.Result;

end CXC3005;
