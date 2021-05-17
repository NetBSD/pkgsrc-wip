

with System;
procedure BXD1001_6 is
  type A_Record is 
    record
      pragma Priority (System.Default_Priority);                  -- ERROR:
             -- pragma Priority not immediately within an allowed construct
      Field : Integer;
    end record;
begin
  null;
end BXD1001_6;
