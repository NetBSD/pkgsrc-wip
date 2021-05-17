

     --==================================================================--


with FC51B00;
package CC51B03_1 is

   subtype Spin_Type is Natural range 0 .. 3;

   type Extended_Vector (Spin : Spin_Type) is   -- Tagged type with
     new FC51B00.Vector with null record;       -- discriminant (indefinite).
      

end CC51B03_1;
