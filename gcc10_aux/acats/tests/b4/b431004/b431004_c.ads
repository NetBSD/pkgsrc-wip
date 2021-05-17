

with B431004_B;
package B431004_C is
    type Der3 is new B431004_B.Der2 with record
        D : Character := 'E';
        E : Integer := 92;
    end record;
end B431004_C;
