
procedure B3A1A02 is

    type Untagged_Inc;

    type Tagged_Inc is tagged;


    O01 : Untagged_Inc;                                   -- ERROR:

    O02 : Tagged_Inc;                                     -- ERROR:

    O03 : access Untagged_Inc;                            -- OK.

    O04 : access Tagged_Inc;                              -- OK.

    O05 : access Untagged_Inc := new Untagged_Inc;        -- ERROR:

    O06 : access Tagged_Inc :=
                  new Tagged_Inc'(null record);           -- ERROR:

    Ren01 : Untagged_Inc renames O03.all;                 -- ERROR:

    Ren02 : Tagged_Inc renames O04.all;                   -- ERROR:

    type A01 is array (1..10) of Untagged_Inc;            -- ERROR:

    type A02 is array (3..8)  of Untagged_Inc;            -- ERROR:

    type R01 (D : Untagged_Inc) is null record;           -- ERROR:

    type R02 is record
        C : Tagged_Inc;                                   -- ERROR:
    end record;

    protected type P01 (D : Untagged_Inc) is              -- ERROR:
        procedure Foo;
    private
        C : Tagged_Inc;                                   -- ERROR:
    end P01;

    task type T01 (D : Untagged_Inc);                     -- ERROR:

    type Acc_UI is access all Untagged_Inc;
    O07 : Acc_UI := new Untagged_Inc'(1);                 -- ERROR:

    type Acc_TI is access constant Tagged_Inc;
    O08 : Acc_TI := new Tagged_Inc;                       -- ERROR:

    type Untagged_Inc is range 1 .. 100;

    type Tagged_Inc is tagged null record;

    protected body P01 is                                 -- OPTIONAL ERROR:
        procedure Foo is begin null; end Foo;
    end P01;

    task body T01 is                                      -- OPTIONAL ERROR:
    begin
        null;
    end T01;



    O11 : F3A1A00.An_Untagged_Type;                       -- ERROR:

    O12 : F3A1A00.A_Tagged_Type;                          -- ERROR:

    O13 : access F3A1A00.An_Untagged_Type;                -- OK.

    O14 : access F3A1A00.A_Tagged_Type;                   -- OK.

    O15 : access F3A1A00.An_Untagged_Type := new F3A1A00.An_Untagged_Type;        -- ERROR:

    O16 : access F3A1A00.A_Tagged_Type :=
                  new F3A1A00.A_Tagged_Type;              -- ERROR:

    O17 : F3A1A00.An_Access_to_Untagged;                  -- ERROR:

    O18 : F3A1A00.An_Access_to_Tagged;                    -- ERROR:

    O19 : F3A1A00.Untagged_Private;                       -- ERROR:

    O20 : F3A1A00.Tagged_Private;                         -- ERROR:

    Ren11 : F3A1A00.An_Untagged_Type renames O13.all;     -- ERROR:

    Ren12 : F3A1A00.A_Tagged_Type renames O14.all;        -- ERROR:

    type A11 is array (1..11) of F3A1A00.An_Untagged_Type;-- ERROR:

    type A12 is array (3..8)  of F3A1A00.An_Untagged_Type;-- ERROR:

    type R11 (D : F3A1A00.An_Untagged_Type) is null record;-- ERROR:

    type R12 is record
        C : F3A1A00.A_Tagged_Type;                        -- ERROR:
    end record;

    type R13 is record
        C1 : F3A1A00.An_Access_to_Untagged;               -- ERROR:
        C2 : F3A1A00.An_Access_to_Tagged;                 -- ERROR:
        C3 : F3A1A00.Untagged_Private;                    -- ERROR:
        C4 : F3A1A00.Tagged_Private;                      -- ERROR:
        C5 : access F3A1A00.Untagged_Private;             -- OK.
        C6 : access F3A1A00.Tagged_Private :=
              new F3A1A00.Tagged_Private;                 -- ERROR:
    end record;

    protected type P11 (D : F3A1A00.An_Untagged_Type) is  -- ERROR:
        procedure Foo;
    private
        C : F3A1A00.A_Tagged_Type;                        -- ERROR:
    end P11;

    task type T11 (D : F3A1A00.An_Untagged_Type);         -- ERROR:

    type Acc_AUT is access constant F3A1A00.An_Untagged_Type;
    O21 : Acc_AUT := new F3A1A00.An_Untagged_Type;        -- ERROR:
    O22 : Acc_AUT;                                        -- OK.

    type Acc_ATT is access all F3A1A00.A_Tagged_Type;
    O23 : Acc_ATT := new F3A1A00.A_Tagged_Type;           -- ERROR:
    O24 : Acc_ATT;                                        -- OK.

    protected body P11 is                                 -- OPTIONAL ERROR:
        procedure Foo is begin null; end Foo;
    end P11;

    task body T11 is                                      -- OPTIONAL ERROR:
    begin
        null;
    end T11;

    procedure Proc11 (P1 : access F3A1A00.Untagged_Private) is
    begin
        null;
    end Proc11;

    procedure Proc12 (P1 : access F3A1A00.An_Untagged_Type) is
    begin
        null;
    end Proc12;

    procedure Proc13 (P1 : access F3A1A00.A_Tagged_Type) is
    begin
        null;
    end Proc13;

    procedure Proc14 (P1 : F3A1A00.Tagged_Private) is
        Ren15 : F3A1A00.Tagged_Private renames P1;        -- ERROR:
    begin
        null;
    end Proc14;


begin
    O03 := new Untagged_Inc;                              -- OK.

    O04 := new Tagged_Inc;                                -- OK.

    O13 := new F3A1A00.An_Untagged_Type;                  -- ERROR:

    O14 := new F3A1A00.A_Tagged_Type;                     -- ERROR:

    Proc11 (new F3A1A00.Untagged_Private);                -- ERROR:

    Proc12 (new F3A1A00.An_Untagged_Type);                -- ERROR:

    Proc13 (new F3A1A00.A_Tagged_Type);                   -- ERROR:

    O22 := new F3A1A00.An_Untagged_Type;                  -- ERROR:

    O24 := new F3A1A00.A_Tagged_Type;                     -- ERROR:

end B3A1A02;
