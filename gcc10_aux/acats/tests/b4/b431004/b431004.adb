

with B431004_Root, B431004_B, B431004_C, B431004_D;
procedure B431004 is
    Bn : B431004_Root.Base := (A => 1, C => 'A');
    BD2: B431004_B.Der2 := (A => 1, C => 'A', B => 10);

    -- (A) The selector names can only name components and discriminants
    --     of the record extension, and cannot name components of
    --     other variants or of the type of the ancestor part;
    -- Case 1: Components of other types.
    A1 : B431004_B.Der2 := (Bn with 2, D => <>);                -- ERROR: D
    A2 : B431004_B.Der2 := (B431004_Root.Base with
                              B => 81, D => True);              -- ERROR: D
    -- Case 2: Components of the wrong variant.
    A3 : B431004_D.Der4 := (B431004_C.Der3 with
                           Which => True, T => <>);             -- OK.
    A4 : B431004_D.Der4 := (B431004_C.Der3 with
                           Which => False, T => 'A');           -- ERROR: T
    -- Case 3: Components of the ancestor.
    A5 : B431004_C.Der3 := (Bn with 2, 'E', 4);                 -- OK.
    A6 : B431004_C.Der3 := (B431004_Root.Base with
                            B => 2, C => 'W', D => 'A', E => 4);-- ERROR: C
    A7 : B431004_C.Der3 := (Bn with A => 13, others => <>);     -- ERROR: A
    A8 : B431004_C.Der3 := (B431004_Root.Base with
                            2, 'A', 4, A => <>);                -- ERROR: A

    -- (B) A component association (other than others => <>) is illegal
    --     if it does not have an associated component;
    -- Case 1: others => expr.
    B1 : B431004_B.Der2 := (Bn with 2, others => True);     -- ERROR: others
    B2 : B431004_B.Der2 := (B431004_Root.Base with
                             B => 19, others => 'A');       -- ERROR: others
    -- Case 2: Too many positional components.
    B3 : B431004_B.Der2 := (Bn with 2, True);               -- ERROR: True
    B4 : B431004_C.Der3 := (Bn with 2, 'E', 4, 'A');        -- ERROR: 'A'

    -- (C) The aggregate is illegal if it has needed components that are
    --     not associated with any component associations;
    C1 : B431004_C.Der3 := (Bn with D => 'E', E => 4);      -- ERROR: B needed
    C2 : B431004_C.Der3 := (Bn with D | E => <>);           -- ERROR: B needed
    C3 : B431004_C.Der3 := (B431004_Root.Base with 2, 'E'); -- ERROR: E needed
    C4 : B431004_C.Der3 := (BD2 with D | E => <>);          -- OK.
    C5 : B431004_C.Der3 := (B431004_B.Der2 with 'E', 2);    -- OK.

    -- (D) The aggregate is illegal if it has a needed component that is
    --     associated with more than one component association;
    -- Case 1: The same component is named twice.
    D1 : B431004_C.Der3 := (B431004_Root.Base with
                            B => 2, D => 'W', D => 'A', E => 4);-- ERROR: D
    D2 : B431004_C.Der3 := (Bn with B => 2,
                              D => <>, E => 4, B => <>);        -- ERROR: B
    -- Case 2: A component is included positionally, and then named.
    D3 : B431004_C.Der3 := (Bn with 2, 'D', E => 4, B => <>);   -- ERROR: B
    D4 : B431004_C.Der3 := (B431004_Root.Base with
                              2, 'W', D => 'A', E => 4);        -- ERROR: D

    -- (E) A component association with an expression cannot have two or
    --     more associated components of different types.
    -- Case 1: A named component with two component names.
    E1 : B431004_C.Der3 := (Bn with B | E => 2, D => 'X');    -- ERROR: B | E
    E2 : B431004_C.Der3 := (B431004_Root.Base with
                              D => 'W', B | E => 6);          -- ERROR: B | E
    E3 : B431004_C.Der3 := (B431004_Root.Base with
                              D => 'W', B | E => <>);         -- OK.
    E4 : B431004_D.Der4 := (B431004_Root.Base with Which => True,
                              D | T => 'A', B => 6, E => 6);  -- OK.
    -- Case 2: others => expr.
    E5 : B431004_C.Der3 := (Bn with D => 'X', others => 18);  -- ERROR: others
    E6 : B431004_C.Der3 := (B431004_Root.Base with
                              D => 'W', others => 26);        -- ERROR: others
    E7 : B431004_C.Der3 := (B431004_Root.Base with
                              D => 'W', others => <>);        -- OK.
    E8 : B431004_D.Der4 := (B431004_Root.Base with Which => True,
                              B => 6, E => 6, others => 'R'); -- OK.

begin
    null;
end B431004;

