

     --==================================================================--


with Report;
package body F460A00 is

   procedure TC_Check_Results (Actual  : in TC_Result_Kind;
                               Expected: in TC_Result_Kind;
                               Message : in String) is
   begin
      if Actual /= Expected then
         case Actual is
            when OK | UN_Init  =>
               Report.Failed ("No exception raised: "         & Message);
            when PE_Exception =>
               Report.Failed ("Program_Error raised: "        & Message);
            when Others_Exception =>
               Report.Failed ("Unexpected exception raised: " & Message);
         end case;
      end if;
   end TC_Check_Results;

end F460A00;
