
     --==================================================================--

package body CA11015_0.CA11015_1 is              

   function Get_Feature_Val (Lat  : Latitude;
                             Long : Longitude;
                             Map  : Feature_Map) return Generic_Feature is
   begin
     return (Map.Feature (Lat, Long));
   end Get_Feature_Val;
   ---------------------------------------------------
   procedure Set_Feature_Val (Lat  : in     Latitude;
                              Long : in     Longitude;
                              Fea  : in     Generic_Feature;
                              Map  : in out Feature_Map) is
   begin
      if Get_Physical_Feature (Lat, Long, Basic_Map) = Unexplored  
                                                -- Parent's operation,
                                                -- Parent's private object.
      then
         raise Terra_Incognita;                 -- Exception from parent.
      else
         Map.Feature (Lat, Long) := Fea;
      end if;
   end Set_Feature_Val;
   ---------------------------------------------------
   function Check_Page (Map     : Feature_Map;
                        Page_No : Page_Type) return boolean is
   begin
      return (Map.Page = Page_No);
   end Check_Page;

end CA11015_0.CA11015_1;
