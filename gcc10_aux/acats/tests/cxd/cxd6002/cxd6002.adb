
----------------------------------------------------------
----------------------------------------------------------

with System;
with Report;
with ImpDef.Annex_D;        use type ImpDef.Annex_D.Processor_Type;
with CXD6002_1;
procedure CXD6002 is
begin
  Report.Test ("CXD6002",
               "Check that an asynchronous transfer of control" &
               " takes place as soon" &
               " as the aborted statement is no longer in an" &
               " abort-deferred region.");
              
  -- the requirements on the abort being immediate are
  -- only placed upon uni-processor systems.
  if ImpDef.Annex_D.Processor /= ImpDef.Annex_D.Uni_Processor then
    Report.Not_Applicable ("Multi-Processor configuration");
    Report.Result;
    CXD6002_1.Done;
    return;
  end if;

  CXD6002_1.Simple_Case;
  CXD6002_1.In_Rendezvous;
  CXD6002_1.In_Protected;
  CXD6002_1.In_Protected_Requeue;

  CXD6002_1.Done;
  Report.Result;
end CXD6002;
