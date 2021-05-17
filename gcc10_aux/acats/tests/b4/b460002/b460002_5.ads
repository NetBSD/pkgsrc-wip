

     --==================================================================--


generic
   type Designated_Type is tagged private;

   type Formal_Operand_Type is access all Designated_Type;
   Formal_Operand: in out Formal_Operand_Type;

   type Formal_Target_Type is access all Designated_Type;
package B460002_5 is

   -- The following conversion is illegal in an instance if the actual
   -- corresponding to Formal_Operand_Type has a deeper level than that
   -- of the actual corresponding to Formal_Target_Type:

   Target : Formal_Target_Type := Formal_Target_Type(Formal_Operand);

end B460002_5;
