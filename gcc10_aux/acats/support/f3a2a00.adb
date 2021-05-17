

     --==================================================================--


with Report;
package body F3A2A00 is

   procedure TC_Display_Results (Actual  : in TC_Result_Kind;
                                 Expected: in TC_Result_Kind;
                                 Message : in String) is
   begin
      if Actual /= Expected then
         case Actual is
            when OK  =>
               Report.Failed ("No exception raised: "         & Message);
            when P_E =>
               Report.Failed ("Program_Error raised: "        & Message);
            when O_E =>
               Report.Failed ("Unexpected exception raised: " & Message);
         end case;
      end if;
   end TC_Display_Results;

end F3A2A00;
