

     --==================================================================--


with B460002_0;
generic
   type Designated_Type is new B460002_0.Tagged_Type with private;

   type Formal_Operand_Type is access Designated_Type;
   Formal_Operand : in out Formal_Operand_Type;

   type Formal_Disc_Record_Type is new B460002_0.Disc_Record_Type;
   Formal_AccDisc : in out Formal_Disc_Record_Type;
package B460002_1 is

   type Internal_Target_Type  is access all Designated_Type;

   type Internal_Operand_Type is access all Designated_Type;
   Internal_Operand : Internal_Operand_Type := new Designated_Type;


   -- The following conversions are always legal. In each case, the conversion
   -- is to a target type declared within the instance, and the level of each
   -- operand type will never be deeper than that of the target type (because
   -- it is either already at library level, already at the same level as the
   -- target type, or must be passed as an actual to the instance):

   Target1 : Internal_Target_Type := Internal_Target_Type(B460002_0.Oper_Func);
   Target2 : Internal_Target_Type := Internal_Target_Type(Formal_AccDisc.D);
   
private

   Target3 : Internal_Target_Type := Internal_Target_Type(Internal_Operand);
   Target4 : Internal_Target_Type := Internal_Target_Type(Formal_Operand);

end B460002_1;
