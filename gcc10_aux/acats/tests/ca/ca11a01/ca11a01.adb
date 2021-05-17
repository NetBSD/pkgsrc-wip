
--=======================================================================--

with FA11A00.CA11A01_0.CA11A01_1;     -- Label_Widget_Pkg, 
                                      -- implicitly with Widget_Pkg,
                                      -- implicitly with Color_Widget_Pkg
with Report;

procedure CA11A01 is

   package Widget_Pkg renames FA11A00;
   package Color_Widget_Pkg renames FA11A00.CA11A01_0;
   package Label_Widget_Pkg renames FA11A00.CA11A01_0.CA11A01_1;

   use Widget_Pkg;              -- All user-defined operators directly visible.

   Mail_Label     : Label_Widget_Pkg.Widget_Label_Str := "Quick_Mail";

   Default_Widget : Widget;
   Black_Widget   : Color_Widget_Pkg.Color_Widget;
   Mail_Widget    : Label_Widget_Pkg.Label_Widget;

begin

   Report.Test ("CA11A01", "Check that type extended in a public " &
                "child inherits primitive operations from its " &
                "ancestor");                                     

   Set_Width (Default_Widget, 9);             -- Call from parent.
   Set_Height (Default_Widget, 10);           -- Call from parent.

   If Default_Widget.Width /= Widget_Length (Report.Ident_Int (9)) or 
     Default_Widget.Height /= Widget_Length (Report.Ident_Int (10)) then
        Report.Failed ("Incorrect result for Default_Widget");
   end if;

   Color_Widget_Pkg.Set_Color_Widget 
     (Black_Widget, 17, 18, Color_Widget_Pkg.Black);   -- Explicitly declared.

   If Black_Widget.Width /= Widget_Length (Report.Ident_Int (17)) or 
     Black_Widget.Height /= Widget_Length (Report.Ident_Int (18)) or 
       Color_Widget_Pkg."/=" (Black_Widget.Color, Color_Widget_Pkg.Black) then
          Report.Failed ("Incorrect result for Black_Widget");
   end if;

   Label_Widget_Pkg.Set_Label_Widget 
     (Mail_Widget, 15, 21, Color_Widget_Pkg.White, 
       "Quick_Mail");                                  -- Explicitly declared.

   If Mail_Widget.Width /= Widget_Length (Report.Ident_Int (15)) or 
     Mail_Widget.Height /= Widget_Length (Report.Ident_Int (21)) or 
       Color_Widget_Pkg."/=" (Mail_Widget.Color, Color_Widget_Pkg.White) or 
         not Label_Widget_Pkg.Verify_Label (Mail_Widget, Mail_Label) then
            Report.Failed ("Incorrect result for Mail_Widget");
   end if;

   Report.Result;

end CA11A01;
