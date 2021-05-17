

     --==================================================================--


with CC70001_2;            -- Generic "zeroing" op for lists of discrete types.
with CC70001_3;            -- Types for application.
with CC70001_4.CC70001_5;  -- Discrete list abstraction + additional ops.

with Report;
procedure CC70001 is

   package Lists_Of_Scores renames CC70001_4;
   package Score_Ops       renames CC70001_4.CC70001_5;

   Scores : Lists_Of_Scores.List_Type;                -- List of points.

   procedure Reset_All_Scores is new CC70001_2        -- Operation on lists of
     (Elem_Type => CC70001_3.Points,                  -- points.
      List_Mgr  => Lists_Of_Scores,
      List_Ops  => Score_Ops);


   -- Begin test code declarations: -----------------------

   type TC_Score_Array is array (1 .. 3) of CC70001_3.Points;

   TC_Initial_Values : constant TC_Score_Array := (2, 4, 6);
   TC_Final_Values   : constant TC_Score_Array := (0, 0, 0);

   TC_Correct_Initial_Values : Boolean := False;
   TC_Correct_Final_Values   : Boolean := False;


   procedure TC_Initialize_List (L : in out Lists_of_Scores.List_Type) is
   begin                                  -- Initial list contains 3 scores
      for I in TC_Score_Array'Range loop  -- with the values 2, 4, and 6.
         Score_Ops.Add_Element (L, TC_Initial_Values(I));
      end loop;
   end TC_Initialize_List;


   procedure TC_Verify_List (L        : in out Lists_of_Scores.List_Type;
                             Expected : in     TC_Score_Array;
                             OK       :    out Boolean) is
      Actual : TC_Score_Array;
   begin                                  -- Verify that all scores have been
      Lists_of_Scores.Reset (L);          -- set to zero.
      for I in TC_Score_Array'Range loop
         Score_Ops.Read_Element (L, Actual(I));
      end loop;
      OK := (Actual = Expected);
   end TC_Verify_List;

   -- End test code declarations. -------------------------


begin
   Report.Test ("CC70001", "Check that the template for a generic formal "   &
                "package may be a child package, and that a child instance " &
                "which is an instance of the template may be passed as an "  &
                "actual to the formal package. Check that the visible part " &
                "of the generic formal package includes the first list of "  &
                "basic declarative items of the package specification");

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
end CC70001;
