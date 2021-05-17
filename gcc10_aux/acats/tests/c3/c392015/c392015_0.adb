
with TCTouch;
package body C392015_0 is

    function Fa return T0 is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('a'); TCTouch.Touch('0');
       return T0'(null record);
    end Fa;

    function Fc return T0'Class is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('c'); TCTouch.Touch('0');
       return T0'(null record);
    end Fc;

    procedure Pa (P : in T0 := Fa) is
    begin
       TCTouch.Touch('P'); TCTouch.Touch('a'); TCTouch.Touch('0');
    end Pa;

    procedure Pb (P : in T0 := Fa) is
    begin
       TCTouch.Touch('P'); TCTouch.Touch('b'); TCTouch.Touch('0');
    end Pb;

    procedure Pc (Param1, Param2 : in T0 := Fa) is
    begin
       TCTouch.Touch('P'); TCTouch.Touch('c'); TCTouch.Touch('0');
    end Pc;

    function Fd (P : in T0 := Fa) return T0'Class is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('d'); TCTouch.Touch('0');
       return T0'Class(P);
    end Fd;

end C392015_0;
