

     --===================================================================--


with CC54003_0;      -- Generic stack of pointers.
pragma Elaborate (CC54003_0);

with CC54003_1;      -- Message abstraction.

package CC54003_2 is

   type Operation_Ptr is access function (Msg_Ptr : CC54003_1.Message_Ptr)
     return CC54003_1.Message_Ptr;

   Maximum_Ops : constant := 4;         -- Arbitrary.

   package Stack_of_Ops is new CC54003_0
     (Item_Type    => CC54003_1.Message,
      Item_Ptr     => CC54003_1.Message_Ptr,
      Function_Ptr => Operation_Ptr,
      Size         => Maximum_Ops);

   Operation_Stack : Stack_Of_Ops.Stack_Type;


   procedure Create_Operation_Stack;

end CC54003_2;
