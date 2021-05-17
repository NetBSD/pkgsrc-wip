
with CA20003_TC;
package body CA20003_0 is

   procedure Do_It (D : in out Data;
                    Dbg : access CA20003_L.Debug_Info := null) is
   begin
      D.B := True;
      CA20003_TC.TC_Test_Subsystem := CA20003_TC.FIRST_VERSION;
   end Do_It;

end CA20003_0;
