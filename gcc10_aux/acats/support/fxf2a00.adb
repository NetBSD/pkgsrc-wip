

     --==================================================================--


package body FXF2A00 is

   function Operations_Loop (Initial : Decimal_Fixed;
                             Operator: Operator_Table;
                             Operand : Operand_Table) return Decimal_Fixed is

      Result     : Decimal_Fixed := Initial;  -- Cumulator.
      Optr_Index : Optr_Range := 0;           -- Index into operations table.
      Opnd_Index : Opnd_Range := 0;           -- Index into operand table.

   begin
      for Count in Loop_Range loop
         Result     := Operator(Optr_Index) (Result, Operand(Opnd_Index));
         Optr_Index := Optr_Index + 1;        -- Modular addition.
         Opnd_Index := Opnd_Index + 1;        -- Modular addition.
      end loop;

      return Result;
   end Operations_Loop;

end FXF2A00;
