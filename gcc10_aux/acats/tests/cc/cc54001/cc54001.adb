

     --===================================================================--


with CC54001_1;

with Report;
procedure CC54001 is

   package Messages renames CC54001_1.Stack_Of_Messages;

   Msg0, Msg1, Msg2, Msg3 : CC54001_1.Message_Ptr;

begin
   Report.Test ("CC54001", "Check that a general access-to-constant type "   &
                           "may be passed as an actual to a generic formal " &
                           "access-to-constant type");

   CC54001_1.Create_Message_Stack;

   Messages.Pop (CC54001_1.Message_Stack, Msg3);  -- Pop items off stack in the
   Messages.Pop (CC54001_1.Message_Stack, Msg2);  -- reverse order that they
   Messages.Pop (CC54001_1.Message_Stack, Msg1);  -- were pushed.
   Messages.Pop (CC54001_1.Message_Stack, Msg0);

   if Msg0.all /= CC54001_1.Message_0 or else
      Msg1.all /= CC54001_1.Message_1 or else
      Msg2.all /= CC54001_1.Message_2 or else
      Msg3.all /= CC54001_1.Message_3
   then
      Report.Failed ("Items popped off of stack do not match those pushed");
   end if;

   Report.Result;
end CC54001;
