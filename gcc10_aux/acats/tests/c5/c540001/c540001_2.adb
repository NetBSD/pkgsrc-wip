
     --==================================================================--

package body C540001_2 is              

   procedure Assign_Enum (ET : out Enum) is
   begin
      case FSO is                         -- Type of expression in case
           when 1      => ET := Alpha;    -- statement is generic formal type.
           when 2      => ET := Beta;
           when others => ET := Theta;
      end case;

   end Assign_Enum;

end C540001_2;
