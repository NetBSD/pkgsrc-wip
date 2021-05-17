

with Report, Ada.Assertions;
with C641003_0; use C641003_0;
procedure C641003 is

   pragma Assertion_Policy (Check);

begin

   Report.Test
     ("C641003",
      "Check that, for a parameter of a scalar type with a specified " &
      "Default_Value, the value of the actual parameter is passed in " &
      "without any predicate check");

   -- First, try initialized objects:
   declare
      Is_Usable     : Boolean := False;
      The_Kind      : Typical_Status := Folded;
      The_Count     : Small_Integer := 0;
      The_Flags     : Valid_Flags := 0;
      The_Data      : Float_Natural := 0.0;
      The_Magnitude : Smaller_Fixed := 0.0;
   begin
      if Is_Usable then
          Report.Failed ("Bad initial value - A1");
      end if;         
      if The_Kind /= Folded then
          Report.Failed ("Bad initial value - A2");
      end if;         
      if The_Count /= 0 then
          Report.Failed ("Bad initial value - A3");
      end if;         
      if The_Flags /= 0 then
          Report.Failed ("Bad initial value - A4");
      end if;         
      if The_Data /= 0.0 then
          Report.Failed ("Bad initial value - A5");
      end if;         
      if The_Magnitude /= 0.0 then
          Report.Failed ("Bad initial value - A6");
      end if;         
      C641003_0.Get_Info (Is_Usable, The_Kind, The_Count, The_Flags, 
                          The_Data, The_Magnitude, Test_Case => 'A');
          -- Should not raise an exception even if buggy, all parameter values
          -- in range.
      if not Is_Usable then
          Report.Failed ("Bad result value - A1");
      end if;         
      if The_Kind /= Raw then
          Report.Failed ("Bad result value - A2");
      end if;         
      if The_Count /= 0 then
          Report.Failed ("Bad result value - A3");
      end if;         
      if The_Flags /= 16#0010# then
          Report.Failed ("Bad result value - A4");
      end if;         
      if The_Data /= 0.0 then
          Report.Failed ("Bad result value - A5");
      end if;         
      if The_Magnitude /= 0.0 then
          Report.Failed ("Bad result value - A6");
      end if;
   end;        

   -- Next, try default initialized objects with the results set:
   declare
      Is_Usable     : Boolean;
      The_Kind      : Status;
      The_Count     : Small_Integer;
      The_Flags     : Word_16;
      The_Data      : Small_Float;
      The_Magnitude : Small_Fixed;
   begin
      -- Is_Usable is not initialized at all, can't pre-test it.
      if The_Kind /= Unknown then
          Report.Failed ("Bad initial value - B2");
      end if;         
      if The_Count /= Unused then
          Report.Failed ("Bad initial value - B3");
      end if;         
      if The_Flags /= 16#DEAD# then
          Report.Failed ("Bad initial value - B4");
      end if;         
      if The_Data /= Flt_Value then
          Report.Failed ("Bad initial value - B5");
      end if;         
      if The_Magnitude /= Fix_Value then
          Report.Failed ("Bad initial value - B6");
      end if;         
      C641003_0.Get_Info (Is_Usable, The_Kind, The_Count, The_Flags, 
                          The_Data, The_Magnitude, Test_Case => 'B');
      if not Is_Usable then
          Report.Failed ("Bad result value - B1");
      end if;         
      if The_Kind /= Solved then
          Report.Failed ("Bad result value - B2");
      end if;         
      if The_Count /= 12 then
          Report.Failed ("Bad result value - B3");
      end if;         
      if The_Flags /= 16#0012# then
          Report.Failed ("Bad result value - B4");
      end if;         
      if The_Data /= 1.75 then
          Report.Failed ("Bad result value - B5");
      end if;         
      if The_Magnitude /= 0.625 then
          Report.Failed ("Bad result value - B6");
      end if;
   end;        

   -- Now, try default initialized objects with the results unchanged:
   -- Note: The defaults are outside of the parameter range, but no
   -- exception should be raised upon the call nor on the copy-back.
   declare
      Is_Usable     : Boolean;
      The_Kind      : Status;
      The_Count     : Small_Integer;
      The_Flags     : Word_16;
      The_Data      : Small_Float;
      The_Magnitude : Small_Fixed;
   begin
      -- Is_Usable is not initialized at all, can't pre-test it.
      if The_Kind /= Unknown then
          Report.Failed ("Bad initial value - C2");
      end if;         
      if The_Count /= Unused then
          Report.Failed ("Bad initial value - C3");
      end if;         
      if The_Flags /= 16#DEAD# then
          Report.Failed ("Bad initial value - C4");
      end if;         
      if The_Data /= Flt_Value then
          Report.Failed ("Bad initial value - C5");
      end if;         
      if The_Magnitude /= Fix_Value then
          Report.Failed ("Bad initial value - C6");
      end if;         
      C641003_0.Get_Info (Is_Usable, The_Kind, The_Count, The_Flags, 
                          The_Data, The_Magnitude, Test_Case => 'C');
      if Is_Usable then
          Report.Failed ("Bad result value - C1");
      end if;         
      if The_Kind /= Unknown then
          Report.Failed ("Bad result value - C2");
      end if;         
      if The_Count /= Unused then
          Report.Failed ("Bad result value - C3");
      end if;         
      if The_Flags /= 16#DEAD# then
          Report.Failed ("Bad result value - C4");
      end if;         
      if The_Data /= Flt_Value then
          Report.Failed ("Bad result value - C5");
      end if;         
      if The_Magnitude /= Fix_Value then
          Report.Failed ("Bad result value - C6");
      end if;
   end;        

   -- Now, try default initialized objects with some written and some
   -- unchanged by the call:
   -- Note: The defaults are outside of the parameter range, but no
   -- exception should be raised upon the call nor on the copy-back.
   declare
      Is_Usable     : Boolean;
      The_Kind      : Status;
      The_Count     : Small_Integer;
      The_Flags     : Word_16;
      The_Data      : Small_Float;
      The_Magnitude : Small_Fixed;
   begin
      -- Is_Usable is not initialized at all, can't pre-test it.
      if The_Kind /= Unknown then
          Report.Failed ("Bad initial value - D2");
      end if;         
      if The_Count /= Unused then
          Report.Failed ("Bad initial value - D3");
      end if;         
      if The_Flags /= 16#DEAD# then
          Report.Failed ("Bad initial value - D4");
      end if;         
      if The_Data /= Flt_Value then
          Report.Failed ("Bad initial value - D5");
      end if;         
      if The_Magnitude /= Fix_Value then
          Report.Failed ("Bad initial value - D6");
      end if;         
      C641003_0.Get_Info (Is_Usable, The_Kind, The_Count, The_Flags, 
                          The_Data, The_Magnitude, Test_Case => 'D');
      if not Is_Usable then
          Report.Failed ("Bad result value - D1");
      end if;         
      if The_Kind /= Folded then
          Report.Failed ("Bad result value - D2");
      end if;         
      if The_Count /= 4 then
          Report.Failed ("Bad result value - D3");
      end if;         
      if The_Flags /= 16#000C# then
          Report.Failed ("Bad result value - D4");
      end if;         
      if The_Data /= Flt_Value then
          Report.Failed ("Bad result value - D5");
      end if;         
      if The_Magnitude /= Fix_Value then
          Report.Failed ("Bad result value - D6");
      end if;
   end;        

   -- Now, try an object with a narrower range
   -- so that one of the results will not fit (an exception should
   -- be raised on the copy-back).
   declare
      subtype Small_Fixed_Natural is Small_Fixed 
          with Static_Predicate => Small_Fixed_Natural >= 0.0;
      Is_Usable     : Boolean;
      The_Kind      : Status;
      The_Count     : Small_Integer;
      The_Flags     : Word_16;
      The_Data      : Small_Float;
      The_Magnitude : Small_Fixed_Natural;
   begin
      -- Is_Usable is not initialized at all, can't pre-test it.
      if The_Kind /= Unknown then
          Report.Failed ("Bad initial value - E2");
      end if;         
      if The_Count /= Unused then
          Report.Failed ("Bad initial value - E3");
      end if;         
      if The_Flags /= 16#DEAD# then
          Report.Failed ("Bad initial value - E4");
      end if;         
      if The_Data /= Flt_Value then
          Report.Failed ("Bad initial value - E5");
      end if;         
      if The_Magnitude /= Fix_Value then
          Report.Failed ("Bad initial value - E6");
      end if;         
      C641003_0.Get_Info (Is_Usable, The_Kind, The_Count, The_Flags, 
                          The_Data, The_Magnitude, Test_Case => 'E');
          -- The result for The_Magnitude is out of range, Constraint_Error
          -- should be raised.
      Report.Failed ("Copy-back out of fixed range did not raise " &
                     "Assertion_Error");   
   exception
      when Ada.Assertions.Assertion_Error =>
          null; -- Expected, OK.
   end;
   
   declare
      subtype Small_Very_Positive is Small_Integer
          with Static_Predicate => Small_Very_Positive > 10;
      Is_Usable     : Boolean;
      The_Kind      : Status;
      The_Count     : Small_Very_Positive := 92;
      The_Flags     : Word_16;
      The_Data      : Small_Float;
      The_Magnitude : Small_Fixed;
   begin
      -- Is_Usable is not initialized at all, can't pre-test it.
      if The_Kind /= Unknown then
          Report.Failed ("Bad initial value - F2");
      end if;         
      if The_Count /= 92 then
          Report.Failed ("Bad initial value - F3");
      end if;         
      if The_Flags /= 16#DEAD# then
          Report.Failed ("Bad initial value - F4");
      end if;         
      if The_Data /= Flt_Value then
          Report.Failed ("Bad initial value - F5");
      end if;         
      if The_Magnitude /= Fix_Value then
          Report.Failed ("Bad initial value - F6");
      end if;         
      C641003_0.Get_Info (Is_Usable, The_Kind, The_Count, The_Flags, 
                          The_Data, The_Magnitude, Test_Case => 'F');
          -- The result for The_Count is out of range, Constraint_Error
          -- should be raised.
      Report.Failed ("Copy-back out of integer range did not raise " &
                     "Assertion_Error");   
   exception
      when Ada.Assertions.Assertion_Error =>
          null; -- Expected, OK.
   end;        

   Report.Result;

end C641003;
