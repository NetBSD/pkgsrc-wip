
with Report;

package body F732B00 is

   pragma Assertion_Policy (Check);

   Change_Number : Natural := 0;

   function Each_Bell_Occurs_Once (Change : Change_Discriminated_Type) return
     Boolean is
     (for all Bell_Number in 1 .. Change.No_Of_Bells =>
        (for some Bell in 1 .. Change.No_Of_Bells =>
            Change.Change (Bell) = Bell_Number
        )
     );

   function And_Only_Once         (Change : Change_Discriminated_Type) return
     Boolean is
     (not
        (for some Bell in 1 .. Change.No_Of_Bells -1 =>
            (for some Other_Bell in Bell + 1 .. Change.No_Of_Bells =>
               Change.Change (Bell) = Change.Change (Other_Bell)
            )
        )
     );

   function Rounds_With_Default_Initialisation
      return Change_Discriminated_Type is

      -- Default initialisation checks the type invariant even within the
      -- package, RM 7.3.2(10/3)

      Change : Change_Discriminated_Type (No_Of_Bells);

   begin

      for Bell in 1 .. Change.No_Of_Bells loop

         Change.Change (Bell) := Bell;

      end loop;

      return Change;

   end Rounds_With_Default_Initialisation;

   function Rounds return Change_Discriminated_Type is

      -- Can knowingly set to something that breaches the type invariant, but
      -- can't use default initialisation as that still checks the type
      -- invariant, RM 7.3.2(10/3) doesn't exclude within the package.

      Change : Change_Discriminated_Type :=
                            (No_Of_Bells => No_Of_Bells,
                             Change      => (others => Bell_Range_Type'First));

   begin

      for Bell in 1 .. Change.No_Of_Bells loop

         Change.Change (Bell) := Bell;

      end loop;

      return Change;

   end Rounds;

   function Invalid_Change return Change_Discriminated_Type is

      -- Can knowingly set to something that breaches the type invariant
      -- within the package.

      Change : constant Change_Discriminated_Type :=
                            (No_Of_Bells => No_Of_Bells,
                             Change      => (others => Bell_Range_Type'First));

   begin

      return Change;

   end Invalid_Change;

   procedure Print_Change (Change : Change_Discriminated_Type) is
     Result : String (1 .. Natural(Change.No_Of_Bells*3));
   begin

      for Place in 1 .. Change.No_Of_Bells loop

         if Change.Change (Place) < 10 then
            Result (Natural(Place*3-2)) := ' ';
            Result (Natural(Place*3-1)) :=
               Character'Val(Change.Change (Place) + Character'Pos('0'));
         else
            Result (Natural(Place*3-2)) := '1';
            Result (Natural(Place*3-1)) :=
               Character'Val(Change.Change (Place) - 10 + Character'Pos('0'));
         end if;
         Result (Natural(Place*3)) := ' ';

      end loop;

      Report.Comment ("Change: " & Result);

   end Print_Change;

   procedure Swap_Bell_With_Following_Bell
     (Change       : in out Change_Discriminated_Type;
      Bell_To_Swap : in     Swappable_Bell_Range_Type) is

      Temp : Bell_Range_Type;

   begin

      Temp := Change.Change (Bell_To_Swap);
      Change.Change (Bell_To_Swap) := Change.Change (Bell_To_Swap + 1);
      Change.Change (Bell_To_Swap + 1) := Temp;

   end Swap_Bell_With_Following_Bell;

   procedure Hunt_For_One_Change
     (Change       : in out Change_Discriminated_Type;
      Tenor_Behind : in     Boolean := True) is

      Hunt_On_How_Many : constant Bell_Range_Type :=
                       (if Tenor_Behind then No_Of_Bells - 1 else No_Of_Bells);

   begin

      -- If Even Change_Number
      if Change_Number mod 2 = 0 then

         for Place in 1 .. Hunt_On_How_Many - 1 loop

            -- If Odd Place
            if Place mod 2 = 1 then

               Swap_Bell_With_Following_Bell
                (Change       => Change,
                 Bell_To_Swap => Place);

            end if;

         end loop;

      else -- Odd Change_Number

         for Place in 1 .. Hunt_On_How_Many - 1 loop

            -- If Even Place
            if Place mod 2 = 0 then

               Swap_Bell_With_Following_Bell
                (Change       => Change,
                 Bell_To_Swap => Place);

            end if;

         end loop;

      end if;

      Change_Number := Change_Number + 1;

   end Hunt_For_One_Change;

   function At_Lead_End (Change : in Change_Discriminated_Type) return Boolean
     is
      (Change.Change (1) = 1);

   procedure Grandsire_Change (Change : in out Change_Discriminated_Type) is
   begin

      Swap_Bell_With_Following_Bell
        (Change       => Change,
         Bell_To_Swap => 1);

      for Place in Bell_Range_Type range 4 .. No_Of_Bells - 1 loop

         if Place mod 2 = 0 then

            Swap_Bell_With_Following_Bell
             (Change       => Change,
              Bell_To_Swap => Place);

         end if;

      end loop;

      Change_Number := Change_Number + 1;

   end Grandsire_Change;

   procedure Broken_Swap_Bell_With_Following_Bell
     (Change       : in out Change_Discriminated_Type;
      Bell_To_Swap : in     Swappable_Bell_Range_Type) is

      Temp : Bell_Range_Type;

   begin

      Temp := Change.Change (Bell_To_Swap);
      Change.Change (Bell_To_Swap) := Change.Change (Bell_To_Swap + 1);
      -- Last line of swap missing.

   end Broken_Swap_Bell_With_Following_Bell;

   procedure Invalid_Grandsire_Change
     (Change : in out Change_Discriminated_Type) is
      -- A routine that uses a buggy Swap routine to make a mess.
      -- Note that the local broken swap does NOT check the invariant after
      -- each call; if we cleaned up the mess before the end of this routine,
      -- there would be no problem.
   begin

      Broken_Swap_Bell_With_Following_Bell
        (Change       => Change,
         Bell_To_Swap => 1);

      for Place in Bell_Range_Type range 4 .. No_Of_Bells - 1 loop

         if Place mod 2 = 0 then

            Broken_Swap_Bell_With_Following_Bell
             (Change       => Change,
              Bell_To_Swap => Place);

         end if;

      end loop;

      Change_Number := Change_Number + 1;

   end Invalid_Grandsire_Change;

   function Swaps_Dont_Overlap (Bells_To_Swap : in Bells_To_Swap_Type) return
     Boolean is
     (for all Pair_To_Swap in 1 .. Bells_To_Swap.Number_Of_Pairs_To_Swap - 1 =>
         Bells_To_Swap.Pairs_To_Swap (Pair_To_Swap + 1) >=
         Bells_To_Swap.Pairs_To_Swap (Pair_To_Swap) + 2
     );

   procedure Swap_Places
    (Change        : in out Change_Discriminated_Type;
     Bells_To_Swap : in     Bells_To_Swap_Type) is
   begin

      for Pair_To_Swap in 1 .. Bells_To_Swap.Number_Of_Pairs_To_Swap loop

         Swap_Bell_With_Following_Bell
          (Change       => Change,
           Bell_To_Swap => Bells_To_Swap.Pairs_To_Swap (Pair_To_Swap));

      end loop;

      Change_Number := Change_Number + 1;

   end Swap_Places;


   procedure Reset_Change (Change : not null access Change_Discriminated_Type;
                           Kind   : in Change_Kind) is
      -- Adjust Change as specified by Kind.
   begin
      if Kind = Valid then
         Change.all := Rounds;
      else -- Kind = Invalid then
         -- Note: We can't call a public routine here, or that would make
         -- and fail the invariant check and we would not test our objectives.
         Change.Change := (others => Bell_Range_Type'First);
      end if;
   end Reset_Change;

   Temp : aliased Change_Discriminated_Type (No_Of_Bells) :=
       Rounds; -- Have to initialize, else will fail invariant check.

   function Get_Change (Change : Access_to_Change;
                        Kind   : in Get_Change_Kind) return Access_to_Change is
      -- Get a Change value, what happens depends on Kind.
   begin
      if Kind = Param_Invalid then
         -- Note: We can't call a public routine here, or that would make
         -- and fail the invariant check and we would not test our objectives.
         Change.Change := (others => Bell_Range_Type'First);
         return null;
      elsif Kind = Result_Invalid then
         -- See note above.
         Temp.Change := (others => Bell_Range_Type'Last);
         return Temp'Access;
      elsif Kind = Result_is_Param then
         return Change;
      else --if Kind = Result_Other_Valid then
         Temp.Change := Rounds.Change;
         return Temp'Access;
      end if;
   end Get_Change;

   function Create_Change (Kind : in Change_Kind)
      return not null access Change_Discriminated_Type is
      -- Create a Change value as specified by Kind.
   begin
      if Kind = Valid then
         Temp.Change := Rounds.Change;
         return Temp'Access;
      else -- Kind = Invalid then
         -- Note: We can't call a public routine here, or that would make
         -- and fail the invariant check and we would not test our objectives.
         Temp.Change := (others => Bell_Range_Type'Last);
         return Temp'Access;
      end if;
   end Create_Change;

end F732B00;
