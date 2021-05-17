 
--------------------------------------------------------------------- C760009

with Report;
with C760009_1;
with C760009_2;
with C760009_3;
procedure C760009 is

  -- Comment following declaration indicates expected calls in the order:
  -- Initialize of a C760009_2 value
  -- Finalize   of a C760009_2 value
  -- Initialize of a C760009_1 value
  -- Adjust     of a C760009_1 value
  -- Finalize   of a C760009_1 value

  Global_Control : C760009_3.Master_Control;
  -- 1, 0, 1, 1, 0

  Parent_Control : C760009_2.Control;
  -- 1, 0, 1, 1, 0

  -- Global_Control is a derived tagged type, the parent type
  --   of Master_Control, Control, is derived from Controlled, and contains
  --   two components of a Controlled type, Simple_Control.  One of these
  --   components has a default value, the other does not.

  procedure Fail( Which: String; Expect, Got: Natural ) is
  begin
    Report.Failed(Which & " Expected" & Natural'Image(Expect)
                        & " got" & Natural'Image(Got) );
  end Fail;

  procedure Master_Assertion( Layer_2_Inits   : Natural;
                              Layer_2_Finals  : Natural;
                              Layer_1_Inits   : Natural;
                              Layer_1_Adjs    : Natural;
                              Layer_1_Finals  : Natural;
                              Failing_Message : String ) is

  begin



   if C760009_2.Initialized /= Layer_2_Inits then
     Fail("C760009_2.Initialize " & Failing_Message,
          Layer_2_Inits, C760009_2.Initialized );
   end if;

   if C760009_2.Finalized not in Layer_2_Finals..Layer_2_Finals*2 then
     Fail("C760009_2.Finalize " & Failing_Message,
           Layer_2_Finals, C760009_2.Finalized );
   end if;

   if C760009_1.Initialize_Called /= Layer_1_Inits then
     Fail("C760009_1.Initialize " & Failing_Message,
           Layer_1_Inits,
          C760009_1.Initialize_Called );
   end if;

   if C760009_1.Adjust_Called not in Layer_1_Adjs..Layer_1_Adjs*2 then
     Fail("C760009_1.Adjust " & Failing_Message,
           Layer_1_Adjs, C760009_1.Adjust_Called );
   end if;

   if C760009_1.Finalize_Called not in Layer_1_Finals..Layer_1_Finals*2 then
     Fail("C760009_1.Finalize " & Failing_Message,
           Layer_1_Finals, C760009_1.Finalize_Called );
   end if;

   C760009_1.Reset_Counters;
   C760009_2.Initialized := 0;
   C760009_2.Finalized   := 0;

  end Master_Assertion;

  procedure Lesser_Assertion( Layer_2_Inits   : Natural;
                              Layer_2_Finals  : Natural;
                              Layer_1_Inits   : Natural;
                              Layer_1_Adjs    : Natural;
                              Layer_1_Finals  : Natural;
                              Failing_Message : String ) is
  begin


   if C760009_2.Initialized > Layer_2_Inits then
     Fail("C760009_2.Initialize " & Failing_Message,
           Layer_2_Inits, C760009_2.Initialized );
   end if;

   if C760009_2.Finalized < Layer_2_Inits 
      or C760009_2.Finalized > Layer_2_Finals*2 then
     Fail("C760009_2.Finalize " & Failing_Message,
           Layer_2_Finals, C760009_2.Finalized );
   end if;

   if C760009_1.Initialize_Called > Layer_1_Inits then
     Fail("C760009_1.Initialize " & Failing_Message,
           Layer_1_Inits,
          C760009_1.Initialize_Called );
   end if;

   if C760009_1.Adjust_Called > Layer_1_Adjs*2 then
     Fail("C760009_1.Adjust " & Failing_Message,
           Layer_1_Adjs, C760009_1.Adjust_Called );
   end if;

   if C760009_1.Finalize_Called < Layer_1_Inits
      or C760009_1.Finalize_Called > Layer_1_Finals*2 then
     Fail("C760009_1.Finalize " & Failing_Message,
           Layer_1_Finals, C760009_1.Finalize_Called );
   end if;

   C760009_1.Reset_Counters;
   C760009_2.Initialized := 0;
   C760009_2.Finalized   := 0;

  end Lesser_Assertion;

begin  -- Main test procedure.

  Report.Test ("C760009", "Check that for an extension_aggregate whose " &
                          "ancestor_part is a subtype_mark, Initialize " &
                          "is called on all controlled subcomponents of " &
                          "the ancestor part.  Also check that the " &
                          "utilization of a controlled type for a generic " &
                          "actual parameter supports the correct behavior " &
                          "in the instantiated software" );

  C760009_1.TC_Trace( "=====> Case 0 <=====" );

  C760009_1.Reset_Counters;
  C760009_2.Initialized := 0;
  C760009_2.Finalized   := 0;

  C760009_3.Validate( Global_Control ); -- check that it Initialized correctly

  C760009_1.TC_Trace( "=====> Case 1 <=====" );

  C760009_3.Check_1.TC_Check_1( ( C760009_2.Control with Data => 1 ) );
  Lesser_Assertion( 2, 3, 2, 3, 6, "Check_1.TC_Check_1" );
  --                |  |  |  |  + Finalize 2 embedded in aggregate
  --                |  |  |  |  + Finalize 2 at assignment in TC_Check_1
  --                |  |  |  |  + Finalize 2 embedded in local variable
  --                |  |  |  + Adjust 2 caused by assignment in TC_Check_1
  --                |  |  |  + Adjust at declaration in TC_Check_1
  --                |  |  + Initialize at declaration in TC_Check_1
  --                |  |  + Initialize of aggregate object
  --                |  + Finalize of assignment target
  --                |  + Finalize of local variable
  --                |  + Finalize of aggregate object
  --               + Initialize of aggregate object
  --               + Initialize of local variable


  C760009_1.TC_Trace( "=====> Case 2 <=====" );

  C760009_3.Check_1.TC_Check_2( Global_Control );
  Master_Assertion( 1, 2, 1, 3, 4, "Check_1.TC_Check_2" );
  --                |  |  |  |  + Finalize 2 at assignment in TC_Check_2
  --                |  |  |  |  + Finalize 2 embedded in local variable
  --                |  |  |  + Adjust 2 caused by assignment in TC_Check_2
  --                |  |  |  + Adjust at declaration in TC_Check_2
  --                |  |  + Initialize at declaration in TC_Check_2
  --                |  + Finalize of assignment target
  --                |  + Finalize of local variable
  --               + Initialize of local variable


  C760009_1.TC_Trace( "=====> Case 3 <=====" );

  Global_Control := ( C760009_2.Control with Data => 2 );
  Lesser_Assertion( 1, 1, 1, 3, 2, "Aggregate -> object" );
  --                |  |  |  |  + Finalize 2 by assignment
  --                |  |  |  + Adjust 2 caused by assignment
  --                |  |  |  + Adjust in aggregate creation
  --                |  |  + Initialize of aggregate object
  --                |  + Finalize of assignment target
  --               + Initialize of aggregate object


  C760009_1.TC_Trace( "=====> Case 4 <=====" );

  C760009_3.Check_1.TC_Check_3( Global_Control );
  Master_Assertion( 1, 2, 1, 3, 4, "Check_1.TC_Check_3" );
  --                |  |  |  |  + Finalize 2 at assignment in TC_Check_3
  --                |  |  |  |  + Finalize 2 embedded in local variable
  --                |  |  |  + Adjust 2 at assignment in TC_Check_3
  --                |  |  |  + Adjust in local variable creation
  --                |  |  + Initialize of local variable in TC_Check_3
  --                |  + Finalize of assignment target
  --                |  + Finalize of local variable
  --               + Initialize of local variable


  C760009_1.TC_Trace( "=====> Case 5 <=====" );

  Global_Control := ( Parent_Control with Data => 3 );
  Lesser_Assertion( 1, 1, 1, 3, 2, "Object Aggregate -> object" );
  --                |  |  |  |  + Finalize 2 by assignment
  --                |  |  |  + Adjust 2 caused by assignment
  --                |  |  |  + Adjust in aggregate creation
  --                |  |  + Initialize of aggregate object
  --                |  + Finalize of assignment target
  --               + Initialize of aggregate object



  C760009_1.TC_Trace( "=====> Case 6 <=====" );

  -- perform this check a second time to make sure nothing is "remembered"

  C760009_3.Check_1.TC_Check_3( Global_Control );
  Master_Assertion( 1, 2, 1, 3, 4, "Check_1.TC_Check_3 second time" );
  --                |  |  |  |  + Finalize 2 at assignment in TC_Check_3
  --                |  |  |  |  + Finalize 2 embedded in local variable
  --                |  |  |  + Adjust 2 at assignment in TC_Check_3
  --                |  |  |  + Adjust in local variable creation
  --                |  |  + Initialize of local variable in TC_Check_3
  --                |  + Finalize of assignment target
  --                |  + Finalize of local variable
  --               + Initialize of local variable


  Report.Result;

end C760009;
