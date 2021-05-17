
--=======================================================================--

package body FA11A00.CA11A01_0.CA11A01_1 is     -- Label_Widget_Pkg

   procedure Set_Label (The_Widget : in out Label_Widget; 
                        L          : in     Widget_Label_Str) is
   begin
      The_Widget.Label := L;
   end Set_Label;
   --------------------------------------------------------------
   procedure Set_Label_Widget (The_Widget : in out Label_Widget;
                               The_Width  : in     Widget_Length;
                               The_Height : in     Widget_Length; 
                               The_Color  : in     Widget_Color_Enum;
                               The_Label  : in     Widget_Label_Str) is
   begin
      Set_Width  (The_Widget, The_Width);   -- Twice inherited.
      Set_Height (The_Widget, The_Height);  -- Twice inherited.
      Set_Color  (The_Widget, The_Color);   -- Inherited from parent.
      Set_Label  (The_Widget, The_Label); 
   end Set_Label_Widget;
   --------------------------------------------------------------
   function Verify_Label (The_Widget : in Label_Widget; 
                          The_Label  : in Widget_Label_Str) return Boolean is
   begin
      return (The_Widget.Label = The_Label);
   end Verify_Label;

end FA11A00.CA11A01_0.CA11A01_1;     -- Label_Widget_Pkg
