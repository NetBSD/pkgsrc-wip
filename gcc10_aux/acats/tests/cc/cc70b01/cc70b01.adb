

     --==================================================================--


with FC70B00;    -- Generic list abstraction.
with CC70B01_0;  -- Generic "zeroing" operation for lists of discrete types.

with Report;
procedure CC70B01 is

   type Points is range 0 .. 10;                    -- Discrete type.
   package Lists_of_Scores is new FC70B00 (Points); -- List-of-points
                                                    -- abstraction.
   Scores : Lists_of_Scores.List_Type;              -- List of points.

   procedure Reset_All_Scores is new                -- Operation on lists of
     CC70B01_0 (Points, Lists_of_Scores);           -- points.


   -- Begin test code declarations: -----------------------

   type TC_Score_Array is array (1 .. 3) of Points;

   TC_Initial_Values : constant TC_Score_Array := (2, 4, 6);
   TC_Final_Values   : constant TC_Score_Array := (0, 0, 0);

   TC_Correct_Initial_Values : Boolean := False;
   TC_Correct_Final_Values   : Boolean := False;


   procedure TC_Initialize_List (L : in out Lists_of_Scores.List_Type) is
   begin                                  -- Initial list contains 3 scores
      for I in TC_Score_Array'Range loop  -- with the values 2, 4, and 6.
         Lists_of_Scores.Add_Element (L, TC_Initial_Values(I));
      end loop;
   end TC_Initialize_List;


   procedure TC_Verify_List (L        : in out Lists_of_Scores.List_Type;
                             Expected : in     TC_Score_Array;
                             OK       :    out Boolean) is
      Actual : TC_Score_Array;
   begin                                  -- Verify that all scores have been
      Lists_of_Scores.Reset (L);          -- set to zero.
      for I in TC_Score_Array'Range loop
         Lists_of_Scores.Read_Element (L, Actual(I));
      end loop;
      OK := (Actual = Expected);
   end TC_Verify_List;

   -- End test code declarations. -------------------------


begin
   Report.Test ("CC70B01", "Check that a library-level generic subprogram "   &
                "may have a formal package as a formal parameter, and that "  &
                "the generic formal actual part may specify explicit actual " &
                "parameters. Check that a use clause is legal in the "        &
                "generic formal part");

   TC_Initialize_List (Scores);
   TC_Verify_List (Scores, TC_Initial_Values, TC_Correct_Initial_Values);

   if not TC_Correct_Initial_Values then
      Report.Failed ("List contains incorrect initial values");
   end if;

   Reset_All_Scores (Scores);
   TC_Verify_List (Scores, TC_Final_Values, TC_Correct_Final_Values);

   if not TC_Correct_Final_Values then
      Report.Failed ("List contains incorrect final values");
   end if;

   Report.Result;
end CC70B01;
