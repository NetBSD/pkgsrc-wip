
package body c452001_0 is

   function "=" (L, R : Circle) return Boolean is
   begin
      return L.Radius = R.Radius; -- circles are same size
   end "=";

   function "=" (L, R : Colored_Circle) return Boolean is
   begin
      return Circle(L) = Circle(R);
   end "=";

end C452001_0;
