 
----------------------------------------------------------------------

with F393A00_2;
with F393A00_3;
package F393A00_4 is
   type Mill is new F393A00_2.Windmill with private;
 
   procedure Swap( A,B: in out Mill );
   function  Create return Mill;
   procedure Stop( It: in out Mill );
 private
   type Mill is new F393A00_2.Windmill with
     record
       Pump: F393A00_3.Pump := F393A00_3.Create;
     end record;
end F393A00_4;
