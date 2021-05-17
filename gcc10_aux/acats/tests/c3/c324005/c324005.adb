

with Report;
with C324005_0; use c324005_0;
with Ada.Assertions; use Ada.Assertions;
procedure C324005 is

   -- Note: the assertion policy in this unit is irrelevant - 3.2.4(8-11/3)
   -- apply. A different test will check that explicitly, but we don't need
   -- to set the policy here.

   X1 : RGB := Green;

   X2 : Other_Color := Violet;

   X3 : Priv_T_P := Good;

   X4 : Priv_T_P := Good;

   Prime_Var : Prime := 5;

   Even_Var_1 : Even := 10;

   Even_Var_2 : Even := 100;

begin

   Report.Test ("C324005",
                "Check predicate checks are not performed for static and " &
                "dynamic subtype predicates when the assertion policy is " &
                "Ignore, but memberships, the Valid attribute, and for " &
                "loops continue to use the predicates -- case B: specific " &
                "assertion policy pragmas");

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

   begin
      declare
         Var : Priv_T_P := Bad;
      begin
         null; -- OK, predicate check is off.
         X3 := Var;
      end;
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate checked for Priv_T_P - "
                   & "explicit initialization");
   end;

   -- Now, the variables Even_Var_1, Prime_Var, X1, and X3 have values
   -- that do not satisfy the appropriate predicate, while X2, X4, and
   -- Even_Var_2 do satisfy the appropriate predicate. Check membership of
   -- all of these:
   if Even_Var_1 in Even then
      Report.Failed ("Membership wrong - Even_Var_1");
   end if;

   if Even_Var_2 not in Even then
      Report.Failed ("Membership wrong - Even_Var_2");
   end if;

   if (Even_Var_2 + 1) in Even then
      Report.Failed ("Membership wrong - Inc(Even_Var_2)");
   end if;

   if Prime_Var in Prime then
      Report.Failed ("Membership wrong - Prime_Var");
   end if;

   if Prime'Base(Report.Ident_Int(6)) in Prime then
      Report.Failed ("Membership wrong - 6");
   end if;

   if Prime'Base(Report.Ident_Int(11)) not in Prime then
      Report.Failed ("Membership wrong - 11");
   end if;

   if X1 in RGB then
      Report.Failed ("Membership wrong - X1");
   end if;

   if Color'Succ(X1) not in RGB then
      Report.Failed ("Membership wrong - Succ(X1)");
   end if;

   if Color'Pred(X1) in RGB then
      Report.Failed ("Membership wrong - Pred(X1)");
   end if;

   if X2 not in Other_Color then
      Report.Failed ("Membership wrong - X2");
   end if;

   if X3 in Priv_T_P then
      Report.Failed ("Membership wrong - X3");
   end if;

   if X4 not in Priv_T_P then
      Report.Failed ("Membership wrong - X4");
   end if;

   -- Check the results of the Valid attribute on these scalar variables:
   if Even_Var_1'Valid then
      Report.Failed ("Valid wrong - Even_Var_1");
   end if;

   if not Even_Var_2'Valid then
      Report.Failed ("Valid wrong - Even_Var_2");
   end if;

   if Prime_Var'Valid then
      Report.Failed ("Valid wrong - Prime_Var");
   end if;

   if X1'Valid then
      Report.Failed ("Valid wrong - X1");
   end if;

   if not X2'Valid then
      Report.Failed ("Valid wrong - X2");
   end if;

   -- Try For loops. (We just check the values and not the order, as that's
   -- done by C550001 and it's unlikely that would change even if the predicate
   -- is ignored).

   for I in RGB loop
      if I /= Red and then I /= Green and then I /= Blue then
         Report.Failed ("RGB for loop wrong - I=" & Color'Image(I));
      end if;
   end loop;

   for I in reverse Prime loop
      if (I > 2 and then Even'Base(I) in Even) or else
         I = 9 or else I = 15 then
         Report.Failed ("Prime for loop wrong - I=" & Prime'Image(I));
      end if;
   end loop;

   Report.Result;

end C324005;

