

with Report;
with C324001_0; use c324001_0;
with Ada.Assertions; use Ada.Assertions;
procedure C324001 is

   pragma Assertion_Policy (Check);

   X1 : RGB;                          -- OK; predicate not checked

   X2 : Another_Color;                -- OK; predicate not checked

   X3 : No_Defaults;                  -- OK; no predicate

   X4 : No_Defaults_P;                -- OK; predicate not checked

   X5 : Defaults;                     -- OK; no predicate

   X6 : RGB := Not_Another_One;       -- OK; predicate is True

   X7 : No_Defaults := Bad;           -- OK; no predicate

   X8 : No_Defaults_P := Good;        -- OK; predicate is True

   X9 : Defaults := Bad;              -- OK; no predicate

   X10 : Defaults_P := Good;          -- OK; predicate is True

   Even_Var_1 : Even;                 -- OK; predicate not checked

   Even_Var_2 : Even := 100;          -- OK; predicate is True

begin

   Report.Test ("C324001",
                "Check predicate checks are performed for static and " &
                "dynamic subtype predicates");
   begin
      Even_Var_1 := 1;
      Report.Failed ("Predicate should fail on assignment of 1 to Even_Var_1");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      Even_Var_1 := 0;                 -- OK; predicate is True
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate not true on assignment of 2 to Even_Var_1");
   end;

   begin
      declare
         Even_Var_3 : Even := Even_Var_2 + 1;
      begin
         Report.Failed ("Predicate should fail on initialization of " &
                        "Even_Var_3");
      end;
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   ----------------

   begin
      declare
         Var : Another_Color := Not_Another_One;
      begin
         Report.Failed ("Predicate specified for Another_Color should fail");
      end;
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      declare
         Var : Defaults_P := Bad;
      begin
         Report.Failed ("Predicate specified for Defaults_P should fail - "
                   & "explicit initialization");
      end;
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      declare
         Var : No_Defaults_P := Bad;
      begin
         Report.Failed ("Predicate specified for No_Defaults_P should fail - "
                   & "explicit initialization");
      end;
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      declare
         Var : Defaults_P;         -- Default init violates predicate
      begin
         Report.Failed ("Predicate specified for Defaults_P should fail - "
                   & "default initialization");
      end;
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      X1 := Not_Another_One;        -- OK; predicate is True
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate not true on assignment to X1");
   end;

   begin
      X2 := Not_Another_One;
      Report.Failed ("Predicate specified for Another_Color should fail");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      X3 := Bad;                    -- OK; no predicate
   exception
      when Assertion_Error =>
         Report.Failed ("No predicate specified for No_Defaults - X3");
   end;

   begin
      X4 := Good;
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate not true for assignment of Good to X4");
   end;

   begin
      X4 := Bad;
      Report.Failed ("Predicate specified for No_Defaults_P should fail - "
                & "assignment to X4");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      X5 := Bad;                    -- OK; no predicate
   exception
      when Assertion_Error =>
         Report.Failed ("No predicate specified for Defaults - X5");
   end;

   begin
      X6 := Not_Another_One;        -- OK; predicate is True
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate is false - assignment to X6");
   end;

   begin
      X7 := Bad;                    -- OK; no predicate
   exception
      when Assertion_Error =>
         Report.Failed ("No predicate specified for No_Defaults - X7");
   end;

   begin
      X8 := Good;                   -- OK; predicate is True
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate is false - assignment to X8");
   end;

   begin
      X8 := Bad;
      Report.Failed ("Predicate specified for No_Defaults_P should fail - "
                & "assignment to X8");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   begin
      X9 := Bad;                    -- OK; no predicate
   exception
      when Assertion_Error =>
         Report.Failed ("No predicate specified for Defaults - X9");
   end;

   begin
      X10 := Good;                  -- OK; predicate is True
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate is false - assignment to X10");
   end;

   begin
      X10 := Bad;
      Report.Failed ("Predicate specified for Defaults_P should fail - "
                & "assignment to X10");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   ----------------

   declare
      procedure P1 (X : Another_Color_Ref) is
      begin
         null;
      end P1;

      Var : Ref := new Node(Red);
   begin
      P1 (Var); -- Violate predicate of 'in' param
      Report.Failed ("Predicate for Another_Color_Ref should fail - P1");
   exception
      when Assertion_Error =>
         null; -- OK
   end;

   declare
      procedure P2 (X : out Another_Color_Ref) is
      begin
         null;
      end P2;

      Var : Ref;
   begin
      P2 (Var); -- No predicate check upon the call, and the check on the
          -- return is for subtype Ref, which has no predicate.
   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised by unnecessary predicate "
               & "evaluation - P2");
   end;

   declare
      procedure P3 (X : out Ref) is
      begin
         X := new Node(Blue);
      end P3;

      Var : Another_Color_Ref; -- Predicate not checked here.
   begin
      P3 (Var); -- No predicate check needed for the call, but the
          -- predicate check will fail upon return.
      Report.Failed ("Predicate is false - access out parameter "
               & "- P3");
   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised by unnecessary predicate "
               & "evaluation - P3");
      when Assertion_Error =>
          null; -- OK
   end;

   declare
      procedure P4 (X : out Another_Color_Ref) is
      begin
         X := new Node(Orange);
      end P4;

      Var : Ref;
   begin
      P4 (Var);     -- OK; don't check predicate on the way 'in'
   exception
      when Assertion_Error =>
         Report.Failed ("Predicate false upon return from P4");
      when Constraint_Error =>
         Report.Failed ("Predicate evaluated prior to execution of P4");
   end;

   declare
      procedure P5 (X : in out Another_Color_Ref) is
      begin
         X := new Node(Orange); -- Can't get here
         Report.Failed ("Constraint_Error not raised while calling P5");
      end P5;

      Var : Ref;
   begin
      P5 (Var);  -- Predicate of 'in out' param raises Constraint_Error
      Report.Failed ("Constraint_Error not raised during evaluation of "
                & "predicate - P5");
   exception
      when Constraint_Error =>
         null; -- OK
   end;

   declare
      procedure P6 (X : in out Ref) is
      begin
         X := new Node(Blue);
      end P6;

      Var : Another_Color_Ref := new Node(Orange);
   begin
      P6 (Var);  -- Outbound predicate of 'in out' param is false.
      Report.Failed ("Predicate is false - access out parameter "
               & "- P6");
   exception
      when Assertion_Error =>
          null; -- OK
   end;

   Report.Result;

end C324001;
