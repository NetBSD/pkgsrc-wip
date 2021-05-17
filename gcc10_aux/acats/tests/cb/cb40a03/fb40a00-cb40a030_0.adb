

     --=================================================================--


with FB40A00.CB40A030_1;  -- private sibling package Text_Parser.Processing;

package body FB40A00.CB40A030_0 is

   function Count_AlphaNumerics (Text : in String) return Natural is
   begin
      FB40A00.CB40A030_1.Process_Text (Text);     -- Call proc in prvt child
                                                  -- package that is a
                                                  -- sibling of this package.
      return (AlphaNumeric_Count);
      -- No exception handler here, exception propagates.
   end Count_AlphaNumerics;

end FB40A00.CB40A030_0;
