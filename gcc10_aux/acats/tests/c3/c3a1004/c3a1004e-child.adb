
-- ----------------------------------------------------------------------------

package body C3A1004E.Child is -- Employee operations

    procedure Recruit (D : access C3A1004D.Department'Class;
                       E : in out C3A1004E.Employee'Class) is
    begin
       C3A1004E.Assign_Employee (E, D.all);
    end Recruit;

    procedure Join (D : in out C3A1004D.Department'Class;
                    E : in out C3A1004E.Employee'Class) is
    begin
       C3A1004E.Assign_Employee (E, D);
    end Join;

    function Image (D : in C3A1004D.Department'Class;
                    E : in C3A1004E.Employee'Class) return String is
    begin
       return Image (E, D);
    end Image;

end C3A1004E.Child;
