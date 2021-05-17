
package body F732A00 is

   pragma Assertion_Policy (Check);

   Change_Number : Natural := 0;

   function Each_Bell_Occurs_Once (Change : Change_Constrained_Type) return
     Boolean is
     (for all Bell_Number in Bell_Range_Type =>
        (for some Bell in Bell_Range_Type =>
            Change (Bell) = Bell_Number
        )
     );

   function And_Only_Once         (Change : Change_Constrained_Type) return
     Boolean is
     (not
        (for some Bell in Bell_Range_Type'First .. Bell_Range_Type'Last -1 =>
            (for some Other_Bell in Bell + 1 .. Bell_Range_Type'Last =>
               Change (Bell) = Change (Other_Bell)
            )
        )
     );

   function Rounds_With_Default_Initialisation
      return Change_Constrained_Type is

      -- Default initialisation checks the type invariant even within the
      -- package, RM 7.3.2(10/3)

      Change : Change_Constrained_Type;

   begin

      for Bell in Bell_Range_Type loop

         Change (Bell) := Bell;

      end loop;

      return Change;

   end Rounds_With_Default_Initialisation;

   function Rounds return Change_Constrained_Type is

      -- Can knowingly set to something that breaches the type invariant, but
      -- can't use default initialisation as that still checks the type
      -- invariant, RM 7.3.2(10/3) doesn't exclude within the package.

      Change : Change_Constrained_Type := (others => Bell_Range_Type'First);

   begin

      for Bell in Bell_Range_Type loop

         Change (Bell) := Bell;

      end loop;

      return Change;

   end Rounds;

   function Invalid_Change return Change_Constrained_Type is

      -- Can knowingly set to something that breaches the type invariant
      -- within the package.

      Change : constant Change_Constrained_Type :=
        (others => Bell_Range_Type'First);

   begin

      return Change;

   end Invalid_Change;

   procedure Swap_Bell_With_Following_Bell
     (Change       : in out Change_Constrained_Type;
      Bell_To_Swap : in     Swappable_Bell_Range_Type) is

      Temp : Bell_Range_Type;

   begin

      Temp := Change (Bell_To_Swap);
      Change (Bell_To_Swap) := Change (Bell_To_Swap + 1);
      Change (Bell_To_Swap + 1) := Temp;

   end Swap_Bell_With_Following_Bell;

   procedure Hunt_For_One_Change
     (Change       : in out Change_Constrained_Type;
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

   function At_Lead_End (Change : in Change_Constrained_Type) return Boolean is
     (Change (1) = 1);

   procedure Grandsire_Change (Change : in out Change_Constrained_Type) is
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
     (Change       : in out Change_Constrained_Type;
      Bell_To_Swap : in     Swappable_Bell_Range_Type) is

      Temp : Bell_Range_Type;

   begin

      Temp := Change (Bell_To_Swap);
      Change (Bell_To_Swap) := Change (Bell_To_Swap + 1);
      -- Last line of swap missing.

   end Broken_Swap_Bell_With_Following_Bell;

   procedure Invalid_Grandsire_Change (
                              Change : in out Change_Constrained_Type) is
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
    (Change        : in out Change_Constrained_Type;
     Bells_To_Swap : in     Bells_To_Swap_Type) is
   begin

      for Pair_To_Swap in 1 .. Bells_To_Swap.Number_Of_Pairs_To_Swap loop

         Swap_Bell_With_Following_Bell
          (Change       => Change,
           Bell_To_Swap => Bells_To_Swap.Pairs_To_Swap (Pair_To_Swap));

      end loop;

      Change_Number := Change_Number + 1;

   end Swap_Places;


   function Get_Concert (Kind : in Concert_Kind) return Concert_Type is
   begin
      -- Careful: we can't call any public functions or procedures if they
      -- might fail, as we're trying to check that the checks are made on
      -- the result, not on the creation of the aggregates.
      case Kind is
         when Null_Concert =>
             return N : Concert_Type (1 .. 0);
         when OK_Len_3 =>
             return O3 : Concert_Type (1 .. 3) := (others => Rounds);
         when OK_Len_6 =>
             return O6 : Concert_Type (1 .. 6) := (others => Rounds) do
                Grandsire_Change (O6(4));
             end return;
         when One_Invalid_Change_First_of_2 =>
             return OIF : Concert_Type (1 .. 2) := (Rounds, Rounds) do
                 -- We have to explicitly initialize this,
                 -- as default initialization is always checked.
                OIF(1) := (others => Bell_Range_Type'First);
             end return;
         when One_Invalid_Change_Last_of_3 =>
             return OIL : Concert_Type (1 .. 3) := (Rounds, Rounds, Rounds) do
                 -- We have to explicitly initialize this,
                 -- as default initialization is always checked.
                OIL(3) := (others => Bell_Range_Type'Last);
             end return;
         when Four_Invalid_Changes =>
             return FIC : Concert_Type (2 .. 5) := (others => (others => 2));
                 -- We have to explicitly initialize this,
                 -- as default initialization is always checked.
      end case;
   end Get_Concert;


   procedure Alter_Concert_Part (Concert : in out Concert_Type;
                                 Index   : in Natural;
                                 Kind    : in Alter_Kind) is
   begin
      if Kind = Set_Invalid then
         Concert(Index)(Bell_Range_Type'First) :=
            Concert(Index)(Bell_Range_Type'Last);
      else -- if Set_Valid
         Grandsire_Change (Concert(Index));
      end if;
   end Alter_Concert_Part;


end F732A00;

