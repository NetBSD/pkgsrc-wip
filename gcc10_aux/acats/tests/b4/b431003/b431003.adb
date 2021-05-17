

with B431003_Root, B431003_B, B431003_C, B431003_D;
procedure B431003 is
    -- Giving all components:
    OB : B431003_Root.Base := (A => 1, C => 'A');            -- OK.
    OP : B431003_Root.Private_Root := (A => 1, C => 'A');    -- ERROR:
    O2 : B431003_B.Der2 :=
                  (A => 1, C => 'A', D => True);             -- OK.
    O3 : B431003_C.Der3 :=
                  (A => 1, C => 'A', D => True, E => 'A');   -- OK.
    O4 : B431003_B.Der4 :=
                  (A => 1, C => 'A', D => True);             -- ERROR:
    O5 : B431003_C.Der5 :=
                  (A => 1, C => 'A', D => True, E => 'A');   -- ERROR:
    O6 : B431003_B.Der6 :=
                  (A => 1, C => 'A', D => True);             -- ERROR:
    O7 : B431003_C.Der7 :=
                  (A => 1, C => 'A', D => True, E => 'A');   -- ERROR:
    O8 : B431003_D.Der8 :=
                  (A => 1, B => True, C|E => 'A', D => True);-- ERROR:
    O9 : B431003_D.Der9 :=
                  (A => 1, B => True, C|E => 'A', D => True);-- ERROR:

    -- Giving just visible components:
    O14 : B431003_B.Der4 :=
                  (D => True);                               -- ERROR:
    O15 : B431003_C.Der5 :=
                  (D => True, E => 'A');                     -- ERROR:
    O16 : B431003_B.Der6 :=
                  (A => 1, C => 'A');                        -- ERROR:
    O17 : B431003_C.Der7 :=
                  (A => 1, C => 'A', E => 'A');              -- ERROR:
    O18 : B431003_D.Der8 :=
                  (B => True, E => 'A', D => True);          -- ERROR:
    O19 : B431003_D.Der9 :=
                  (A => 1, B => True, C|E => 'A');           -- ERROR:
begin
    null;
end B431003;

