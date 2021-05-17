
     --==================================================================--

package body CA11016_0 is              

   procedure Initialize_Basic_Map (Map : in out Map_Type) is
   -- Not a real initialization.  Real application can use geographic
   -- database to create the basic map.

   begin
      for I in Latitude'first .. Latitude'last loop
         for J in 1 .. 2 loop
            Map (I, J) := Desert;
         end loop;
         for J in 3 .. 4 loop
            Map (I, J) := Forest;
         end loop;
         for J in 5 .. 7 loop
            Map (I, J) := Water;
         end loop;
      end loop;

   end Initialize_Basic_Map;
   --------------------------------------------------------
   function Get_Physical_Feature (Lat  : Latitude;
                                  Long : Longitude;
                                  Map  : Map_Type) 
     return Physical_Features is
   begin
     return (Map (Lat, Long));
   end Get_Physical_Feature;
   --------------------------------------------------------

   begin
      -- Initialize a basic map.
      Initialize_Basic_Map (Basic_Map);

end CA11016_0;
