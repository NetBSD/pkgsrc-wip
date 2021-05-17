
     --==================================================================--

-- Generic child package of physical map.  Instantiate this package to
-- create map copy with a new geographic feature, i.e., population, density,
-- or weather.

generic               

   type Generic_Feature is (<>);  -- Any geographic feature, i.e., population,
                                  -- density, or weather that can be
                                  -- characterized by a scalar value.

package CA11015_0.CA11015_1 is              

   type Feature_Map is private;

   function Get_Feature_Val (Lat  : Latitude;
                             Long : Longitude;
                             Map  : Feature_Map) return Generic_Feature;

   procedure Set_Feature_Val (Lat  : in     Latitude;
                              Long : in     Longitude;
                              Fea  : in     Generic_Feature;
                              Map  : in out Feature_Map);

   function Check_Page (Map     : Feature_Map;
                        Page_No : Page_Type) return boolean;

private
   type Feature_Type is array (Latitude, Longitude) of Generic_Feature;

   type Feature_Map is
     record
        Feature : Feature_Type;
        Page    : Page_Type := Next_Page;    -- Operation from parent.
     end record;

end CA11015_0.CA11015_1;
