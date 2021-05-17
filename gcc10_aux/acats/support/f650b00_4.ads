
----------------------------------------------------------------------

with F650B00_2;
with F650B00_3;
package F650B00_4 is
   type Mill is new F650B00_2.Windmill with private;

   procedure Swap( A,B: in out Mill );
   function  Create return Mill;
   procedure Stop( It: in out Mill );
 private
   type Mill is new F650B00_2.Windmill with
     record
       Pump: F650B00_3.Pump := F650B00_3.Create;
     end record;
end F650B00_4;
