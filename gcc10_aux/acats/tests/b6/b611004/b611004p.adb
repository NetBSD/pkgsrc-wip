

package body B611004P is

    procedure OK (P : in out Root) is
    begin
       P.N := P.N + 12;
    end OK;

    procedure No_Spec1 (P : in out Root)
       with Pre'Class => Is_OK (P) is                          -- OK. {13;3}
    begin
       P.N := P.N * 2;
    end No_Spec1;

    procedure Spec1 (P : in out Root)
       with Pre'Class => Is_OK (P) is                          -- ERROR: {13;3}
    begin
       P.N := P.N + 2;
    end Spec1;

    procedure Spec2 (P : in out Root) is separate
       with Pre'Class => Is_OK (P);                            -- ERROR: {13;3}

    procedure Spec3 (P : in out Root);

    procedure Spec3 (P : in out Root)
       with Pre'Class => Is_OK (P) is                          -- ERROR: {13;3}
    begin
       P.N := P.N * 2;
    end Spec3;

    function No_Spec4 (P : Root) return Root is (N => P.N * 2)
       with Pre'Class => Is_OK (P);                            -- OK. {13;1}

    function Spec4 (P : Root) return Root is (N => P.N + 2)
       with Pre'Class => Is_OK (P);                            -- ERROR: {13;1}


    procedure No_Spec5 (P : in out Root)
       with Post'Class => Is_OK (P) is                         -- OK. {13;3}
    begin
       P.N := P.N + 2;
    end No_Spec5;

    procedure Spec5 (P : in out Root)
       with Post'Class => Is_OK (P) is                         -- ERROR: {13;3}
    begin
       P.N := P.N + 2;
    end Spec5;

    procedure Spec6 (P : in out Root) is separate
       with Post'Class => Is_OK (P);                           -- ERROR: {13;1}

    procedure Spec7 (P : in out Root);

    procedure Spec7 (P : in out Root)
       with Post'Class => Is_OK (P) is                         -- ERROR: {13;3}
    begin
       P.N := P.N + 2;
    end Spec7;

    function No_Spec8 (P : Root) return Root is (N => P.N + 2)
       with Post'Class => Is_OK (P);                           -- OK. {13;1}

    function Spec8 (P : Root) return Root is (N => P.N + 2)
       with Post'Class => Is_OK (P);                           -- ERROR: {13;1}


    procedure No_Spec9 (P : in out Root) is null
       with Pre'Class => Is_OK (P);                            -- OK. {13;1}

    procedure Spec9 (P : in out Root) is null
       with Pre'Class => Is_OK (P);                            -- ERROR: {13;1}

    procedure SpecA (P : in out Root) is null
       with Post'Class => Is_OK (P);                           -- ERROR: {13;1}

end B611004P;
