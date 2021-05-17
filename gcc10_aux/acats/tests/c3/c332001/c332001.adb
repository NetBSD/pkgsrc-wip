
------------------------------------------------------------------- C332001

with Report;
with C332001_0;
procedure C332001 is

begin  -- Main test procedure.

  Report.Test ("C332001", "Check that the static expression given for a " &
                          "number declaration may be of any numeric type. " &
                          "Check that the type of the named number is " &
                          "universal_integer of universal_real regardless " &
                          "of the type of the static expression that " &
                          "provides its value" );
   
  C332001_0.Check_Values;

  Report.Result;

end C332001;
