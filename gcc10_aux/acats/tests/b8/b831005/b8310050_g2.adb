
package body B8310050_G2 is

   type T is new F;

   overriding
   procedure E (X : in out T) is null;                     -- OK.

   overriding
   function G (X : Character) return T is (Comp => X);     -- OK.

   procedure Do_Something (A : in out F) is null;
end B8310050_G2;
