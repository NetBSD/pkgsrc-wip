
-- ----------------------------------------------------------------------------

with Report;
with C3A1004D;
package body C3A1004E is -- Employees

   procedure Assign_Employee
     (E : in out Employee;
      D : in out C3A1004D.Department'Class) is
   begin
      if E.During_Mod then
          return; -- We're already updating this (need to break recursion).
      end if;
--Report.Comment ("Assign Employee: " & E.Id.all & " to " & C3A1004D.Image(D));
      if E.Dept /= D'Unchecked_Access then
         E.During_Mod := True;
         C3A1004D.Appoint (E, D); -- Could call Assign_Employee again.
         E.Dept := D'Unchecked_Access;
         E.During_Mod := False;
      -- else already right, do nothing.
      end if;
   end Assign_Employee;

   function Current_Department
     (E : in Employee) return Dept_Ptr is
   begin
      return E.Dept;
   end Current_Department;

   function Hire (Id : String) return Emp_Ptr is
      Ptr : Emp_Ptr := new Employee;
   begin
      Ptr.Id := new String'(Id);
      return Ptr;
   end Hire;

   procedure Display (E : Employee) is
   begin
      Report.Comment ("Employee: " & E.Id.all);
   end Display;

   function Image (E : Employee) return String is
   begin
      return "Employee: " & E.Id.all;
   end Image;

   function Image (E : Employee;
                   D : C3A1004D.Department'Class) return String is
      use type C3A1004D.Department'Class;
   begin
      if D /= E.Dept.all then
         return "Wrong department for " & Image (E);
      else
         return Image (E) & " of " & C3A1004D.Image(D);
      end if;
   end Image;
end C3A1004E;
