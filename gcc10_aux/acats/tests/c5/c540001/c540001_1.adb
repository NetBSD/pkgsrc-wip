
     --==================================================================--

package body C540001_1 is 
   function Get_Small_Int (P : Boolean) return Small_Int is
   begin
      if P then
         return Small_Int'First;
      else
         return Small_Int'Last; 
      end if;
   end Get_Small_Int;

   ---------------------------------------------------------------------
   procedure Assign_Mixed (P1 : in     Boolean;
                           P2 :    out Mixed) is
   begin
      case Get_Small_Int (P1) is          -- Function call as expression
           when 1  => P2 := None;         -- in case statement.
           when 2  => P2 := 'A';
           -- No others needed.
      end case;

   end Assign_Mixed;

   ---------------------------------------------------------------------
   function Get_Tagged (P : Tagged_Type) return C540001_0.Int is
   begin
      return C540001_0.Int'Last;
   end Get_Tagged;

end C540001_1;
