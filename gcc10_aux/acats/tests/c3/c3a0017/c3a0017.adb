
-- ----------------------------------------------------------------------------

with Report;
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;
with C3A0017P;

procedure C3A0017 is

   function Double (X : Float) return Float is
   begin
      return 2.0 * X;
   end Double;

   function Triple (X : Float) return Float is
   begin
      return 3.0 * X;
   end ;

begin
   Report.Test ("C3A0017", "Anonymous access to subprogram types");

   Report.Comment ("Indirect function call and renaming test " &
                   "(local subprograms)");
   declare
      function Evaluate
        (Fn : access function (X: Float) return Float;
         X  : Float)
        return Float is
         Ren_F : access function (F: Float) return Float renames Fn;
      begin
         if Fn (X) /= Ren_F (X) then
            Report.Failed ("Renaming test failed (local)");
         end if;

         return Fn (X);
      end Evaluate;

      procedure Pass_It
        (Fn : access function (X: Float)
         return Float := Double'Access) is
         Result : Float;
      begin
         --  Check that the formal can be passed as an actual to
         --  another subprogram.

         Result := Evaluate (Fn, 3.0);

         if Result /= 6.0 then
            Report.Failed ("Wrong result in called function (Pass_It)");
         end if;
      end Pass_It;

      Result : Float;
   begin
      Result := Evaluate (Double'Access, 5.0);

      if Result /= 10.0 then
         Report.Failed ("Wrong result in called function (local, Double)");
      end if;

      Result := Evaluate (Sqrt'Access, 9.0);

      if Result /= 3.0 then
         Report.Failed ("Wrong result in called function (local, Sqrt)");
      end if;

      Pass_It (Double'Access);
      Pass_It;
   end;

   --  Following test carries the same checks that the previous test
   --  but the subprograms with the anonymous access types are found
   --  in a separate package

   Report.Comment ("Indirect function call and renaming test " &
                   "(package subprograms)");
   declare
      Result : Float;
   begin
      Result := C3A0017P.Evaluate (Double'Access, 7.5);

      if Result /= 15.0 then
         Report.Failed ("Wrong result in called function (package, Double)");
      end if;

      Result := C3A0017P.Evaluate (Sqrt'Access, 36.0);
      if Result /= 6.0 then
         Report.Failed ("Wrong result in called function (package, Sqrt)");
      end if;


      C3A0017P.Pass_It (Double'Access);
      C3A0017P.Pass_It;
   end;

   Report.Comment ("Record component test");
   declare
      type Rec is record
         C : access function (F : Float) return Float;
      end record;

      R      : Rec := (C => Double'Access);
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
      type D_Rec (D : access function (F : Float) return Float) is
         record
            Dummy : Natural;
         end record;

      DR_1   : D_Rec (D => Triple'Access);
      DR_2   : D_Rec := (D => Triple'Access, Dummy => 0);
      Result : Float;
   begin
      DR_1.Dummy := 0;

      --  Call through the access discriminant
      Result     := DR_1.D (1.5);

      if Result /= 4.5 then
         Report.Failed ("Wrong result (discriminant 1)");
      end if;

      --  Call through the access discriminant
      Result   := DR_2.D (3.0);

      if Result /= 9.0 then
         Report.Failed ("Wrong result (discriminant 1)");
      end if;
   end;

   Report.Comment ("Array test");
   declare
      type Table is array (Integer range <>) of
        access function (F: Float) return Float;
      T      : Table (1 .. 2) := (Double'Access, Triple'Access);
      Result : Float;
   begin
      Result := T (1)(2.0);
      if Result /= 4.0 then
         Report.Failed ("Wrong result from array(1)");
      end if;

      Result := T (2)(2.0);
      if Result /= 6.0 then
         Report.Failed ("Wrong result from array(2)");
      end if;
   end;

   Report.Comment ("Object and function returning tests");
   declare
      Obj : access function (F: Float) return Float;
      Result : Float;
   begin
      Obj := Triple'access;
      Result := Obj (4.5);
      if Result /= 13.5 then
         Report.Failed ("Wrong result from object (1)");
      end if;
      Result := C3A0017P.Return_It.all (3.5);
      if Result /= 7.0 then
         Report.Failed ("Wrong result from call of function result (1)");
      end if;
      Result := C3A0017P.Return_It (9.0); -- Implicit .all
      if Result /= 18.0 then
         Report.Failed ("Wrong result from call of function result (2)");
      end if;
      Result := C3A0017P.Evaluate (C3A0017P.Return_It, 7.5);
      if Result /= 15.0 then
         Report.Failed ("Wrong result in called function passed function result");
      end if;
      Obj := C3A0017P.Return_It;
      Result := Obj (4.5);
      if Result /= 9.0 then
         Report.Failed ("Wrong result from object (2)");
      end if;
   end;

   Report.Result;
end C3A0017;

