
-----------------------------------------------------------------------------

with Report;
with C3A0001_0;

procedure C3A0001 is

   Sine_Access : C3A0001_0.Sine_Function_Ptr;
   X, Theta    : Float := 0.0;

begin

   Report.Test ("C3A0001", "Check that access to subprogram can be " &
                "used to select and invoke an operation with " &
                "appropriate arguments dynamically");

   Sine_Access := C3A0001_0.Sine_Calc_Fast'Access;

   -- Invoking Sine function designated by access value
   X := Sine_Access(Theta);

   If C3A0001_0.TC_Call_Tag /= 1 then
      Report.Failed ("Incorrect Sine_Calc_Fast result");
   end if;

   Sine_Access := C3A0001_0.Sine_Calc_Acc'Access;

   -- Invoking Sine function designated by access value
   X := Sine_Access(Theta);

   If C3A0001_0.TC_Call_Tag /= 2 then
      Report.Failed ("Incorrect Sine_Calc_Acc result");
   end if;

   Sine_Access := C3A0001_0.Sine_Calc_Table'Access;

   -- Invoking Sine function designated by access value
   X := Sine_Access(Theta);

   If C3A0001_0.TC_Call_Tag /= 3 then
      Report.Failed ("Incorrect Sine_Calc_Table result");
   end if;

   Report.Result;

end C3A0001;
