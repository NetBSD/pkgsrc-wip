

--=======================================================================--


package body FA11B00.CA11B02_0 is     -- Application_Two_Widget

   procedure App2_Widget_Specific_Op1 (The_Widget : in out App2_Widget;    
                                       S          : in     Widget_Size) is
   begin
      The_Widget.Size := S;
   end App2_Widget_Specific_Op1;

               --==============================================--

   procedure App2_Widget_Specific_Op2 (The_Widget : in out App2_Widget;    
                                       Loc        : in     Widget_Location) is
   begin
      The_Widget.Location := Loc;
   end App2_Widget_Specific_Op2;

end FA11B00.CA11B02_0;     -- Application_Two_Widget
