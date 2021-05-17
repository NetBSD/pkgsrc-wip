

     --==================================================================--


with CXC3007_0;

with Ada.Interrupts;

with ImpDef.Annex_C;
with Report;
procedure CXC3007 is
begin

   Report.Test ("CXC3007", "Attach_Handler and Exchange_Handler: Check "  &
                "that default treatment is restored if either is called " &
                "with value null or with result of Current_Handler when " &
                "no user-specified handler is attached");

   declare
      package AI renames Ada.Interrupts;

      Default     : AI.Parameterless_Handler;
      Old_Handler : AI.Parameterless_Handler;
   begin

      if AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
         Report.Failed ("User-specified handler is attached at start-up");
      else

         -- Identify and record default treatment:
         Default := AI.Current_Handler (Impdef.Annex_C.Interrupt_To_Generate);


      -- ==============
      -- Attach_Handler:
      -- ==============

         -- Attach a user handler:

         AI.Attach_Handler (CXC3007_0.Dynamic.Handler1'Access,
                            Impdef.Annex_C.Interrupt_To_Generate);

         if not AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Attach_Handler: nothing attached after 1 call");
         end if;


         -- Restore default treatment (using null):

         AI.Attach_Handler (null, Impdef.Annex_C.Interrupt_To_Generate);

         if AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Attach_Handler: default treatment not restored " &
                           "after call with null");
         end if;


         -- Attach a user handler twice:

         AI.Attach_Handler (CXC3007_0.Dynamic.Handler1'Access,
                            Impdef.Annex_C.Interrupt_To_Generate);

         AI.Attach_Handler (CXC3007_0.Dynamic.Handler2'Access,
                            Impdef.Annex_C.Interrupt_To_Generate);

         if not AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Attach_Handler: nothing attached after 2 calls");
         end if;


         -- Restore default treatment (using value obtained at start-up):

         AI.Attach_Handler (Default, Impdef.Annex_C.Interrupt_To_Generate);

         if AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Attach_Handler: default treatment not restored " &
                           "after call with start-up value");
         end if;


         -- Restore default treatment (using call to Current_Handler):

         AI.Attach_Handler (AI.Current_Handler(Impdef.Annex_C.Interrupt_To_Generate),
                            Impdef.Annex_C.Interrupt_To_Generate);

         if AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Attach_Handler: default treatment not restored " &
                           "after call with Current_Handler");
         end if;



      -- ================
      -- Exchange_Handler:
      -- ================

         -- Default treatment is in effect at this point.


         -- Exchange for a user handler twice:

         AI.Exchange_Handler (Old_Handler,
                              CXC3007_0.Dynamic.Handler1'Access,
                              Impdef.Annex_C.Interrupt_To_Generate);

                              -- Old_Handler now points to default treatment.

         AI.Exchange_Handler (Old_Handler,
                              CXC3007_0.Dynamic.Handler2'Access,
                              Impdef.Annex_C.Interrupt_To_Generate);

                              -- Old_Handler now points to Handler1.

         if not AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Exchange_Handler: nothing attached after 2 calls");
         end if;


         -- Restore default treatment (using null):

         AI.Exchange_Handler (Old_Handler,
                              null,
                              Impdef.Annex_C.Interrupt_To_Generate);

                              -- Old_Handler now points to Handler2.

         if AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Exchange_Handler: default treatment not " &
                           "restored after call with null");
         end if;


         -- Default treatment is again in effect at this point.


         -- Exchange for a user handler:

         AI.Exchange_Handler (Old_Handler,
                              CXC3007_0.Dynamic.Handler1'Access,
                              Impdef.Annex_C.Interrupt_To_Generate);

                              -- Old_Handler now points to default treatment.

         if not AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Exchange_Handler: nothing attached after 1 call");
         end if;


         -- Restore default treatment (using current value of Old_Handler):

         AI.Exchange_Handler (Old_Handler,
                              Old_Handler,
                              Impdef.Annex_C.Interrupt_To_Generate);

                              -- Old_Handler now points to Handler1.

         if AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Exchange_Handler: default treatment not " &
                           "restored after call with value of Old_Handler");
         end if;


         -- Default treatment is again in effect at this point.


         -- Restore default treatment (using call to Current_Handler):

         AI.Exchange_Handler (Old_Handler,
                              AI.Current_Handler(Impdef.Annex_C.Interrupt_To_Generate),
                              Impdef.Annex_C.Interrupt_To_Generate);

                              -- Old_Handler now points to default treatment.

         if AI.Is_Attached (Impdef.Annex_C.Interrupt_To_Generate) then
            Report.Failed ("Exchange_Handler: default treatment not " &
                           "restored after call with Current_Handler");
         end if;


      end if;

   exception
      when Program_Error =>
         Report.Failed ("Unexpected Program_Error raised");
   end;


   Report.Result;

end CXC3007;
