

     --==================================================================--


with C460010_0;
with C460010_1;
with C460010_2;

with Report;

procedure C460010 is

   generic function Generic_Equality renames C460010_2;

begin
   Report.Test ("C460010", "Check that Constraint_Error is not raised if " &
                "an array aggregate without an others choice is assigned " &
                "to an object of a constrained array subtype, and the "    &
                "length of each dimension of the aggregate equals the "    &
                "length of the corresponding dimension of the target object");


               ---=---=---=---=---=---=---=---=---=---=---


   declare
     type Arr is array (1..1) of C460010_0.Array_Static_Modular_Constraint;
     function Equals is new Generic_Equality (Arr);
     Target : Arr;
   begin
                       ---=---=---=---=---=---=---
     CASE_1:
     begin
        Target := (1 => (1 => 1, 2 => 2, 3 => 3));  -- Named associations.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 1");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 1");
      end CASE_1;

                       ---=---=---=---=---=---=---

     CASE_2:
     begin
        Target := (1 => (5, 10, 15));  -- Positional associations.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 2");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 2");
      end CASE_2;

                       ---=---=---=---=---=---=---
   end;


               ---=---=---=---=---=---=---=---=---=---=---


   declare
     type Rec (Disc : C460010_0.Modular_Type := 4) is record
       Arr : C460010_0.Array_Modular_Index(2 .. Disc);
     end record;

     function Equals is new Generic_Equality (Rec);
     Target : Rec;
   begin
                       ---=---=---=---=---=---=---
     CASE_3:
     begin
        Target := (Disc => 4, Arr => (1 => 1, 2 => 2, 3 => 3));  -- Named.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 3");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 3");
      end CASE_3;

                       ---=---=---=---=---=---=---

     CASE_4:
     begin
        Target := (Disc => 4, Arr => (1 ,2, 3));    -- Positional.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 4");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 4");
      end CASE_4;

                       ---=---=---=---=---=---=---
   end;


               ---=---=---=---=---=---=---=---=---=---=---


   declare
     type Arr is array (1..1) of C460010_0.Array_Nonstatic_Modular_Constraint;
     function Equals is new Generic_Equality (Arr);
     Target : Arr;
   begin
                       ---=---=---=---=---=---=---
     CASE_5:
     begin
        Target := (1 => (1 => 1, 2 => 2, 3 => 3));  -- Named associations.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 5");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 5");
      end CASE_5;

                       ---=---=---=---=---=---=---

     CASE_6:
     begin
        Target := (1 => ((5, 10, 15)));  -- Positional associations.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 6");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 6");
      end CASE_6;

                       ---=---=---=---=---=---=---
   end;


               ---=---=---=---=---=---=---=---=---=---=---


   declare
     type Arr is array (1..1) of C460010_1.Array_Static_Integer_Constraint;
     function Equals is new Generic_Equality (Arr);
     Target : Arr;
   begin
                       ---=---=---=---=---=---=---
     CASE_7:
     begin
        Target := (1 => (1 => True, 2 => True, 3 => False));  -- Named.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 7");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 7");
      end CASE_7;

                       ---=---=---=---=---=---=---

     CASE_8:
     begin
        Target := (1 => ((False, False, True)));  -- Positional.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 8");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 8");
      end CASE_8;

                       ---=---=---=---=---=---=---
   end;


               ---=---=---=---=---=---=---=---=---=---=---


   declare
     type Arr is array (1..1) of C460010_1.Array_Nonstatic_Integer_Constraint;
     function Equals is new Generic_Equality (Arr);
     Target : Arr;
   begin
                       ---=---=---=---=---=---=---
     CASE_9:
     begin
        Target := (1 => (1 => True, 2 => True, 3 => False));  -- Named.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 9");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 9");
      end CASE_9;

                       ---=---=---=---=---=---=---

     CASE_10:
     begin
        Target := (1 => (False, False, True));      -- Positional.

        if not Equals (Target, Target) then
             Report.Failed ("Avoid optimization");  -- Never executed.
        end if;
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error raised: Case 10");
         when others           =>
            Report.Failed ("Unexpected exception raised: Case 10");
      end CASE_10;

                       ---=---=---=---=---=---=---
   end;


               ---=---=---=---=---=---=---=---=---=---=---


     Report.Result;

end C460010;
