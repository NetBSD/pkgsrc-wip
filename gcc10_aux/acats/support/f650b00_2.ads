
----------------------------------------------------------------------

with F650B00_1;
package F650B00_2 is

   type Rotational_Measurement is range -1_000 .. 1_000;
   type Windmill is new F650B00_1.Object with private;

   procedure Swap( A,B: in out Windmill );

   function  Create return Windmill;

   procedure Add_Spin( To_Mill : in out Windmill;
                       RPMs    : in     Rotational_Measurement );

   procedure Stop( Mill : in out Windmill );

   function  Spin( Mill : Windmill ) return Rotational_Measurement;

private
   type Windmill is new F650B00_1.Object with
     record
       Spin : Rotational_Measurement := 0;
     end record;
end F650B00_2;
