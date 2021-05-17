
with Report;
with C452003_Root.Child;
with C452003A;
procedure C452003 is

   pragma Assertion_Policy (Check);

   Local_Root_Obj : aliased C452003_Root.Root_Type := (Id => 1);

   Local_Child_Obj : aliased C452003_Root.Child.Child_Type :=
                     (Id => 2, Name => "XXXX");

begin

   Report.Test
     ("C452003",
      "Check that memberships with a tested type of a named general " &
       "access-to-object type work as defined");

   C452003A.Do_Tests (Local_Root_Obj'Access, Is_Root => True);

   C452003A.Do_Tests (Local_Child_Obj'Access, Is_Root => False);

   Report.Result;

end C452003;
