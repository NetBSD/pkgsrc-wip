
-- no package body C390011_5 required

------------------------------------------------------------------- C390011

with Report;
with C390011_0;
with C390011_2;
with C390011_3;
with C390011_4;
with C390011_5;
with Ada.Tags;
procedure C390011 is

begin  -- Main test procedure.

  Report.Test ("C390011", "Check that tagged types declared within " &
                          "generic package declarations generate distinct " &
                          "tags for each instance of the generic. " &
                          "Check that 'Base may be used as a subtype mark. " &
                          "Check that T'Base and T'Class are allowed as " &
                          "the subtype mark in a function result" );

  -- build the tag information table
  C390011_0.Add_Tag_To_List(T => C390011_2.Table'Tag,
                       X_Name => Ada.Tags.Expanded_Name(C390011_2.Table'Tag),
                       X_Tag  => Ada.Tags.External_Tag(C390011_2.Table'Tag) );

  C390011_0.Add_Tag_To_List(T => C390011_3.Table'Tag,
                       X_Name => Ada.Tags.Expanded_Name(C390011_3.Table'Tag),
                       X_Tag  => Ada.Tags.External_Tag(C390011_3.Table'Tag) );

  C390011_0.Add_Tag_To_List(T => C390011_4.Table'Tag,
                       X_Name => Ada.Tags.Expanded_Name(C390011_4.Table'Tag),
                       X_Tag  => Ada.Tags.External_Tag(C390011_4.Table'Tag) );

  C390011_0.Add_Tag_To_List(T => C390011_5.Table_3'Tag,
                     X_Name => Ada.Tags.Expanded_Name(C390011_5.Table_3'Tag),
                     X_Tag  => Ada.Tags.External_Tag(C390011_5.Table_3'Tag) );

  C390011_0.Add_Tag_To_List(T => C390011_5.Table_4'Tag,
                     X_Name => Ada.Tags.Expanded_Name(C390011_5.Table_4'Tag),
                     X_Tag  => Ada.Tags.External_Tag(C390011_5.Table_4'Tag) );

  -- preform the check for distinct tags
  C390011_0.Check_List_For_Duplicates;

  Report.Result;

end C390011;
