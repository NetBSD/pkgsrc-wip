
package body C452001_3 is

   function "=" (L : in Star; R : in Star) return Boolean is
   begin
      return (L.Class = R.Class) and (L.Color = R.Color);
   end "=";

end C452001_3;
