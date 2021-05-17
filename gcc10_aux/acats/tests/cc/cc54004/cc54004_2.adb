

     --===================================================================--


package body CC54004_2 is

   procedure Push (Stack    : in out Stack_Type;
                   Elem_Ptr : in     Element_Ptr) is
   begin
      Stack(Top) := Elem_Ptr;
      Top := Top + 1;     -- Artificial: no Constraint_Error protection.
   end Push;


   procedure Pop  (Stack     : in out Stack_Type;
                   Elem_Ptr  :    out Element_Ptr)is
   begin
      Top := Top - 1;     -- Artificial: no Constraint_Error protection.
      Elem_Ptr := Stack(Top);
   end Pop;


   -- Call Handle for each element on the stack. Since the dereferenced access
   -- object is of a class-wide type, all calls to Handle are dispatching. The
   -- version of Handle called will be that declared for the type
   -- corresponding to the tag of the operand.

   procedure Process_Stack (Stack  : in out Stack_Type) is
   begin -- Artificial: no Constraint_Error protection.
      for I in reverse Index'First .. (Top - 1) loop
         Handle (Stack(I).all);            -- Call dispatches based on
      end loop;                            -- tag of operand.
   end Process_Stack;

end CC54004_2;
