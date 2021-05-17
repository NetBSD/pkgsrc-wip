
with C731001_1.Unrelated; use C731001_1.Unrelated;
    pragma Elaborate(C731001_1.Unrelated);
package body C731001_1.Parent.Child is

    XXX3: constant String :=
      Check_String(Op1(T3_Obj), "Parent.Op1 body") &
      Check_String(Op1(T3_Class_Obj), "Parent.Op1 body") &
      Check_String(Op1(T3_Root_Class_Obj), "Parent.Op1 body") &

      Check_String(Call_Op2(T3_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T3_Class_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T3_Root_Class_Obj), "Parent.Op2 body") &

      Check_String(Op2(T3_Obj), "Parent.Op2 body") &
      Check_String(Op2(T3_Class_Obj), "Parent.Op2 body") &
      Check_String(Op2(T3_Root_Class_Obj), "Parent.Op2 body");

    XXXXX4: constant String :=
      Check_String(Op1(T4_Obj), "Parent.Op1 body") &
      Check_String(Op1(T4_Class_Obj), "Parent.Op1 body") &
      Check_String(Op1(T4_Root_Class_Obj), "Parent.Op1 body") &

      Check_String(Call_Op2(T4_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T4_Class_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T4_Root_Class_Obj), "Parent.Op2 body") &

      Check_String(Op2(T4_Root_Class_Obj), "Parent.Op2 body");

    function Make return T3 is
        Result: T3;
    begin
        return Result;
    end Make;

    package body Nested is
        function Make return T4 is
            Result: T4;
        begin
            return Result;
        end Make;

        XXXXXX4: constant String :=
          Check_String(Op1(T4_Obj), "Parent.Op1 body") &
          Check_String(Op1(T4_Class_Obj), "Parent.Op1 body") &
          Check_String(Op1(T4_Root_Class_Obj), "Parent.Op1 body") &

          Check_String(Call_Op2(T4_Obj), "Parent.Op2 body") &
          Check_String(Call_Op2(T4_Class_Obj), "Parent.Op2 body") &
          Check_String(Call_Op2(T4_Root_Class_Obj), "Parent.Op2 body") &

          Check_String(Op2(T4_Obj), "Parent.Op2 body") &
          Check_String(Op2(T4_Class_Obj), "Parent.Op2 body") &
          Check_String(Op2(T4_Root_Class_Obj), "Parent.Op2 body");

    end Nested;

    type T5 is new T2 with null record;
    subtype T5_Class is T5'Class;
    function Make return T5;

    function Make return T5 is
        Result: T5;
    begin
        return Result;
    end Make;

    XXXXXXX4: constant String :=
      Check_String(Op1(T4_Obj), "Parent.Op1 body") &
      Check_String(Op1(T4_Class_Obj), "Parent.Op1 body") &
      Check_String(Op1(T4_Root_Class_Obj), "Parent.Op1 body") &

      Check_String(Call_Op2(T4_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T4_Class_Obj), "Parent.Op2 body") &
      Check_String(Call_Op2(T4_Root_Class_Obj), "Parent.Op2 body") &

      Check_String(Op2(T4_Root_Class_Obj), "Parent.Op2 body");

end C731001_1.Parent.Child;
