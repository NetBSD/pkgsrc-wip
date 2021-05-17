

     --=================================================================--


with FB40A00.CB40A04_0; -- Explicit "with" of Text_Parser.Count_AlphaNumerics
with Report;            -- Implicit "with" of Text_Parser.

procedure CB40A04 is

   String_Var : String (1..19) := "The quick brown fox";

   Number_Of_AlphaNumeric_Characters : Natural := 0;

begin

   Report.Test ("CB40A04", "Check that a predefined exception is " &
                           "correctly propagated out of a public " &
                           "child function to a client");

   Process_Block:
   begin

      Number_Of_AlphaNumeric_Characters :=       -- Provide slice of string
        FB40A00.CB40A04_0 (String_Var (5..10));  -- to subprogram.
                                                           
      Report.Failed ("Exception should have been handled");

   exception

      when Constraint_Error =>                      -- Correct exception 
         null;                                      -- propagation.

      when others =>
         Report.Failed ("Exception handled in an others handler");

   end Process_Block;

   Report.Result;

end CB40A04;
