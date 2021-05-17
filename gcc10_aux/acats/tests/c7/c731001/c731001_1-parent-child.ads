
package C731001_1.Parent.Child is
    pragma Elaborate_Body;

    type T3 is new Root with null record;
    subtype T3_Class is T3'Class;
    function Make return T3;

    T3_Obj: T3;
    T3_Class_Obj: T3_Class := T3_Obj;
    T3_Root_Class_Obj: Root_Class := T3_Obj;

    X3: constant String :=
      Check_String(Op1(T3_Obj), "Parent.Op1 body") &
      Check_String(Op1(T3_Class_Obj), "Parent.Op1 body") &
      Check_String(Op1(T3_Root_Class_Obj), "Parent.Op1 body") &

      Check_String(Call_Op2(T3_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T3_Class_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T3_Root_Class_Obj), "Parent.Op2 body");

    package Nested is
        type T4 is new Root with null record;
        subtype T4_Class is T4'Class;
        function Make return T4;

        T4_Obj: T4;
        T4_Class_Obj: T4_Class := T4_Obj;
        T4_Root_Class_Obj: Root_Class := T4_Obj;

        X4: constant String :=
          Check_String(Op1(T4_Obj), "Parent.Op1 body") &
          Check_String(Op1(T4_Class_Obj), "Parent.Op1 body") &
          Check_String(Op1(T4_Root_Class_Obj), "Parent.Op1 body") &

          Check_String(Call_Op2(T4_Obj), "Parent.Op2 body") &
          Check_String(Call_Op2(T4_Class_Obj), "Parent.Op2 body") &
          Check_String(Call_Op2(T4_Root_Class_Obj), "Parent.Op2 body");

    private

        XX4: constant String :=
          Check_String(Op1(T4_Obj), "Parent.Op1 body") &
          Check_String(Op1(T4_Class_Obj), "Parent.Op1 body") &
          Check_String(Op1(T4_Root_Class_Obj), "Parent.Op1 body") &

          Check_String(Call_Op2(T4_Obj), "Parent.Op2 body") &
          Check_String(Call_Op2(T4_Class_Obj), "Parent.Op2 body") &
          Check_String(Call_Op2(T4_Root_Class_Obj), "Parent.Op2 body");

    end Nested;

    use Nested;

    XXX4: constant String :=
      Check_String(Op1(T4_Obj), "Parent.Op1 body") &
      Check_String(Op1(T4_Class_Obj), "Parent.Op1 body") &
      Check_String(Op1(T4_Root_Class_Obj), "Parent.Op1 body") &

      Check_String(Call_Op2(T4_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T4_Class_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T4_Root_Class_Obj), "Parent.Op2 body");

private

    XX3: constant String :=
      Check_String(Op1(T3_Obj), "Parent.Op1 body") &
      Check_String(Op1(T3_Class_Obj), "Parent.Op1 body") &
      Check_String(Op1(T3_Root_Class_Obj), "Parent.Op1 body") &

      Check_String(Call_Op2(T3_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T3_Class_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T3_Root_Class_Obj), "Parent.Op2 body") &

      Check_String(Op2(T3_Obj), "Parent.Op2 body") &
      Check_String(Op2(T3_Class_Obj), "Parent.Op2 body") &
      Check_String(Op2(T3_Root_Class_Obj), "Parent.Op2 body");

    XXXX4: constant String :=
      Check_String(Op1(T4_Obj), "Parent.Op1 body") &
      Check_String(Op1(T4_Class_Obj), "Parent.Op1 body") &
      Check_String(Op1(T4_Root_Class_Obj), "Parent.Op1 body") &

      Check_String(Call_Op2(T4_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T4_Class_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T4_Root_Class_Obj), "Parent.Op2 body") &

      Check_String(Op2(T4_Root_Class_Obj), "Parent.Op2 body");

end C731001_1.Parent.Child;
