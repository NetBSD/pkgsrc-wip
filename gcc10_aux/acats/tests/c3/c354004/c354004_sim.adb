

package body C354004_Sim is
   Address_Reg_Values : array (Address_Register_Type) of Address_Type :=
      (others => Address_Type'First);

   function Address_Register_Value (Addr_Reg : Address_Register_Type)
      return Address_Type is
   begin
      return Address_Reg_Values(Addr_Reg);
   end Address_Register_Value;


   procedure Set_Address_Register (Addr_Reg  : in Address_Register_Type;
                                   New_Value : in Address_Type) is
   begin
      Address_Reg_Values(Addr_Reg) := New_Value;
   end Set_Address_Register;


   function Calculate_Effective_Address (Addr_Reg : Address_Register_Type;
                                         Offset   : Offset_Type)
                                                return Address_Type is
   begin
      return Address_Reg_Values(Addr_Reg) + Address_Type'Mod (Offset);
   end Calculate_Effective_Address;

end C354004_Sim;
