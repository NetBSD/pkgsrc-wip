

     --==================================================================--


with BC70005_0;  -- Template for formal package with explicit actual part.
with BC70005_1;  -- Template for formal package with (<>) actual part.

generic
   with package Matrix_Ops is new BC70005_1 (<>);

   with package Signature  is new BC70005_0
     (Group_Type => Matrix_Ops.Matrix_Type,
      Identity   => Matrix_Ops.Add_Ident,
      Operation  => Matrix_Ops."+");

   use Signature;          -- Signature package directly visible.
package BC70005 is

   A : Matrix_Ops.Matrix_Type := Matrix_Ops.Add_Ident;                -- OK.
   B : Matrix_Ops.Matrix_Type := A;                                   -- OK.


   -- Attempt to reference the formal part of the formal package using
   -- expanded names. All references to Group_Type, Identity, and Operation
   -- are illegal.

   ID1 : Signature.Group_Type;                                        -- ERROR:
                                           -- Signature.Group_Type not visible.

   ID2 : Matrix_Ops.Matrix_Type := Signature.Identity;                -- ERROR:
                                             -- Signature.Identity not visible.

   ID3 : Matrix_Ops.Matrix_Type :=
           Signature.Operation (A, B);                                -- ERROR:
                                            -- Signature.Operation not visible.


   -- Attempt to reference the formal part of the formal package using direct
   -- names. All references to Group_Type, Identity, and Operation are
   -- illegal.

   ID4 : Group_Type;                                                  -- ERROR:
                                                     -- Group_Type not visible.

   ID5 : Matrix_Ops.Matrix_Type := Identity;                          -- ERROR:
                                                       -- Identity not visible.

   ID6 : Matrix_Ops.Matrix_Type := Operation (A, B);                  -- ERROR:
                                                      -- Operation not visible.


end BC70005;
