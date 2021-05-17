

     --=================================================================--


package body FB40A00 is


   procedure Increment_AlphaNumeric_Count is
   begin
      AlphaNumeric_Count := AlphaNumeric_Count + 1;
   end Increment_AlphaNumeric_Count;


   procedure Increment_Non_AlphaNumeric_Count is
   begin
      Non_AlphaNumeric_Count := Non_AlphaNumeric_Count + 1;
   end Increment_Non_AlphaNumeric_Count;


end FB40A00;
