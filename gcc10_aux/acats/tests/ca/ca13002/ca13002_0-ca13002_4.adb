
     --==================================================================--

-- Terminal_Driver.WYSE.
package body CA13002_0.CA13002_4 is                     

   procedure Move_Cursor (Col : in TC_Call_From) is
   begin
      Send_Control_Sequence (Fourth_Child, Col);
   end Move_Cursor;

   procedure CA13002_5 is separate;

end CA13002_0.CA13002_4;
