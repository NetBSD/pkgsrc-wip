
package C761010_1.Var_Strings.Types is

    type Ptr is access all Var_String;
    Ptr_Const: constant Ptr;

    type Ptr_Arr is array(Positive range <>) of Ptr;
    Ptr_Arr_Const: constant Ptr_Arr;

    type Ptr_Rec(N_Strings: Natural) is
        record
            Ptrs: Ptr_Arr(1..N_Strings);
        end record;
    Ptr_Rec_Const: constant Ptr_Rec;

private

    Ptr_Const: constant Ptr := new Var_String'
      (Finalization.Controlled with
       Length => 1,
       Comp_1 => null,
       Comp_2 => null,
       Comp_3 => (others => ' '),
       TC_Lab => 'C');

    Ptr_Arr_Const: constant Ptr_Arr :=
      (1 => new Var_String'
       (Finalization.Controlled with
        Length => 1,
        Comp_1 => new String'("abcdefghij"),
        Comp_2 => null,
        Comp_3 => (2..2 => ' '),
        TC_Lab => 'D'));

    Ptr_Rec_Var: Ptr_Rec :=
      (3,
       (1..2 => null,
        3 => new Var_String'
        (Finalization.Controlled with
         Length => 2,
         Comp_1 => new String'("abcdefghij"),
         Comp_2 => null,
         Comp_3 => (2..2 => ' '),
         TC_Lab => 'E')));

    Ptr_Rec_Const: constant Ptr_Rec :=
      (3,
       (1..2 => null,
        3 => new Var_String'
        (Finalization.Controlled with
         Length => 2,
         Comp_1 => new String'("abcdefghij"),
         Comp_2 => null,
         Comp_3 => (2..2 => ' '),
         TC_Lab => 'F')));

    type Arr is array(Positive range <>) of Var_String(Length => 2);

    Arr_Var: Arr :=
      (1 => (Finalization.Controlled with
         Length => 2,
         Comp_1 => new String'("abcdefghij"),
         Comp_2 => null,
         Comp_3 => (2..2 => ' '),
         TC_Lab => 'G'));

    type Rec(N_Strings: Natural) is
        record
            Ptrs: Ptr_Rec(N_Strings);
            Strings: Arr(1..N_Strings) :=
              (others =>
                 (Finalization.Controlled with
                  Length => 2,
                  Comp_1 => new String'("abcdefghij"),
                  Comp_2 => null,
                  Comp_3 => (2..2 => ' '),
                  TC_Lab => 'H'));
        end record;

    Default_Init_Rec_Var: Rec(N_Strings => 10);
    Empty_Default_Init_Rec_Var: Rec(N_Strings => 0);

    Rec_Var: Rec(N_Strings => 2) :=
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
            TC_Lab => 'J'))),
       Strings =>
         (1 =>
            (Finalization.Controlled with
             Length => 2,
             Comp_1 => new String'("abcdefghij"),
             Comp_2 => null,
             Comp_3 => (2..2 => ' '),
             TC_Lab => 'K'),
          others =>
            (Finalization.Controlled with
             Length => 2,
             Comp_1 => new String'("abcdefghij"),
             Comp_2 => null,
             Comp_3 => (2..2 => ' '),
             TC_Lab => 'L')));

    procedure Check_Equal(X, Y: Rec);

end C761010_1.Var_Strings.Types;
