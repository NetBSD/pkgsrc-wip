

     --==================================================================--


generic
   type Designated_Type is tagged private;
   type Formal_Target_Type is access all Designated_Type;
package B460002_2 is

   type Internal_Operand_Type is access all Designated_Type;
   Internal_Operand : Internal_Operand_Type := new Designated_Type;


   -- The following conversion is illegal in an instance if the package is
   -- instantiated at a level deeper than that of the actual corresponding
   -- to Formal_Target_Type:

   Target : Formal_Target_Type := Formal_Target_Type(Internal_Operand);

end B460002_2;
