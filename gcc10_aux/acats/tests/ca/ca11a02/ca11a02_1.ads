
--=======================================================================--

with FA11A00.CA11A02_0;               -- Color_Widget_Pkg.

package CA11A02_1 is

   type Label_Widget (Str_Disc : Integer) is new 
     FA11A00.CA11A02_0.Color_Widget with
       record
         Label : String (1 .. Str_Disc);
       end record;

   -- Inherits (inherited) procedure Set_Width from Color_Widget.
   -- Inherits (inherited) procedure Set_Height from Color_Widget.
   -- Inherits procedure Set_Color from Color_Widget.

end CA11A02_1;
