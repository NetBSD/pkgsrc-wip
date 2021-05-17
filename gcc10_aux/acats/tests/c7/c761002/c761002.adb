
with Report;
with TCTouch;
with C761002_0;
with Unchecked_Deallocation;
procedure C761002 is

  -- check the straightforward case
  procedure Subtest_1 is
    type Access_1 is access C761002_0.Global;
    V1 : Access_1;
    procedure Allocate is
      V2 : Access_1;
    begin
      V2 := new C761002_0.Global;
      V1 := V2;  -- "dead" assignment must not be optimized away due to
                 -- finalization "side effects", many more of these follow
    end Allocate;
  begin
    Allocate;
    -- no calls to Finalize should have occurred at this point
    TCTouch.Validate("","Allocated nested, retained");
  end Subtest_1;

  -- check Unchecked_Deallocation
  procedure Subtest_2 is
    type Access_2 is access C761002_0.Global;
    procedure Free is
              new Unchecked_Deallocation(C761002_0.Global, Access_2);
    V1 : Access_2;
    V2 : Access_2;

    procedure Allocate is
    begin
      V1 := new C761002_0.Global;
      V2 := new C761002_0.Global;
    end Allocate;

  begin
    Allocate;
    -- no calls to Finalize should have occurred at this point.
    TCTouch.Validate("","Allocated nested, non-local");

    Free(V1); -- instance of Unchecked_Deallocation
    -- should cause the finalization of V1.all
    TCTouch.Validate("F","Unchecked Deallocation");
  end Subtest_2; -- leaving this scope should cause the finalization of V2.all

  -- check various master-exit scenarios
  -- the "Fake" parameters are used to avoid unwanted optimizations
  procedure Subtest_3 is
    procedure With_Local_Block is
      type Access_3 is access C761002_0.Global;
      V1 : Access_3;
    begin
      declare
        V2 : Access_3 := new C761002_0.Global;
      begin
        V1 := V2;
      end;
      TCTouch.Validate("","Local Block, normal exit");
      -- the allocated object should be finalized on leaving this scope
    end With_Local_Block;

    procedure With_Local_Block_Return(Fake: Integer) is
      type Access_4 is access C761002_0.Global;
      V1 : Access_4 := new C761002_0.Global;
    begin
      if Fake = 0 then
        declare
          V2 : Access_4;
        begin
          V2 := new C761002_0.Global;
          return; -- the two allocated objects should be finalized
        end;      -- upon leaving this scope
      else
        V1 := null;
      end if;
    end With_Local_Block_Return;

    procedure With_Goto(Fake: Integer) is
      type Access_5 is access C761002_0.Global;
      V1 : Access_5 := new C761002_0.Global;
      V2 : Access_5;
      V3 : Access_5;
    begin
      if Fake = 0 then
        declare
          type Access_6 is access C761002_0.Second;
          V6 : Access_6;
        begin
          V6 := new C761002_0.Second;
          goto check;
        end;
      else
        V2 := V1;
      end if;
      V3 := V2;
<<check>>
      TCTouch.Validate("S","goto past master end");
     end With_Goto;

  begin
    With_Local_Block;
    TCTouch.Validate("F","Local Block, normal exit, after master");

    With_Local_Block_Return( Report.Ident_Int(0) );
    TCTouch.Validate("FF","Local Block, return from block");

    With_Goto( Report.Ident_Int(0) );
    TCTouch.Validate("F","With Goto");

  end Subtest_3;

  procedure Subtest_4 is

    Oops : exception;

    procedure Alley( Fake: Integer ) is
      type Access_1 is access C761002_0.Global;
      V1 : Access_1;
    begin
      V1 := new C761002_0.Global;
      if Fake = 1 then
        raise Oops;
      end if;
      V1 := null;
    end Alley;

  begin
    Catch: begin
      Alley( Report.Ident_Int(1) );
    exception
      when Oops   => TCTouch.Validate("F","leaving via exception");
      when others => Report.Failed("Wrong exception");
    end Catch;
  end Subtest_4;

begin  -- Main test procedure.

  Report.Test ("C761002", "Check that objects of a controlled type created "
                        & "by an allocator for a named access type are "
                        & "finalized appropriately. "
                        & "Check that Unchecked_Deallocation of a "
                        & "controlled object causes finalization "
                        & "of that object" );

  Subtest_1;
  -- leaving the scope of the access type should finalize the
  -- collection
  TCTouch.Validate("F","Allocated nested, Subtest 1");

  Subtest_2;
  -- Unchecked_Deallocation already finalized one of the two
  -- objects allocated, the other should be the only one finalized
  -- at leaving the scope of the access type.
  TCTouch.Validate("F","Allocated non-local");

  Subtest_3;
  -- there should be no remaining finalizations from this subtest
  TCTouch.Validate("","Localized objects");

  Subtest_4;
  -- there should be no remaining finalizations from this subtest
  TCTouch.Validate("","Exception testing");

  Report.Result;

end C761002;
