
package body B3A1A04 is

    -- Note: No WITH of the full view here, the imported types remain
    -- incomplete. 3.10.1(8.4/3) allows tagged incomplete views to be
    -- used as parameters (only); thus most of these cases are legal.

    procedure Proc2 (A : F3A1A00.A_Tagged_Type'Class) is       -- OK.
    begin
       null;
    end Proc2;

    procedure Proc4 (Cnt : in Natural;
                     Obj : out F3A1A00.Tagged_Private'Class) is-- OK.
    begin
       null;
    end Proc4;

    procedure Proc6 (
               Wobble : access F3A1A00.A_Tagged_Type'Class) is -- OK.
    begin
       null;
    end Proc6;

    function Func2 (Rash : Character)
                   return F3A1A00.A_Tagged_Type'Class is       -- ERROR:
    begin
       return (raise Program_Error); -- So we have the required return stmt.
    end Func2;

    function Func4 (Cnt : Natural)
                   return access F3A1A00.Tagged_Private'Class is -- OK.
    begin
       return null;
    end Func4;

    -- Note: The following are also illegal because indefinite objects
    -- are not allowed without initialization (and there is no legal
    -- initialization that can be written), as well as being illegal
    -- uses of an incomplete type.

    Obj6 : F3A1A00.A_Tagged_Type'Class;                        -- ERROR:

    type Rec2 is
       record
          Comp : F3A1A00.Tagged_Private'Class;                 -- ERROR:
       end record;

    protected body PT1 is
       function F (Num : Float)
          return F3A1A00.A_Tagged_Type'Class is                -- ERROR:
       begin
          return (raise Program_Error);
       end F;

       entry E (B : in out F3A1A00.A_Tagged_Type'Class)        -- OK.
          when True is
       begin
          C := 'H';
       end E;
    end PT1;

    task body Tsk1 is
    begin
       select
          accept E1 (B : in out F3A1A00.A_Tagged_Type'Class) do-- OK.
             null;
          end E1;
       or
          accept E2 (B : out F3A1A00.Tagged_Private'Class) do  -- OK.
             null;
          end E2;
       end select;
    end Tsk1;

end B3A1A04;

