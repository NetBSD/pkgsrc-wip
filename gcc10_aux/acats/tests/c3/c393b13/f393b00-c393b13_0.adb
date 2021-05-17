 -- Alert_Foundation.Public_Child;

--=======================================================================--

package body F393B00.C393B13_0 is
          -- Alert_Foundation.Public_Child
  
  procedure Handle (CA : in out Child_Alert) is
    begin
      CA.Msg(1..Message'Length) := Message;
      CA.Times_Handled := CA.Times_Handled + 1;
    end;
  
end F393B00.C393B13_0;
