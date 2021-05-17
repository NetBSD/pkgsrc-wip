
     --==================================================================--

-- Terminal_Driver.VT100.
package body CA13002_0.CA13002_1 is                     

   procedure Move_Cursor (Col : in TC_Call_From) is
   begin
      Send_Control_Sequence (First_Child, Col);
   end Move_Cursor;

end CA13002_0.CA13002_1;
