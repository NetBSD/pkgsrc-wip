
     --==================================================================--

package body BA13B01_0.BA13B01_1 is

   function Assign_Color (C : Parent_Color) 
     return Child_Vis_Ext is
     CE : Child_Vis_Ext := (CR => (VC => C), PI => 24);
   begin
     return CE;
   end Assign_Color;

   -------------------------------------------------------

   function Assign_Integer (I : Parent_Integer)
     return Child_Private is
     CE : Child_Private := (VI => I);
   begin
     return CE;
   end Assign_Integer;

end BA13B01_0.BA13B01_1;
