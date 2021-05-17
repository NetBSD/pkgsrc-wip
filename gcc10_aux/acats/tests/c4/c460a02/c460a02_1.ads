

     --==================================================================--


with F460A00;
generic
   type Designated_Type is private;
   type Target_Type is access all Designated_Type;
   FObj : in out Target_Type;
   FRes : in out F460A00.TC_Result_Kind;
package C460A02_1 is
   type Operand_Type is access Designated_Type;
   Ptr : Operand_Type := new Designated_Type;

   procedure Dummy; -- Needed to allow package body.
end C460A02_1;
