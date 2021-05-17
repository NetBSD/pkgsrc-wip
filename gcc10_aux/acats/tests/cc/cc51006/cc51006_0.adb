

     --==================================================================--


package body CC51006_0 is

   -- The implementations of the operations below are purely artificial; the
   -- validity of their implementations in the context of the abstraction is
   -- irrelevant to the feature being tested.

   function Weight_To_String (Wt : Weight_Type) return String is
   begin
      if Wt > 0.0 then         -- Always true for this test.
         return ("Root type's implementation called");
      else
         return ("Unexpected result                ");
      end if;
   end Weight_To_String;

end CC51006_0;
