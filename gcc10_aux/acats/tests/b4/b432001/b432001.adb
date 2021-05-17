

with B432001_Root, B432001_B, B432001_C, B432001_D;
use  B432001_Root, B432001_B, B432001_C, B432001_D;
procedure B432001 is
    Un : B432001_Root.Unrelated;
    Bn : B432001_Root.Base := (A => 1, C => 'A');
    D2 : B432001_B.Der2 := (Bn with B => False);             -- OK.
    D4 : B432001_C.Der4 := (Bn with B => True);              -- OK.
    D8 : B432001_D.Der8 := (D4 with others => <>);           -- OK.
    O1 : B432001_C.Der3 :=
                  (Bn with B => True, D => True);            -- OK.
    O2 : B432001_C.Der3 :=
                  (B432001_Root.Base with others => <>);     -- OK.
    O3 : B432001_C.Der3 :=
                  (B432001_Root.Base'Class with B | D => <>);-- ERROR: D.
    O4 : B432001_C.Der3 :=
                  (B432001_Root.Factory with B | D => <>);   -- ERROR: E.
    O5 : B432001_C.Der3 :=
                  (New_One with B => True, D => True);       -- ERROR: G.
    O6 : B432001_C.Der3 :=
                  (B432001_Root.New_One with B => True, D => True); -- OK.
    O7 : B432001_C.Der4 := (D4 with null record);            -- ERROR: F.
    O8 : B432001_C.Der4 := (Nested.Loaded with B => True);   -- ERROR: G.
    O9 : B432001_C.Der4 :=
                  (D8 with null record);                     -- ERROR: F.
    OA : B432001_C.Der4 :=
                  (B432001_D.Der8 with null record);         -- ERROR: F.
    OB : B432001_C.Der4 := (Nested.Val with others => <>);   -- ERROR: C.
    OC : B432001_C.Der4 := (Natural with others => <>);      -- ERROR: C.
    OD : B432001_C.Der4 :=
                  (B432001_Root.Base'Class(Bn) with B => <>);-- ERROR: E.
    OE : B432001_C.Der4 :=
                  (B432001_B.Der2'Class with null record);   -- ERROR: D.
    OG : B432001_D.Der5 := (Bn with B => True, E => 'E');    -- OK.
    OH : B432001_D.Der5 := (D4 with E => 'F');               -- OK.
    OI : B432001_C.Der6 := (Bn with others => <>);           -- ERROR: H.
    OJ : B432001_C.Der6 :=
                  (B432001_Root.Base with others => <>);     -- ERROR: H.
    OK : B432001_D.Der7 :=
                  (B432001_C.Der6 with E => 'F');            -- OK.
    OL : B432001_D.Der7 :=
                  (Bn with B => True, D => False, E => 'F'); -- ERROR: B.
    OM : B432001_D.Der7 :=
                  (D2 with D => False, E => 'F');            -- ERROR: B.
    ON : B432001_Root.Base :=
                  (null with A => 1, C => 'A');              -- ERROR: C, H.
    OV : B432001_C.Der3 :=
                  (B432001_Root.Unrelated with D => True);   -- ERROR: A.
    OW : B432001_C.Der3 :=
                  (Un with D => <>);                         -- ERROR: A.
    OX : B432001_Root.Base := (Nested.Wild with C => 'E');   -- ERROR: H.
    OY : B432001_Root.Base := (A => Nested.Wild, C => 'D');  -- OK.
    OZ : B432001_C.Der4 := (Nested.Wild with B => True);     -- OK.
	    -- (Wild return Natural is not considered, it's not tagged.)
begin
    null;
end B432001;

