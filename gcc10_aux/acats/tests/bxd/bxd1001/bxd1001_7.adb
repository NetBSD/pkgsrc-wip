

with System;
procedure BXD1001_7 is
  task T is
    entry E;
  end T;

  task body T is
     pragma Priority (System.Default_Priority);                   -- ERROR:
                              -- pragma priority not allowed in a task body
  begin
    accept E do
       pragma Priority (System.Priority'Last);                    -- ERROR:
                      -- pragma priority not allowed in an accept statement
       null;
    end E;
  end T;
begin
  T.E;
end BXD1001_7;
