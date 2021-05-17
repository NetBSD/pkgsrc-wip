
with System;
with Report;
package body CXD6002_1 is

  Verbose : constant Boolean := False;


  Check_Point_Start : Boolean;
  pragma Atomic (Check_Point_Start);
  Check_Point_Resume : Boolean;
  pragma Atomic (Check_Point_Resume);
  Check_Point_Protected : Boolean;
  pragma Atomic (Check_Point_Protected);
  Check_Point_Not_Protected : Boolean;
  pragma Atomic (Check_Point_Not_Protected);

----------------------------------------------------------

  protected Gun is
    entry Remove_Safety;
    procedure Pull_Trigger;
  private
    pragma Interrupt_Priority (System.Interrupt_Priority'First);
    Safety_Off : Boolean := False;
  end Gun;

  protected body Gun is
    entry Remove_Safety when Safety_Off is
    begin
      Safety_Off := False;  -- one at a time, please
    end Remove_Safety;

    procedure Pull_Trigger is
    begin
      Safety_Off := True;
    end Pull_Trigger;
  end Gun;


  task Weapon is
    pragma Interrupt_Priority (System.Interrupt_Priority'First);
    entry Fire;
  end Weapon;

  task body Weapon is
  begin
    loop
      Gun.Remove_Safety;
      accept Fire;
    end loop;
  end Weapon;

----------------------------------------------------------


  procedure Initialize is
  begin
    Check_Point_Start         := False;
    Check_Point_Resume        := False;
    Check_Point_Protected     := False;
    Check_Point_Not_Protected := False;
  end Initialize;


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

----------------------------------------------------------

  procedure Simple_Victim is
  begin
     Check_Point_Resume := True;
     Check_Point_Protected := True;  -- n/a in this test
     Gun.Pull_Trigger;
     Check_Point_Not_Protected := True;
  end Simple_Victim;

  procedure Simple_Case is
   -- the action being aborted is not in a abort-deferred region
   -- when the abort occurs.
  begin
    Initialize;
    select
      Weapon.Fire;   -- waits for Simple_Victim to Pull_Trigger
    then abort
      Check_Point_Start := True;
      Simple_Victim;
      Report.Failed ("simple test - did not abort");
    end select;
    Check_Results ("simple case - no abort deferral");
  end Simple_Case;

----------------------------------------------------------

  task Server is
    entry Simple_Service;
  end Server;

  task body Server is
  begin
    select
      accept Simple_Service do
        Check_Point_Resume := True;
        Gun.Pull_Trigger;
        Check_Point_Protected := True; 
      end Simple_Service;
    or
      terminate;
    end select;
  end Server;


  procedure Rendezvous_Victim is
  begin
    Server.Simple_Service;
    Check_Point_Not_Protected := True;
  end Rendezvous_Victim;

  procedure In_Rendezvous is
  begin
    Initialize;
    select
      Weapon.Fire;  -- waits for Server to Pull_Trigger
    then abort
      Check_Point_Start := True;
      Rendezvous_Victim;
      Report.Failed ("rendezvous test - did not abort");
    end select;
    Check_Results ("in rendezvous when abort occurs");
  end In_Rendezvous;

----------------------------------------------------------

  protected Protected_Object is
    procedure Service;
  end Protected_Object;

  protected body Protected_Object is
    procedure Service is
    begin
      Check_Point_Resume := True;
      Gun.Pull_Trigger;
      Check_Point_Protected := True; 
    end Service;
  end Protected_Object;

  procedure Protected_Victim is
  begin
    Protected_Object.Service;
    Check_Point_Not_Protected := True;
  end Protected_Victim; 


  procedure In_Protected is
  begin
    Initialize;
    select
      Weapon.Fire;  -- waits for Protected_Object to Pull_Trigger
    then abort
      Check_Point_Start := True;
      Protected_Victim;
      Report.Failed ("protected test - did not abort");
    end select;
    Check_Results ("in protected operation when abort occurs");
  end In_Protected;

----------------------------------------------------------

  protected Protected_Object_w_Requeue is
    entry Service_1;
    entry Service_2;
    entry Service_3;
  end Protected_Object_w_Requeue;

  protected body Protected_Object_w_Requeue is
    entry Service_1 when True is
    begin
      Check_Point_Resume := True;
      Gun.Pull_Trigger;
      requeue Service_2;  -- no abort yet
    end Service_1;

    entry Service_2  when True is
    begin
      Check_Point_Protected := True; 
      requeue Service_3 with abort;  -- now the abort can occur
    end Service_2;

    entry Service_3  when True is
    begin
      Check_Point_Not_Protected := True;
    end Service_3;
  end Protected_Object_w_Requeue;

  procedure Requeue_Victim is
  begin
    Protected_Object_w_Requeue.Service_1;
  end Requeue_Victim; 


  procedure In_Protected_Requeue is
  begin
    Initialize;
    select
      Weapon.Fire;  -- waits for Protected_Object_w_Requeue to Pull_Trigger
    then abort
      Check_Point_Start := True;
      Requeue_Victim;
      Report.Failed ("requeue test - did not abort");
    end select;
    Check_Results ("in requeueing operation when abort occurs");
  end In_Protected_Requeue;

----------------------------------------------------------

  procedure Done is
  -- cleanup operation
  begin
    abort Weapon;
  end Done;
end CXD6002_1;
