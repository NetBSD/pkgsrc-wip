
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with TCTouch;
package body C641001_0 is

  String_Data : constant String := "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  procedure Check_String_10( S : out String_10; Start, Stop: Natural ) is
  begin
    if S'Length /= 10 then
      Report.Failed("Length check not performed prior to execution");
    end if;
    S := String_Data(Start..Stop);
  exception
    when others => Report.Failed("Exception encountered in Check_String_10");
  end Check_String_10;

  procedure Check_Illegal_Slice_Reference( Slice_Passed : in out String;
                                           Index: Natural ) is
  begin
    -- essentially "do-nothing" for optimization foilage...
    if Slice_Passed(Index) in Character then
    -- Intent is    ^^^^^  should raise Constraint_Error
      Report.Failed("Illegal Slice provided legal character");
    else
      Report.Failed("Illegal Slice provided illegal character");
    end if;
  exception
    when Constraint_Error =>
      null; -- expected case
    when others =>
      Report.Failed("Wrong exception in Check_Illegal_Slice_Reference");
  end Check_Illegal_Slice_Reference;

  procedure Check_Tag_Slice( TL : in out Tag_List_10 ) is
    -- if the view conversion is not performed, one of the following checks
    -- will fail (given data passed as 0..9 and then 2..11)
  begin
    Check_Under_Index:  -- index 0 should raise C_E
    begin
      TCTouch.Assert( TL(Report.Ident_Int(0)).Data_Item = "*****",
                      "Index 0 (illegal); bad data" );
      Report.Failed("Index 0 did not raise Constraint_Error");
    exception
      when Constraint_Error =>
        null; -- expected case
      when others =>
        Report.Failed("Wrong exception in Check_Under_Index ");
    end Check_Under_Index;

    Check_Over_Index:  -- index 11 should raise C_E
    begin
      TCTouch.Assert( TL(Report.Ident_Int(11)).Data_Item = "*****",
                      "Index 11 (illegal); bad data" );
      Report.Failed("Index 11 did not raise Constraint_Error");
    exception
      when Constraint_Error =>
        null; -- expected case
      when others =>
        Report.Failed("Wrong exception in Check_Over_Index ");
    end Check_Over_Index;

  end Check_Tag_Slice;

  procedure Check_Out_Tagged_Data( Formal : out Tagged_Data ) is
  begin
    TCTouch.Assert( Formal.Data_Item = "*****", "out formal data bad" );
    Formal.Data_Item(1) := '!';
  end Check_Out_Tagged_Data;

end C641001_0;
