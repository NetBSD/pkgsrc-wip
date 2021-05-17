

     --==================================================================--


package body C460A01_0 is
   function Convert (P : Operand_Type) return Target_Type is
   begin
      return Target_Type(P); -- Never fails.
   end Convert;
end C460A01_0;
