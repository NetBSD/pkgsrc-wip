

     --=================================================================--


with FB40A00.CB40A01_0;
with Report;

procedure CB40A01 is

   String_Pointer : FB40A00.String_Pointer_Type := 
     new String'("'Twas the night before Christmas, " &
                 "and all through the house...");

begin

   Process_Block:
   begin

      Report.Test ("CB40A01", "Check that a user defined exception " &
                              "is correctly propagated out of a "    &
                              "public child package");

      FB40A00.CB40A01_0.Process_Text (String_Pointer);

      Report.Failed ("Exception should have been handled");

   exception

      when FB40A00.Completed_Text_Processing =>      -- Correct exception 
         if FB40A00.AlphaNumeric_Count /= 48 then    -- propagation.
            Report.Failed ("Incorrect string processing");
         end if;

      when others =>
         Report.Failed ("Exception handled in an others handler");

   end Process_Block;

   Report.Result;

end CB40A01;
