
-------------------------------------------------------------------- C761003

with Report;
with TCTouch;
with C761003_0;
with C761003_2;
with C761003_Support;
procedure C761003 is

  package Sup renames C761003_Support;

---------------------------------------------------------------- Subtest_1

  Subtest_1_Inits_Expected : constant := 5;  -- includes 1 previous

  procedure Subtest_1 is

    -- the constant will take its constraint from the value.
    -- must be declared first to be finalized last (and take the
    -- initialize from before calling subtest_1)
    Item_1 : constant C761003_0.Global := C761003_0.Null_Global;

    -- Item_2, declared second, should be finalized second to last.
    Item_2 : C761003_0.Global(Sup.Pick_Char);

    -- Item_3 and Item_4 will be created in the order of the
    -- list.
    Item_3, Item_4 : C761003_0.Global(Sup.Pick_Char);

   -- Item_5 will be finalized first.
    Item_5 : C761003_0.Second(Sup.Pick_Char);

  begin
    if Item_3.Tag >= Item_4.Tag then
      Report.Failed("Controlled objects created by list in wrong order");
    end if;
    -- check that nothing has happened yet!
    TCTouch.Validate("","Subtest 1 body");
  end Subtest_1;

---------------------------------------------------------------- Subtest_2

  -- These declarations should cause calls to initialize and
  -- finalize.  The expected operations are the subprograms associated
  -- with the abstract types.  Note that for these objects, the
  -- Initialize and Finalize are visible only by inheritance.

  Subtest_2_Inits_Expected : constant := 4;

  procedure Subtest_2 is

    Item_1 : C761003_2.Global;
    Item_2, Item_3 : C761003_2.Global;
    Item_4 : C761003_2.Second;

  begin
    -- check that nothing has happened yet!
    TCTouch.Validate("","Subtest 2 body");
  end Subtest_2;

---------------------------------------------------------------- Subtest_3

  -- Test for controlled objects embedded in arrays.  Using structures
  -- that will cause a checkable order.

  Subtest_3_Inits_Expected : constant := 8;

  procedure Subtest_3 is

    type Global_List is array(Natural range <>)
                          of C761003_0.Global(Sup.Pick_Char);

    Items : Global_List(1..4);  -- components have the same tag

    type Second_List is array(Natural range <>)
                          of C761003_0.Second(Sup.Pick_Char);

    Second_Items : Second_List(1..4);  -- components have the same tag,
                                       -- distinct from the tag used in Items

  begin
    -- check that nothing has happened yet!
    TCTouch.Validate("","Subtest 3 body");
  end Subtest_3;

---------------------------------------------------------------- Subtest_4

  -- These declarations should cause dispatching calls to initialize and
  -- finalize.  The expected operations are the subprograms associated
  -- with the abstract types.

  Subtest_4_Inits_Expected : constant := 2;

  procedure Subtest_4 is

    type Global_Rec is record
      Item1: C761003_0.Global(Sup.Pick_Char);
    end record;

    type Second_Rec is record
      Item2: C761003_2.Second;
    end record;

    G : Global_Rec;
    S : Second_Rec;

  begin
    -- check that nothing has happened yet!
    TCTouch.Validate("","Subtest 4 body");
  end Subtest_4;

---------------------------------------------------------------- Subtest_5

  -- Test for controlled objects embedded in arrays.  In these cases, the
  -- order of the finalization of the components is not defined by the
  -- language.

  Subtest_5_Inits_Expected : constant := 8;

  procedure Subtest_5 is


    type Another_Global_List is array(Natural range <>)
                          of C761003_2.Global;

    More_Items : Another_Global_List(1..4);

    type Another_Second_List is array(Natural range <>)
                          of C761003_2.Second;

    Second_More_Items : Another_Second_List(1..4);

  begin
    -- check that nothing has happened yet!
    TCTouch.Validate("","Subtest 5 body");
  end Subtest_5;

---------------------------------------------------------------- Subtest_6

  -- These declarations should cause dispatching calls to initialize and
  -- finalize.  The expected operations are the subprograms associated
  -- with the abstract types.

  Subtest_6_Inits_Expected : constant := 2;

  procedure Subtest_6 is

    type Global_Rec is record
     Item2: C761003_2.Global;
    end record;

    type Second_Rec is record
      Item1: C761003_0.Second(Sup.Pick_Char);
   end record;

    G : Global_Rec;
    S : Second_Rec;

  begin
    -- check that nothing has happened yet!
    TCTouch.Validate("","Subtest 6 body");
  end Subtest_6;

begin  -- Main test procedure.

  Report.Test ("C761003", "Check that an object of a controlled type "
                        & "is finalized when the enclosing master is "
                        & "complete, left by a transfer of control, "
                        & "and performed in the correct order" );

  -- adjust for optional adjusts and initializes for C761003_0.Null_Global
  TCTouch.Flush; -- clear the optional adjust
  if Sup.Inits_Called /= 1 then
    -- C761003_0.Null_Global did not get "initialized"
    C761003_0.Initialize(C761003_0.Null_Global);  -- prime the pump
  end if;

  Subtest_1;
  Sup.Validate(Subtest_1_Inits_Expected, 1);

  Subtest_2;
  Sup.Validate(Subtest_2_Inits_Expected, 2);

  Subtest_3;
  Sup.Validate(Subtest_3_Inits_Expected, 3);

  Subtest_4;
  Sup.Validate(Subtest_4_Inits_Expected, 4);

  Subtest_5;
  Sup.Validate(Subtest_5_Inits_Expected, 5, Check_Order => False);

  Subtest_6;
  Sup.Validate(Subtest_6_Inits_Expected, 6);

  Report.Result;

end C761003;
