
----------------------------------------------------------

with System;
with Report;
with ImpDef.Annex_D;        use type ImpDef.Annex_D.Processor_Type;
with Ada.Task_Identification;
with Ada.Synchronous_Task_Control;
with CXD6001_1;
with CXD6001_2;
procedure CXD6001 is
begin
  Report.Test ("CXD6001",
               "Check that an abort takes place as soon" &
               " as the aborted task is no longer in an" &
               " abort-deferred region.");

  if ImpDef.Annex_D.Processor /= ImpDef.Annex_D.Uni_Processor then
      Report.Not_Applicable ("Multi-Processor configuration");
      Report.Result;
      return;
  end if;

  -- The requirements on the abort being immediate are
  -- only placed upon uni-processor systems.
  -- Only the simple case does not have an abort completion point
  -- prior to the check for being aborted.
  CXD6001_2.Simple_Case;

  -- A multi-processor could fail the following tests, as the
  -- victim task may continue to execute, return from the rendezvous
  -- or protected action, and set the Not_Protected flag for failure,
  -- before the killer task can abort it.
  CXD6001_2.In_Rendezvous;
  CXD6001_2.In_Protected;

  Report.Result;
end CXD6001;
