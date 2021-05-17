
with CA20003_TC;
package body CA20003_L is

   procedure Display (Dbg : in Debug_Info) is
   begin
      CA20003_TC.TC_Debug_Subsystem := CA20003_TC.BAD_VERSION;
   end Display;

begin
   CA20003_TC.TC_Debug_Subsystem := CA20003_TC.FIRST_VERSION;
end CA20003_L;

