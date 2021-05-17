
-- ---------------------------------------------------------------------------

with Report;
with C3A0018P;
procedure C3A0018 is

   protected Local_PO is
      function Double (X : Float) return Float;
      function Times_Factor (X : Float) return Float;
      procedure Set_Factor (X : Float);
   private
      Factor : Float := 3.0;
   end Local_PO;

   protected body Local_PO is
      function Double (X : Float) return Float is
      begin
         return 2.0 * X;
      end Double;

      function Times_Factor (X : Float) return Float is
      begin
         return Factor * X;
      end ;

      procedure Set_Factor (X : Float) is
      begin
         Factor := X;
      end Set_Factor;
   end Local_PO;

begin
   Report.Test ("C3A0018", "Check that an anonymous access type can be an " &
                           "access-to-protected subprogram type, and that it " &
                           "can be called with an appropriate profile");

   Report.Comment ("Indirect function call and renaming test " &
                   "(local subprograms)");
   declare
      function Evaluate
        (Fn : access protected function (X: Float) return Float;
         X  : Float)
        return Float is
         -- renaming test
         Ren_F : access protected function (F: Float) return Float renames Fn;
      begin
         if Fn (X) /= Ren_F (X) then
            Report.Failed ("Renaming test failed (local)");
         end if;
         declare
            R1 : Float := Ren_F (X);
         begin
            if Fn (X) /= R1 then
                Report.Failed ("Renamed call has different result that direct call (local)");
            end if;
            return R1;
         end;
      end Evaluate;

      procedure Pass_It
        (Fn : access protected function (X: Float)
                     return Float := Local_PO.Double'Access) is
         Result : Float;
      begin
         --  Check that the formal can be passed as an actual to
         --  another subprogram
         Result := Evaluate (Fn, 3.0);

         if Result /= 6.0 then
            Report.Failed ("Wrong result in called function (Pass_It)");
         end if;
      end Pass_It;

      Result : Float;
   begin
      Result := Evaluate (Local_PO.Double'Access, 5.0);

      if Result /= 10.0 then
         Report.Failed ("Wrong result in called function (local)");
      end if;

      Pass_It (Local_PO.Double'Access);
      Pass_It;
   end;

   Report.Comment ("Indirect function call and renaming test " &
                   "(package subprograms)");
   declare
      Result : Float;
   begin
      Result := C3A0018P.Evaluate (Local_PO.Double'Access, 7.5);

      if Result /= 15.0 then
         Report.Failed ("Wrong result in called function (local)");
      end if;

      C3A0018P.Pass_It (Local_PO.Double'Access);
      C3A0018P.Pass_It;
   end;

   Report.Comment ("Record component test");
   declare
      type Rec is record
         C : access protected function (F : Float) return Float;
      end record;

      R      : Rec := (C => Local_PO.Double'Access);
      Result : Float;
   begin
      --  Call through the access component
      Result := R.C (2.5);

      if Result /= 5.0 then
         Report.Failed ("Wrong result (record component)");
      end if;
   end;

   Report.Comment ("Discriminant test");
   declare
      type D_Rec (D : access protected function (F : Float) return Float) is
      record
         Dummy : Natural;
      end record;

      DR_1   : D_Rec (D => Local_PO.Double'Access);
      DR_2   : D_Rec := (D => C3A0018P.PO.Times_Factor'Access, Dummy => 0);
      Result : Float;
   begin
      DR_1.Dummy := 0;
      C3A0018P.PO.Set_Factor (3.5);

      --  Call through the access discriminant
      Result     := DR_1.D (4.0);
      if Result /= 8.0 then
         Report.Failed ("Wrong result (discriminant 1)");
      end if;

      Result   := DR_2.D (3.0);
      if Result /= 10.5 then
         Report.Failed ("Wrong result (discriminant 2)");
      end if;
   end;

   Report.Comment ("Array test");
   declare
      type Table is array (Integer range <>) of
        access protected function (F: Float) return Float;
      T      : Table (1 .. 2) := (Local_PO.Double'Access,
                                  Local_PO.Times_Factor'Access);
      Result : Float;
   begin
      Local_PO.Set_Factor (3.25);

      Result := T (1)(2.0);
      if Result /= 4.0 then
         Report.Failed ("Wrong result from array(1)");
      end if;

      Result := T (2)(4.0);
      if Result /= 13.0 then
         Report.Failed ("Wrong result from array(2)");
      end if;
   end;

   Report.Comment ("Object and function returning tests");
   declare
      FObj : access protected function (F: Float) return Float;
      PObj : access protected procedure (F: Float);
      Result : Float;
   begin
      PObj := Local_PO.Set_Factor'access;
      FObj := C3A0018P.PO.Times_Factor'access;
      PObj (4.0);
      Result := FObj (4.0); -- Better use the previously set factor of 3.5.
      if Result /= 14.0 then
         Report.Failed ("Wrong result from object (1)");
      end if;
      C3A0018P.PO.Set_Factor (4.0);
      Result := C3A0018P.Return_It.all (3.5);
      if Result /= 14.0 then
         Report.Failed ("Wrong result from call of function result (1)");
      end if;
      Result := C3A0018P.Return_It (2.5); -- Implicit .all
      if Result /= 10.0 then
         Report.Failed ("Wrong result from call of function result (2)");
      end if;
      C3A0018P.PO.Set_Factor (2.5);
      Result := C3A0018P.Evaluate (C3A0018P.Return_It, 3.0);
      if Result /= 7.5 then
         Report.Failed ("Wrong result in called function passed function result");
      end if;
      FObj := C3A0018P.Return_It;
      Result := FObj (5.0);
      if Result /= 12.5 then
         Report.Failed ("Wrong result from object (2)");
      end if;
   end;

   Report.Result;
end C3A0018;

