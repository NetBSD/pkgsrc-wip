
package B831001_2 is
    type T is tagged null record;

    not overriding
    procedure P (X : T); -- OK

    not overriding
    function F return T; -- OK
end B831001_2;
