

     --==================================================================--


with C460006_0.C460006_1.C460006_2.C460006_3;

with Report;
procedure C460006 is

   package Root_Package       renames C460006_0;
   package Parent_Package     renames C460006_0.C460006_1;
   package Child_Package      renames C460006_0.C460006_1.C460006_2;
   package Grandchild_Package renames C460006_0.C460006_1.C460006_2.C460006_3;

begin
   Report.Test ("C460006", "Check that a view conversion to a tagged type " &
                "is permitted in the prefix of a selected component, an "   &
                "object renaming declaration, and (if the operand is a "    &
                "variable) on the left side of an assignment statement.  "  &
                "Check that such a renaming or assignment does not change " &
                " the tag of the operand");


   --
   -- Check conversion as prefix of selected component:
   --

   Selected_Component_Subtest:
   declare
      use Root_Package, Parent_Package, Child_Package, Grandchild_Package;

      Var    : Grandchild_Type   := Grandchild_Value;
      CW_Var : Parent_Type'Class := Var;

      Ren    : Integer renames Parent_Type(Var).C1;

   begin
      if Ren /= 15 then
         Report.Failed ("Wrong value: selected component in renaming");
      end if;

      if Child_Type(Var).C2 /= "Hello" then
         Report.Failed ("Wrong value: selected component in IF");
      end if;

      Grandchild_Type(CW_Var).C3(2..4) := "eir";
      if CW_Var /= Parent_Type'Class
                   (Grandchild_Type'(None, None, 15, "Hello", "Weird"))
      then
         Report.Failed ("Wrong value: selected component in assignment");
      end if;
   end Selected_Component_Subtest;


   --
   -- Check conversion in object renaming:
   --

   Object_Renaming_Subtest:
   declare
      use Root_Package, Parent_Package, Child_Package, Grandchild_Package;

      Var : Grandchild_Type := Grandchild_Value;
      Ren1 : Parent_Type       renames Parent_Type(Var);
      Ren2 : Child_Type        renames Child_Type(Var);
      Ren3 : Parent_Type'Class renames Parent_Type'Class(Var);
      Ren4 : Parent_Type       renames Parent_Type(Ren2); -- Rename of rename.
   begin
      Outer_Proc (Ren1);
      if Ren1 /= (Parent_Outer, Grandchild_Inner, 15) then
         Report.Failed ("Value or tag not preserved by object renaming: Ren1");
      end if;

      Outer_Proc (Ren2);
      if Ren2 /= (Child_Outer, Grandchild_Inner, 15, "Hello") then
         Report.Failed ("Value or tag not preserved by object renaming: Ren2");
      end if;

      Outer_Proc (Ren3);
      if Ren3 /= Parent_Type'Class
                 (Grandchild_Type'(Grandchild_Outer,
                                   Grandchild_Inner,
                                   15,
                                   "Hello",
                                   "World"))
      then
         Report.Failed ("Value or tag not preserved by object renaming: Ren3");
      end if;

      Outer_Proc (Ren4);
      if Ren4 /= (Parent_Outer, Grandchild_Inner, 15) then
         Report.Failed ("Value or tag not preserved by object renaming: Ren4");
      end if;
   end Object_Renaming_Subtest;


   --
   -- Check reading view conversion, and conversion as left side of assignment:
   --

   View_Conversion_Subtest:
   declare
      use Root_Package, Parent_Package, Child_Package, Grandchild_Package;

      Var : Grandchild_Type := Grandchild_Value;
      Specific  : Child_Type;
      ClassWide : Parent_Type'Class := Var;   -- Grandchild_Type tag.
   begin
      if Parent_Type(Var) /= (None, None, 15) then
         Report.Failed ("View has wrong value: #1");
      end if;

      if Child_Type(Var) /= (None, None, 15, "Hello") then
         Report.Failed ("View has wrong value: #2");
      end if;

      if Parent_Type'Class(Var) /= ClassWide_Func then
         Report.Failed ("Upward view conversion did not preserve " &
                        "extension's components");
      end if;


      Parent_Type(Specific) := (None, None, 26); -- Assign to view.
      Outer_Proc (Specific);                     -- Call dispatching op.

      if Specific /= (Child_Outer, Child_Inner, 26, "-----") then
         Report.Failed ("Value or tag not preserved by assignment: Specific");
      end if;


      Parent_Type(ClassWide) := (None, None, 44); -- Assign to view.
      Outer_Proc (ClassWide);                     -- Call dispatching op.

      if ClassWide /= Parent_Type'Class
                      (Grandchild_Type'(Grandchild_Outer,
                                        Grandchild_Inner,
                                        44,
                                        "Hello",
                                        "World"))
      then
         Report.Failed ("Value or tag not preserved by assignment: ClassWide");
      end if;
   end View_Conversion_Subtest;

   Report.Result;

end C460006;
