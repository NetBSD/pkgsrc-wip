
--=======================================================================--

package body FA11B00.CA11B01_0.CA11B01_1 is     -- Application_Three_Widget

   procedure App3_Widget_Specific_Oper 
     (The_Widget : in out App3_Widget; 
      S          : in     Widget_Size) is
   begin
      The_Widget.Size := S;
   end App3_Widget_Specific_Oper;

end FA11B00.CA11B01_0.CA11B01_1;                -- Application_Three_Widget
