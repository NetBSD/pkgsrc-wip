
     --==================================================================--

package body FA13B00_0 is             

   function Assign_Visible_Tagged(I : Visible_Integer) 
     return Visible_Tagged is
     VT : Visible_Tagged := (PR => (VI => I));
   begin
     return VT;
   end Assign_Visible_Tagged;

   -------------------------------------------------------

   function Assign_Private_Tagged (I : Visible_Integer) 
     return Private_Tagged is
     PT : Private_Tagged := (VI => I);
   begin
     return PT;
   end Assign_Private_Tagged;

   -------------------------------------------------------

end FA13B00_0;
