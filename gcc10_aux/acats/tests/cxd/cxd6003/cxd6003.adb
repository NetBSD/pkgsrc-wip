

with Report;
with ImpDef.Annex_D; use ImpDef.Annex_D;
with CXD6003_0;  use CXD6003_0;
with Ada.Unchecked_Deallocation;
procedure CXD6003 is

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
 
    Report.Test ("CXD6003", "Check that aborts are deferred during" &
                            " initialization, finalization, and assignment" &
                            " operations on controlled objects but" &
                            " restored immediately afterward");

    -- the requirements on the abort being immediate are
    -- only placed upon uni-processor systems.
    if ImpDef.Annex_D.Processor /= ImpDef.Annex_D.Uni_Processor then
        Report.Not_Applicable ("Multi-Processor configuration");
        Report.Result;
        return;
    end if;

    Check_State (Unknown, "initial condition");

    -- check that initialization and finalization both take place 
    -- and are abort deferred 
    Completed_Init := False;
    select
        State_Manager.Wait_For_Change;
    then abort
        declare
            My_Controlled_Obj : Is_Controlled;
        begin
            Report.Failed ("abort not immediate - init/final");
        end; 
    end select;
    if not Completed_Init then
        Report.Failed ("initialization was aborted");
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
            Report.Failed ("abort not immediate - adjust");
        end select;

        -- note that assignment operation is not the same as an
        -- assignment statement.  The state could be either Finished_Adjust
        -- or Finished_Final depending upon the use of temporaries.
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
            -- depending upon the implementation, the copy into the
            -- resulting object may not have occurred yet.
            -- Just note it.
            Report.Comment("assignment not performed");
        end if;
    end;
    Check_State (Finished_Final, "finalization for check adjust block");

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
             Report.Failed ("abort not immediate - finalize in dealloc");
      end select;
      Check_State (Finished_Final, "finalization in dealloc");
    end;

    -- explicitly calling Initialize, Finalize, or Adjust is not
    -- abort deferred.
    declare
        Obj : Is_Controlled;
    begin
        State_Manager.Reset;   -- so we will wait for change
        select
            State_Manager.Wait_For_Change;
        then abort
            CXD6003_0.Initialize (Obj);
        end select;
        Check_State (Start_Init, "abort erroneously deferred - initialize");
            
        State_Manager.Reset;   -- so we will wait for change
        select
            State_Manager.Wait_For_Change;
        then abort
            CXD6003_0.Adjust (Obj);
        end select;
        Check_State (Start_Adjust, "abort erroneously deferred - adjust");
            
        State_Manager.Reset;   -- so we will wait for change
        select
            State_Manager.Wait_For_Change;
        then abort
            CXD6003_0.Finalize (Obj);
        end select;
        Check_State (Start_Final, "abort erroneously deferred - finalize");
    end;
    Check_State (Finished_Final, "finalization for explicit call block");
    Report.Result;
 
end CXD6003;
