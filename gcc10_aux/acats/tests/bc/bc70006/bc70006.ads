

     --==================================================================--


with BC70006_0;  -- Template for formal package with explicit actual part.
with BC70006_1;  -- Template for formal package with (<>) actual part.

package BC70006 is

   generic
       with package Matrices is new BC70006_1 (<>);

       with package Math_Sig  is new BC70006_0
          (Group_Type => Matrices.Matrix_Type,
           Identity   => Matrices.Add_Ident,
           Operation  => Matrices."+");

       use Math_Sig;          -- Math_Sig package directly visible.
   procedure Matrix_Manipulator;

end BC70006;
