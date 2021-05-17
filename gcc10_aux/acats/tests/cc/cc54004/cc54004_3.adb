

     --===================================================================--


package body CC54004_3 is

   procedure TC_Create_Alert_Stack is
   begin
      Alert_Stacks.Push (Alert_List, new CC54004_1.Low_Alert);
      Alert_Stacks.Push (Alert_List, new CC54004_1.Medium_Alert);
   end TC_Create_Alert_Stack;

end CC54004_3;
