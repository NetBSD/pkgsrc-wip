
------------------------------------------------------------------- CD90001

with Report;
with CD90001_0;

procedure CD90001 is

  Eight_NA   : Boolean := False;
  Sixteen_NA : Boolean := False;

begin  -- Main test procedure.

  Report.Test ("CD90001", "Check that Unchecked_Conversion is supported " &
                          "and is reversible in appropriate cases" );
  Eight_Bit_Case:
  begin
    if CD90001_0.User_Enums'Size /= CD90001_0.Eight_Bits'Size then
      Report.Comment("The sizes of the 8 bit types used in this test "
                            & "do not match" );
      Eight_NA := True;
    elsif CD90001_0.User_Enums'Alignment /= CD90001_0.Eight_Bits'Alignment then
      Report.Comment("The alignments of the 8 bit types used in this "
                            & "test do not match" );
      Eight_NA := True;
    else
      CD90001_0.TC_Check_Case_1;
    end if;

  exception
    when Constraint_Error =>
           Report.Failed("Constraint_Error raised in 8 bit case");
    when others           =>
           Report.Failed("Unexpected exception raised in 8 bit case");
  end Eight_Bit_Case;

  Sixteen_Bit_Case:
  begin
    if CD90001_0.Signed_16'Size /= CD90001_0.Bits_16'Size then
      Report.Comment("The sizes of the 16 bit types used in this test "
                            & "do not match" );
      Sixteen_NA := True;
    elsif CD90001_0.Signed_16'Alignment /= CD90001_0.Bits_16'Alignment then
      Report.Comment("The alignments of the 16 bit types used in this "
                            & "test do not match" );
      Sixteen_NA := True;
    else
      CD90001_0.TC_Check_Case_2;
    end if;

  exception
    when Constraint_Error =>
           Report.Failed("Constraint_Error raised in 16 bit case");
    when others           =>
           Report.Failed("Unexpected exception raised in 16 bit case");
  end Sixteen_Bit_Case;

  if Eight_NA and Sixteen_NA then
    Report.Not_Applicable("No cases in this test apply");
  end if;

  Report.Result;

end CD90001;
