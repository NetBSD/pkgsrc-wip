
-- ---------------------------------------------------------------------------
with Report;
package body C3A0018P is

   protected body PO is
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
   end PO;

   function Evaluate
     (Fn : access protected function (X: Float) return Float;
      X  : Float)
     return Float is
      -- renaming test
      Ren_F : access protected function (F: Float) return Float renames Fn;
   begin
      if Fn (X) /= Ren_F (X) then
         Report.Failed ("Renaming test (in package) failed");
      end if;

      return Fn (X);
   end Evaluate;

   procedure Pass_It
     (Fn : access protected function (X: Float)
      return Float := PO.Double'Access) is
      Result : Float;
   begin
      --  Check that the formal can be passed as an actual to
      --  another subprogram
      Result := Evaluate (Fn, 3.0);                                -- test

      if Result /= 6.0 then
         Report.Failed ("Wrong result in called function (Pass_It)");
      end if;
   end Pass_It;


   function Return_It
      return access protected function (X: Float) return Float is
      -- Return an access to PO.Times_Factor.
   begin
      return PO.Times_Factor'access;
   end Return_It;

end C3A0018P;
