

     --==================================================================--


with FC70B00;    -- Generic list abstraction.
with CC70B02_0;  -- Generic discrete type operations.
with CC70B02_1;  -- Generic discrete list operations.

with Report;
procedure CC70B02 is

   type Points is range 0 .. 100;                   -- Discrete type.

   package Points_Ops is new CC70B02_0 (Points);    -- Points-type operations.
   package Lists_of_Points is new FC70B00 (Points); -- Points lists.
   package Points_List_Ops is new                   -- Points-list operations.
     CC70B02_1 (Points_Ops, Lists_Of_Points);
      
   Scores : Lists_of_Points.List_Type;              -- List of points.


   -- Begin test code declarations: -----------------------

   type TC_Score_Array is array (1 .. 3) of Points;

   TC_Initial_Values : constant TC_Score_Array := (23, 15,  0);
   TC_Final_Values   : constant TC_Score_Array := (46, 30,  0);

   TC_Correct_Initial_Values : Boolean := False;
   TC_Correct_Final_Values   : Boolean := False;


   procedure TC_Initialize_List (L : in out Lists_Of_Points.List_Type) is
   begin                                  -- Initial list contains 3 scores
      for I in TC_Score_Array'Range loop  -- with the values 23, 15, and 0.
         Lists_Of_Points.Add_Element (L, TC_Initial_Values(I));
      end loop;
   end TC_Initialize_List;


   procedure TC_Verify_List (L        : in out Lists_Of_Points.List_Type;
                             Expected : in     TC_Score_Array;
                             OK       :    out Boolean) is
      Actual : TC_Score_Array;
   begin                                  -- Verify that all scores have been
      Lists_Of_Points.Reset (L);          -- set to zero.
      for I in TC_Score_Array'Range loop
         Lists_Of_Points.Read_Element (L, Actual(I));
      end loop;
      OK := (Actual = Expected);
   end TC_Verify_List;

   -- End test code declarations. -------------------------


begin
   Report.Test ("CC70B02", "Check that a library-level generic package "      &
                "may have a formal package as a formal parameter, and that "  &
                "the generic formal actual part may specify explicit actual " &
                "parameters (including a formal parameter of a previously "   &
                "declared formal package). Check that a use clause is legal " &
                "in the generic formal part");

   TC_Initialize_List (Scores);
   TC_Verify_List (Scores, TC_Initial_Values, TC_Correct_Initial_Values);

   if not TC_Correct_Initial_Values then
      Report.Failed ("List contains incorrect initial values");
   end if;

   Points_List_Ops.Double_List (Scores);
   TC_Verify_List (Scores, TC_Final_Values, TC_Correct_Final_Values);

   if not TC_Correct_Final_Values then
      Report.Failed ("List contains incorrect final values");
   end if;

   Report.Result;
end CC70B02;
