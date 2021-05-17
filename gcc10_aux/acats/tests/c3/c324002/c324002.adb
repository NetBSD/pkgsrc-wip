

with Report;
with C324002_0; use c324002_0;
with Ada.Assertions; use Ada.Assertions;
procedure C324002 is

   pragma Assertion_Policy (Check);

   subtype Max_10_Char_String is Unbounded_String
      with Dynamic_Predicate => Length (Max_10_Char_String) <= 10;

   Our_Data : array (1 .. 10) of Max_10_Char_String;
       -- Stand-in for application data structure.

begin
   Report.Test ("C324002",
                "Check predicate checks are performed for a " &
                "dynamic predicate of a by-reference type");

   begin
      Our_Data(1) := +"123456";
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate not true on assignment (1)");
   end;

   begin
      Our_Data(2) := +"123" & Our_Data(1);
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate not true on assignment (2)");
   end;

   begin
      Our_Data(3) := +"1234567890AB";
      Report.Failed ("Predicate should fail on assignment (3)");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      Our_Data(4) := +"123456" & Our_Data(1);
      Report.Failed ("Predicate should fail on assignment (4)");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      Set_Unbounded_String (Our_Data(5), "123456");
         -- Out parameter predicate check succeeds.
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate not true on Out parameter (5)");
   end;

   begin
      Set_Unbounded_String (Our_Data(6), "1234567890AB");
         -- Out parameter predicate check fails.
      Report.Failed ("Predicate should fail on Out parameter (6)");
   exception
      when Assertion_Error =>
         null; -- OK
         if Length (Our_Data(6)) /= 12 then
            Report.Failed ("Value not changed before predicate failure");
         end if;
         -- Note that there is is an oddity here in that Our_Data(6) will
         -- actually have the out-of-bounds value here, as it is changed
         -- before the predicate check. This seems necessary to be able to
         -- add a predicate to an existing type (as in this example), but it
         -- is one of the reasons that a dynamic predicate is not quite as
         -- good as a constraint.
   end;

   begin
      Our_Data(7) := +"1234";
      Append (Our_Data(7), "5678");
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate not true on In Out parameter (7)");
   end;

   begin
      Our_Data(8) := +"123456";
      Append (Our_Data(8), "7890AB");
         -- In Out parameter predicate check fails on return.
      Report.Failed ("Predicate should fail on In Out parameter (8)");
   exception
      when Assertion_Error =>
         null; -- OK
         if Length (Our_Data(8)) /= 12 then
            Report.Failed ("Value not changed before predicate failure");
         end if;
         -- See not about oddity above.
   end;

   declare
      Temp1 : Unbounded_String;
   begin
      Temp1 := +"123456" & Our_Data(1); -- No predicate to check here.
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate checked inappropriately (1)");
   end;

   declare
      Temp2 : Unbounded_String;
   begin
      Temp2 := Max_10_Char_String(Unbounded_String'(+"123456" & Our_Data(1)));
          -- Predicate checked by explicit type conversion.
      Report.Failed ("Predicate should fail from explicit " &
                     "type conversion (2)");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   -- Required by Corrigedum 2015, via AI12-0100-1.
   declare
      Temp3 : Unbounded_String;
   begin
      Temp3 := Max_10_Char_String'(+"123456" & Our_Data(1));
          -- Predicate checked by qualified expression.
      Report.Failed ("Predicate should fail from qualified expression (3)");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   Report.Result;

end C324002;
