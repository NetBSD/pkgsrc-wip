
     --==================================================================--

package body C540001_5 is

   procedure Assign_Tagged (P1 : in     New_Tagged;
                            P2 :    out New_Tagged) is
   begin
      case Get_Tagged (P1) is                      -- Case expression is
                                                   -- inherited function.
         when 2      => P2 := (C540001_1.Bee, 'B');       
         when others => P2 := (C540001_1.Sea, C540001_1.None);
      end case;

   end Assign_Tagged;

end C540001_5;
