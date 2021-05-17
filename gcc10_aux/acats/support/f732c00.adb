
package body F732C00 is

   pragma Assertion_Policy (Check);

   Change_Number : Natural := 0;

   function Each_Bell_Occurs_Once (Change : Change_Tagged_Type) return
     Boolean is
     (for all Bell_Number in Bell_Range_Type =>
        (for some Bell in Bell_Range_Type =>
            Change.Data (Bell) = Bell_Number
        )
     );

   function And_Only_Once         (Change : Change_Tagged_Type) return
     Boolean is
     (not
        (for some Bell in Bell_Range_Type'First .. Bell_Range_Type'Last -1 =>
            (for some Other_Bell in Bell + 1 .. Bell_Range_Type'Last =>
               Change.Data (Bell) = Change.Data (Other_Bell)
            )
        )
     );

   function Rounds return Change_Tagged_Type is

      -- RM 7.3.2(10/4) allows default initialization to an invalid value
      -- as the partial view has unknown discriminants.

      Change : Change_Tagged_Type;

   begin

      for Bell in Bell_Range_Type loop

         Change.Data (Bell) := Bell;

      end loop;

      return Change;

   end Rounds;

   function Invalid_Change return Change_Tagged_Type is

      -- Can knowingly set to something that breaches the type invariant
      -- within the package.

      Change : constant Change_Tagged_Type :=
        (Data => (others => Bell_Range_Type'First));

   begin

      return Change;

   end Invalid_Change;

   procedure Swap_Bell_With_Following_Bell
     (Change       : in out Change_Tagged_Type;
      Bell_To_Swap : in     Swappable_Bell_Range_Type) is

      Temp : Bell_Range_Type;

   begin

      Temp := Change.Data (Bell_To_Swap);
      Change.Data (Bell_To_Swap) := Change.Data (Bell_To_Swap + 1);
      Change.Data (Bell_To_Swap + 1) := Temp;

   end Swap_Bell_With_Following_Bell;

   procedure Hunt_For_One_Change
     (Change       : in out Change_Tagged_Type;
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

   function At_Lead_End (Change : in Change_Tagged_Type) return Boolean is
     (Change.Data (1) = 1);

   procedure Grandsire_Change (Change : in out Change_Tagged_Type) is
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
     (Change       : in out Change_Tagged_Type;
      Bell_To_Swap : in     Swappable_Bell_Range_Type) is

      Temp : Bell_Range_Type;

   begin

      Temp := Change.Data (Bell_To_Swap);
      Change.Data (Bell_To_Swap) := Change.Data (Bell_To_Swap + 1);
      -- Last line of swap missing.

   end Broken_Swap_Bell_With_Following_Bell;

   procedure Broken_Grandsire_Change (Change : in out Change_Tagged_Type) is
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

   end Broken_Grandsire_Change;

   function Swaps_Dont_Overlap (Bells_To_Swap : in Bells_To_Swap_Type) return
     Boolean is
     (for all Pair_To_Swap in 1 .. Bells_To_Swap.Number_Of_Pairs_To_Swap - 1 =>
         Bells_To_Swap.Pairs_To_Swap (Pair_To_Swap + 1) >=
         Bells_To_Swap.Pairs_To_Swap (Pair_To_Swap) + 2
     );

   procedure Swap_Places
    (Change        : in out Change_Tagged_Type;
     Bells_To_Swap : in     Bells_To_Swap_Type) is
   begin

      for Pair_To_Swap in 1 .. Bells_To_Swap.Number_Of_Pairs_To_Swap loop

         Swap_Bell_With_Following_Bell
          (Change       => Change,
           Bell_To_Swap => Bells_To_Swap.Pairs_To_Swap (Pair_To_Swap));

      end loop;

      Change_Number := Change_Number + 1;

   end Swap_Places;

end F732C00;

