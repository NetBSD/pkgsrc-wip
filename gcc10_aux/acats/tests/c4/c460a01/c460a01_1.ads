

     --==================================================================--


generic
   type Designated_Type is tagged private;
   type Operand_Type is access all Designated_Type;
   type Target_Type  is access all Designated_Type;
package C460A01_1 is
   function Convert (P : Operand_Type) return Target_Type;
end C460A01_1;
