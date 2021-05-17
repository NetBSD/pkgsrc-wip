
------------------------------------------------------------- C761006_Support

with Report;
package body C761006_Support is

  procedure Raise_Propagating_Exception(Do_It: Boolean) is
  begin
     if Report.Ident_Bool(Do_It) then
       raise Propagating_Exception;
     end if;
  end Raise_Propagating_Exception;

  Seed : Natural := 0;

  function Unique_Value return Natural is
  begin
    Seed := Seed +1;
    return Seed;
  end Unique_Value;

end C761006_Support;
