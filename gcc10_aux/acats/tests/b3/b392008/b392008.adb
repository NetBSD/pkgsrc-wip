

     --===================================================================--


package body B392008 is

   procedure Derived_Class_Wide_Formal (AP     : in     Access_Proc;
                                        AF     : in     Access_Func;
                                        Ptr    : in out CW_Access;
                                        Operand: in out Tag'Class) is

      Local_Spec  : Tag;
      Local_Class : Tag'Class := Local_Spec;
      Temp        : Tag := AF (Operand);                              -- ERROR:
                    -- Actual parameter in function call is dynamically tagged.
   begin
      AP (Operand);                                                   -- ERROR:
                   -- Actual parameter in procedure call is dynamically tagged.

      AP (Tag'Class(Local_Spec));                                     -- ERROR:
                   -- Actual parameter in procedure call is dynamically tagged.

      Local_Spec := AF (Local_Class);                                 -- ERROR:
                    -- Actual parameter in function call is dynamically tagged.

      AP (Dyn_Tag_Func (Local_Class));                                -- ERROR:
                   -- Actual parameter in procedure call is dynamically tagged.

      Local_Spec := AF (Ptr.all);                                     -- ERROR:
                    -- Actual parameter in function call is dynamically tagged.
   end Derived_Class_Wide_Formal;



   package body Private_Class_Wide_Formal is

      function Dyn_Tag_Func (A: Tag) return Tag is
      begin
         return A;
      end Dyn_Tag_Func;


      procedure Inner_Proc (AP     : in     Access_Proc;
                            AF     : in     Access_Func;
                            Ptr    : in out CW_Access;
                            Operand: in out Tag'Class) is

         Local_Spec  : Tag;
         Local_Class : Tag'Class := Local_Spec;
         Temp        : Tag := AF (Operand);                           -- ERROR:
                    -- Actual parameter in function call is dynamically tagged.
      begin
         AP (Operand);                                                -- ERROR:
                   -- Actual parameter in procedure call is dynamically tagged.

         Local_Spec := AF (Tag'Class(Local_Spec));                    -- ERROR:
                    -- Actual parameter in function call is dynamically tagged.

         AP (Local_Class);                                            -- ERROR:
                                             -- Call with class-wide parameter.

         Local_Spec := AF (Dyn_Tag_Func (Local_Class));               -- ERROR:
                                             -- Call with class-wide parameter.

         AP (Ptr.all);                                                -- ERROR:
                   -- Actual parameter in procedure call is dynamically tagged.
      end Inner_Proc;

   end Private_Class_Wide_Formal;

end B392008;
