

     --==================================================================--


with FC70C00_0;  -- Generic list type abstraction.
with FC70C00_1;  -- Generic list operations.
with CC70C02_0;  -- Additional generic list operations.

with Report;
procedure CC70C02 is

   type Points is range 0 .. 100;                     -- Discrete type.

   package Lists_of_Points is new FC70C00_0 (Points); -- Points lists.

   package Basic_Point_Ops is new                     -- Basic points-list ops.
     FC70C00_1 (Lists_Of_Points);

   package Points_List_Ops is new                     -- More points-list ops.
     CC70C02_0 (Lists          => Lists_Of_Points,
                Basic_List_Ops => Basic_Point_Ops);

   Scores : Lists_of_Points.List_Type;                -- List of points.


   -- Begin test code declarations: -----------------------

   type TC_Score_Array is array (1 .. 3) of Points;

   TC_List_Values : constant TC_Score_Array := (23, 15,  0);

   TC_Correct_List_Values : Boolean := False;


   procedure TC_Initialize_List (L : in out Lists_Of_Points.List_Type) is
   begin                                  -- Initial list contains 3 scores
      for I in TC_Score_Array'Range loop  -- with the values 23, 15, and 0.
         Points_List_Ops.Add_Element (L, TC_List_Values(I));
      end loop;
   end TC_Initialize_List;


   procedure TC_Verify_List (L        : in out Lists_Of_Points.List_Type;
                             Expected : in     TC_Score_Array;
                             OK       :    out Boolean) is
      Actual : TC_Score_Array;
   begin
      Basic_Point_Ops.Reset (L);
      for I in TC_Score_Array'Range loop
         Points_List_Ops.Read_Element (L, Actual(I));
      end loop;
      OK := (Actual = Expected);
   end TC_Verify_List;

   -- End test code declarations. -------------------------


begin

   Report.Test ("CC70C02", "Check that a generic formal package may be " &
                "passed as an actual to another formal package");

   TC_Initialize_List (Scores);
   TC_Verify_List (Scores, TC_List_Values, TC_Correct_List_Values);

   if not TC_Correct_List_Values then
      Report.Failed ("List contains incorrect values");
   end if;

   Report.Result;

end CC70C02;
