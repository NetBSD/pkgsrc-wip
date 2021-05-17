
-----------------------------------------------------------------------------
with Report;
with TCTouch;
with C761005_0;
with C761005_2;
with C761005_Support;
procedure C761005 is

  package Sup renames C761005_Support;

  Subtest_1_Inits_Expected : constant := 4;
  procedure Subtest_1 is
    Item_1 : C761005_0.Final_Root(Sup.Pick_Char);
    Item_2, Item_3 : C761005_0.Final_Root(Sup.Pick_Char);
    Item_4 : C761005_0.Ltd_Final_Root(Sup.Pick_Char);
  begin
    -- check that nothing has happened yet!
    TCTouch.Validate("","Subtest 1 body");
  end Subtest_1;

  -- These declarations should cause calls to initialize and
  -- finalize.  The expected operations are the subprograms associated
  -- with the abstract types.
  Subtest_2_Inits_Expected : constant := 4;
  procedure Subtest_2 is
    Item_1 : C761005_2.Final_Child;
    Item_2, Item_3 : C761005_2.Final_Child;
    Item_4 : C761005_2.Ltd_Final_Child;
  begin
    -- check that nothing has happened yet!
    TCTouch.Validate("","Subtest 2 body");
  end Subtest_2;

begin  -- Main test procedure.

  Report.Test ("C761005", "Check that an object of a controlled type "
                        & "is finalized when the enclosing master is "
                        & "complete, left by a transfer of control, "
                        & "and performed in the correct order" );

  Subtest_1;
  Sup.Validate(Subtest_1_Inits_Expected,1); 
  
  Subtest_2;
  Sup.Validate(Subtest_2_Inits_Expected,2);

  Report.Result;

end C761005;
