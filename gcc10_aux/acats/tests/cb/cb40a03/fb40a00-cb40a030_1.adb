

     --=================================================================--


package body  FB40A00.CB40A030_1  is

   procedure Process_Text (Text : in String) is
      Loop_Count : Integer := Text'Length + 1;
   begin
      for Pos in 1..Loop_Count loop          -- Process string, force the 
                                             -- raise of Constraint_Error. 
         if (Text (Pos) in 'a'..'z') or 
            (Text (Pos) in 'A'..'Z') or
            (Text (Pos) in '0'..'9') then
            Increment_AlphaNumeric_Count;
         else
            Increment_Non_AlphaNumeric_Count;
         end if;

      end loop;
      -- No exception handler here, exception propagates.
   end Process_Text;

end FB40A00.CB40A030_1;  
