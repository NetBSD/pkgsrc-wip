
-- ----------------------------------------------------------------------------

-- Note: No with of C3A1003D (departments).
package body C3A10030 is -- Employee operations

    procedure Recruit (D : in     C3A1003E.Dept_Ptr;
                       E : in out C3A1003E.Employee'Class) is
    begin
       C3A1003E.Assign_Employee (E, D.all);
    end Recruit;

    procedure Change_To_Department_Of (E1 : in out C3A1003E.Employee'Class;
                                       E2 : in     C3A1003E.Employee'Class) is
       -- Change E1 to be in the same department as E2.
    begin
       C3A1003E.Assign_Employee (E1, C3A1003E.Current_Department (E2).all);
    end Change_To_Department_Of;

end C3A10030;
