

with Report;
with ImpDef;
with C980003_0;  use C980003_0;
with Ada.Unchecked_Deallocation;
procedure C980003 is

    procedure Check_State (Should_Be : States;
                           Msg       : String) is
        Cur : States := State_Manager.Current;
    begin
        if Cur /= Should_Be then
            Report.Failed (Msg);
            Report.Comment ("expected: " & States'Image (Should_Be) &
                            "  found: " & States'Image (Cur));
        elsif Verbose then
            Report.Comment ("passed: " & Msg);
        end if;
    end Check_State;

begin
 
    Report.Test ("C980003", "Check that aborts are deferred during" &
                            " initialization, finalization, and assignment" &
                            " operations on controlled objects");

    Check_State (Unknown, "initial condition");

    -- check that initialization and finalization take place
    Init_Occurred := False;
    select
        State_Manager.Wait_For_Change;
    then abort
        declare
            My_Controlled_Obj : Is_Controlled;
        begin
            delay 0.0;   -- abort completion point
            Report.Failed ("state change did not occur");
        end; 
    end select;
    if not Init_Occurred then
        Report.Failed ("Initialize did not complete");
    end if;
    Check_State (Finished_Final, "init/final for declared item");

    -- check adjust
    State_Manager.Reset;
    declare
        Source, Dest : Is_Controlled;
    begin
        Check_State (Finished_Init, "adjust initial state");
        Source.Id := 3;
        Dest.Id := 4;
        State_Manager.Reset;  -- so we will wait for change
        select
            State_Manager.Wait_For_Change;
        then abort
            Dest := Source;
        end select;

        -- there are two implementation methods for the 
        -- assignment statement:
        --   1.  no temporary was used in the assignment statement 
        --        thus the entire
        --        assignment statement is abort deferred.  
        --   2.  a temporary was used in the assignment statement so
        --        there are two assignment operations.  An abort may
        --        occur between the assignment operations
        -- Various optimizations are allowed by 7.6 that can affect
        -- how many times Adjust and Finalize are called. 
        -- Depending upon the implementation, the state can be either
        -- Finished_Adjust or Finished_Finalize.   If it is any other
        -- state then the abort took place at the wrong time.

        case State_Manager.Current is
        when Finished_Adjust =>
            if Verbose then
                Report.Comment ("assignment aborted after adjust");
            end if;
        when Finished_Final =>
            if Verbose then
                Report.Comment ("assignment aborted after finalize");
            end if;
        when Start_Adjust =>
            Report.Failed ("assignment aborted in adjust");
        when Start_Final =>
            Report.Failed ("assignment aborted in finalize");
        when Start_Init =>
            Report.Failed ("assignment aborted in initialize");
        when Finished_Init =>
            Report.Failed ("assignment aborted after initialize");
        when Unknown =>
            Report.Failed ("assignment aborted in unknown state");
        end case;


        if Dest.Id /= 3 then
            if Verbose then
                Report.Comment ("assignment not performed");
            end if;
        end if;
    end;


     -- check dynamically allocated objects
    State_Manager.Reset;
    declare
        type Pointer_Type is access Is_Controlled;
        procedure Free is new Ada.Unchecked_Deallocation (
              Is_Controlled, Pointer_Type);
        Ptr : Pointer_Type;
    begin
      -- make sure initialize is done when object is allocated
      Ptr := new Is_Controlled;
      Check_State (Finished_Init, "init when item allocated");
      -- now try aborting the finalize
      State_Manager.Reset;
      select
             State_Manager.Wait_For_Change;
      then abort
             Free (Ptr);
      end select;
      Check_State (Finished_Final, "finalization in dealloc");
    end;

    Report.Result;
 
end C980003;
