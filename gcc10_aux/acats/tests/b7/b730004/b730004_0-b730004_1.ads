
-- No bodies provided for B730004_0.

     --=================================================================--

-- Public child

package B730004_0.B730004_1 is

   -- Type definitions.

   type Color is (White, Black, Red);

   type Child_Extension1 is new Visible_Tagged with  
      record 
         VI : Visible_Integer;
      end record;

   type Child_Extension2 is new Private_Tagged with 
      record 
         C  : Color; 
      end record;

   -- Object definitions.

   Visible_Integer_Num : Visible_Integer := 7;

   -- Subprogram definitions.

   function Assign_Private_Tagged (I : Visible_Integer) 
     return Private_Tagged;

   function Assign_Private_Extension (I : Visible_Integer) 
     return Private_Extension;

   function Assign_Visible_Tagged (I : Visible_Integer) 
     return Visible_Tagged;

   function Assign_Integer (I : Visible_Integer) return Child_Extension1;

   function Assign_Color (C : Color) return Child_Extension2;

   function Assign_Child_Extension1 (I : Visible_Integer) 
     return Child_Extension1;

   function Assign_Child_Extension2 (I : Visible_Integer) 
     return Child_Extension2;

end B730004_0.B730004_1;
