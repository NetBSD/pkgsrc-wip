
with Report;
with C761001_1;
package body C761001_0 is

  My_Object : Global;

  Done : Boolean := False;

  procedure Finalize( It: in out Global ) is
  begin
    if not C761001_1.Library_Task'Terminated then
      Report.Failed("Library task not terminated before finalize");
    end if;
    if Done then  -- checking included "just in case"
      Report.Comment("Test FAILED, even if previously reporting passed");
      Report.Failed("Unwarranted multiple call to finalize");
    end if;
    Report.Result;
    Done := True;
  end Finalize;

end C761001_0;
