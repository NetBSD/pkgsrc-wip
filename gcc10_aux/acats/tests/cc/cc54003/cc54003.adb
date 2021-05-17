

     --===================================================================--


with CC54003_1;  -- Message abstraction.
with CC54003_2;  -- Message-operation stack.

with Report;
procedure CC54003 is

   package Msg_Ops renames CC54003_2.Stack_Of_Ops;

   Msg      : CC54003_1.Message_Ptr := new CC54003_1.Message'("Hello there");
   Expected : CC54003_1.Message     := "Dummy: Hello there (12:03pm)";

begin
   Report.Test ("CC54003", "Check that a general access-to-subprogram type " &
                           "may be passed as an actual to a generic formal " &
                           "access-to-subprogram type");

   CC54003_2.Create_Operation_Stack;

   declare
      Actual : CC54003_1.Message_Ptr := 
        Msg_Ops.Execute_Stack (CC54003_2.Operation_Stack, Msg);
   begin
      if Actual.all /= Expected then
         Report.Failed ("Wrong result from dereferenced subprogram execution");
      end if;
   end;

   Report.Result;
end CC54003;
