
------------------------------------------------------- C392011_2.C392011_3

with C392011_0;
package C392011_2.C392011_3 is

  type Wide_Reference is access all C392011_0.Level_0'Class;

  type Ragged_Element;

  type List_Pointer is access Ragged_Element;

  type Ragged_Element is record
    Data : Wide_Reference;
    Next : List_Pointer;
  end record;

  procedure Build_List;

  procedure Traverse_List;

end C392011_2.C392011_3;
