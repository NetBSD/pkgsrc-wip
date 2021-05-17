
     --==================================================================--

-- Terminal_Driver.
package body CA13002_0 is                  

   procedure Send_Control_Sequence (Row : in TC_Name;
                                    Col : in TC_Call_From) is
   begin
      -- Reads a key and takes action.
      TC_Calls (Row, Col) := true;
   end Send_Control_Sequence;

end CA13002_0;
