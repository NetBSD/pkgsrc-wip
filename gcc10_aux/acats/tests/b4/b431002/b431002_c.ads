

with B431002_B;
package B431002_C is
    type Der3 is new B431002_B.Der2 with record
        E : Character := 'E';
    end record;
end B431002_C;
