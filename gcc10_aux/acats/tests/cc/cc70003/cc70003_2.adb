

     --==================================================================--


package body CC70003_2 is

   -- The implementations of the functions below are purely artificial; the
   -- validity of their implementations in the context of the abstraction is
   -- irrelevant to the feature being tested.

   function Sine (F : Float) return Float is
   begin
      return (-0.15);
   end Sine;

   function Exp (F : Float) return Float is
   begin
      if (F = 0.0) then
         return (-0.69);
      else
         return (2.0);  -- This branch should be taken.
      end if;
   end Exp;

end CC70003_2;
