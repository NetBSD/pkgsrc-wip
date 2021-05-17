

with B431002_Root, B431002_B, B431002_C, B431002_D;
procedure B431002 is
    Bn : B431002_Root.Base := (A => 1, C => 'A');
begin
    declare
        O1 : B431002_B.Der2 := (Bn with D => <>);                  -- OK.
        O2 : B431002_B.Der2 := (Bn with <>);                       -- ERROR: A
    begin
        if O1.D then
            null;
        end if;
    end;
    declare
        O3 : B431002_C.Der3 := (B431002_Root.Base with True, 'A'); -- OK.
        O4 : B431002_C.Der3 := (B431002_Root.Base with True, <>);  -- ERROR: A
    begin
        if O3.D then
            null;
        end if;
    end;
    declare
        O5 : B431002_D.Der4 := (Bn with True, B => True, E => <>); -- OK.
        O6 : B431002_D.Der4 := (Bn with <>, B => True, E => <>);   -- ERROR: A
    begin
        if O5.D then
            null;
        end if;
    end;
    declare
        O7 : B431002_D.Der4 := (Bn with True, E => <>, B => True); -- OK.
        O8 : B431002_D.Der4 := (Bn with D => True, E => <>, True); -- ERROR: B
    begin
        if O7.D then
            null;
        end if;
    end;
    declare
        O9 : B431002_D.Der4 := (B431002_B.Der2 with
                                  E => 'D', others => True);       -- OK.
        OA : B431002_D.Der4 := (B431002_B.Der2 with
                                  E => 'D', True);                 -- ERROR: B
    begin
        if O9.D then
            null;
        end if;
    end;
    declare
        O9A: B431002_D.Der4 := (Bn with True, E => 'A', B => True);-- OK.
        OAA: B431002_D.Der4 := (Bn with True, E => 'A', True);     -- ERROR: B
    begin
        if O9A.D then
            null;
        end if;
    end;
    declare
        OB : B431002_D.Der4 := (Bn with E => <>, others => True);  -- OK.
        OC : B431002_D.Der4 := (Bn with others => True, E => <>);  -- ERROR: C
    begin
        if OB.D then
            null;
        end if;
    end;
    declare
        OD : B431002_D.Der4 := (Bn with True, others => <>);       -- OK.
        OE : B431002_D.Der4 := (Bn with others => <>, True);       -- ERROR: C
    begin
        if OD.D then
            null;
        end if;
    end;
    declare
        OG : B431002_D.Der4 := (Bn with
                                B | D => True, others => 'A');     -- OK.
        OH : B431002_D.Der4 := (Bn with
                                others => True, others => 'A');    -- ERROR: C
    begin
        if OG.D then
            null;
        end if;
    end;
    declare
        OI : B431002_D.Der4 := (Bn with E => <>,
                                      D => False, B => True);      -- OK.
        OJ : B431002_D.Der4 := (Bn with E => <>,
                                      others => False, B => True); -- ERROR: C
    begin
        if OI.D then
            null;
        end if;
    end;
    declare
        OK : B431002_D.Der4 := (Bn with
                                 True, E => <>, B => True);        -- OK.
        OL : B431002_D.Der4 := (Bn with
                                 False, others => <>, B => True);  -- ERROR: C
    begin
        if OK.D then
            null;
        end if;
    end;
    declare
        OM : B431002_B.Der2 := (Bn with D => False, others => <>); -- OK.
        ON : B431002_B.Der2 := (Bn with others => <>, D => False); -- ERROR: C
    begin
        if OM.D then
            null;
        end if;
    end;
end B431002;

