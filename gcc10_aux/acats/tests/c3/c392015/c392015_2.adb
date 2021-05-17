
with TCTouch;
package body C392015_2 is

    function Fa return T2 is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('a'); TCTouch.Touch('2');
       return T2'(null record);
    end Fa;

    function Fb return T2 is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('b'); TCTouch.Touch('2');
       return T2'(null record);
    end Fb;

    function Fc2 return T2'Class is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('c'); TCTouch.Touch('2');
       return T2'(null record);
    end Fc2;

    procedure Pb (P : in T2 := Fb) is
    begin
       TCTouch.Touch('P'); TCTouch.Touch('b'); TCTouch.Touch('2');
    end Pb;

    function Fd (P : in T2 := Fa) return C392015_0.T0'Class is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('d'); TCTouch.Touch('2');
       return C392015_0.T0'Class(P);
    end Fd;

    function Ff (P : in T2 := Fa) return T2'Class is
    begin
       TCTouch.Touch('F'); TCTouch.Touch('f'); TCTouch.Touch('2');
       return T2'Class(P);
    end Ff;

end C392015_2;
