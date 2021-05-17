

with B432001_C;
package B432001_D is
    type Der5 is new B432001_C.Der4 with record
        E : Character := 'E';
    end record;
    function New_One return Der5;

    type Der7 is new B432001_C.Der6 with record
        E : Character := 'E';
    end record;
    function New_One return Der7;

    type Der8 is new B432001_C.Der4 with null record;
    function New_One return Der8;

end B432001_D;
