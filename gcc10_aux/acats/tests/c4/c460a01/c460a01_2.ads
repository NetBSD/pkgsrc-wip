

     --==================================================================--


with F460A00;
generic
   type Designated_Type (<>) is new F460A00.Tagged_Type with private;
   type Operand_Type is access Designated_Type;
package C460A01_2 is
   procedure Proc (P   : Operand_Type; 
                   Res : out F460A00.TC_Result_Kind);
end C460A01_2;
