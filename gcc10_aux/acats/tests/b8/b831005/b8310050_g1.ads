

with B8310050;
generic
   type F is new B8310050.R;
package B8310050_G1 is
   type T is new F;

   overriding
   procedure E (X : in out T);                             -- OK.

   overriding
   function G (X : Character) return T;                    -- OK.

end B8310050_G1;
