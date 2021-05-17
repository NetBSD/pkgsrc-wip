

package body B611002P is

    procedure No_Spec1 (P : in out Natural)
       with Pre => P mod 2 = 0 is                              -- OK. {13;3}
    begin
       P := P * 2;
    end No_Spec1;

    procedure Spec1 (P : in out Natural)
       with Pre => P mod 2 = 0 is                              -- ERROR: {13;3}
    begin
       P := P * 2;
    end Spec1;

    procedure Spec2 (P : in out Natural) is separate
       with Pre => P mod 2 = 0;                                -- ERROR: {13;1}

    procedure Spec3 (P : in out Natural);

    procedure Spec3 (P : in out Natural)
       with Pre => P mod 2 = 0 is                              -- ERROR: {13;3}
    begin
       P := P * 2;
    end Spec3;

    function No_Spec4 (P : Natural) return Natural is (P * 2)
       with Pre => P mod 2 = 0;                                -- OK. {13;1}

    function Spec4 (P : Natural) return Natural is (P * 2)
       with Pre => P mod 2 = 0;                                -- ERROR: {13;1}


    procedure No_Spec5 (P : in out Natural)
       with Post => P mod 2 = 0 is                             -- OK. {13;3}
    begin
       P := P * 2;
    end No_Spec5;

    procedure Spec5 (P : in out Natural)
       with Post => P mod 2 = 0 is                             -- ERROR: {13;3}
    begin
       P := P * 2;
    end Spec5;

    procedure Spec6 (P : in out Natural) is separate
       with Post => P mod 2 = 0;                               -- ERROR: {13;1}

    procedure Spec7 (P : in out Natural);

    procedure Spec7 (P : in out Natural)
       with Post => P mod 2 = 0 is                             -- ERROR: {13;3}
    begin
       P := P * 2;
    end Spec7;

    function No_Spec8 (P : Natural) return Natural is (P * 2)
       with Post => P mod 2 = 0;                               -- OK. {13;1}

    function Spec8 (P : Natural) return Natural is (P * 2)
       with Post => P mod 2 = 0;                               -- ERROR: {13;1}

    -- Note: Aspects Pre and Post are illegal on null procedures by
    -- 6.1.1 (9/3), so we don't need to test them here.

end B611002P;
