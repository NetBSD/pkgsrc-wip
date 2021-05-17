 
--------------------------------------------------------------------- C760012

with Report;
with TCTouch;
with C760012_0;
procedure C760012 is

  use type C760012_0.List;

  procedure Subtest_1 is
  -- by 3.8(18);6.0 One_Of_Them is constrained by per-object constraints
  -- 7.6.1(9);6.0 dictates the order of finalization of the components

    One_Of_Them : C760012_0.List_Item;
  begin
    if One_Of_Them.Next /= null then  -- just to hold the subtest in place
      Report.Failed("No default value for Next");
    end if;
  end Subtest_1;

  List : C760012_0.List;

  procedure Subtest_2 is
  begin

    List := new C760012_0.List_Item;

    List.Next := new C760012_0.List_Item;

  end Subtest_2;

  procedure Subtest_3 is
  begin

    C760012_0.Deallocate( List.Next );

    C760012_0.Deallocate( List );

  end Subtest_3;
  
begin  -- Main test procedure.

  Report.Test ("C760012", "Check that record components that have " &
                          "per-object access discriminant constraints " &
                          "are initialized in the order of their " &
                          "component declarations, and after any " &
                          "components that are not so constrained.  " &
                          "Check that record components that have " &
                          "per-object access discriminant constraints " &
                          "are finalized in the reverse order of their " &
                          "component declarations, and before any " &
                          "components that are not so constrained" );

  Subtest_1;
  TCTouch.Validate("AACDFQRSTT", "One object");

  Subtest_2;
  TCTouch.Validate("AACDFAACDF", "Two objects dynamically allocated");

  Subtest_3;
  TCTouch.Validate("QRSTTQRSTT", "Two objects deallocated");

  Report.Result;

end C760012;
