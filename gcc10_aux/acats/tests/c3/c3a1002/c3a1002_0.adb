
     --==================================================================--

package body C3A1002_0 is

   task body Incomplete5 is  
   begin
      select 
         accept Read_Disc (P : out Enu_Type) do  
            P := D5;
         end Read_Disc;
      or
         terminate;
      end select;

   end Incomplete5;

   ----------------------------------------------------------------------
   task body Incomplete6 is 
   begin
      select 
         accept Read_Int (P : out Small_Int) do  
            P := D6;
         end Read_Int;
      or
         terminate;
      end select;

   end Incomplete6;

end C3A1002_0;
