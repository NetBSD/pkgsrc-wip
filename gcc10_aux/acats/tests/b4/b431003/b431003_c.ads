

with B431003_B;
package B431003_C is
    type Der3 is new B431003_B.Der2 with record
        E : Character := 'E';
    end record;

    type Der5 is new B431003_B.Der4 with record
        E : Character := 'E';
    end record;

    type Der7 is new B431003_B.Der6 with record
        E : Character := 'E';
    end record;
end B431003_C;
