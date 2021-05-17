
--=======================================================================--

with FA11A00.CA11A02_0;               -- Color_Widget_Pkg, 
                                      -- implicitly with Widget_Pkg
with CA11A02_1;

with Report;

procedure CA11A02 is

   package Widget_Pkg renames FA11A00;
   package Color_Widget_Pkg renames FA11A00.CA11A02_0;

   use Widget_Pkg;              -- All user-defined operators directly visible.

   procedure Set_Label (The_Widget : in out CA11A02_1.Label_Widget; 
                        L          : in     String) is
   begin
      The_Widget.Label := L;
   end Set_Label;
   ---------------------------------------------------------
   procedure Set_Widget (The_Widget : in out CA11A02_1.Label_Widget;
                         The_Width  : in     Widget_Length;
                         The_Height : in     Widget_Length; 
                         The_Color  : in     
                                          Color_Widget_Pkg.Widget_Color_Enum;
                         The_Label  : in     String) is
   begin
      CA11A02_1.Set_Width  (The_Widget, The_Width);    -- Twice inherited.
      CA11A02_1.Set_Height (The_Widget, The_Height);   -- Twice inherited.
      CA11A02_1.Set_Color (The_Widget, The_Color);     -- Inherited.
      Set_Label  (The_Widget, The_Label);              -- Explicitly declared.
   end Set_Widget;                                         

   White_Widget : CA11A02_1.Label_Widget (11);

begin

   Report.Test ("CA11A02", "Check that a type extended in a client of " &
                "a public child inherits primitive operations from parent");

   Set_Widget (White_Widget, 15, 21, Color_Widget_Pkg.White, "Alarm_Clock");  

   If White_Widget.Width /= Widget_Length (Report.Ident_Int (15)) or 
     White_Widget.Height /= Widget_Length (Report.Ident_Int (21)) or
       Color_Widget_Pkg."/=" (White_Widget.Color, Color_Widget_Pkg.White) or
         White_Widget.Label /= "Alarm_Clock" then
            Report.Failed ("Incorrect result for White_Widget");
   end if;

   Report.Result;

end CA11A02;
