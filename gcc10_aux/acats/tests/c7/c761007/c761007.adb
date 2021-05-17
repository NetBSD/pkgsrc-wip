
------------------------------------------------------------------ C761007

with Report;
with Impdef;
with TCTouch;
with C761007_0;
with C761007_1;
with C761007_2;
procedure C761007 is

  task type Subtests( Outer, Inner : Character) is
    entry Ready;
    entry Complete;
  end Subtests;

  task body Subtests is
    Local_Prot_W_Fin_Obj : C761007_2.Prot_W_Fin_Obj;
  begin
    Local_Prot_W_Fin_Obj.Set_Effects( Outer, Inner );

    accept Ready;

    select
      accept Complete;
    or terminate;       -- used in Subtest 4
    end select;
  exception
    -- the exception caused by the finalization of Local_Prot_W_Fin_Obj
    --  should never be visible to this scope.
    when others => Report.Failed("Exception in a Subtest object "
                                 & Outer & Inner);
  end Subtests;

  procedure Subtest_1 is
    -- check the case where "nothing special" happens.

    This_Subtest : Subtests( 'A', 'B' );
  begin

    This_Subtest.Ready;
    This_Subtest.Complete;

    while not This_Subtest'Terminated loop -- wait for finalization
      delay Impdef.Clear_Ready_Queue;
    end loop;

    -- in the finalization of This_Subtest, the controlled object embedded in
    -- the Prot_W_Fin_Obj will finalize.  An exception is raised in the
    -- container object, after "touching" it's tag character.
    -- The finalization of the contained controlled object must be performed.


    TCTouch.Validate( "AB", "Item embedded in task" );


  exception
    when others => Report.Failed("Undesirable exception in Subtest_1");

  end Subtest_1;

  procedure Subtest_2 is
    -- check for explicit abort

    task Subtest_Task is
      entry Complete;
    end Subtest_Task;

    task body Subtest_Task is

      task Nesting;
      task body Nesting is
        Deep_Nesting : Subtests( 'E', 'F' );
      begin
        if Report.Ident_Bool( True ) then
          -- controlled objects have been created in the elaboration of
          -- Deep_Nesting.  Deep_Nesting must call the Set_Effects operation
          -- in the Prot_W_Fin_Obj, and then hang waiting for the Complete
          -- entry call.
          Deep_Nesting.Ready;
          abort Deep_Nesting;
        else
          Report.Failed("Dead code in Nesting");
        end if;
      exception
        when others => Report.Failed("Exception in Subtest_Task.Nesting");
      end Nesting;

      Local_2 : C761007_2.Prot_W_Fin_Obj;

    begin
      -- Nesting has activated at this point, which implies the activation
      -- of Deep_Nesting as well.

      Local_2.Set_Effects( 'C', 'D' );

      -- wait for Nesting to terminate

      while not Nesting'Terminated loop
        delay Impdef.Clear_Ready_Queue;
      end loop;

      accept Complete;

    exception
      when others => Report.Failed("Exception in Subtest_Task");
    end Subtest_Task;

  begin

    -- wait for everything in Subtest_Task to happen
    Subtest_Task.Complete;

    while not Subtest_Task'Terminated loop -- wait for finalization
      delay Impdef.Clear_Ready_Queue;
    end loop;

    TCTouch.Validate( "EFCD", "Aborted nested task" );

  exception
    when others => Report.Failed("Undesirable exception in Subtest_2");
  end Subtest_2;

  procedure Subtest_3 is
    -- check abort caused by asynchronous transfer of control

    task Subtest_3_Task is
      entry Complete;
    end Subtest_3_Task;

    procedure Check_Atc_Operation is
      Check_Atc : C761007_2.Prot_W_Fin_Obj;
    begin

      Check_Atc.Set_Effects( 'G', 'H' );


      while Report.Ident_Bool( True ) loop -- wait to be aborted
        if Report.Ident_Bool( True ) then
          Impdef.Exceed_Time_Slice;
          delay Impdef.Switch_To_New_Task;
        else
          Report.Failed("Optimization prevention");
        end if;
      end loop;

      Report.Failed("Check_Atc_Operation loop completed");

    end Check_Atc_Operation;

    task body Subtest_3_Task is
      task Nesting is
        entry Complete;
      end Nesting;

      task body Nesting is
        Nesting_3 : C761007_2.Prot_W_Fin_Obj;
      begin
        Nesting_3.Set_Effects( 'G', 'H' );

        -- give Check_Atc_Operation sufficient time to perform it's
        -- Set_Effects on it's local Prot_W_Fin_Obj object
        delay Impdef.Clear_Ready_Queue;

        accept Complete;
      exception
        when others => Report.Failed("Exception in Subtest_3_Task.Nesting");
      end Nesting;

      Local_3 : C761007_2.Prot_W_Fin_Obj;

    begin -- Subtest_3_Task

      Local_3.Set_Effects( 'I', 'J' );

      select
        Nesting.Complete;
      then abort ---------------------------------------------------- cause KL
        Check_ATC_Operation;
      end select;

      accept Complete;

    exception
      when others => Report.Failed("Exception in Subtest_3_Task");
    end Subtest_3_Task;

  begin -- Subtest_3
    Subtest_3_Task.Complete;

    while not Subtest_3_Task'Terminated loop -- wait for finalization
      delay Impdef.Clear_Ready_Queue;
    end loop;

    TCTouch.Validate( "GHIJ", "Asynchronously aborted operation" );

  exception
    when others => Report.Failed("Undesirable exception in Subtest_3");
  end Subtest_3;

  procedure Subtest_4 is
    -- check the case where transfer is caused by terminate alternative
    -- highly similar to Subtest_1

    This_Subtest : Subtests( 'M', 'N' );
  begin

    This_Subtest.Ready;
    -- don't call This_Subtest.Complete;

  exception
    when others => Report.Failed("Undesirable exception in Subtest_4");

  end Subtest_4;

begin  -- Main test procedure.

  Report.Test ("C761007", "Check that if a finalize procedure invoked by " &
                          "a transfer of control or selection of a " &
                          "terminate alternative attempts to propagate " &
                          "an exception, the exception is ignored, but " &
                          "any other finalizations due to be performed " &
                          "are performed" );

  Subtest_1;  -- checks internal

  Subtest_2;  -- checks internal

  Subtest_3;  -- checks internal

  Subtest_4;
  TCTouch.Validate( "MN", "transfer due to terminate alternative" );

  Report.Result;

end C761007;
