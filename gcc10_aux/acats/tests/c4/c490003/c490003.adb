

     --==================================================================--


with C490003_0;
with C490003_1;

with Report;
procedure C490003 is
begin
   Report.Test ("C490003", "Check that static expressions failing "          &
                "Overflow_Check are legal if part of a larger static "       &
                "expression. Check that static expressions as right "        &
                "operands of short-circuit control forms are not "           &
                "evaluated if value of control form is determined by "       &
                "left operand. Check that static expressions in non-static " &
                "contexts are evaluated exactly");


--
-- Static expressions within larger static expressions:
--


   if C490003_0.Flt_Range_Diff not in C490003_0.My_Flt'Base'Range then
      Report.Failed ("Error evaluating static expression: floating point");
   end if;

   if C490003_0.Symmetric not in Boolean'Range then
      Report.Failed ("Error evaluating static expression: fixed point");
   end if;

   if C490003_0.Center not in Integer'Base'Range then
      Report.Failed ("Error evaluating static expression: integer");
   end if;


--
-- Short-circuit control forms:
--

   declare
      N : constant := 0.0;
   begin

      begin
         if not ( (N = 0.0) or else (1.0/N > 0.5) ) then
            Report.Failed ("Error evaluating OR ELSE");
         end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Right side of OR ELSE was evaluated");
         when others           =>
            Report.Failed ("OR ELSE: unexpected exception raised");
      end;

      begin
         if (N /= 0.0) and then (1.0/N <= 0.5) then
            Report.Failed ("Error evaluating AND THEN");
         end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Right side of AND THEN was evaluated");
         when others           =>
            Report.Failed ("AND THEN: unexpected exception raised");
      end;

   end;


--
-- Exact evaluation of static expressions:
--


   declare
      use C490003_1;

      Left  : constant := 6.0 + 0.3125*( (Full*0.375) + (Half/2.4) -
                             ((Quarter + 36.0)/3.0) )/10.0;            -- 11.25
      Right : constant := (Pi/3.0) * 1.2 * (15.0/96.0);                -- Pi/16
   begin
      if Deg_To_Rad*Left /= Right then
         Report.Failed ("Static expressions not evaluated exactly: #1");
      end if;

      if ((Pi*Rad_To_Deg)*2.0 + 4.0*Quarter)/16.0 /= Rad_To_Deg*(Pi/4.0) then
         Report.Failed ("Static expressions not evaluated exactly: #2");
      end if;
   end;


   Report.Result;
end C490003;
