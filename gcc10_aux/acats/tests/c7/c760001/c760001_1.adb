
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C760001_1 is

  procedure Initialize( TC: in out Test_Controlled ) is
  begin
    if TC.Last_Proc_Called /= None then
      Report.Failed("Initialize for Test_Controlled");
    end if;
    TC.Last_Proc_Called := Init;
    C760001_0.Initialize(C760001_0.Root_Controlled(TC));
  end Initialize;

  procedure Adjust    ( TC: in out Test_Controlled ) is
  begin
    TC.Last_Proc_Called := Adj;
    C760001_0.Adjust(C760001_0.Root_Controlled(TC));
  end Adjust;

  procedure Finalize  ( TC: in out Test_Controlled ) is
  begin
    TC.Last_Proc_Called := Fin;
  end Finalize;

  procedure Initialize( TC: in out Nested_Controlled ) is
  begin
    if TC.Last_Proc_Called /= None then
      Report.Failed("Initialize for Nested_Controlled");
    end if;
    TC.Last_Proc_Called := Init;
    C760001_0.Initialize(C760001_0.Root_Controlled(TC));
  end Initialize;

  procedure Adjust    ( TC: in out Nested_Controlled ) is
  begin
    TC.Last_Proc_Called := Adj;
    C760001_0.Adjust(C760001_0.Root_Controlled(TC));
  end Adjust;

  procedure Finalize  ( TC: in out Nested_Controlled ) is
  begin
    TC.Last_Proc_Called := Fin;
  end Finalize;

end C760001_1;
