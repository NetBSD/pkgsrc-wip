 -- Alert_Foundation.Public_Child

--=======================================================================--
  
with Report;
with F393B00.C393B13_0;
  -- Alert_foundation.Public_Child;
procedure C393B13 is
  package Child renames F393B00.C393B13_0;
  CA : Child.Child_Alert(Child.Message'Length);
 
begin

  Report.Test ("C393B13", "Check that an extended type can be derived " &
                          "from an abstract type");

  if CA.Times_Handled /= 0 then
    Report.Failed ("Wrong initialization");
  end if;

  Child.Handle (CA);
  if (CA.Times_Handled /= 1)
  or (CA.Msg /= Child.Message) then
    Report.Failed ("Wrong results from Handle");
  end if;
  
  Report.Result;

end C393B13;
