
     --==================================================================--

with CA11016_0.CA11016_2;            -- Map display device operation,
                                     -- implicitly withs parent, physical map
                                     -- application.

use CA11016_0.CA11016_2;             -- Allows direct visibility to the simple
                                     -- name of CA11016_0.CA11016_2.

with Report;

procedure CA11016 is

   TC_Packet : IO_Packet;

begin 

   Report.Test ("CA11016", "Check that body of a public child package can " &
                           "use its sibling private generic package "       &
                           "declarations and operations");

-- Simulate control information at coordinates 3 and 7 of the
-- basic map for the SDUGD.
         
         Water_Display_Subtest:
         begin
            TC_Packet.Lat  := 3;
            TC_Packet.Long := 7;

            -- Build color and light intensity of the basic map at 
            -- latitude 3 and longitude 7.

            Data_For_SDUGD (TC_Packet.Lat, TC_Packet.Long, TC_Packet);

            if ( (TC_Packet.Color     /= Blue) or
                 (TC_Packet.Intensity /= 3) ) then
                Report.Failed ("Map display device contains " &
                               "incorrect values for water subtest");
            end if;

         end Water_Display_Subtest;

-- Simulate control information at coordinates 2 and 1 of the
-- basic map for the SDUGD.
         
         Desert_Display_Subtest:
         begin
            TC_Packet.Lat  := 9;
            TC_Packet.Long := 2;

            -- Build color and light intensity of the basic map at 
            -- latitude 9 and longitude 2.

            Data_For_SDUGD (TC_Packet.Lat, TC_Packet.Long, TC_Packet);

            if ( (TC_Packet.Color     /= Brown) or
                 (TC_Packet.Intensity /= 7) ) then
                Report.Failed ("Map display device contains " &
                               "incorrect values for desert subtest");
            end if;

         end Desert_Display_Subtest;

-- Simulate control information at coordinates 8 and 4 of the
-- basic map for the SDUGD.
         
         Forest_Display_Subtest:
         begin
            TC_Packet.Lat  := 8;
            TC_Packet.Long := 4;

            -- Build color and light intensity of the basic map at 
            -- latitude 8 and longitude 4.

            Data_For_SDUGD (TC_Packet.Lat, TC_Packet.Long, TC_Packet);

            if ( (TC_Packet.Color     /= Green) or
                 (TC_Packet.Intensity /= 1) ) then
                Report.Failed ("Map display device contains " &
                               "incorrect values for forest subtest");
            end if;

         end Forest_Display_Subtest;

   Report.Result;

end CA11016;
