
-- ----------------------------------------------------------------------------

with Report;
with C3A1003D; use C3A1003D;
with C3A1003E; use C3A1003E;
with C3A10030;
procedure C3A10032 is
   Dept1, Dept2, Dept3 : aliased Department;
   E1, E2, E3, E4, E5, E6 : C3A1003E.Emp_Ptr;
begin
   Report.Test ("C3A1003", "Check that a dereference of an " &
                           "access-to-tagged-incomplete type can be passed " &
                           "directly as a parameter");

   E1 := Hire ("Rodgers");
   E2 := Hire ("Nelson");
   E3 := Hire ("Cobb");
   E4 := Hire ("Shields");
   E5 := Hire ("Matthews");
   E6 := Hire ("Hyde");

   Create (Dept1, "Offense");
   Create (Dept2, "Defense");
   Create (Dept3, "Special-Teams");

   -- Sorry, it's NFL playoff season. :-)

   Appoint (E1.all, Dept1);
   Appoint (E2.all, Dept1);
   --Display (Dept1);

   Appoint (E4.all, Dept2);
   Appoint (E5.all, Dept2);
   --Display (Dept2);

   Appoint (E3.all, Dept3);
   Appoint (E6.all, Dept3);
   --Display (Dept3);

   if not Is_Member (E1.all, Dept1) then
      Report.Failed ("Rodgers not on offense!");
   end if;
   if Is_Member (E4.all, Dept1) then
      Report.Failed ("Shields on offense!");
   end if;
   if not Is_Member (E6.all, Dept3) then
      Report.Failed ("Hyde not on special teams!");
   end if;

   C3A10030.Recruit (Dept2'Unchecked_Access, E6.all);-- Move Hyde to Defense.

   C3A10030.Change_To_Department_Of (E3.all, E1.all);-- Move Cobb with Rodgers.

   if not Is_Member (E3.all, Dept1) then
      Report.Failed ("Cobb not on offense!");
   end if;
   if not Is_Member (E6.all, Dept2) then
      Report.Failed ("Hyde not on defense!");
   end if;

   Report.Result;
end C3A10032;

