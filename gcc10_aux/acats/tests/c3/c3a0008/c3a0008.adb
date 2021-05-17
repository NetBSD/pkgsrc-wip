

-----------------------------------------------------------------------------


with Report;

with Integrate_Lookup; 

procedure C3A0008 is

  Area : Float := 0.0;

begin

  Report.Test ("C3A0008", "Check that subprogram references may be passed "
                        & "as parameters using access-to-subprogram types. " 
                       & "Check that the passed subprograms may be invoked "
                        & "from within the called subprogram");

  Area := Integrate_Lookup.Integrate
            (Integrate_Lookup.Log'Access, 1.0, 2.0);

  If not Integrate_Lookup.TC_Log_Call or Area /= 0.2 then
     Report.Failed ("Incorrect Log result");
  end if;

  Area := Integrate_Lookup.Integrate
            (Integrate_Lookup.Sine'Access, 1.0, 2.0);

  If not Integrate_Lookup.TC_Sine_Call or Area /= 0.0 then
     Report.Failed ("Incorrect Sine result");
  end if;

  Area := Integrate_Lookup.Integrate
            (Integrate_Lookup.Cos'Access, 1.0, 2.0);

  If not Integrate_Lookup.TC_Cos_Call or Area /= 2.0 then
     Report.Failed ("Incorrect Cos result");
  end if;

  Report.Result;

end C3A0008;
