
-- ----------------------------------------------------------------------------

with Report;
with C3A1004D; use C3A1004D;
with C3A1004E; use C3A1004E;
with C3A1004E.Child;
procedure C3A10042 is
   Dept1, Dept2, Dept3 : aliased Department;
   E1, E2, E3, E4, E5, E6 : C3A1004E.Emp_Ptr;
begin
   Report.Test ("C3A1004", "Check that a parameter of a " &
                           "tagged incomplete type can be passed " &
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

   C3A1004E.Child.Recruit (Dept2'Unchecked_Access, E6.all);
                                             -- Move Hyde to Defense.

   C3A1004E.Child.Join (Dept1, E3.all);      -- Move Cobb to Offense.

   if not Is_Member (E3.all, Dept1) then
      Report.Failed ("Cobb not on offense!");
   end if;
   if not Is_Member (E6.all, Dept2) then
      Report.Failed ("Hyde not on defense!");
   end if;

   if C3A1004E.Child.Image (Dept2, E5.all) /=
      "Employee: Matthews of Department: Defense      " then
      Report.Failed ("Wrong image (1): " &
                     C3A1004E.Child.Image (Dept2, E5.all));
   end if;

   if C3A1004E.Child.Image (Dept3, E2.all) /=
      "Wrong department for Employee: Nelson" then
      Report.Failed ("Wrong image (2): " &
                     C3A1004E.Child.Image (Dept3, E2.all));
   end if;

   Report.Result;
end C3A10042;

