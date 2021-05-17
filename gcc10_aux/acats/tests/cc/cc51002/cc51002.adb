

     --==================================================================--


with CC51002_0;  -- Root message type and operations.
with CC51002_1;  -- Message class function.
with CC51002_2;  -- Extended message type and operations.

with Report;
procedure CC51002 is

   function Send_Msg  is new CC51002_1 (CC51002_0.Msg_Type);
   function Send_WMsg is new CC51002_1 (CC51002_2.Who_Msg_Type);

   Mess  : CC51002_0.Msg_Type     := (Text => "Greetings!");
   WMess : CC51002_2.Who_Msg_Type := (Text => "Willkommen",
                                      From => CC51002_2.Outside);

   TC_Okay_MStatus  : Boolean := False;
   TC_Okay_WMStatus : Boolean := False;

begin
   Report.Test ("CC51002", "Check that, for formal derived tagged types, " &
                "the formal parameter names and default expressions for "  &
                "a primitive subprogram in an instance are determined by " &
                "the primitive subprogram of the ancestor type, but that " &
                "the primitive subprogram body executed is that of the"    &
                "actual type");

   TC_Okay_MStatus := Send_Msg (Mess);
   if not TC_Okay_MStatus then
      Report.Failed ("Wrong result from call to root type's operation");
   end if;

   TC_Okay_WMStatus := Send_WMsg (WMess);
   if not TC_Okay_WMStatus then
      Report.Failed ("Wrong result from call to derived type's operation");
   end if;

   Report.Result;
end CC51002;
