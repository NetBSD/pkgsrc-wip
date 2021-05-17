

     --===================================================================--


with CC54001_0;      -- Generic stack of pointers.
pragma Elaborate (CC54001_0);

package CC54001_1 is

   subtype Message     is String;
   type    Message_Ptr is access constant Message;

   Message_Count : constant := 4;

   Message_0 : aliased constant Message := "Hello";
   Message_1 : aliased constant Message := "Doctor";
   Message_2 : aliased constant Message := "Name";
   Message_3 : aliased constant Message := "Continue";


   package Stack_of_Messages is new CC54001_0
     (Element_Type => Message,
      Element_Ptr  => Message_Ptr,
      Size         => Message_Count);

   Message_Stack : Stack_Of_Messages.Stack_Type;


   procedure Create_Message_Stack;

end CC54001_1;
