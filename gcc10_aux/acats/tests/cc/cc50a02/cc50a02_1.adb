

     --==================================================================--

--
-- This generic procedure performs all of the testing of the
-- stack abstraction.
--

with Report;
procedure CC50A02_1 (S : in out Stacker.Stack; I : in Item_Type) is
begin
   Stacker.Push (I, S);                    -- Push onto empty stack.

   -- Calls to View_Top must initialize a declared object of type Item_Type
   -- because the type may be unconstrained.

   declare
      Buffer : Item_Type := Stacker.View_Top (S);
   begin
      if Buffer /= I then
         Report.Failed ("   Expected item not on stack");
      end if;
   exception
      when Constraint_Error =>
         Report.Failed ("   Unexpected error: Tags of pushed and popped " &
                        "items don't match");
   end;


exception
   when others =>
      Report.Failed ("   Unexpected error: Item not pushed onto stack");
end CC50A02_1;
