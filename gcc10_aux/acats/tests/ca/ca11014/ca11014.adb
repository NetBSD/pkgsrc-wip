                                                   -- Points list operation.

     --==================================================================--

with CA11014_1.CA11014_2;      -- Additional generic list operation,
                               -- implicitly with list operation.
with CA11014_3;                -- Package containing discrete type declaration.
with CA11014_4;                -- Points list.
with CA11014_5.CA11014_6;      -- Points list operation.
with Report;

procedure CA11014 is

   package Lists_Of_Scores renames CA11014_4;
   package Score_Ops renames CA11014_5;
   package Point_Ops renames CA11014_5.CA11014_6;

   Scores : Lists_Of_Scores.List_Type;                -- List of points.

   type TC_Score_Array is array (1 .. 3) of CA11014_3.Points;

   TC_Initial_Values : constant TC_Score_Array := (10, 21, 49);
   TC_Final_Values   : constant TC_Score_Array := (0, 0, 0);

   TC_Initial_Values_Are_Correct : boolean := false;
   TC_Final_Values_Are_Correct   : boolean := false;

               --------------------------------------------------

   -- Initial list contains 3 scores with the values 10, 21, and 49.
   procedure TC_Initialize_List (L : in out Lists_of_Scores.List_Type) is
   begin                                  
      for I in TC_Score_Array'range loop  
         Score_Ops.Add_Element (L, TC_Initial_Values(I));
                   -- Operation from generic parent.
      end loop;
   end TC_Initialize_List;

               --------------------------------------------------

   -- Verify that all scores have been set to zero.
   procedure TC_Verify_List (L        : in out Lists_of_Scores.List_Type;
                             Expected : in     TC_Score_Array;
                             OK       :    out boolean) is
      Actual : TC_Score_Array;
   begin                                  
      Lists_of_Scores.Reset (L);       -- Operation from parent's formal.
      for I in TC_Score_Array'range loop
         Score_Ops.Read_Element (L, Actual(I));
                   -- Operation from generic parent.
      end loop;
      OK := (Actual = Expected);
   end TC_Verify_List;

               --------------------------------------------------

begin -- CA11014 

   Report.Test ("CA11014", "Check that an instantiation of a child package " &
                           "of a generic package can use its parent's "      & 
                           "declarations and operations, including a "       &
                           "formal package of the parent");

   TC_Initialize_List (Scores);
   TC_Verify_List (Scores, TC_Initial_Values, TC_Initial_Values_Are_Correct);

   if not TC_Initial_Values_Are_Correct then
      Report.Failed ("List contains incorrect initial values");
   end if;

   Point_Ops.Write_First_To_List (Scores);
                   -- Operation from generic child package.

   TC_Verify_List (Scores, TC_Final_Values, TC_Final_Values_Are_Correct);

   if not TC_Final_Values_Are_Correct then
      Report.Failed ("List contains incorrect final values");
   end if;

   Report.Result;

end CA11014;
