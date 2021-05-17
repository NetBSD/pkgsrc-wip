

     --==================================================================--


package body BC70006 is

   procedure Matrix_Manipulator is

      A : Matrices.Matrix_Type := Matrices.Add_Ident;                 -- OK.
      B : Matrices.Matrix_Type := A;                                  -- OK.


      -- Attempt to reference the formal part of the formal package using
      -- expanded names. All references to Group_Type, Identity, and Operation
      -- are illegal.

      ID1 : Math_Sig.Group_Type;                                      -- ERROR:
                                            -- Math_Sig.Group_Type not visible.

      ID5 : Matrices.Matrix_Type;                                     -- OK.


      ID2 : Matrices.Matrix_Type :=
              Math_Sig.Operation (A, B);                              -- ERROR:
                                             -- Math_Sig.Operation not visible.



      -- Attempt to reference the formal part of the formal package using
      -- direct names. All references to Group_Type, Identity, and Operation
      -- are illegal.

      ID3 : Group_Type;                                               -- ERROR:
                                                     -- Group_Type not visible.

      ID4 : Matrices.Matrix_Type := Identity;                         -- ERROR:
                                                       -- Identity not visible.

      ID6 : Matrices.Matrix_Type;                                     -- OK.

   begin
      -- Attempt to reference Identity using expanded name.
      ID5 := Math_Sig.Identity;                                       -- ERROR:
                                                       -- Identity not visible.

      -- Attempt to reference Operation using direct name.
      ID6 := Operation (A, B);                                        -- ERROR:
                                                      -- Operation not visible.

   end Matrix_Manipulator;

end BC70006;
