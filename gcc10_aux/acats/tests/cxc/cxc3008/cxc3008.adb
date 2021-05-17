

     --==================================================================--


with CXC3008_0;

with Ada.Interrupts;

with ImpDef.Annex_C;
with Report;
procedure CXC3008 is
begin

   Report.Test ("CXC3008", "Check Current_Handler, Attach_Handler, and " &
                "Exchange_Handler when user-specified handlers are "     &
                "attached. Check Detach_Handler");

   ImpDef.Annex_C.Enable_Interrupts;    -- Enable interrupts, if necessary.


   declare
      package AI renames Ada.Interrupts;

      Old_Handler : AI.Parameterless_Handler;
   begin

      -- Attach a user handler:

      AI.Attach_Handler (CXC3008_0.Dynamic1.Handler'Access,
                         ImpDef.Annex_C.Interrupt_To_Generate);

      -- Attach a different user handler:

      AI.Attach_Handler (CXC3008_0.Dynamic2.Handler'Access,
                         ImpDef.Annex_C.Interrupt_To_Generate);

      ImpDef.Annex_C.Generate_Interrupt;
      delay ImpDef.Annex_C.Wait_For_Interrupt;

      if CXC3008_0.Dynamic1.Handle_Count /= 0 or
         CXC3008_0.Dynamic2.Handle_Count /= 1
      then
         Report.Failed ("Wrong handler counts after 1st interrupt");
      end if;

      Report.Comment ("Done with 1st interrupt");


      -- Exchange handlers:

      AI.Exchange_Handler (Old_Handler,
                           CXC3008_0.Dynamic1.Handler'Access,
                           ImpDef.Annex_C.Interrupt_To_Generate);

                           -- Old_Handler now designates Dynamic2.Handler.

      ImpDef.Annex_C.Generate_Interrupt;
      delay ImpDef.Annex_C.Wait_For_Interrupt;

      if CXC3008_0.Dynamic1.Handle_Count /= 1 or
         CXC3008_0.Dynamic2.Handle_Count /= 1
      then
         Report.Failed ("Wrong handler counts after 2nd interrupt");
      end if;

      Report.Comment ("Done with 2nd interrupt");

      -- Current handler is Dynamic1.Handler.


      -- Attach a handler with pragma Attach_Handler (via object creation):

      declare
         Static : CXC3008_0.Handler_Type;
      begin

         ImpDef.Annex_C.Generate_Interrupt;
         delay ImpDef.Annex_C.Wait_For_Interrupt;

         if Static.Handle_Count /= 1             or
            CXC3008_0.Dynamic1.Handle_Count /= 1 or
            CXC3008_0.Dynamic2.Handle_Count /= 1
         then
            Report.Failed ("Wrong handler counts after 3rd interrupt");
         end if;

         Report.Comment ("Done with 3rd interrupt");

      end;

      -- Protected object Static has been finalized, and previous handler
      -- (Dynamic1.Handler) should be restored. 


      -- Exchange handlers:

      AI.Exchange_Handler (Old_Handler,
                           Old_Handler,  -- Designates Dynamic2.Handler.
                           ImpDef.Annex_C.Interrupt_To_Generate);

                           -- Old_Handler now designates Dynamic1.Handler.

      ImpDef.Annex_C.Generate_Interrupt;
      delay ImpDef.Annex_C.Wait_For_Interrupt;

      if CXC3008_0.Dynamic1.Handle_Count /= 1 or
         CXC3008_0.Dynamic2.Handle_Count /= 2
      then
         Report.Failed ("Wrong handler counts after 4th interrupt");
      end if;

      Report.Comment ("Done with 4th interrupt");


      -- Attach a different handler:

      AI.Attach_Handler (Old_Handler, -- Designates Dynamic1.Handler.
                         ImpDef.Annex_C.Interrupt_To_Generate);

      -- Attach yet a different user handler:

      -- In practice, calling Current_Handler within Attach_Handler for
      -- the same interrupt will probably never occur, but calling it for
      -- a different interrupt will. That's what is simulated below:

      AI.Attach_Handler
        (AI.Current_Handler(ImpDef.Annex_C.Interrupt_To_Generate),
         ImpDef.Annex_C.Interrupt_To_Generate);

      ImpDef.Annex_C.Generate_Interrupt;
      delay ImpDef.Annex_C.Wait_For_Interrupt;

      if CXC3008_0.Dynamic1.Handle_Count /= 2 or
         CXC3008_0.Dynamic2.Handle_Count /= 2
      then
         Report.Failed ("Wrong handler counts after 5th interrupt");
      end if;

      Report.Comment ("Done with 5th interrupt");


      -- Exchange handlers:

      -- In practice, calling Current_Handler within Exchange_Handler for
      -- the same interrupt will probably never occur, but calling it for
      -- a different interrupt will. That's what is simulated below:

      AI.Exchange_Handler
        (Old_Handler,
         AI.Current_Handler(ImpDef.Annex_C.Interrupt_To_Generate),
         ImpDef.Annex_C.Interrupt_To_Generate);

                           -- Old_Handler now designates Dynamic1.Handler.

      ImpDef.Annex_C.Generate_Interrupt;
      delay ImpDef.Annex_C.Wait_For_Interrupt;

      if CXC3008_0.Dynamic1.Handle_Count /= 3 or
         CXC3008_0.Dynamic2.Handle_Count /= 2
      then
         Report.Failed ("Wrong handler counts after 6th interrupt");
      end if;

      Report.Comment ("Done with 6th interrupt");



      -- Test Detach_Handler:

      if not AI.Is_Attached (ImpDef.Annex_C.Interrupt_To_Generate) then
         Report.Failed ("No user-specified handler is attached");
      else

         -- Detach handler:

         AI.Detach_Handler (ImpDef.Annex_C.Interrupt_To_Generate);

         if AI.Is_Attached (ImpDef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Default treatment not restored by Detach_Handler");
         end if;

      end if;

   exception
      when Program_Error =>
         Report.Failed ("Unexpected Program_Error raised");
   end;


   Report.Result;

end CXC3008;
