
------------------------------------------------------------------ C760007

with Report;
with C760007_0;
procedure C760007 is

  procedure Check_Adjust_Count(Message: String;
                               Min: Natural := 1;
                               Max: Natural := 2) is
  begin

     -- in order to allow for the anonymous objects referred to in
     -- the reference manual, the check for calls to Adjust must be
     -- in a range.  This number must then be further adjusted
     -- to allow for the optimization that does not call for an adjust
     -- of an aggregate initial value built directly in the object

     if C760007_0.Adjust_Count not in Min..Max then
       Report.Failed(Message
                   & " = " & Natural'Image(C760007_0.Adjust_Count));
     end if;
     C760007_0.Adjust_Count := 0;
  end Check_Adjust_Count;

  procedure Check_Child_Adjust_Count(Message: String;
                                     Min: Natural := 1;
                                     Max: Natural := 2) is
  begin
     -- ditto above

     if C760007_0.Child_Adjust_Count not in Min..Max then
       Report.Failed(Message
                   & " = " & Natural'Image(C760007_0.Child_Adjust_Count));
     end if;
     C760007_0.Child_Adjust_Count := 0;
  end Check_Child_Adjust_Count;

  Object : C760007_0.Controlled;

--      Check that Adjust is called for the execution of a return
--      statement for a function returning a result of a (non-limited)
--      controlled type or a result of a noncontrolled type with
--      controlled components.

  procedure Subtest_1 is
    function Create return C760007_0.Controlled is
      New_Object : C760007_0.Controlled;
    begin
      return New_Object;
    end Create;

    procedure Examine( Thing : in C760007_0.Controlled ) is
    begin
      Check_Adjust_Count("Function call passed as parameter",0);
    end Examine;

  begin
    -- this assignment must call Adjust:
    --   1: on the value resulting from the function
    --      ** unless this is optimized out by building the result directly
    --         in the target object.
    --   2: on Object once it's been assigned
    -- may call adjust
    --   1: for a anonymous object created in the evaluation of the function
    --   2: for a anonymous object created in the assignment operation

    Object := Create;

    Check_Adjust_Count("Function call",1,4);

    Examine( Create );

  end Subtest_1;

--      Check that Adjust is called when evaluating an aggregate
--      component association for a controlled component.

  procedure Subtest_2 is
    S : C760007_0.Structure;

    procedure Examine( Thing : in C760007_0.Structure ) is
    begin
      Check_Adjust_Count("Aggregate passed as parameter");
    end Examine;

  begin
    -- this assignment must call Adjust:
    --   1: on the value resulting from the aggregate
    --      ** unless this is optimized out by building the result directly
    --         in the target object.
    --   2: on Object once it's been assigned
    -- may call adjust
    --   1: for a anonymous object created in the evaluation of the aggregate
    --   2: for a anonymous object created in the assignment operation
    S := ( Controlled_Component => Object );
    Check_Adjust_Count("Aggregate and Assignment", 1, 4);

    Examine( C760007_0.Structure'(Controlled_Component => Object) );
  end Subtest_2;

--      Check that Adjust is called for the assignment of the ancestor
--      expression of an extension aggregate when the type of the
--      aggregate is controlled.

  procedure Subtest_3 is
    Bambino : C760007_0.Child;

    procedure Examine( Thing : in C760007_0.Child ) is
    begin
      Check_Adjust_Count("Extension aggregate as parameter (ancestor)", 0, 2);
      Check_Child_Adjust_Count("Extension aggregate as parameter", 0, 4);
    end Examine;

  begin
    -- implementation permissions make all of the following calls to adjust
    -- optional:
    -- these assignments may call Adjust:
    --   1: on the value resulting from the aggregate
    --   2: on Object once it's been assigned
    --   3: for a anonymous object created in the evaluation of the aggregate
    --   4: for a anonymous object created in the assignment operation
    Bambino := ( Object with TC_XX => 10 );
    Check_Adjust_Count("Ancestor (expression) part of aggregate", 0, 2);
    Check_Child_Adjust_Count("Child aggregate assignment 1", 0, 4 );

    Bambino := ( C760007_0.Controlled with TC_XX => 11 );
    Check_Adjust_Count("Ancestor (subtype_mark) part of aggregate", 0, 2);
    Check_Child_Adjust_Count("Child aggregate assignment 2", 0, 4 );

    Examine( ( Object with TC_XX => 21 ) );

    Examine( ( C760007_0.Controlled with TC_XX => 37 ) );

  end Subtest_3;

begin  -- Main test procedure.

  Report.Test ("C760007", "Check that Adjust is called for the " &
                          "execution of a return statement for a " &
                          "function returning a result containing a " &
                          "controlled type.  Check that Adjust is " &
                          "called when evaluating an aggregate " &
                          "component association for a controlled " &
                          "component.  " &
                          "Check that Adjust is called for the " &
                          "assignment of the ancestor expression of an " &
                          "extension aggregate when the type of the " &
                          "aggregate is controlled" );

  Subtest_1;
  Subtest_2;
  Subtest_3;

  Report.Result;

end C760007;
