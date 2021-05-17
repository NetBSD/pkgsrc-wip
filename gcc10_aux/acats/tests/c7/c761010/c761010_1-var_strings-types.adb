
package body C761010_1.Var_Strings.Types is

    -- Check that parameter passing doesn't create new objects,
    -- and therefore doesn't need extra Adjusts or Finalizes.

    procedure Check_Equal(X, Y: Rec) is
        -- We assume that the arguments should be equal.
        -- But we cannot assume that pointer values are the same.
    begin
        if X.N_Strings /= Y.N_Strings then
            Failed("Records should be equal (1)");
        else
            for I in 1 .. X.N_Strings loop
                if X.Ptrs.Ptrs(I) /= Y.Ptrs.Ptrs(I) then
                    if X.Ptrs.Ptrs(I) = null or else
                       Y.Ptrs.Ptrs(I) = null or else
                       X.Ptrs.Ptrs(I).all /= Y.Ptrs.Ptrs(I).all then
                       Failed("Records should be equal (2)");
                    end if;
                end if;
                if X.Strings(I) /= Y.Strings(I) then
                    Failed("Records should be equal (3)");
                end if;
            end loop;
        end if;
    end Check_Equal;

    procedure My_Check_Equal
              (X: Rec := Rec_Var;
               Y: Rec :=
      (N_Strings => 2,
       Ptrs =>
         (2,
          (1..1 => null,
           2 => new Var_String'
           (Finalization.Controlled with
            Length => 2,
            Comp_1 => new String'("abcdefghij"),
            Comp_2 => null,
            Comp_3 => (2..2 => ' '),
            TC_Lab => 'M'))),
       Strings =>
         (1 =>
            (Finalization.Controlled with
             Length => 2,
             Comp_1 => new String'("abcdefghij"),
             Comp_2 => null,
             Comp_3 => (2..2 => ' '),
             TC_Lab => 'N'),
          others =>
            (Finalization.Controlled with
             Length => 2,
             Comp_1 => new String'("abcdefghij"),
             Comp_2 => null,
             Comp_3 => (2..2 => ' '),
             TC_Lab => 'O'))))
              renames Check_Equal;
begin

    My_Check_Equal;

    Check_Equal(Rec_Var,
      (N_Strings => 2,
       Ptrs =>
         (2,
          (1..1 => null,
           2 => new Var_String'
           (Finalization.Controlled with
            Length => 2,
            Comp_1 => new String'("abcdefghij"),
            Comp_2 => null,
            Comp_3 => (2..2 => ' '),
            TC_Lab => 'P'))),
       Strings =>
         (1 =>
            (Finalization.Controlled with
             Length => 2,
             Comp_1 => new String'("abcdefghij"),
             Comp_2 => null,
             Comp_3 => (2..2 => ' '),
             TC_Lab => 'Q'),
          others =>
            (Finalization.Controlled with
             Length => 2,
             Comp_1 => new String'("abcdefghij"),
             Comp_2 => null,
             Comp_3 => (2..2 => ' '),
             TC_Lab => 'R'))));

    -- Use the objects to avoid optimizations.

    Check_Equal(Ptr_Const.all, Ptr_Const.all);
    Check_Equal(Ptr_Arr_Const(1).all, Ptr_Arr_Const(1).all);
    Check_Equal(Ptr_Rec_Const.Ptrs(Ptr_Rec_Const.N_Strings).all,
                Ptr_Rec_Const.Ptrs(Ptr_Rec_Const.N_Strings).all);
    Check_Equal(Ptr_Rec_Var.Ptrs(Ptr_Rec_Var.N_Strings).all,
                Ptr_Rec_Var.Ptrs(Ptr_Rec_Var.N_Strings).all);

    if Report.Equal (3, 2) then
       -- Can't get here.
       Check_Equal (Arr_Var(1), Default_Init_Rec_Var.Strings(1));
       Check_Equal (Arr_Var(1), Empty_Default_Init_Rec_Var.Strings(1));
    end if;

end C761010_1.Var_Strings.Types;
