
     --==================================================================--

with C540001_0;
package C540001_1 is 
   type Enum_Type is (Eh, Bee, Sea, Dee); -- Range of Enum_Type'Val is 0..3.
   type Mixed     is ('A','B', 'C', None); 
   subtype Small_Num is Natural range 0 .. 10;
   type Small_Int is range 1 .. 2;
   function Get_Small_Int (P : Boolean) return Small_Int;
   procedure Assign_Mixed (P1 : in     Boolean;
                           P2 :    out Mixed);

   type Tagged_Type is tagged
     record
        C1 : Enum_Type;
     end record;
   function Get_Tagged (P : Tagged_Type) return C540001_0.Int;

end C540001_1;
