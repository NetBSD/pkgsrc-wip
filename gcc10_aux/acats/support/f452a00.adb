
with Report;
use Report;
package body F452A00 is

    Cnt : Natural := 0;

    procedure Fill_False (X : out R; Obj : T) is
    begin
        X.C1 := Ident_Char ('a');
        X.C2 := (Ident_Bool (False) .. Ident_Bool (False) => Obj);
        X.C3 := 5.0;
    end Fill_False;

    procedure Fill_True (X : out R; Obj : T) is
    begin
        X.C1 := Ident_Char ('b');
        X.C4 := Ident_Bool (True);
        X.C5 := Obj;
    end Fill_True;

    procedure Fill (X : out T) is
    begin
        Cnt := Cnt + 1;
        case Cnt mod 3 is
            when 0 =>
                X := Obj3;
            when 1 =>
                X := Obj1;
            when 2 =>
                X := Obj2;
            when others =>
                Failed (Subtest & " - Something went wrong in case statement");
        end case;
    end Fill;

    procedure Check is

    begin
        Comment (Subtest & " - Checking reemergence of equality");
        if Obj1 /= Obj2 or Obj1 = Obj3 or Obj2 = Obj3 then
            Failed
               (Subtest &
                " - predefined equality reemerged in generic instantiation");
        end if;

        Comment (Subtest & " - Checking composability of equality");

        Rec:
            declare
                X1 : R := (D  => False,
                           C1 => Ident_Char ('a'),
                           C2 => (others => Obj1),
                           C3 => 5.0);
                X2 : R (Ident_Bool (False));
                X3 : R (False);

                Y1 : R (Ident_Bool (True));
                Y2 : constant R := (D  => True,
                                    C1 => Ident_Char ('b'),
                                    C4 => Ident_Bool (True),
                                    C5 => Obj2);
                Y3 : R (True);
            begin
                Fill_False (X2, Obj2);
                Fill_False (X3, Obj3);
                Fill_True (Y1, Obj1);
                Fill_True (Y3, Obj3);
                if X1 /= X2 or X1 = X3 or X2 = X3 or
                   Y1 /= Y2 or Y1 = Y3 or Y2 = Y3 then
                    Failed
                       (Subtest &
                        " - Equality does not compose properly for records");
                end if;
            end Rec;

        Arr:
            declare
                type A is array (Positive range <>) of T;

                X1 : A (Ident_Int (10) .. Ident_Int (12)) :=
                         (Obj1, Obj2, Obj3);
                X2 : A (Ident_Int (7) .. Ident_Int (9));
                X3 : constant A (1 .. 3) := (Obj2, Obj2, Obj2);
            begin
                Fill (X2 (X2'First));
                Fill (X2 (X2'First + 1));
                Fill (X2 (X2'First + 2));
                if X1 /= X2 or X1 = X3 or X2 = X3 then
                    Failed (Subtest &
                          " - Equality does not compose properly for arrays");
                end if;
            end Arr;

    end Check;

end F452A00;

