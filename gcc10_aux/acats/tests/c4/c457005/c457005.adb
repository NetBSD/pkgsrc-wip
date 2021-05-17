
with Report;
with C457005_0; use C457005_0;
with Ada.Assertions; use Ada.Assertions;
procedure C457005 is

   -- Note: the assertion policy in this unit is irrelevant - 3.2.4(8-11/3)
   -- apply. A different test will check that explicitly, but we don't need
   -- to set the policy here.

   X1 : RGB := Green;

   X2 : Other_Color := Violet;

   Prime_Var : Prime := 5;

   Even_Var_1 : Small_Even := Small_Even(Report.Ident_Int(4));

   Even_Var_2 : Small_Even := Small_Even(Report.Ident_Int(10));

   procedure Check (Evaled, Expected : Natural; Tag : String) is
   begin
      if not Report.Equal (Evaled, Expected) then
         Report.Failed ("Wrong result - " & Tag);
         Report.Comment ("Evaled=" & Natural'Image(Evaled) &
                         "; Expected=" & Natural'Image(Expected));
      end if;
   end Check;

begin

   Report.Test ("C457005",
                "When the selecting expression of a case expression is a " &
                "name with a static nominal subtype and has a static " &
                "predicate, the static predicate is disabled, and the " &
                "value of the selecting expression does not satisfy the " &
                "predicate, check that the others choice is returned, or, " &
                "if there is no others choice, that Constraint_Error is " &
                "raised");

   -- Check that checks are not made for these predicates:
   begin
      Even_Var_1 := 1;
      -- OK, predicate check is off.
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate checked on assignment of 1 to Even_Var_1");
   end;

   begin
      Prime_Var := Prime(Report.Ident_Int(4));
      -- OK, predicate check is off.
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate checked on type conversion 4 to Prime");
   end;

   begin
      X1 := Yellow;
      -- OK, predicate check is off.
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate checked on assignment of Yellow to RGB");
   end;

   -- Now, the variables Even_Var_1, Prime_Var, and X1 have values
   -- that do not satisfy the appropriate predicate, while X2 and
   -- Even_Var_2 do satisfy the appropriate predicate.

   -- Check case expressions of all of these, both with and without "others":
   Check ((case Even_Var_1 is
             when 2 => 987,
             when 4 => 654,
             when others => 321),
      Expected => 321, Tag => "Even_Var_1, others");

   begin
      Check ((case Even_Var_1 is
             when  0 => 3,
             when  2 => 4,
             when  4 => 12,
             when  6 => 15,
             when  8 => 66,
             when 10 => 92),
          Expected => 666, Tag => "Even_Var_1, no others");
      Report.Failed ("Case expression did not raise Constraint_Error as " &
                     "expected - Even_Var_1");
   exception
      when Constraint_Error =>
         Report.Comment ("Case expression raised Constraint_Error as " &
                         "expected - Even_Var_1");
   end;

   Check ((case Even_Var_2 is
             when  8 => 987,
             when 10 => 654,
             when others => 321),
      Expected => 654, Tag => "Even_Var_2, others");

   Check ((case Even_Var_2 is
             when 2 | 4 | 6 | 8 => 42,
             when 0 | 10 => 99),
      Expected => 99, Tag => "Even_Var_2, no others");

   Check ((case Prime_Var is
             when 2 | 3 | 5 => 222,
             when others => 999),
      Expected => 999, Tag => "Prime_Var, others");

   begin
      Check ((case Prime_Var is
                when 2 | 3 | 5 => 43,
                when 7 | 11 | 13 | 17 | 19 => 94),
         Expected => 666, Tag => "Prime_Var, no others");
      Report.Failed ("Case expression did not raise Constraint_Error as " &
                     "expected - Prime_Var");
   exception
      when Constraint_Error =>
         Report.Comment ("Case expression raised Constraint_Error as " &
                         "expected - Prime_Var");
   end;

   Check ((case X1 is
             when Red    => 39,
             when Green  => 43,
             when Blue   => 90,
             when others => 94),
      Expected => 94, Tag => "X1, others");

   begin
      Check ((case X1 is
             when Red    => 39,
             when Green  => 43,
             when Blue   => 90),
         Expected => 94, Tag => "X1, no others");
      Report.Failed ("Case expression did not raise Constraint_Error as " &
                     "expected - X1");
   exception
      when Constraint_Error =>
         Report.Comment ("Case expression raised Constraint_Error as " &
                         "expected - X1");
   end;

   Check ((case X2 is
             when Orange => 24,
             when Yellow => 39,
             when Indigo => 55,
             when Violet => 80,
             when others => 94),
         Expected => 80, Tag => "X2, others");

   Check ((case X2 is
             when Orange => 24,
             when Yellow => 39,
             when Indigo => 55,
             when Violet => 80),
         Expected => 80, Tag => "X2, no others");

   Report.Result;

end C457005;

