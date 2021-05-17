
package body B3A1A01 is
    -- Note: No WITH of the full view here, the imported types remain
    -- incomplete. 3.10.1(8.4/3) allows tagged incomplete views to be
    -- used as parameters (only); that accounts for the non-access OKs
    -- below.

    procedure Proc1 (A : F3A1A00.An_Untagged_Type) is          -- ERROR:
    begin
        null;
    end Proc1;

    procedure Proc2 (A : F3A1A00.A_Tagged_Type) is             -- OK.
    begin
        null;
    end Proc2;

    procedure Proc3 (Cnt : in Natural;
                     Obj : out F3A1A00.Untagged_Private) is    -- ERROR:
    begin
        null;
    end Proc3;

    procedure Proc4 (Cnt : in Natural;
                     Obj : out F3A1A00.Tagged_Private) is      -- OK.
    begin
        null;
    end Proc4;

    procedure Proc5 (Wobble : in out
                               F3A1A00.An_Access_to_Tagged) is -- ERROR:
    begin
        null;
    end Proc5;

    procedure Proc6 (Wobble : access F3A1A00.A_Tagged_Type) is -- OK.
    begin
        null;
    end Proc6;

    function Func1 (Ouch : Boolean)
                   return F3A1A00.An_Untagged_Type is          -- ERROR:
    begin
       return (raise Program_Error); -- So we have the required return stmt.
    end Func1;

    function Func2 (Rash : Character)
                   return F3A1A00.A_Tagged_Type is             -- ERROR:
    begin
       return (raise Program_Error);
    end Func2;

    function Func3 (Flat : Natural)
                   return F3A1A00.An_Access_to_Untagged is     -- ERROR:
    begin
       return (raise Program_Error);
    end Func3;

    function Func4 (Curve : Float)
                   return access F3A1A00.An_Untagged_Type is   -- OK.
    begin
       return null;
    end Func4;

    protected body PT1 is
       procedure P (B : in out F3A1A00.An_Untagged_Type) is    -- ERROR:
       begin
          C := 'L';
       end P;

       entry E (B : in out F3A1A00.An_Untagged_Type)           -- ERROR:
          when True is
       begin
          C := 'B';
       end E;
    end PT1;

    protected body PT2 is
       function F (B : F3A1A00.A_Tagged_Type) return Boolean is-- OK.
       begin
          return True;
       end F;

       entry E (B : in out F3A1A00.A_Tagged_Type)              -- OK.
          when True is
       begin
          C := 'B';
       end E;
    end PT2;

    protected body PT3 is
       entry E1 (B : in F3A1A00.Untagged_Private) when True is -- ERROR:
       begin
          C := 'B';
       end E1;
       entry E2 (B : in F3A1A00.Tagged_Private) when True is   -- OK.
       begin
          C := 'C';
       end E2;
       entry E3 (B : in F3A1A00.An_Access_to_Tagged)           -- ERROR:
          when True is
       begin
          C := 'J';
       end E3;
       entry E4 (B : in F3A1A00.An_Access_to_Untagged)         -- ERROR:
          when True is
       begin
          C := 'H';
       end E4;
    end PT3;

    task body Tsk1 is
    begin
       select
          accept E1 (B : in out F3A1A00.An_Untagged_Type) do   -- ERROR:
             null;
          end E1;
       or
          accept E2 (B : in out F3A1A00.A_Tagged_Type) do      -- OK.
             null;
          end E2;
       or
          accept E3 (B : in  F3A1A00.Untagged_Private) do      -- ERROR:
             null;
          end E3;
       or
          accept E4 (B : out F3A1A00.Tagged_Private) do        -- OK.
             null;
          end E4;
       or
          accept E5 (B : in F3A1A00.An_Access_to_Tagged) do    -- ERROR:
             null;
          end E5;
       or
          accept E6 (B : in F3A1A00.An_Access_to_Untagged) do  -- ERROR:
             null;
          end E6;
       end select;
    end Tsk1;

end B3A1A01;
