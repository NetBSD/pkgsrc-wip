
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C390011_0 is

  use type Ada.Tags.Tag;
  type SP is access String;

  type List_Item;
  type List_P is access List_Item;
  type List_Item is record
    The_Tag  : Ada.Tags.Tag;
    Exp_Name : SP;
    Ext_Tag  : SP;
    Next : List_P;
  end record;

  The_List : List_P;

  procedure Add_Tag_To_List ( T : Ada.Tags.Tag; X_Name, X_Tag: String ) is
  begin  -- prepend the tag information to the list
    The_List := new List_Item'( The_Tag  => T, 
                                Exp_Name => new String'(X_Name), 
                                Ext_Tag  => new String'(X_Tag),
                                Next     => The_List );
  end Add_Tag_To_List;

  procedure Check_List_For_Duplicates is
    Finger : List_P;
    Thumb  : List_P := The_List;
  begin  -- 
    while Thumb /= null loop
      Finger := Thumb.Next;
      while Finger /= null loop
        -- Check that the tag is unique
        if Finger.The_Tag = Thumb.The_Tag then
          Report.Failed("Duplicate Tag");
        end if;

        -- Check that the Expanded name is unique
        if Finger.Exp_Name.all = Thumb.Exp_Name.all then
          Report.Failed("Tag name " & Finger.Exp_Name.all & " repeats");
        end if;

        -- Check that the External Tag is unique

        if Finger.Ext_Tag.all = Thumb.Ext_Tag.all then
          Report.Failed("External Tag " & Finger.Ext_Tag.all & " repeats");
        end if;
        Finger := Finger.Next;
      end loop;
      Thumb  := Thumb.Next;
   end loop;
  end Check_List_For_Duplicates;

begin
  -- some things I just don't trust...
  if The_List /= null then
    Report.Failed("Implicit default for The_List not null");
  end if;
end C390011_0;
