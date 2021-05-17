
--=======================================================================--

package body FA11A00.CA11A01_0 is     -- Color_Widget_Pkg

   procedure Set_Color (The_Widget : in out Color_Widget; 
                        C          : in     Widget_Color_Enum) is
   begin
      The_Widget.Color := C;
   end Set_Color;
   ---------------------------------------------------------------
   procedure Set_Color_Widget (The_Widget : in out Color_Widget; 
                               The_Width  : in     Widget_Length;
                               The_Height : in     Widget_Length; 
                               The_Color  : in     Widget_Color_Enum) is
   begin
      Set_Width  (The_Widget, The_Width);   -- Inherited from parent.
      Set_Height (The_Widget, The_Height);  -- Inherited from parent.
      Set_Color  (The_Widget, The_Color);
   end Set_Color_Widget;

end FA11A00.CA11A01_0;     -- Color_Widget_Pkg
