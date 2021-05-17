

     --==================================================================--


with B460002_0;
generic
   type Designated_Type is new B460002_0.Tagged_Type with private;
   type Formal_Operand_Type is access all Designated_Type;
package B460002_4 is

   -- Derived access type (level is that of ultimate ancestor):
   type Derived_Operand_Type is new Formal_Operand_Type;
   Derived_Operand : Derived_Operand_Type;

private

   -- The following conversion is illegal in an instance if the level of the
   -- ultimate ancestor of the actual corresponding to Formal_Operand_Type is
   -- deeper than that of B460002_0.External_Target_Type_L0:

   Target : B460002_0.External_Target_Type_L0 :=
            B460002_0.External_Target_Type_L0(Derived_Operand);

end B460002_4;
