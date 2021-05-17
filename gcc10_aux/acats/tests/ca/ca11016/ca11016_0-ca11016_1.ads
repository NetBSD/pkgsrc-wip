
     --==================================================================--

-- Private generic child package of physical map.  This generic package may
-- be instantiated for any display device which has display locations 
-- (latitude, longitude) that can be characterized by an integer value.
-- For example, the intensity of the display point might be so characterized.
-- It can be instantiated for any desired range of values (which would 
-- correspond to the range accepted by the display device).


private 

generic               

   type Display_Value is range <>;  -- Any display feature that is 
                                    -- represented by an integer.

package CA11016_0.CA11016_1 is              

   function Get_Display_Value (Lat  : Latitude;
                               Long : Longitude;
                               Map  : Map_Type) return Display_Value;

end CA11016_0.CA11016_1;
