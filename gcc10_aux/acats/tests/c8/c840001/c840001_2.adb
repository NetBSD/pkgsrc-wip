

     --==================================================================--

with Report;
with C840001_1;
procedure C840001_2 is

   -- Note that C840001_0 and it's contents is not visible in any form here.

   TC_Operand   : C840001_1.Precision_Pos_Float := 41.0;

   TC_Operand2  : C840001_1.Precision_Pos_Float;

   use type C840001_1.Precision_Pos_Float;
      -- Makes the operators of its parent type directly visible, even though
      -- the parent type and operators are not otherwise visible at all.

begin

   TC_Operand2 := +TC_Operand; -- Overridden operator is visible and called.

   if TC_Operand2 /= 82.0 then -- Predefined equality.
      Report.Failed ("3rd test: type's overridden operation not called for " &
                     "operand of 1st subtype");
   end if;
   if TC_Operand + 3.0 >= TC_Operand2 - 13.0 then -- Various predefined operators.
      Report.Failed ("3rd test: wrong result from predefined operators");
   end if;

end C840001_2;
