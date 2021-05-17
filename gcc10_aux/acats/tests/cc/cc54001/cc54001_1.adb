

     --===================================================================--


package body CC54001_1 is

   procedure Create_Message_Stack is
      -- Push access objects onto stack. Note that some are statically
      -- allocated, and some are dynamically allocated (using an aliased
      -- object to initialize).
   begin
      Stack_Of_Messages.Push (Message_Stack, Message_0'Access); -- Static.
      Stack_Of_Messages.Push (Message_Stack,
                              new Message'(Message_1));         -- Dynamic.
      Stack_Of_Messages.Push (Message_Stack, Message_2'Access); -- Static.
      Stack_Of_Messages.Push (Message_Stack,                    -- Dynamic.
                              new Message'(Message_3));
   end Create_Message_Stack;

end CC54001_1;
