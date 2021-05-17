

     --==================================================================--


package body CA11016_0.CA11016_1 is              

   function Get_Display_Value (Lat  : Latitude;
                               Long : Longitude;
                               Map  : Map_Type) 
     return Display_Value is
   begin
      case Get_Physical_Feature (Lat, Long, Map) is
                                          -- Parent's operation,
           when Forest => return (Display_Value'first);
                                          -- Parent's type.
           when Desert => return (Display_Value'last);
                                          -- Parent's type.
           when others => return 
                            ( (Display_Value'last - Display_Value'first) / 2 );
                                          -- NOTE: Results are truncated.
      end case;

   end Get_Display_Value;

end CA11016_0.CA11016_1;
