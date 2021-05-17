

private with CA12002_Parent.Pub_Pack_Child_1.Pub_Grandchild;
with CA12002_Parent.Pub_Pack_Child_2;
with Report;
use Report;
procedure CA12002 is
begin
   Test ("CA12002",
         "Check that the declaration of a public descendant of a unit L can " &
         "mention a private child of L in a private with clause. " &
         "Check that a public descendant of a public root library unit can " &
         "be mentioned in a private with clause on any unit. Check that a " &
         "name mentioned in a private with clause can be used in a private " &
         "part, including those of nested and descendant packages. " &
         "Check that a name mentioned in a private with clause can be used " &
         "in the visible part of a private descendant, in a body, and " &
         "in a subunit");

   if CA12002_Parent.Pub_Pack_Child_1.X /= Report.Ident_Int (5) then
      Failed ("Error referencing object from private package");
   end if;

   if CA12002_Parent.Pub_Pack_Child_1.Y then
      Failed ("Error calling private function");
   end if;

   if CA12002_Parent.Pub_Pack_Child_1.Nested.Z /= Report.Ident_Int (15) then
      Failed ("Error referencing object from private package in nested package");
   end if;

   declare
      X : Integer := Report.Ident_Int (1);
   begin
      CA12002_Parent.Pub_Pack_Child_1.P (X);
      if X /= Report.Ident_Int (7) then
         Failed ("Error calling private procedure");
      end if;
   end;

   if CA12002_Parent.Pub_Pack_Child_1.F /= Report.Ident_Int (4) then
      Failed ("Error calling separate function");
   end if;

   if not CA12002_Parent.Pub_Pack_Child_1.Pub_Grandchild.W then
      Failed ("Error calling private function in grandchild");
   end if;

   if CA12002_Parent.Pub_Pack_Child_2.F /= 21.0 then
      Failed ("Error referencing object through private descendant");
   end if;

   Result;
end CA12002;
