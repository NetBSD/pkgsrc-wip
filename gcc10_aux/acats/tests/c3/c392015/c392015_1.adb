
with TCTouch;
package body C392015_1 is

    function Fa return T1 is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('a'); TCTouch.Touch('1');
       return T1'(null record);
    end Fa;

    procedure Pa (P : in T1 := Fa) is
    begin
       TCTouch.Touch('P'); TCTouch.Touch('a'); TCTouch.Touch('1');
    end Pa;

    procedure Pb (P : in T1 := Fa) is
    begin
       TCTouch.Touch('P'); TCTouch.Touch('b'); TCTouch.Touch('1');
    end Pb;

    procedure Pc (Param1, Param2 : in T1 := Fa) is
    begin
       TCTouch.Touch('P'); TCTouch.Touch('c'); TCTouch.Touch('1');
    end Pc;

    procedure Pd (Param1 : in T1; Param2 : in C392015_0.T0 := C392015_0.Fa) is
    begin
       TCTouch.Touch('P'); TCTouch.Touch('d'); TCTouch.Touch('1');
    end Pd;

    function Fc1 return T1'Class is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('c'); TCTouch.Touch('1');
       return T1'(null record);
    end Fc1;

    function Fd (P : in T1 := Fa) return C392015_0.T0'Class is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('d'); TCTouch.Touch('1');
       return C392015_0.T0'Class(P);
    end Fd;

    function Fe (P : in T1 := Fa) return T1'Class is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('e'); TCTouch.Touch('1');
       return T1'Class(P);
    end Fe;

end C392015_1;
