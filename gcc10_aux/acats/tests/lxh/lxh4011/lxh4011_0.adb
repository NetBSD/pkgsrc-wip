
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body LXH4011_0 is

  procedure Update( ST: Simple_Tag ) is
  begin
    Report.Comment( "Update Simple_Tag" );
  end Update;

  procedure Update( CT: Complex_Tag ) is
  begin
    Report.Comment( "Update Complex_Tag" );
  end Update;

  An_Item    : aliased Simple_Tag'Class := Simple_Tag'(1,2);      -- violation
                            -- not an error, pragma has not yet been processed
  The_Item   : aliased Simple_Tag       := Simple_Tag'(1,2);
  Other_Item : aliased Complex_Tag      := (1,2,True);

  type Test_List is array(Natural range 1..3) of Tag_Pointer;

  Tests : Test_List := (An_Item'Access, Other_Item'Access, The_Item'Access);

  procedure TC_Check is
  begin
    for I in Tests'Range loop
      Update( Tests(Report.Ident_Int(I)).all );
    end loop;
  end TC_Check;

end LXH4011_0;
