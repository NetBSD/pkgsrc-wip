


with CXA40120;
with Ada.Characters.Handling;
with Ada.Strings.Wide_Maps;
with Report;

procedure CXA4012 is

   use CXA40120;
   use Ada.Strings;

begin

   Report.Test ("CXA4012", "Check that the types, operations, and other " &
                           "entities defined within the package "         &
                           "Ada.Strings.Wide_Maps are available and "     &
                           "produce correct results");

   Test_Block:
   declare

      use type Wide_Maps.Wide_Character_Set;
  
      MidPoint_Letter  : constant := 13;
      Last_Letter      : constant := 26;

      Vowels           : constant Wide_Maps.Wide_Character_Sequence := 
                           Equiv("aeiou");
      Quasi_Vowel      : constant Wide_Character := Equiv('y');

      Alphabet         : Wide_Maps.Wide_Character_Sequence(1..Last_Letter);
      Half_Alphabet    : Wide_Maps.Wide_Character_Sequence(1..MidPoint_Letter);
      Inverse_Alphabet : Wide_Maps.Wide_Character_Sequence(1..Last_Letter);

      Alphabet_Set,
      Consonant_Set,
      Vowel_Set,
      Full_Vowel_Set,
      First_Half_Set,
      Second_Half_Set : Wide_Maps.Wide_Character_Set := Wide_Maps.Null_Set;

   begin

      -- Load the alphabet string for use in creating sets.

      for i in 0..MidPoint_Letter-1 loop
         Half_Alphabet(i+1) := 
           Wide_Character'Val(Wide_Character'Pos(Equiv('a')) + i);
      end loop;

      for i in 0..Last_Letter-1 loop
         Alphabet(i+1) := 
           Wide_Character'Val(Wide_Character'Pos(Equiv('a')) + i);
      end loop;


      -- Initialize a series of Wide_Character_Set objects.
      
      Alphabet_Set    := Wide_Maps.To_Set(Alphabet);
      Vowel_Set       := Wide_Maps.To_Set(Vowels);
      Full_Vowel_Set  := Vowel_Set   OR  Wide_Maps.To_Set(Quasi_Vowel);
      Consonant_Set   := Vowel_Set  XOR  Alphabet_Set;

      First_Half_Set  := Wide_Maps.To_Set(Half_Alphabet);
      Second_Half_Set := Alphabet_Set  XOR  First_Half_Set;


      -- Evaluation of Set objects, operators, and functions.

      if Alphabet_Set /= (Vowel_Set OR Consonant_Set) then
         Report.Failed("Incorrect set combinations using OR operator");
      end if;


      for i in Vowels'First .. Vowels'Last loop
         if not Wide_Maps.Is_In(Vowels(i), Vowel_Set)    or
            not Wide_Maps.Is_In(Vowels(i), Alphabet_Set) or
            Wide_Maps.Is_In(Vowels(i), Consonant_Set) 
         then
            Report.Failed("Incorrect function Is_In use with set " &
                          "combinations - " & Integer'Image(i));
         end if;
      end loop;


      if Wide_Maps.Is_Subset(Vowel_Set, First_Half_Set)    or
         Wide_Maps."<="(Vowel_Set, Second_Half_Set)        or
         not Wide_Maps.Is_Subset(Vowel_Set, Alphabet_Set)
      then
         Report.Failed
           ("Incorrect set evaluation using Is_Subset function");
      end if;

     
      if not (Full_Vowel_Set = Wide_Maps.To_Set(Equiv("aeiouy"))) then
         Report.Failed("Incorrect result for ""="" set operator");
      end if;


      if not ((Vowel_Set AND First_Half_Set) OR 
              (Full_Vowel_Set AND Second_Half_Set)) = Full_Vowel_Set then
         Report.Failed
           ("Incorrect result for AND, OR, or ""="" set operators");
      end if;


      if (Alphabet_Set AND Wide_Maps.Null_Set) /= Wide_Maps.Null_Set  or
         (Alphabet_Set OR  Wide_Maps.Null_Set) /= Alphabet_Set
      then
         Report.Failed("Incorrect result for AND or OR set operators");
      end if;


      Vowel_Set := Full_Vowel_Set;
      Vowel_Set := Vowel_Set AND (NOT Wide_Maps.To_Set(Quasi_Vowel));
      
      if not (Vowels = Wide_Maps.To_Sequence(Vowel_Set)) then
         Report.Failed("Incorrect Set to Sequence translation");
      end if;

      
      for i in 0..Last_Letter-1 loop
         Inverse_Alphabet(i+1) := Alphabet(Last_Letter-i);
      end loop;


      -- Wide_Character_Mapping

      declare
         Inverse_Map : Wide_Maps.Wide_Character_Mapping :=
                         Wide_Maps.To_Mapping(Alphabet, Inverse_Alphabet);
      begin
         if Wide_Maps.Value(Wide_Maps.Identity, Equiv('b')) /= 
            Wide_Maps.Value(Inverse_Map, Equiv('y'))       
         then
            Report.Failed("Incorrect Inverse mapping");
         end if;
      end;


      -- Check that Translation_Error is raised when a character is
      -- repeated in the parameter "From" string.
      declare
         Bad_Map : Wide_Maps.Wide_Character_Mapping;
      begin
         Bad_Map := Wide_Maps.To_Mapping(From => Equiv("aa"), 
                                         To   => Equiv("yz"));
         Report.Failed("Exception not raised with repeated character");
      exception
         when Translation_Error => null;  -- OK
         when others            => 
            Report.Failed("Incorrect exception raised in To_Mapping with " &
                          "a repeated character");
      end;


      -- Check that Translation_Error is raised when the parameters of the
      -- function To_Mapping are of unequal lengths.
      declare
         Bad_Map : Wide_Maps.Wide_Character_Mapping;
      begin
         Bad_Map := Wide_Maps.To_Mapping(Equiv("abc"), Equiv("yz"));
         Report.Failed
           ("Exception not raised with unequal parameter lengths");
      exception
         when Translation_Error => null;  -- OK
         when others            => 
            Report.Failed("Incorrect exception raised in To_Mapping with " &
                          "unequal parameter lengths");
      end;


      -- Check that the access-to-subprogram type is defined and available.
      -- This provides for one Wide_Character mapping capability only.
      -- The actual mapping functionality will be tested in conjunction with
      -- the tests of subprograms defined for Wide_String handling.

      declare

         X_Map_Ptr : Wide_Maps.Wide_Character_Mapping_Function := 
                       X_Map'Access;

      begin
         if X_Map_Ptr(Equiv('A')) /=    -- both return 'X'
            X_Map_Ptr.all(Equiv('Q')) 
         then  
            Report.Failed
              ("Incorrect result using access-to-subprogram values");
         end if;
      end;


   exception
      when others => Report.Failed ("Exception raised in Test_Block");
   end Test_Block;


   Report.Result;

end CXA4012;
