
with Report;
package body C760002_1 is

  procedure Initialize( TC: in out Test_Controlled ) is
  begin
    TC.Last_Proc_Called := Init;
    C760002_0.Initialize(C760002_0.Root_Controlled(TC));
  end Initialize;

  procedure Adjust    ( TC: in out Test_Controlled ) is
  begin
    TC.Last_Proc_Called := Adj;
    C760002_0.Adjust(C760002_0.Root_Controlled(TC));
  end Adjust;

  procedure Finalize  ( TC: in out Test_Controlled ) is
  begin
    TC.Last_Proc_Called := Fin;
  end Finalize;

  procedure Initialize( TC: in out Nested_Controlled ) is
  begin
    TC.Last_Proc_Called := Init;
    C760002_0.Initialize(C760002_0.Root_Controlled(TC));
  end Initialize;

  procedure Adjust    ( TC: in out Nested_Controlled ) is
  begin
    TC.Last_Proc_Called := Adj;
    C760002_0.Adjust(C760002_0.Root_Controlled(TC));
  end Adjust;

  procedure Finalize  ( TC: in out Nested_Controlled ) is
  begin
    TC.Last_Proc_Called := Fin;
  end Finalize;

  procedure Initialize( TC: in out Test_Limited_Controlled ) is
  begin
    TC.Last_Proc_Called := Init;
    C760002_0.Initialize(C760002_0.Root_Limited_Controlled(TC));
  end Initialize;

  procedure Adjust    ( TC: in out Test_Limited_Controlled ) is
  begin
    Report.Failed("Adjust called for Test_Limited_Controlled");
  end Adjust;

  procedure Finalize  ( TC: in out Test_Limited_Controlled ) is
  begin
    TC.Last_Proc_Called := Fin;
  end Finalize;

  procedure Initialize( TC: in out Nested_Limited_Controlled ) is
  begin
    TC.Last_Proc_Called := Init;
    C760002_0.Initialize(C760002_0.Root_Limited_Controlled(TC));
  end Initialize;

  procedure Adjust    ( TC: in out Nested_Limited_Controlled ) is
  begin
    Report.Failed("Adjust called for Nested_Limited_Controlled");
  end Adjust;

  procedure Finalize  ( TC: in out Nested_Limited_Controlled ) is
  begin
    TC.Last_Proc_Called := Fin;
  end Finalize;

end C760002_1;
