

     --==================================================================--

--
-- This generic procedure performs all of the testing of the
-- stack abstraction.
--

with Report;
procedure CC50A01_1 (S : in out Stacker.Stack; I : in Item_Type) is
begin
   Stacker.Push (I, S);                    -- Push onto empty stack.
   Stacker.Push (I, S);                    -- Push onto nonempty stack.

   if Stacker.Size_Of (S) /= 2 then
      Report.Failed ("   Wrong stack size after 2 Pushes");
   end if;

   -- Calls to View_Top must initialize a declared object of type Item_Type
   -- because the type may be unconstrained.

   declare
      Buffer1 : Item_Type := Stacker.View_Top (S);
   begin
      Stacker.Pop (S);                     -- Pop item off nonempty stack.
      if Buffer1 /= I then
         Report.Failed ("   Wrong stack item value after 1st Pop");
      end if;
   end;

   declare
      Buffer2 : Item_Type := Stacker.View_Top (S);
   begin
      Stacker.Pop (S);                     -- Pop last item off stack.
      if Buffer2 /= I then
         Report.Failed ("   Wrong stack item value after 2nd Pop");
      end if;
   end;

   if Stacker.Size_Of (S) /= 0 then
      Report.Failed ("   Wrong stack size after 2 Pops");
   end if;

   declare
      Buffer3 : Item_Type := Stacker.View_Top (S);
   begin
      if Buffer3 /= Default then
         Report.Failed ("   Wrong result after Pop of empty stack");
      end if;
      Stacker.Pop (S);                     -- Pop off empty stack.
   end;

end CC50A01_1;
