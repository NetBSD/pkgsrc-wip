

     --==================================================================--


package body CC51006_2 is

   -- The implementations of the operations below are purely artificial; the
   -- validity of their implementations in the context of the abstraction is
   -- irrelevant to the feature being tested.

   function Weight_To_String (Wt : Grams) return String is
   begin
      return ("GRAMS: Should never be called    ");
   end Weight_To_String;


   function Weight_To_String (Wt : Pounds) return String is
   begin
      return ("POUNDS: Should never be called   ");
   end Weight_To_String;

end CC51006_2;
