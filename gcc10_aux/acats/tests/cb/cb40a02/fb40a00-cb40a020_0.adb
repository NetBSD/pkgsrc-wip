

     --=================================================================--


with FB40A00.CB40A020_0.CB40A020_1;   -- "with" of  private child subprogram
                                      -- Text_Parser.Processing.Process_Text 
package body FB40A00.CB40A020_0 is

   function Count_AlphaNumerics (Text : in String) return Natural is
   begin
      FB40A00.CB40A020_0.CB40A020_1 (Text);  -- Call prvt child proc.
      return (AlphaNumeric_Count);           -- Global maintained in parent.
      -- No exception handler here, exception propagates.
   end Count_AlphaNumerics;

end FB40A00.CB40A020_0;
