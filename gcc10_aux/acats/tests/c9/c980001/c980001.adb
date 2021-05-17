 
---------------------------------------------------------------------------

with Report;
with TCTouch;
with Impdef;
with C980001_0;
procedure C980001 is

  procedure Check_Initialize_Conditions is
  begin
    if not C980001_0.Initialize_Called then
      C980001_0.Fail_And_Clear("Initialize did not correctly complete");
    end if;
    TCTouch.Validate("Ii", "Initialization Sequence");
  end Check_Initialize_Conditions;

  procedure Check_Adjust_Conditions is
  begin
    if not C980001_0.Adjust_Called then
      C980001_0.Fail_And_Clear("Adjust did not correctly complete");
    end if;
    TCTouch.Validate("Aa", "Adjust Sequence");
  end Check_Adjust_Conditions;

  procedure Check_Finalize_Conditions is
  begin
    if not C980001_0.Finalize_Called then
      C980001_0.Fail_And_Clear("Finalize did not correctly complete");
    end if;
    TCTouch.Validate("FfFfFf", "Finalization Sequence",
                     Order_Meaningful => False);
  end Check_Finalize_Conditions;

  procedure Wait_Your_Turn is
    Overrun : Natural := 0;
  begin
    while C980001_0.Progress.Is_Locked loop  -- and waits
      delay C980001_0.A_Little_While;
      Overrun := Overrun +1;
      if Overrun > 10 then  
        C980001_0.Fail_And_Clear("Overrun expired lock");
      end if;
    end loop;
  end Wait_Your_Turn;

begin  -- Main test procedure.

  Report.Test ("C980001", "Check the interaction between asynchronous " &
                          "transfer of control and controlled types" );

  C980001_0.Progress.Lock;
  C980001_0.Hold_Up.Lock;

  select
    C980001_0.Hold_Up.Lock;  -- Init will unlock

    Wait_Your_Turn;  -- abortable part is stuck in Initialize
    Check_Initialize_Conditions;

  then abort
    declare
      Object : C980001_0.Sticks_In_Initialize;
    begin
      delay Impdef.Minimum_Task_Switch;
      if Report.Ident_Int( Object.Item ) /= Object.Item then
        Report.Failed("Optimization foil caused failure");
      end if;
      C980001_0.Fail_And_Clear(
                           "Initialize test executed beyond expected region");
    end;
  end select;

  C980001_0.Progress.Lock;

  select
    C980001_0.Hold_Up.Lock;  -- Adjust will unlock

    Wait_Your_Turn;  -- abortable part is stuck in Adjust
    Check_Adjust_Conditions;

  then abort
    declare
      Object1 : C980001_0.Sticks_In_Adjust;
      Object2 : C980001_0.Sticks_In_Adjust;
    begin
      Object1 := Object2;
      delay Impdef.Minimum_Task_Switch;
      if Report.Ident_Int( Object2.Item )
         /= Report.Ident_Int( Object1.Item ) then
        Report.Failed("Optimization foil 1 caused failure");
      end if;
      C980001_0.Fail_And_Clear("Adjust test executed beyond expected region");
    end;
  end select;

  C980001_0.Progress.Lock;

  select
    C980001_0.Hold_Up.Lock;  -- Finalize will unlock

    Wait_Your_Turn;  -- abortable part is stuck in Finalize
    Check_Finalize_Conditions;

  then abort
    declare
      Object1 : C980001_0.Sticks_In_Finalize;
      Object2 : C980001_0.Sticks_In_Finalize;
    begin
      Object1 := Object2;  -- cause a finalize call
      delay Impdef.Minimum_Task_Switch;
      if Report.Ident_Int( Object2.Item )
         /= Report.Ident_Int( Object1.Item ) then
        Report.Failed("Optimization foil 2 caused failure");
      end if;
      C980001_0.Fail_And_Clear(
                             "Finalize test executed beyond expected region");
    end;
  end select;

  Report.Result;

exception
  when others => C980001_0.Fail_And_Clear("Exception in main");
                 Report.Result;
end C980001;
