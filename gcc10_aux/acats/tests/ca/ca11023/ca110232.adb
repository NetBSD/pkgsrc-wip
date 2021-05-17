
-- ----------------------------------------------------------------------------

with Report;
with CA11023D; use CA11023D;
with CA11023E; use CA11023E;
procedure CA110232 is
   Dept1, Dept2 : Department;
   E1, E2, E3, E4, E5, E6 : CA11023E.Emp_Ptr;
begin
   Report.Test ("CA110232", "Check that the context clause of a limited " &
                            "view is empty, and that the types imported " &
                            "from a limited view appear complete when the " &
                            "library package is visible");

   E1 := Hire ("Smith");
   E2 := Hire ("Trump");
   E3 := Hire ("Hilton");
   E4 := Hire ("Stewart");
   E5 := Hire ("Rove");
   E6 := Hire ("Bush");

   Create (Dept1, "Mailroom");
   Create (Dept2, "Executive");

   Appoint (CA11023D.Emp_Ptr (E1), Dept1);
   Appoint (CA11023D.Emp_Ptr (E3), Dept1);
   Appoint (CA11023D.Emp_Ptr (E5), Dept1);
   Appoint (CA11023D.Emp_Ptr (E6), Dept1);
   Display (Dept1);

   Appoint (CA11023D.Emp_Ptr (E2), Dept2);
   Appoint (CA11023D.Emp_Ptr (E4), Dept2);
   Display (Dept2);

   if not Is_Member (CA11023D.Emp_Ptr (E2), Dept2) then
      Report.Failed ("Trump in Mailroom!");
   end if;
   if Is_Member (CA11023D.Emp_Ptr (E1), Dept2) then
      Report.Failed ("Smith in Executive Suites!");
   end if;
   declare
      use type Department;
   begin
      if Current_Department (E3.all).all /= Department'Class(Dept1) then
          Report.Failed ("Wrong department for Hilton!");
      end if;
      if Current_Department (E6.all).all = Department'Class(Dept2) then
          Report.Failed ("Wrong department for Bush!");
      end if;
   end;

   Report.Result;
end CA110232;

