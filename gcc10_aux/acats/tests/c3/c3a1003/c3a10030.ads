
-- ----------------------------------------------------------------------------

with C3A1003E; -- Employees
package C3A10030 is -- Employee operations

    procedure Recruit (D : in     C3A1003E.Dept_Ptr;
                       E : in out C3A1003E.Employee'Class);
       -- Recruit E for D.

    procedure Change_To_Department_Of (E1 : in out C3A1003E.Employee'Class;
                                       E2 : in     C3A1003E.Employee'Class);
       -- Change E1 to be in the same department as E2.

end C3A10030;
