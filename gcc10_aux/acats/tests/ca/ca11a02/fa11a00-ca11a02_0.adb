
--=======================================================================--

package body FA11A00.CA11A02_0 is     -- Color_Widget_Pkg

   procedure Set_Color (The_Widget : in out Color_Widget; 
                        C          : in     Widget_Color_Enum) is
   begin
      The_Widget.Color := C;
   end Set_Color;

end FA11A00.CA11A02_0;     -- Color_Widget_Pkg
