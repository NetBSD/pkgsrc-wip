
     --==================================================================--

package body C540001_4 is

   procedure Gen_Assign_Mixed (P : out C540001_1.Mixed) is
   begin
      case Formal_Func is                          -- Case expression is
         when 1      => P := C540001_1.'A';        -- generic function.
         when others => P := C540001_1.'B';
      end case;

   end Gen_Assign_Mixed;

end C540001_4;
