
with B415002_A; use B415002_A;
procedure B415002 is

    CLRef : Constant_Reference := (D => Obj'access);
        -- The object could be a variable, but that's irrelevant to the
        -- objective.
    VLRef : Variable_Reference := (D => Obj'access);

begin

    if CLRef = 10 then                                            -- OK.
        VLRef := 20;                                              -- OK.
    elsif VLRef = 12 then                                         -- OK.
        CLRef := 52;                                              -- ERROR:
    else
        Sink (VLRef);                                             -- OK.
        Sink (CLRef);                                             -- ERROR:
    end if;

    if CRef = 21 then                                             -- OK.
        VRef := 32;                                               -- OK.
    elsif VRef = 4 then                                           -- OK.
        CRef := 92;                                               -- ERROR:
    else
        Sink (VRef);                                              -- OK.
        Sink (CRef);                                              -- ERROR:
    end if;

    -- Use explicitly (not the generalized reference):
    if CLRef.D.all = 44 then                                      -- OK.
        VLRef.D.all := 42;                                        -- OK.
    elsif VLRef.D.all = 33 then                                   -- OK.
        CLRef.D.all :=  8;                                        -- ERROR:
    else
        Sink (VLRef.D.all);                                       -- OK.
        Sink (CLRef.D.all);                                       -- ERROR:
    end if;

end B415002;
