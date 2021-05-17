
     --==================================================================--

with CA13001_0;
with CA13001_1.CA13001_5;        -- Implicitly with parent, CA13001_1.
with Report;

procedure CA13001 is

   Mommy           : CA13001_0.Family := CA13001_0.Mother;
   Daddy           : CA13001_0.Family := CA13001_0.Father;
   BG              : CA13001_0.Family := CA13001_0.Teen;
   BG_Clunker      : CA13001_1.Transportation := CA13001_1.Clunker;
   Get_Key         : CA13001_1.Key_Type;
   Get_Transit     : boolean := false;
   Return_Transit  : boolean := false;

begin 
   Report.Test ("CA13001", "Check that a protected subunit declared in " & 
                "a child unit of a private parent have the same visibility " &
                "into its parent, its parent's siblings, and packages on " &
                "which its parent depends");

   -- Get transportation for mother to go to work.
   CA13001_0.Destination(CA13001_0.Mother) := CA13001_0.Work;
   CA13001_1.CA13001_5.Provide_Transportation (Mommy, Get_Key, Get_Transit);
   if not Get_Transit then
      Report.Failed ("Failed to get mother transportation");
   end if;

   -- Get transportation for teen to go to school.
   CA13001_0.Destination(CA13001_0.Teen) := CA13001_0.School;
   Get_Transit := false;
   CA13001_1.CA13001_5.Provide_Transportation (BG, Get_Key, Get_Transit);
   if not Get_Transit then
      Report.Failed ("Failed to get teen transportation");
   end if;

   -- Get transportation for father to go to the beach.
   CA13001_0.Destination(CA13001_0.Father) := CA13001_0.Beach;
   Get_Transit := false;
   CA13001_1.CA13001_5.Provide_Transportation (Daddy, Get_Key, Get_Transit);
   if Get_Transit and not CA13001_1.Walking then
      Report.Failed ("Failed to make daddy to walk to the beach");
   end if;

   -- Return the clunker.
   CA13001_1.CA13001_5.Return_Transportation (BG_Clunker, Return_Transit);
   if not Return_Transit then
      Report.Failed ("Failed to get back the clunker");
   end if;

   Report.Result;

end CA13001;
