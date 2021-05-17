
     --===================================================================--


package body CC54003_2 is

   procedure Create_Operation_Stack is
   begin
      Stack_Of_Ops.Push (Operation_Stack, CC54003_1.Add_Prefix'Access);
      Stack_Of_Ops.Push (Operation_Stack, CC54003_1.Add_Suffix'Access);
   end Create_Operation_Stack;

end CC54003_2;
