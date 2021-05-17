
with Report;
with C540003_0; use C540003_0;
with Ada.Assertions; use Ada.Assertions;
procedure C540003 is

   -- Note: the assertion policy in this unit is irrelevant - 3.2.4(8-11/3)
   -- apply. A different test will check that explicitly, but we don't need
   -- to set the policy here.

   X1 : RGB := Green;

   X2 : Other_Color := Violet;

   Prime_Var : Prime := 5;

   Even_Var_1 : Small_Even := Small_Even(Report.Ident_Int(4));

   Even_Var_2 : Small_Even := Small_Even(Report.Ident_Int(10));

begin

   Report.Test ("C540003",
                "When the selecting expression of a case statement is a " &
                "name with a static nominal subtype and has a static " &
                "predicate, the static predicate is disabled, and the " &
                "value of the selecting expression does not satisfy the " &
                "predicate, check that the others choice is executed, or, " &
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
   begin
      case Even_Var_1 is
         when 2 => Report.Failed ("Wrong choice - Even_Var_1");
         when 4 => Report.Failed ("Wrong choice - Even_Var_1");
         when others => null;
      end case;
   exception
      when Constraint_Error =>
         Report.Failed ("Case statement raised Constraint_Error rather " &
                        "than executing others choice - Even_Var_1");
   end;

   begin
      case Even_Var_1 is
         when  0 => Report.Comment ("Wrong choice - Even_Var_1 (0)");
         when  2 => Report.Comment ("Wrong choice - Even_Var_1 (2)");
         when  4 => Report.Comment ("Wrong choice - Even_Var_1 (4)");
         when  6 => Report.Comment ("Wrong choice - Even_Var_1 (6)");
         when  8 => Report.Comment ("Wrong choice - Even_Var_1 (8)");
         when 10 => Report.Comment ("Wrong choice - Even_Var_1 (10)");
      end case;
      Report.Failed ("Case statement did not raise Constraint_Error as " &
                     "expected - Even_Var_1");
   exception
      when Constraint_Error =>
         Report.Comment ("Case statement raised Constraint_Error as " &
                         "expected - Even_Var_1");
   end;

   case Even_Var_2 is
      when  8 => Report.Failed ("Wrong choice - Even_Var_2");
      when 10 => null;
      when others => Report.Failed ("Wrong choice - Even_Var_2");
   end case;

   case Even_Var_2 is
      when 2 | 4 | 6 | 8 => Report.Failed ("Wrong choice - Even_Var_2 (2)");
      when 0 | 10 => null;
   end case;

   case Prime_Var is
      when 2 | 3 | 5 => Report.Failed ("Wrong choice - Prime_Var");
      when others => null;
   end case;

   begin
      case Prime_Var is
         when 2 | 3 | 5 => Report.Comment ("1st choice - Prime_Var");
         when 7 | 11 | 13 | 17 | 19 =>
                           Report.Comment ("2nd choice - Prime_Var");
      end case;
      Report.Failed ("Case statement did not raise Constraint_Error as " &
                     "expected - Prime_Var");
   exception
      when Constraint_Error =>
         Report.Comment ("Case statement raised Constraint_Error as " &
                         "expected - Prime_Var");
   end;

   case X1 is
      when Red    => Report.Failed ("Wrong choice (Red) - X1");
      when Green  => Report.Failed ("Wrong choice (Green) - X1");
      when Blue   => Report.Failed ("Wrong choice (Blue) - X1");
      when others => null;
   end case;

   begin
      case X1 is
         when Red    => Report.Comment ("Wrong choice (Red) - X1");
         when Green  => Report.Comment ("Wrong choice (Green) - X1");
         when Blue   => Report.Comment ("Wrong choice (Blue) - X1");
      end case;
      Report.Failed ("Case statement did not raise Constraint_Error as " &
                     "expected - X1");
   exception
      when Constraint_Error =>
         Report.Comment ("Case statement raised Constraint_Error as " &
                         "expected - X1");
   end;

   case X2 is
      when Orange => Report.Failed ("Wrong choice (Orange) - X2");
      when Yellow => Report.Failed ("Wrong choice (Yellow) - X2");
      when Indigo => Report.Failed ("Wrong choice (Indigo) - X2");
      when Violet => null;
      when others => Report.Failed ("Wrong choice (others) - X2");
   end case;

   case X2 is
      when Orange => Report.Failed ("Wrong choice (Orange) - X2 - 2");
      when Yellow => Report.Failed ("Wrong choice (Yellow) - X2 - 2");
      when Indigo => Report.Failed ("Wrong choice (Indigo) - X2 - 2");
      when Violet => null;
   end case;

   Report.Result;

end C540003;

