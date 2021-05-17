
     --==================================================================--

-- Terminal_Driver.DOS_ANSI.
package body CA13002_0.CA13002_3 is                     

   procedure Move_Cursor (Col : in TC_Call_From) is
   begin
      Send_Control_Sequence (Third_Child, Col);
   end Move_Cursor;

   procedure CA13002_5 is separate;

end CA13002_0.CA13002_3;
