
--=======================================================================--

with Report;


package body FA11D00.CA11D02_0.CA11D02_1 is     -- Array_Complex

   function Multiply (Left  : Complex_Array_Type;
                      Right : Complex_Array_Type)
     return Complex_Array_Type is

   -- This procedure will raise an exception depending on the input
   -- parameter.  The exception will be handled locally by the
   -- "others" handler.

      Result : Complex_Array_Type := (others => Zero);

      subtype Vector_Size is Positive range Left'Range;

   begin  
      if Left = Result or else Right = Result then -- Do not multiply zero.
         raise Multiply_Error;                     -- Refence to exception in
                                                   -- grandparent package.
         Report.Failed ("Program control not transferred by raise");
      else
         for I in Vector_Size loop
           Result(I) := ( Left(I) * Right(I) );    -- Basic_Complex."*".
         end loop;
      end if;
      return (Result);
   
   exception
      when others =>
         Report.Comment ("Exception is handled by others in Multiplication");
         TC_Handled_In_Grandchild_Pkg_Func := true;
         return (Zero, Zero);
      
   end Multiply;
   --------------------------------------------------------------
   function Add (Left, Right : Complex_Array_Type)
     return Complex_Array_Type is

   -- This function will raise an exception depending on the input
   -- parameter.  The exception will be propagated and handled
   -- by the caller.

      Result : Complex_Array_Type := (others => Zero);

      subtype Vector_Size is Positive range Left'Range;

   begin  
      if Left = Result or Right = Result then     -- Do not add zero.
         raise Add_Error;                         -- Refence to exception in
                                                  -- grandparent package.
         Report.Failed ("Program control not transferred by raise");
      else
         for I in Vector_Size loop                   
           Result(I) := ( Left(I) + Right(I) );   -- Basic_Complex."+".
         end loop;
      end if;
      return (Result);
 
   end Add;
   --------------------------------------------------------------
   procedure Inverse (Right : in     Complex_Array_Type;
                      Left  : in out Complex_Array_Type) is

   -- This function will raise an exception depending on the input
   -- parameter.  The exception will be handled/reraised to be
   -- handled by the caller.

      Result : Complex_Array_Type := (others => Zero);

      Array_With_Zero : boolean := false;

   begin
      for I in 1 .. Right'Length loop
        if Right(I) = Zero then      -- Check for zero.
          Array_With_Zero := true;
        end if;
      end loop;

      If Array_With_Zero then
         raise Inverse_Error;      -- Do not inverse zero.
         Report.Failed ("Program control not transferred by raise");
      else
         for I in 1 .. Array_Size loop
           Left(I).Real := - Right(I).Real;
           Left(I).Imag := - Right(I).Imag;
        end loop;
      end if;

   exception
      when Inverse_Error  => 
         TC_Handled_In_Grandchild_Pkg_Proc := true;
         Left := Result;
         raise;     -- Reraise the Inverse_Error exception in the subtest.
         Report.Failed ("Exception not reraised in handler");

      when others => 
         Report.Failed ("Unexpected exception in procedure Inverse");
   end Inverse;

end FA11D00.CA11D02_0.CA11D02_1;     -- Array_Complex
