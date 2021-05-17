
with C392015_0, C392015_1;
package C392015_2 is

    type T2 is new C392015_1.T1 with null record;

    -- Inherits:
    --procedure Pa (P : in T2 := Fa);
    --procedure Pb (P : in T2 := Fa);
    --procedure Pc (Param1, Param2 : in T2 := Fa);
    --procedure Pd (Param1 : in T2; Param2 : in C392015_0.T0 := C392015_0.Fa);
    --function Fe (P : in T2 := Fa) return C392015_1.T1'Class;

    function Fa return T2;

    function Fb return T2;

    function Fc2 return T2'Class;

    function Fd (P : in T2 := Fa) return C392015_0.T0'Class;

    function Ff (P : in T2 := Fa) return T2'Class;

private
    procedure Pb (P : in T2 := Fb); -- Privately override Pb with a
                                    -- different default.
end C392015_2;
