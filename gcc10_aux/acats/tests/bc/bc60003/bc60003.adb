
with BC60003_A, BC60003_B;
procedure BC60003 is

    use all type BC60003_A.Root; -- Make the primitives directly visible
                                 -- so that 12.6(9.1-2/3) can apply.

    package Inst01 is new BC60003_B.Gen_1
        (TPriv => BC60003_A.Root,
         P     => BC60003_A.P1);                                 -- OK.

    package Inst02 is new BC60003_B.Gen_1
        (TPriv => BC60003_A.Root,
         P     => BC60003_A.Nested.Not_Prim_P);                  -- ERROR:

    package Inst03 is new BC60003_B.Gen_1
        (TPriv => BC60003_A.Root,
         P     => BC60003_B.P4);                                 -- ERROR:

    --package Inst04 is new BC60003_B.Gen_1
    --    (TPriv => BC60003_A.Root'Class,
    --     P     => P1);                                         -- ERROR: ??

    package Inst05 is new BC60003_B.Gen_1
        (TPriv => BC60003_A.Root'Class,
         P     => BC60003_A.P3);                                 -- ERROR:


    package Inst06 is new BC60003_B.Gen_2
        (TPriv => BC60003_A.Root,
         P     => BC60003_A.P2);                                 -- OK.

    package Inst07 is new BC60003_B.Gen_2
        (TPriv => BC60003_A.Root,
         P     => BC60003_B.P5);                                 -- ERROR:


    package Inst08 is new BC60003_B.Gen_3
        (TPriv => BC60003_A.Root,
         F     => BC60003_A.F);                                  -- OK.

    package Inst09 is new BC60003_B.Gen_3
        (TPriv => BC60003_A.Root,
         F     => BC60003_A.Nested.Not_Prim_F);                  -- ERROR:

    package Inst10 is new BC60003_B.Gen_3
        (TPriv => BC60003_A.Root,
         F     => BC60003_B.F);                                  -- ERROR:

    --package Inst11 is new BC60003_B.Gen_3
    --    (TPriv => BC60003_A.Root'Class,
    --     F     => F);                                          -- ERROR: ??

    package Inst12 is new BC60003_B.Gen_3
        (TPriv => BC60003_A.Root'Class,
         F     => BC60003_A.F2);                                 -- ERROR:


    package Inst13 is new BC60003_B.Gen_4
        (TPriv     => BC60003_A.Root,
         Construct => BC60003_A.Construct);                      -- OK.

    package Inst14 is new BC60003_B.Gen_4
        (TPriv     => BC60003_A.Root,
         Construct => BC60003_A.Nested.Not_Prim_Const);          -- ERROR:

    package Inst15 is new BC60003_B.Gen_4
        (TPriv     => BC60003_A.Root,
         Construct => BC60003_B.Construct);                      -- ERROR:

    package Inst16 is new BC60003_B.Gen_4
        (TPriv     => BC60003_A.Root'Class,
         Construct => Construct);                                -- ERROR:
        -- Note: 12.6(9.1-2/3) does not apply to Construct, as it does
        -- not have a controlling parameter.

    package Inst17 is new BC60003_B.Gen_4
        (TPriv     => BC60003_A.Root'Class,
         Construct => BC60003_A.Build);                          -- ERROR:


    package Inst18 is new BC60003_B.Gen_5
        (P     => BC60003_A.P1);                                 -- OK.

    package Inst19 is new BC60003_B.Gen_5
        (P     => BC60003_A.Nested.Not_Prim_P);                  -- ERROR:

    package Inst20 is new BC60003_B.Gen_5
        (P     => BC60003_B.P4);                                 -- ERROR:


    package Inst21 is new BC60003_B.Gen_6
        (Construct => BC60003_A.Construct);                      -- OK.

    package Inst22 is new BC60003_B.Gen_6
        (Construct => BC60003_A.Nested.Not_Prim_Const);          -- ERROR:

    package Inst23 is new BC60003_B.Gen_6
        (Construct => BC60003_B.Construct);                      -- ERROR:


    package Inst24 is new BC60003_B.Gen_7
        (TDer => BC60003_A.Root,
         P    => BC60003_A.P1);                                  -- OK.

    package Inst25 is new BC60003_B.Gen_7
        (TDer => BC60003_A.Root,
         P    => BC60003_A.Nested.Not_Prim_P);                   -- ERROR:

    package Inst26 is new BC60003_B.Gen_7
        (TDer => BC60003_A.Root,
         P    => BC60003_B.P4);                                  -- ERROR:

    --package Inst27 is new BC60003_B.Gen_7
    --    (TDer => BC60003_A.Root'Class,
    --     P    => P1);                                          -- ERROR: ??

    package Inst28 is new BC60003_B.Gen_7
        (TDer => BC60003_A.Root'Class,
         P    => BC60003_A.P3);                                  -- ERROR:


    package Inst29 is new BC60003_B.Gen_8
        (TDer      => BC60003_A.Root,
         Construct => BC60003_A.Construct);                      -- OK.

    package Inst30 is new BC60003_B.Gen_8
        (TDer      => BC60003_A.Root,
         Construct => BC60003_A.Nested.Not_Prim_Const);          -- ERROR:

    package Inst31 is new BC60003_B.Gen_8
        (TDer      => BC60003_A.Root,
         Construct => BC60003_B.Construct);                      -- ERROR:

    package Inst32 is new BC60003_B.Gen_8
        (TDer      => BC60003_A.Root'Class,
         Construct => Construct);                                -- ERROR:

    package Inst33 is new BC60003_B.Gen_8
        (TDer      => BC60003_A.Root'Class,
         Construct => BC60003_A.Build);                          -- ERROR:


    generic
        type TDer is new BC60003_A.Root with private;
        with procedure P (T : in out TDer); -- Normal formal!
        with function FCon return TDer is abstract;
    package Gen_T1 is

        package Inst41 is new BC60003_B.Gen_1
            (TPriv => TDer, P     => P1);                        -- OK.

        package Inst42 is new BC60003_B.Gen_1
            (TPriv => TDer, P     => P);                         -- ERROR:

        package Inst43 is new BC60003_B.Gen_4
            (TPriv => TDer, Construct => Construct);             -- OK.

        package Inst44 is new BC60003_B.Gen_4
            (TPriv => TDer, Construct => FCon);                  -- OK.

        package Inst45 is new BC60003_B.Gen_7
            (TDer  => TDer, P     => P1);                        -- OK.

        package Inst46 is new BC60003_B.Gen_7
            (TDer  => TDer, P     => P);                         -- ERROR:

        package Inst47 is new BC60003_B.Gen_8
            (TDer  => TDer, Construct => Construct);             -- OK.

        package Inst48 is new BC60003_B.Gen_8
            (TDer  => TDer, Construct => FCon);                  -- OK.

    end Gen_T1;


    -- Try the example of AARM 12.6(8.j-8.l/2):

    generic
        type TDer (<>) is new BC60003_A.Root with private;
    package Gen_TA is

        procedure Dummy;

    end Gen_TA;

    package body Gen_TA is

        package Inst97 is new BC60003_B.Gen_4
            (TPriv => TDer, Construct => Construct);             -- OK.

        procedure Dummy is null;

    end Gen_TA;

    package Inst98 is new Gen_TA
        (TDer => BC60003_A.Root);                                -- OK.

    package Inst99 is new Gen_TA
        (TDer => BC60003_A.Root'Class);                          -- OK.

begin
    null;
end BC60003;
