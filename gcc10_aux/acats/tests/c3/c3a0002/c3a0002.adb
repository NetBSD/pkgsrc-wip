
-----------------------------------------------------------------------------

with Report;
with C3A0002_0; 

procedure C3A0002 is

   Log_Access : C3A0002_0.Log_Procedure_Ptr;
   Theta      : Float := 0.0;

begin

   Report.Test ("C3A0002", "Check that access to subprogram type can be "
                         & "used to select and invoke procedures with "
                         & "appropriate arguments dynamically" );

   Log_Access := C3A0002_0.Log_Calc_Fast'Access;

   -- Invoking Log procedure designated by access value
   Log_Access (Theta);

   If C3A0002_0.TC_Call_Tag /= 1 or C3A0002_0.Return_Num /= 0.0 then
      Report.Failed ("Incorrect Log_Calc_Fast result");
   end if;

   Theta := 1.0;

   Log_Access := C3A0002_0.Log_Calc_Acc'Access;

   -- Invoking Log procedure designated by access value
   Log_Access (Theta);

   If C3A0002_0.TC_Call_Tag /= 2 or C3A0002_0.Return_Num /= 1.0 then
      Report.Failed ("Incorrect Log_Calc_Acc result");
   end if;

   Theta := -1.0;

   Log_Access := C3A0002_0.Log_Calc_Table'Access;

   -- Invoking Log procedure designated by access value
   Log_Access (Theta);

   If C3A0002_0.TC_Call_Tag /= 3 or C3A0002_0.Return_Num /= -1.0 then
      Report.Failed ("Incorrect Log_Calc_Table result");
   end if;

   Report.Result;

end C3A0002;
