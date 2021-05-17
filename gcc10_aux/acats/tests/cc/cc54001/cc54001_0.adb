

     --===================================================================--


package body CC54001_0 is

   procedure Push (Stack    : in out Stack_Type;
                   Elem_Ptr : in     Element_Ptr) is
   begin
      Stack(Top) := Elem_Ptr;
      Top := Top + 1;  -- Artificial: no Constraint_Error protection.
   end Push;


   procedure Pop (Stack    : in out Stack_Type;
                  Elem_Ptr :    out Element_Ptr) is
   begin
      Top := Top - 1;  -- Artificial: no Constraint_Error protection.
      Elem_Ptr := Stack(Top);
   end Pop;

end CC54001_0;
