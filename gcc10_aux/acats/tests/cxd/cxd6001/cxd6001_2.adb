
----------------------------------------------------------
with ImpDef;
with CXD6001_1;
with System;
with Report;
with Ada.Task_Identification;
with Ada.Synchronous_Task_Control;

package body CXD6001_2 is
  package TID renames Ada.Task_Identification;
  package STC renames Ada.Synchronous_Task_Control;
  Verbose : constant Boolean := CXD6001_1.Verbose;

  type Action_Requests is (Simple, In_Rdzv, In_Prot);

  Check_Point_Start : Boolean := False;
  pragma Atomic (Check_Point_Start);
  Check_Point_Resume : Boolean := False;
  pragma Atomic (Check_Point_Resume);
  Check_Point_Protected : Boolean := False;
  pragma Atomic (Check_Point_Protected);
  Check_Point_Not_Protected : Boolean := False;
  pragma Atomic (Check_Point_Not_Protected);


  procedure Check_Results (Title : String) is
  begin
    if Verbose then
      Report.Comment (Title);
    end if;
    if Check_Point_Start then
      if Verbose then
        Report.Comment ("  start reached");
      end if;
    else
      Report.Failed ("start never reached");
    end if;

    if Check_Point_Resume then
      if Verbose then
        Report.Comment ("  resume reached");
      end if;
    else
      Report.Failed ("resume never reached");
    end if;

    if Check_Point_Protected then
      if Verbose then
        Report.Comment ("  protected reached");
      end if;
    else
      Report.Failed ("protected operation aborted");
    end if;

    if Check_Point_Not_Protected then
      Report.Failed ("abort was not immediate");
    else
      if Verbose then
        Report.Comment ("  immediate abort");
      end if;
    end if;
  end Check_Results;

----------------

  task Server is
    entry Simple_Service;
  end Server;

  task body Server is
  begin
    select
      accept Simple_Service do
        Check_Point_Resume := True;
        STC.Set_True (CXD6001_1.Kill_Now);
        Check_Point_Protected := True;
      end Simple_Service;
    or
      terminate;
    end select;
  end Server;

----------------
  protected Protected_Object is
    procedure Service;
  end Protected_Object;

  protected body Protected_Object is
    procedure Service is
    begin
        Check_Point_Resume := True;
        STC.Set_True (CXD6001_1.Kill_Now);
        Check_Point_Protected := True;
    end Service;
  end Protected_Object;

----------------

  task type Victim_Type is
    entry Get_ID (Id : out TID.Task_ID);
    entry Do_It (Action : Action_Requests);
  end Victim_Type;

  task body Victim_Type is
    This_Action : Action_Requests;
  begin
    select
      accept Get_Id (Id : out TID.Task_ID) do
        Id := TID.Current_Task;
      end Get_ID;
    or
      -- allows clean termination when the test is
      -- determined to be not applicable.
      terminate;
    end select;

    Check_Point_Start := False;
    Check_Point_Resume := False;
    Check_Point_Protected := False;
    Check_Point_Not_Protected := False;

    accept Do_It (Action : Action_Requests) do
      This_Action := Action;
    end Do_It;

    Check_Point_Start := True;
    case This_Action is
      when Simple =>
              Check_Point_Resume := True;
              Check_Point_Protected := True;  -- n/a in this test
              STC.Set_True (CXD6001_1.Kill_Now);
              Check_Point_Not_Protected := True;
      when In_Rdzv =>
              Server.Simple_Service;
              Check_Point_Not_Protected := True;
      when In_Prot =>
              Protected_Object.Service;
              Check_Point_Not_Protected := True;
    end case;

    -- should not get to this point
    delay 0.0;
    Report.Failed ("task was not aborted for this action: " &
                   Action_Requests'Image (This_Action));
  end Victim_Type;

------------------------

  Simple_Victim : Victim_Type;

  procedure Simple_Case is
    -- the task being aborted is not in a abort-deferred region
    -- when the abort occurs.
    Victim : TID.Task_ID;
  begin
    Simple_Victim.Get_ID (Victim);
    CXD6001_1.Killer_Task.Task_To_Abort (Victim);
    Simple_Victim.Do_It (Simple);
    delay ImpDef.Clear_Ready_Queue;
    Check_Results ("simple case - no abort deferral");
  end Simple_Case;

------------------------

  Rendezvous_Victim : Victim_Type;

  procedure In_Rendezvous is
    -- the task being aborted is in a rendezvous with a server
    -- when the abort occurs.
    Victim : TID.Task_ID;
  begin
    Rendezvous_Victim.Get_ID (Victim);
    CXD6001_1.Killer_Task.Task_To_Abort (Victim);
    Rendezvous_Victim.Do_It (In_Rdzv);
    delay ImpDef.Clear_Ready_Queue;
    Check_Results ("in rendezvous when abort occurs");
  end In_Rendezvous;

------------------------

  Protected_Victim : Victim_Type;

  procedure In_Protected is
    -- the task being aborted is in a protected operation
    -- when the abort occurs.
    Victim : TID.Task_ID;
  begin
    Protected_Victim.Get_ID (Victim);
    CXD6001_1.Killer_Task.Task_To_Abort (Victim);
    Protected_Victim.Do_It (In_Prot);
    delay ImpDef.Clear_Ready_Queue;
    Check_Results ("in protected operation when abort occurs");
  end In_Protected;
end CXD6001_2;
