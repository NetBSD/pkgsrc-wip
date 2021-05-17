
-- ----------------------------------------------------------------------------

with Report;
with CA11023D;
package body CA11023E is

   procedure Assign_Employee
     (E : in out Employee;
      D : in     Dept_Ptr) is
   begin
      E.Dept := D;
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

end CA11023E;
