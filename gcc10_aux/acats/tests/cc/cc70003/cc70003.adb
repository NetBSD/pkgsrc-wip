

     --==================================================================--


with CC70003_0;    -- Generic list abstraction.
with CC70003_1;  -- Generic operation-list abstraction.
with CC70003_2;  -- Math library.

with Report;
procedure CC70003 is

   type Math_Op is access function (F : Float) return Float;

   package Math_Op_Lists        is new CC70003_0 (Math_Op);
   package Math_Op_List_Support is new CC70003_1 (Math_Op, Math_Op_Lists);

   Sin_Ptr : Math_Op := CC70003_2.Sine'Access;
   Exp_Ptr : Math_Op := CC70003_2.Exp'Access;

   Op_List : Math_Op_Lists.List_Type;

   Operand  : Float := 0.0;
   Expected : Float := 2.0;


begin
   Report.Test ("CC70003", "Check that the actual passed to a formal " &
                "package may be a formal access-to-subprogram type");

   Math_Op_Lists.Write_Element (1, Op_List, Sin_Ptr);
   Math_Op_Lists.Write_Element (2, Op_List, Exp_Ptr);

   Math_Op_List_Support.Execute_List (Op_List, Operand);

   if (Operand /= Expected) then
      Report.Failed ("Incorrect results from indirect function calls");
   end if;

   Report.Result;
end CC70003;
