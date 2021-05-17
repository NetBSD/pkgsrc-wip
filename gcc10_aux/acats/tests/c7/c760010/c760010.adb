 
---------------------------------------------------------------------------

with Report;
with C760010_0;
with C760010_1;
with C760010_2;
procedure C760010 is

  use type C760010_0.Actions;

  procedure Case_Failure(Message: String) is
  begin
    Report.Failed(Message & " for case "
                  & C760010_0.Actions'Image(C760010_0.Action) );
  end Case_Failure;

  procedure Check_Implicit_Initialize is
    Item   : C760010_2.Embedded_Derived;  -- exception here propagates to
    Gadget : C760010_2.Embedded_Derived;  -- caller
  begin
    if C760010_0.Action
       in C760010_0.Init_Raise_User_Defined..C760010_0.Init_Raise_Standard
    then
      Case_Failure("Anticipated exception at implicit init");
    end if;
    begin
      Item := Gadget;                     -- exception here handled locally
      if C760010_0.Action in C760010_0.Adj_Raise_User_Defined
                                   .. C760010_0.Fin_Raise_Standard then
        Case_Failure ("Anticipated exception at assignment");
      end if;
    exception
      when Program_Error =>
        if C760010_0.Action not in C760010_0.Adj_Raise_User_Defined
                                   .. C760010_0.Fin_Raise_Standard then
          Report.Failed("Program_Error in Check_Implicit_Initialize");
        end if;
      when Tasking_Error =>
        Report.Failed("Tasking_Error in Check_Implicit_Initialize");
      when C760010_0.User_Defined_Exception =>
        Report.Failed("User_Error in Check_Implicit_Initialize");
      when others =>
        Report.Failed("Wrong exception Check_Implicit_Initialize");
    end;
  end Check_Implicit_Initialize;

---------------------------------------------------------------------------

  Global_Item : C760010_2.Embedded_Derived;

---------------------------------------------------------------------------

  procedure Check_Explicit_Initialize is
  begin
    begin
      C760010_2.Initialize( Global_Item );
    if C760010_0.Action
       in C760010_0.Init_Raise_User_Defined..C760010_0.Init_Raise_Standard
    then
      Case_Failure("Anticipated exception at explicit init");
    end if;
    exception
      when Program_Error =>
        Report.Failed("Program_Error in Check_Explicit_Initialize");
      when Tasking_Error =>
        if C760010_0.Action /= C760010_0.Init_Raise_Standard then
          Report.Failed("Tasking_Error in Check_Explicit_Initialize");
        end if;
      when C760010_0.User_Defined_Exception =>
        if C760010_0.Action /= C760010_0.Init_Raise_User_Defined then
          Report.Failed("User_Error in Check_Explicit_Initialize");
        end if;
      when others =>
        Report.Failed("Wrong exception in Check_Explicit_Initialize");
    end;
  end Check_Explicit_Initialize;

---------------------------------------------------------------------------

  procedure Check_Explicit_Adjust is
  begin
    begin
      C760010_2.Adjust( Global_Item );
    if C760010_0.Action
       in C760010_0.Adj_Raise_User_Defined..C760010_0.Adj_Raise_Standard
    then
      Case_Failure("Anticipated exception at explicit Adjust");
    end if;
    exception
      when Program_Error =>
        Report.Failed("Program_Error in Check_Explicit_Adjust");
      when Tasking_Error =>
        if C760010_0.Action /= C760010_0.Adj_Raise_Standard then
          Report.Failed("Tasking_Error in Check_Explicit_Adjust");
        end if;
      when C760010_0.User_Defined_Exception =>
        if C760010_0.Action /= C760010_0.Adj_Raise_User_Defined then
          Report.Failed("User_Error in Check_Explicit_Adjust");
        end if;
      when others =>
        Report.Failed("Wrong exception in Check_Explicit_Adjust");
    end;
  end Check_Explicit_Adjust;

---------------------------------------------------------------------------

  procedure Check_Explicit_Finalize is
  begin
    begin
      C760010_2.Finalize( Global_Item );
    if C760010_0.Action
       in C760010_0.Fin_Raise_User_Defined..C760010_0.Fin_Raise_Standard
    then
      Case_Failure("Anticipated exception at explicit Finalize");
    end if;
    exception
      when Program_Error =>
        Report.Failed("Program_Error in Check_Explicit_Finalize");
      when Tasking_Error =>
        if C760010_0.Action /= C760010_0.Fin_Raise_Standard then
          Report.Failed("Tasking_Error in Check_Explicit_Finalize");
        end if;
      when C760010_0.User_Defined_Exception =>
        if C760010_0.Action /= C760010_0.Fin_Raise_User_Defined then
          Report.Failed("User_Error in Check_Explicit_Finalize");
        end if;
      when others =>
        Report.Failed("Wrong exception in Check_Explicit_Finalize");
    end;
  end Check_Explicit_Finalize;

---------------------------------------------------------------------------

begin  -- Main test procedure.

  Report.Test ("C760010", "Check that explicit calls to finalization " &
                          "procedures that raise exceptions propagate " &
                          "the exception raised.  Check the utilization " &
                          "of a controlled type as the actual for a " &
                          "generic formal tagged private parameter" );

  for Act in C760010_0.Actions loop
    C760010_1.Reset_Counters;
    C760010_0.Action := Act;

    begin
      Check_Implicit_Initialize;
      if Act in
         C760010_0.Init_Raise_User_Defined..C760010_0.Init_Raise_Standard then
        Case_Failure("No exception at Check_Implicit_Initialize");
      end if;
    exception
      when Tasking_Error =>
        if Act /= C760010_0.Init_Raise_Standard then
          Case_Failure("Tasking_Error at Check_Implicit_Initialize");
        end if;
      when C760010_0.User_Defined_Exception =>
        if Act /= C760010_0.Init_Raise_User_Defined then
          Case_Failure("User_Error at Check_Implicit_Initialize");
        end if;
      when Program_Error =>
         -- If finalize raises an exception, all other object are finalized
         -- first and Program_Error is raised upon leaving the master scope.
         -- 7.6.1:14
         if Act not in C760010_0.Fin_Raise_User_Defined..
                       C760010_0.Fin_Raise_Standard then
            Case_Failure("Program_Error at Check_Implicit_Initialize");
         end if;
      when others =>
        Case_Failure("Wrong exception at Check_Implicit_Initialize");
    end;

    Check_Explicit_Initialize;
    Check_Explicit_Adjust;
    Check_Explicit_Finalize;

    C760010_1.Check_Counters(0,0,0, C760010_0.Actions'Image(Act));

  end loop;

  -- Set to No_Action to avoid exception in finalizing Global_Item
  C760010_0.Action := C760010_0.No_Action;

  Report.Result;

end C760010;
