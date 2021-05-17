
---

package body FXA5A00 is


   function Result_Within_Range (Result          : Float;
                                 Expected_Result : Float;
                                 Relative_Error  : Float) return Boolean is
   begin
      return (Result <= Expected_Result + Relative_Error) and 
             (Result >= Expected_Result - Relative_Error);
   end Result_Within_Range;


   function Result_Within_Range (Result          : New_Float;
                                 Expected_Result : Float;
                                 Relative_Error  : Float) return Boolean is
   begin
      return (Float(Result) <= Expected_Result + Relative_Error) and 
             (Float(Result) >= Expected_Result - Relative_Error);
   end Result_Within_Range;


   procedure Dont_Optimize (Check_Result : Eval_Type; 
                            Num          : Integer) is
   begin
      -- Note that the use of Minus_Large here is simply as a "dummy" value,
      -- designed to indicate use of the Check_Result parameter, and has no
      -- pass/fail significance to any test using this procedure.
      --
      if Float(Check_Result) = Minus_Large then
         Report.Comment("Attempted Defeat of Optimization ONLY -- Not " &
                        "a cause for test failure! "                    & 
                        "Result = Minus_Large, Case:" & Integer'Image(Num));
      end if;
   end Dont_Optimize;

end FXA5A00;
