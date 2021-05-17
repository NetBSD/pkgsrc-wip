
------------------------------------------------------------------- CC40001

with Report;
with TCTouch;
with CC40001_0.CC40001_1;
with CC40001_0.CC40001_2;
with CC40001_0.CC40001_3;
with CC40001_0.CC40001_4;
procedure CC40001 is

  function Not_Adjusted( CO : CC40001_0.Simple_Object )
    return Boolean is
     use type CC40001_0.States;
  begin
    return CO.TC_Current_State /= CC40001_0.Adjusted;
  end Not_Adjusted;

  function Not_Adjusted( CO : CC40001_0.CC40001_1.Object_In_Time )
    return Boolean is
     use type CC40001_0.States;
  begin
    return CO.TC_Current_State /= CC40001_0.Adjusted;
  end Not_Adjusted;

   -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Subtest 1

  procedure Subtest_1 is
    Object_0 : CC40001_0.Simple_Object('T');
    Object_1 : CC40001_0.CC40001_1.Object_In_Time('t');

    package Subtest_1_1 is
      new CC40001_0.CC40001_2( Object_0 ); -- classwide generic formal object

    package Subtest_1_2 is
      new CC40001_0.CC40001_2( Object_1 ); -- classwide generic formal object
  begin
    TCTouch.Flush;  -- clear out all "A" and "T" entries, no further calls
                    -- to Touch should occur before the call to Validate

    -- set the objects TC_Current_State to "Reset"
    CC40001_0.User_Operation( Object_0, "Subtest 1" );
    CC40001_0.CC40001_1.User_Operation( Object_1, "Subtest 1" );

    -- check that the objects TC_Current_State is "Adjusted"
    Subtest_1_1.TC_Verify_State;
    Subtest_1_2.TC_Verify_State;

    TCTouch.Validate( "", "No actions should occur here, subtest 1" );

  end Subtest_1;

   -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Subtest 2

  procedure Subtest_2 is
    Object_0 : CC40001_0.Simple_Object('T');
    Object_1 : CC40001_0.CC40001_1.Object_In_Time('t');

    package Subtest_2_1 is -- generic formal object is discriminated private
      new CC40001_0.CC40001_3( CC40001_0.Simple_Object,
                               Object_0,
                               Not_Adjusted );

    package Subtest_2_2 is -- generic formal object is discriminated private
      new CC40001_0.CC40001_3( CC40001_0.CC40001_1.Object_In_Time,
                               Object_1,
                               Not_Adjusted );

  begin
    TCTouch.Flush;  -- clear out all "A" and "T" entries

    -- set the objects state to "Reset"
    CC40001_0.User_Operation( Object_0, "Subtest 2" );
    CC40001_0.CC40001_1.User_Operation( Object_1, "Subtest 2" );

    Subtest_2_1.TC_Verify_State;
    Subtest_2_2.TC_Verify_State;

    TCTouch.Validate( "", "No actions should occur here, subtest 2" );

  end Subtest_2;

   -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Subtest 3

  procedure Subtest_3 is
    Object_0 : CC40001_0.Simple_Object('T');
    Object_1 : CC40001_0.CC40001_1.Object_In_Time('t');

    package Subtest_3_1 is -- generic formal object is discriminated tagged
      new CC40001_0.CC40001_4( CC40001_0.Simple_Object,
                               Object_0,
                               Not_Adjusted );

    package Subtest_3_2 is -- generic formal object is discriminated tagged
      new CC40001_0.CC40001_4( CC40001_0.CC40001_1.Object_In_Time,
                               Object_1,
                               Not_Adjusted );
  begin
    TCTouch.Flush;  -- clear out all "A" and "T" entries

    -- set the objects state to "Reset"
    CC40001_0.User_Operation( Object_0, "Subtest 3" );
    CC40001_0.CC40001_1.User_Operation( Object_1, "Subtest 3" );

    Subtest_3_1.TC_Verify_State;
    Subtest_3_2.TC_Verify_State;

    TCTouch.Validate( "", "No actions should occur here, subtest 3" );

  end Subtest_3;

begin  -- Main test procedure.

  Report.Test ("CC40001", "Check that adjust and finalize are called on " &
                          "the constant object created by the " &
                          "evaluation of a generic association for a " &
                          "formal object of mode in" );

  -- check that the created constant objects are properly adjusted
  -- and subsequently finalized

  CC40001_0.Finalization_Count := 0;

  Subtest_1;

  if CC40001_0.Finalization_Count < 4 then
    Report.Failed("Insufficient Finalizations for Subtest 1");
  end if;

  CC40001_0.Finalization_Count := 0;

  Subtest_2;

  if CC40001_0.Finalization_Count < 4 then
    Report.Failed("Insufficient Finalizations for Subtest 2");
  end if;

  CC40001_0.Finalization_Count := 0;

  Subtest_3;

  if CC40001_0.Finalization_Count < 4 then
    Report.Failed("Insufficient Finalizations for Subtest 3");
  end if;

  Report.Result;

end CC40001;
