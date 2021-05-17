
package body C452001_2 is

   function "=" (L : in Spacecraft; R : in Spacecraft) return Boolean is
   begin
      return L(1).Design = R(1).Design;
   end "=";

end C452001_2;
