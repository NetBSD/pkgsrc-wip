
--=======================================================================--

package body FA11B00 is     -- Application_One_Widget

   procedure Set_Color (The_Widget : in out App1_Widget; 
                        C          : in     Widget_Color_Enum) is
   begin
      The_Widget.Color := C;
   end Set_Color;
   -------------------------------------------------------------
   procedure Set_Label (The_Widget : in out App1_Widget; 
                        L          : in     Widget_Label_Str) is
   begin
      The_Widget.Label := L;
   end Set_Label;
   -------------------------------------------------------------
   procedure Set_Id (The_Widget : in out App1_Widget; 
                     I          : in     Widget_Id) is
   begin
      The_Widget.Id := I;
   end Set_Id;
   -------------------------------------------------------------
   procedure App1_Widget_Specific_Oper 
     (The_Widget : in out App1_Widget; 
      I          : in     Widget_Id;
      C          : in     Widget_Color_Enum;
      L          : in     Widget_Label_Str) is
   begin
      Set_Color    (The_Widget, C);
      Set_Label    (The_Widget, L);
      Set_Id       (The_Widget, I);
   end App1_Widget_Specific_Oper;

end FA11B00;                -- Application_One_Widget
