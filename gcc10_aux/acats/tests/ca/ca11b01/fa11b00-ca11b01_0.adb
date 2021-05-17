
--=======================================================================--

package body FA11B00.CA11B01_0 is     -- Application_Two_Widget

   procedure App2_Widget_Specific_Oper 
     (The_Widget : in out App2_Widget;    
      Loc        : in     Widget_Location) is
   begin
      The_Widget.Location := Loc;
   end App2_Widget_Specific_Oper;

end FA11B00.CA11B01_0;                -- Application_Two_Widget
