
-----------------------------------------------------------------------------

with Report;
with C3A0003_0;

procedure C3A0003 is

   type Real is digits 5;

   Subtype Trig_Float is Real range -1.0 .. 1.0;

   package Trig is new C3A0003_0 (Real_Num => Trig_Float);

   Sine_Access : Trig.Sine_Function_Ptr;
   X, Theta    : Trig_Float := 0.0;

begin

   Report.Test ("C3A0003", "Check that a function in a generic instance can "
                         & "be called using an access-to-subprogram value");

   Sine_Access := Trig.Sine_Calc_Fast'Access;

   -- Invoking Sine function designated by access value
   X := Sine_Access.all(Theta);

   If Trig.TC_Call_Tag /= 1 then
      Report.Failed ("Incorrect Sine_Calc_Fast result");
   end if;

   Sine_Access := Trig.Sine_Calc_Acc'Access;

   -- Invoking Sine function designated by access value
   X := Sine_Access.all(Theta);

   If Trig.TC_Call_Tag /= 2 then
      Report.Failed ("Incorrect Sine_Calc_Acc result");
   end if;

   Sine_Access := Trig.Sine_Calc_Table'Access;

   -- Invoking Sine function designated by access value
   X := Sine_Access.all(Theta);

   If Trig.TC_Call_Tag /= 3 then
      Report.Failed ("Incorrect Sine_Calc_Table result");
   end if;

   Report.Result;

end C3A0003;
