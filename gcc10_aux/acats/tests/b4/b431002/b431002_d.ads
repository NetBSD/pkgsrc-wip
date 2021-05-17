

with B431002_C;
package B431002_D is
    type Der4 is new B431002_C.Der3 with record
        B : Boolean := True;
    end record;
end B431002_D;
