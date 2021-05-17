

with B431003_C;
package B431003_D is
    type Der8 is new B431003_C.Der5 with record
        B : Boolean := True;
    end record;

    type Der9 is new B431003_C.Der7 with record
        B : Boolean := True;
    end record;
end B431003_D;
