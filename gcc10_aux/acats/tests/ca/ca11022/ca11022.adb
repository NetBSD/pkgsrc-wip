
     --==================================================================--

with CA11022_0.CA11022_2;              -- VT100 Graphic, implicitly with
                                       -- CA11022_0, Graphic Manager.
with CA11022_0.CA11022_3;              -- IBM3270 Graphic.
with Report;

procedure CA11022 is

begin

   Report.Test ("CA11022", "Check that body of a child unit can depend on " &
                "its generic sibling");

   -- Customized graphic functions for the VT100 terminal.
   CA11022_0.CA11022_2.VT100_Graphic;

   if not CA11022_0.TC_Screen (4,9) and not CA11022_0.TC_Screen (5,10) 
     and not CA11022_0.TC_Screen (9,14) and not CA11022_0.TC_Draw_Circle 
       and not CA11022_0.TC_Draw_Square then
          Report.Failed ("Wrong results for the VT100");
   end if;

   CA11022_0.TC_Draw_Circle := false;
   CA11022_0.TC_Draw_Square := false;

   -- Customized graphic functions for the IBM3270 terminal.
   CA11022_0.CA11022_3.IBM3270_Graphic;

   if not CA11022_0.TC_Screen (12,42) and not CA11022_0.TC_Screen (13,43) 
     and not CA11022_0.TC_Screen (14,44) and not CA11022_0.TC_Screen (46,18) 
       and not CA11022_0.TC_Draw_Circle and not CA11022_0.TC_Draw_Square then
          Report.Failed ("Wrong results for the IBM3270");
   end if;

   Report.Result;

end CA11022;
