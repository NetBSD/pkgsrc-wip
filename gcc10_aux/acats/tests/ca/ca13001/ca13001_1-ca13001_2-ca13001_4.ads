
-- No bodies required for CA13001_1.CA13001_2.CA13001_3.

     --==================================================================--

-- Context clauses required for visibility needed by a separate subunit.

with CA13001_0;                           
use  CA13001_0;

-- Public grandchild of a private parent.

package CA13001_1.CA13001_2.CA13001_4 is

   type Transit is
      record
         Available : boolean := false;
      end record;
   type Keys_Array is array (Transportation) of Transit;
   Fuel : array (Transportation) of boolean := (others => true);

   protected Family_Transportation is

      procedure Get_Vehicle (Who : in     Family;
                             Key :    out Key_Type);
      procedure Return_Vehicle (Tr : in Transportation);
      function TC_Verify (What : Transportation) return boolean;

   private
      Keys : Keys_Array;

   end Family_Transportation;

end CA13001_1.CA13001_2.CA13001_4;
