

     --===================================================================--


package body CC54003_0 is

   procedure Push (Stack    : in out Stack_Type;
                   Func_Ptr : in     Function_Ptr) is
   begin
      Stack(Top) := Func_Ptr;
      Top := Top + 1;     -- Artificial: no Constraint_Error protection.
   end Push;


   -- Call each subprogram on the stack in sequence. For the first call, pass
   -- Initial_Input. For succeeding calls, pass the result of the previous
   -- call.

   function Execute_Stack (Stack         : Stack_Type;
                           Initial_Input : Item_Ptr) return Item_Ptr is
      Result : Item_Ptr := Initial_Input;
   begin
      for I in reverse Index'First .. (Top - 1) loop    -- Artificial: no C_E
         Result := Stack(I)(Result);                    -- protection.
      end loop;
      return Result;
   end Execute_Stack;

end CC54003_0;
