
--=======================================================================--

package FA11A00.CA11A01_0.CA11A01_1 is     -- Label_Widget_Pkg
-- This public grandchild extends the extension from its parent.  It 
-- represents processing of widgets in a window system.  

   -- Declaration used by private extension component.
   subtype Widget_Label_Str is string (1 .. 10);

   type Label_Widget is new Color_Widget with private;  
                            -- Record extension of parent tagged type.

   -- Inherits (inherited) procedure Set_Width from Color_Widget.
   -- Inherits (inherited) procedure Set_Height from Color_Widget.
   -- Inherits procedure Set_Color from Color_Widget.
   -- Inherits procedure Set_Color_Widget from Color_Widget.

   procedure Set_Label_Widget (The_Widget : in out Label_Widget;
                               The_Width  : in     Widget_Length;
                               The_Height : in     Widget_Length; 
                               The_Color  : in     Widget_Color_Enum;
                               The_Label  : in     Widget_Label_Str);

   -- The following function is needed to verify the value of the
   -- extension's private component.

   function Verify_Label (The_Widget : in Label_Widget;
                          The_Label  : in Widget_Label_Str) return Boolean;

private
   type Label_Widget is new Color_Widget with
      record
         Label : Widget_Label_Str;
      end record;

end FA11A00.CA11A01_0.CA11A01_1;     -- Label_Widget_Pkg
