

     --===================================================================--


package body C640001_2 is

   procedure Add_Op (Op   : in     Proc_Ptr;
                     List : in out Op_List) is
   begin
      List.Top := List.Top + 1;  -- Artificial; no Constraint_Error protection.
      List.Ops(List.Top) := Op;
   end Add_Op;


   procedure Process_Operand (Operand  : in out Tag;
                              List     : in     Op_List;
                              First_Op : in     Positive;
                              Last_Op  : in     Positive) is
   begin
      for I in First_Op .. Last_Op loop
         List.Ops(I)(Operand);       -- Implicit dereference of an
      end loop;                      -- access-to-subprogram value.
   end Process_Operand;

end C640001_2;
