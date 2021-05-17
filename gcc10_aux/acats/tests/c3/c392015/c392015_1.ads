
with C392015_0;
package C392015_1 is

    type T1 is new C392015_0.T0 with null record;

    function Fa return T1;

    procedure Pa (P : in T1 := Fa);

    procedure Pb (P : in T1 := Fa);

    procedure Pc (Param1, Param2 : in T1 := Fa);

    procedure Pd (Param1 : in T1; Param2 : in C392015_0.T0 := C392015_0.Fa);
        -- Param2 is not a controlling operand.

    function Fc1 return T1'Class;

    function Fd (P : in T1 := Fa) return C392015_0.T0'Class;

    function Fe (P : in T1 := Fa) return T1'Class;

end C392015_1;
