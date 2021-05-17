

procedure BXD1002_3(Pri : Integer) is
  task T is
    pragma priority (Pri);                                           -- OK.
  end T;

  pragma Priority (Pri);                                           -- ERROR:
                                  -- priority for a procedure must be static

  task body T is 
  begin
    null;
  end T;
begin
  null;
end BXD1002_3;
