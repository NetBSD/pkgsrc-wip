
-- ----------------------------------------------------------------------------
with Report;
with C432005_0; use C432005_0;
procedure C432005 is

   procedure Check (P : in out T_PO; S : String := "") is
      Value : Integer;
   begin
      --  Check the protected object component
      P.Set (Value => 123);
      P.Get (Value);
      if Value /= 123 then
         Report.Failed (S & " : wrong value in PO component");
      end if;
   end Check;

   procedure Check (T : in out T_Task; S : String := "") is
      Value : Integer;
   begin
      --  Check the task component
      T.Set (Value => 123);
      T.Get (Value);
      if Value /= 123 then
         Report.Failed (S & " : wrong value in task component");
      end if;
   end Check;

begin
   Report.Test ("C432005", "Check that the ancestor expression type in an " &
                           "extension aggregate can be limited. Check that " &
                           "the ancestor subtype mark in an extension " &
                           "aggregate can be limited.");

   declare
      type T10 is tagged limited record
         A : Natural := Report.Ident_Int(999);
      end record;
      type T20 is new T10 with record
         P20 : T_PO;
         T20 : T_Task;
      end record;
      type T30 is new T20 with record
         P30 : T_PO;
         T30 : T_Task;
      end record;

      O1 : T20 := (T10 with P20 => <>, T20 => <>);
      O2 : T20 := (T10'(A => Report.Ident_Int(2)) with P20 => <>, T20 => <>);

      O3 : T30 := (T20 with P30 => <>, T30 => <>);
      O4 : T30 := (T20'(A => Report.Ident_Int(4), P20 => <>, T20 => <>)
                   with P30 => <>, T30 => <>);
   begin
      if O1.A /= 999 then
         Report.Failed ("Wrong value for O1.A");
      end if;
      Check (O1.P20, "O1.P20");
      Check (O1.T20, "O1.T20");

      if O2.A /= 2 then
         Report.Failed ("Wrong value for O2.A");
      end if;
      Check (O2.P20, "O2.P20");
      Check (O2.T20, "O2.T20");

      if O3.A /= 999 then
         Report.Failed ("Wrong value for O3.A");
      end if;
      Check (O3.P20, "O3.P20");
      Check (O3.T20, "O3.T20");
      Check (O3.P30, "O3.P30");
      Check (O3.T30, "O3.T30");

      if O4.A /= 4 then
         Report.Failed ("Wrong value for O4.A");
      end if;
      Check (O4.P20, "O4.P20");
      Check (O4.T20, "O4.T20");
      Check (O4.P30, "O4.P30");
      Check (O4.T30, "O4.T30");
   end;

   Report.Result;
end C432005;
