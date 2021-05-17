
--=======================================================================--

package body FA11A00 is     -- Widget_Pkg

   procedure Set_Width (The_Widget : in out Widget; 
                        W          : in Widget_Length) is
   begin
      The_Widget.Width := W;
   end Set_Width;
   -------------------------------------------------------
   procedure Set_Height (The_Widget : in out Widget; 
                         H          : in Widget_Length) is
   begin
      The_Widget.Height := H;
   end Set_Height;

end FA11A00;     -- Widget_Pkg
