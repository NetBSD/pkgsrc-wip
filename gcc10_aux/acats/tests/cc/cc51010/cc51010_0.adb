

     --==================================================================--


package body CC51010_0 is

   package body Incomplete_Map is

      procedure Insert (Map  : in out Map_Type;
                        Elem : in out Element_Type;
                        Key  : in Key_Type) is
      begin
         -- Simplistic implementation to show proof-of-concept.
         Map.Items := Map.Items + 1;
         Map.Data(Map.Items) := (The_Key => Key,
                                 The_Element => Access_To (Elem));
           -- Will raise Constraint_Error if full.
      end Insert;


      function Element (Map : in Map_Type;
                        Key : in Key_Type) return access Element_Type is
      begin
         for I in 1 .. Map.Items loop
            if Map.Data(I).The_Key = Key then
               return Map.Data(I).The_Element;
            end if;
         end loop;
         return null;
      end Element;

   end Incomplete_Map;

end CC51010_0;


