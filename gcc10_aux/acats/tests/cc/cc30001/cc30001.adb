

     --==================================================================--

with CC30001_2;  -- System message type and operations.
with CC30001_3;  -- Instance with mail type and operations.

with Report;
procedure CC30001 is

   package System_Messages renames CC30001_3;


   Sys_Msg1 : System_Messages.Mail_Type := (Text   => "System shutting down",
                                            Signal => CC30001_2.Warning,
                                            To     => "AllUsers",
                                            Message_Sent => False);

   Sys_Msg2 : System_Messages.Mail_Type'Class := Sys_Msg1;


   use System_Messages, CC30001_2;                 -- All versions of "Send"
                                                   -- directly visible.

begin

   Report.Test ("CC30001", "Check that if a non-overriding primitive "     &
                "subprogram is declared for a type derived from a formal " &
                "derived tagged type, the copy of that subprogram in an "  &
                "instance can override a subprogram inherited from the "   &
                "actual type");


   Send (Sys_Msg1);   -- Calls version declared in instance (version declared
                      -- in CC30001_2 has been overridden).

   if not Sys_Msg1.Message_Sent then
      Report.Failed ("Non-dispatching call: instance operation not called");
   end if;


   Send (Sys_Msg2);   -- Calls version declared in instance (version declared
                      -- in CC30001_2 has been overridden).

   if not Sys_Msg2.Message_Sent then
      Report.Failed ("Dispatching call: instance operation not called");
   end if;


   Report.Result;
end CC30001;
