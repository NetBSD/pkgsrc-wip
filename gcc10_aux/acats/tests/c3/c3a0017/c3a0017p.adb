
-- ----------------------------------------------------------------------------

with Report;
package body C3A0017P is

   function Double (X : Float) return Float is
   begin
      return 2.0 * X;
   end Double;

   function Evaluate
     (Fn : access function (X: Float) return Float;
      X  : Float)
     return Float is
      Ren_F : access function (F: Float) return Float renames Fn;
   begin
      if Fn (X) /= Ren_F (X) then
         Report.Failed ("Renaming test (in package) failed");
      end if;

      return Fn (X);
   end Evaluate;

   procedure Pass_It
     (Fn : access function (X: Float)
      return Float := Double'Access) is
      Result : Float;
   begin
      --  Check that the formal can be passed as an actual to
      --  another subprogram
      Result := Evaluate (Fn, 3.0);

      if Result /= 6.0 then
         Report.Failed ("Wrong result in called function (Pass_It)");
      end if;
   end Pass_It;

   function Return_It
      return access function (X: Float) return Float is
      -- Return an access to Double.
   begin
      return Double'access;
   end Return_It;

end C3A0017P;
