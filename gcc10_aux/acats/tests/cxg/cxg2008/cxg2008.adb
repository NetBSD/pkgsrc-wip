
------------------------------------------------------------------------------

with System;
with Report;
with Ada.Numerics.Generic_Complex_Types;
with Ada.Numerics.Complex_Types;
with CXG2008_0;  use CXG2008_0;
procedure CXG2008 is
   Verbose : constant Boolean := False;

   package Float_Check is
      subtype Real is Float;
      procedure Do_Test;
   end Float_Check;

   package body Float_Check is
      package Complex_Types is new
           Ada.Numerics.Generic_Complex_Types (Real);
      use Complex_Types;

      -- keep track if an accuracy failure has occurred so the test
      -- can be short-circuited to avoid thousands of error messages.
      Failure_Detected : Boolean := False;

      Mult_MBE : constant Real := 5.0;
      Divide_MBE : constant Real := 13.0;


      procedure Check (Actual, Expected : Complex;
                       Test_Name : String;
                       MBE : Real) is
         Rel_Error : Real;
         Abs_Error : Real;
         Max_Error : Real;
      begin
         -- In the case where the expected result is very small or 0
         -- we compute the maximum error as a multiple of Model_Epsilon instead
         -- of Model_Epsilon and Expected.
         Rel_Error := MBE * abs Expected.Re * Real'Model_Epsilon;
         Abs_Error := MBE * Real'Model_Epsilon;
         if Rel_Error > Abs_Error then
            Max_Error := Rel_Error;
         else
            Max_Error := Abs_Error;
         end if;

         if abs (Actual.Re - Expected.Re) > Max_Error then
            Failure_Detected := True;
            Report.Failed (Test_Name &
                           " actual.re: " & Real'Image (Actual.Re) &
                           " expected.re: " & Real'Image (Expected.Re) &
                           " difference.re " &
                           Real'Image (Actual.Re - Expected.Re) &
                           " mre:" & Real'Image (Max_Error) );
         elsif Verbose then
	    if Actual = Expected then
	       Report.Comment (Test_Name & " exact result for real part");
	    else
	       Report.Comment (Test_Name & " passed for real part");
	    end if;
         end if;

         Rel_Error := MBE * abs Expected.Im * Real'Model_Epsilon;
         if Rel_Error > Abs_Error then
            Max_Error := Rel_Error;
         else
            Max_Error := Abs_Error;
         end if;
         if abs (Actual.Im - Expected.Im) > Max_Error then
            Failure_Detected := True;
            Report.Failed (Test_Name &
                           " actual.im: " & Real'Image (Actual.Im) &
                           " expected.im: " & Real'Image (Expected.Im) &
                           " difference.im " &
                           Real'Image (Actual.Im - Expected.Im) &
                           " mre:" & Real'Image (Max_Error) );
         elsif Verbose then
	    if Actual = Expected then
	       Report.Comment (Test_Name & " exact result for imaginary part");
	    else
	       Report.Comment (Test_Name & " passed for imaginary part");
	    end if;
         end if;
      end Check;


      procedure Special_Values is
      begin

         --- test 1 ---
         declare
            T : constant := (Real'Machine_EMax - 1) / 2;
            Big : constant := (1.0 * Real'Machine_Radix) ** (2 * T);
	    Expected : Complex := (0.0, 0.0);
            X : Complex := (0.0, 0.0);
	    Y : Complex := (Big, Big);
            Z : Complex;
         begin
            Z := X * Y;
            Check (Z, Expected, "test 1a -- (0+0i) * (big+big*i)",
                   Mult_MBE);
            Z := Y * X;
            Check (Z, Expected, "test 1b -- (big+big*i) * (0+0i)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 1");
            when others =>
               Report.Failed ("exception in test 1");
         end;

         --- test 2 ---
	 declare
            T : constant := Real'Model_EMin + 1;
            Tiny : constant := (1.0 * Real'Machine_Radix) ** T;
	    U : Complex := (Tiny, Tiny);
            X : Complex := (0.0, 0.0);
	    Expected : Complex := (0.0, 0.0);
	    Z : Complex;
         begin
            Z := U * X;
            Check (Z, Expected, "test 2 -- (tiny,tiny) * (0,0)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 2");
            when others =>
               Report.Failed ("exception in test 2");
         end;

         --- test 3 ---
	 declare
            T : constant := (Real'Machine_EMax - 1) / 2;
            Big : constant := (1.0 * Real'Machine_Radix) ** (2 * T);
	    B : Complex := (Big, Big);
            X : Complex := (0.0, 0.0);
	    Z : Complex;
         begin
            if Real'Machine_Overflows then
               Z := B / X;
               Report.Failed ("test 3 - Constraint_Error not raised");
               Check (Z, Z, "not executed - optimizer thwarting", 0.0);
            end if;
         exception
            when Constraint_Error => null;  -- expected
            when others =>
               Report.Failed ("exception in test 3");
         end;

         --- test 4 ---
	 declare
            T : constant := Real'Model_EMin + 1;
            Tiny : constant := (1.0 * Real'Machine_Radix) ** T;
	    U : Complex := (Tiny, Tiny);
            X : Complex := (0.0, 0.0);
	    Z : Complex;
         begin
            if Real'Machine_Overflows then
               Z := U / X;
               Report.Failed ("test 4 - Constraint_Error not raised");
               Check (Z, Z, "not executed - optimizer thwarting", 0.0);
            end if;
         exception
            when Constraint_Error => null;  -- expected
            when others =>
               Report.Failed ("exception in test 4");
         end;


         --- test 5 ---
	 declare
	    X : Complex := (Sqrt2, Sqrt2);
            Z : Complex;
            Expected : constant Complex := (0.0, 4.0);
         begin
            Z := X * X;
            Check (Z, Expected, "test 5 -- (sqrt2,sqrt2) * (sqrt2,sqrt2)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 5");
            when others =>
               Report.Failed ("exception in test 5");
         end;

         --- test 6 ---
	 declare
	    X : Complex := Sqrt3 - Sqrt3 * i;
            Z : Complex;
            Expected : constant Complex := (0.0, -6.0);
         begin
            Z := X * X;
            Check (Z, Expected, "test 6 -- (sqrt3,-sqrt3) * (sqrt3,-sqrt3)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 6");
            when others =>
               Report.Failed ("exception in test 6");
         end;

         --- test 7 ---
	 declare
	    X : Complex := Sqrt2 + Sqrt2 * i;
	    Y : Complex := Sqrt2 - Sqrt2 * i;
            Z : Complex;
            Expected : constant Complex := 0.0 + i;
         begin
            Z := X / Y;
            Check (Z, Expected, "test 7 -- (sqrt2,sqrt2) / (sqrt2,-sqrt2)",
                   Divide_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 7");
            when others =>
               Report.Failed ("exception in test 7");
         end;
      end Special_Values;


      procedure Do_Mult_Div (X, Y : Complex) is
	 Z : Complex;
	 Args : constant String :=
	   "X=(" & Real'Image (X.Re) & "," & Real'Image (X.Im) & ") " &
	   "Y=(" & Real'Image (Y.Re) & "," & Real'Image (Y.Im) & ") " ;
      begin
	 Z := (X * X) / X;
	 Check (Z, X, "X*X/X " & Args, Mult_MBE + Divide_MBE);
	 Z := (X * Y) / X;
	 Check (Z, Y, "X*Y/X " & Args, Mult_MBE + Divide_MBE);
	 Z := (X * Y) / Y;
	 Check (Z, X, "X*Y/Y " & Args, Mult_MBE + Divide_MBE);
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error in Do_Mult_Div for " & Args);
         when others =>
            Report.Failed ("exception in Do_Mult_Div for " & Args);
      end Do_Mult_Div;

      -- select complex values X and Y where the real and imaginary
      -- parts are selected from the ranges (1/radix..1) and
      -- (1..radix).  This translates into quite a few combinations.
      procedure Mult_Div_Check is
         Samples : constant := 17;
	 Radix : constant Real := Real(Real'Machine_Radix);
	 Inv_Radix : constant Real := 1.0 / Real(Real'Machine_Radix);
	 Low_Sample : Real;  -- (1/radix .. 1)
	 High_Sample : Real; -- (1 .. radix)
	 Sample : array (1..2) of Real;
	 X, Y : Complex;
      begin
         for I in 1 .. Samples loop
            Low_Sample := (1.0 - Inv_Radix) / Real (Samples) * Real (I) +
			  Inv_Radix;
	    Sample (1) := Low_Sample;
	    for J in 1 .. Samples loop
               High_Sample := (Radix - 1.0) / Real (Samples) * Real (I) +
			      Radix;
	       Sample (2) := High_Sample;
	       for K in 1 .. 2 loop
		  for L in 1 .. 2 loop
		     X := Complex'(Sample (K), Sample (L));
		     Y := Complex'(Sample (L), Sample (K));
		     Do_Mult_Div (X, Y);
                     if Failure_Detected then
                        return;   -- minimize flood of error messages
                     end if;
		  end loop;
	       end loop;
            end loop;  -- J
         end loop;  -- I
      end Mult_Div_Check;


      procedure Do_Test is
      begin
         Special_Values;
         Mult_Div_Check;
      end Do_Test;
   end Float_Check;

   -----------------------------------------------------------------------
   -----------------------------------------------------------------------
   -- check the floating point type with the most digits

   package A_Long_Float_Check is
      type A_Long_Float is digits System.Max_Digits;
      subtype Real is A_Long_Float;
      procedure Do_Test;
   end A_Long_Float_Check;

   package body A_Long_Float_Check is

      package Complex_Types is new
           Ada.Numerics.Generic_Complex_Types (Real);
      use Complex_Types;

      -- keep track if an accuracy failure has occurred so the test
      -- can be short-circuited to avoid thousands of error messages.
      Failure_Detected : Boolean := False;

      Mult_MBE : constant Real := 5.0;
      Divide_MBE : constant Real := 13.0;


      procedure Check (Actual, Expected : Complex;
                       Test_Name : String;
                       MBE : Real) is
         Rel_Error : Real;
         Abs_Error : Real;
         Max_Error : Real;
      begin
         -- In the case where the expected result is very small or 0
         -- we compute the maximum error as a multiple of Model_Epsilon instead
         -- of Model_Epsilon and Expected.
         Rel_Error := MBE * abs Expected.Re * Real'Model_Epsilon;
         Abs_Error := MBE * Real'Model_Epsilon;
         if Rel_Error > Abs_Error then
            Max_Error := Rel_Error;
         else
            Max_Error := Abs_Error;
         end if;

         if abs (Actual.Re - Expected.Re) > Max_Error then
            Failure_Detected := True;
            Report.Failed (Test_Name &
                           " actual.re: " & Real'Image (Actual.Re) &
                           " expected.re: " & Real'Image (Expected.Re) &
                           " difference.re " &
                           Real'Image (Actual.Re - Expected.Re) &
                           " mre:" & Real'Image (Max_Error) );
         elsif Verbose then
	    if Actual = Expected then
	       Report.Comment (Test_Name & " exact result for real part");
	    else
	       Report.Comment (Test_Name & " passed for real part");
	    end if;
         end if;

         Rel_Error := MBE * abs Expected.Im * Real'Model_Epsilon;
         if Rel_Error > Abs_Error then
            Max_Error := Rel_Error;
         else
            Max_Error := Abs_Error;
         end if;
         if abs (Actual.Im - Expected.Im) > Max_Error then
            Failure_Detected := True;
            Report.Failed (Test_Name &
                           " actual.im: " & Real'Image (Actual.Im) &
                           " expected.im: " & Real'Image (Expected.Im) &
                           " difference.im " &
                           Real'Image (Actual.Im - Expected.Im) &
                           " mre:" & Real'Image (Max_Error) );
         elsif Verbose then
	    if Actual = Expected then
	       Report.Comment (Test_Name & " exact result for imaginary part");
	    else
	       Report.Comment (Test_Name & " passed for imaginary part");
	    end if;
         end if;
      end Check;


      procedure Special_Values is
      begin

         --- test 1 ---
         declare
            T : constant := (Real'Machine_EMax - 1) / 2;
            Big : constant := (1.0 * Real'Machine_Radix) ** (2 * T);
	    Expected : Complex := (0.0, 0.0);
            X : Complex := (0.0, 0.0);
	    Y : Complex := (Big, Big);
            Z : Complex;
         begin
            Z := X * Y;
            Check (Z, Expected, "test 1a -- (0+0i) * (big+big*i)",
                   Mult_MBE);
            Z := Y * X;
            Check (Z, Expected, "test 1b -- (big+big*i) * (0+0i)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 1");
            when others =>
               Report.Failed ("exception in test 1");
         end;

         --- test 2 ---
	 declare
            T : constant := Real'Model_EMin + 1;
            Tiny : constant := (1.0 * Real'Machine_Radix) ** T;
	    U : Complex := (Tiny, Tiny);
            X : Complex := (0.0, 0.0);
	    Expected : Complex := (0.0, 0.0);
	    Z : Complex;
         begin
            Z := U * X;
            Check (Z, Expected, "test 2 -- (tiny,tiny) * (0,0)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 2");
            when others =>
               Report.Failed ("exception in test 2");
         end;

         --- test 3 ---
	 declare
            T : constant := (Real'Machine_EMax - 1) / 2;
            Big : constant := (1.0 * Real'Machine_Radix) ** (2 * T);
	    B : Complex := (Big, Big);
            X : Complex := (0.0, 0.0);
	    Z : Complex;
         begin
            if Real'Machine_Overflows then
               Z := B / X;
               Report.Failed ("test 3 - Constraint_Error not raised");
               Check (Z, Z, "not executed - optimizer thwarting", 0.0);
            end if;
         exception
            when Constraint_Error => null;  -- expected
            when others =>
               Report.Failed ("exception in test 3");
         end;

         --- test 4 ---
	 declare
            T : constant := Real'Model_EMin + 1;
            Tiny : constant := (1.0 * Real'Machine_Radix) ** T;
	    U : Complex := (Tiny, Tiny);
            X : Complex := (0.0, 0.0);
	    Z : Complex;
         begin
            if Real'Machine_Overflows then
               Z := U / X;
               Report.Failed ("test 4 - Constraint_Error not raised");
               Check (Z, Z, "not executed - optimizer thwarting", 0.0);
            end if;
         exception
            when Constraint_Error => null;  -- expected
            when others =>
               Report.Failed ("exception in test 4");
         end;


         --- test 5 ---
	 declare
	    X : Complex := (Sqrt2, Sqrt2);
            Z : Complex;
            Expected : constant Complex := (0.0, 4.0);
         begin
            Z := X * X;
            Check (Z, Expected, "test 5 -- (sqrt2,sqrt2) * (sqrt2,sqrt2)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 5");
            when others =>
               Report.Failed ("exception in test 5");
         end;

         --- test 6 ---
	 declare
	    X : Complex := Sqrt3 - Sqrt3 * i;
            Z : Complex;
            Expected : constant Complex := (0.0, -6.0);
         begin
            Z := X * X;
            Check (Z, Expected, "test 6 -- (sqrt3,-sqrt3) * (sqrt3,-sqrt3)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 6");
            when others =>
               Report.Failed ("exception in test 6");
         end;

         --- test 7 ---
	 declare
	    X : Complex := Sqrt2 + Sqrt2 * i;
	    Y : Complex := Sqrt2 - Sqrt2 * i;
            Z : Complex;
            Expected : constant Complex := 0.0 + i;
         begin
            Z := X / Y;
            Check (Z, Expected, "test 7 -- (sqrt2,sqrt2) / (sqrt2,-sqrt2)",
                   Divide_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 7");
            when others =>
               Report.Failed ("exception in test 7");
         end;
      end Special_Values;


      procedure Do_Mult_Div (X, Y : Complex) is
	 Z : Complex;
	 Args : constant String :=
	   "X=(" & Real'Image (X.Re) & "," & Real'Image (X.Im) & ") " &
	   "Y=(" & Real'Image (Y.Re) & "," & Real'Image (Y.Im) & ") " ;
      begin
	 Z := (X * X) / X;
	 Check (Z, X, "X*X/X " & Args, Mult_MBE + Divide_MBE);
	 Z := (X * Y) / X;
	 Check (Z, Y, "X*Y/X " & Args, Mult_MBE + Divide_MBE);
	 Z := (X * Y) / Y;
	 Check (Z, X, "X*Y/Y " & Args, Mult_MBE + Divide_MBE);
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error in Do_Mult_Div for " & Args);
         when others =>
            Report.Failed ("exception in Do_Mult_Div for " & Args);
      end Do_Mult_Div;

      -- select complex values X and Y where the real and imaginary
      -- parts are selected from the ranges (1/radix..1) and
      -- (1..radix).  This translates into quite a few combinations.
      procedure Mult_Div_Check is
         Samples : constant := 17;
	 Radix : constant Real := Real(Real'Machine_Radix);
	 Inv_Radix : constant Real := 1.0 / Real(Real'Machine_Radix);
	 Low_Sample : Real;  -- (1/radix .. 1)
	 High_Sample : Real; -- (1 .. radix)
	 Sample : array (1..2) of Real;
	 X, Y : Complex;
      begin
         for I in 1 .. Samples loop
            Low_Sample := (1.0 - Inv_Radix) / Real (Samples) * Real (I) +
			  Inv_Radix;
	    Sample (1) := Low_Sample;
	    for J in 1 .. Samples loop
               High_Sample := (Radix - 1.0) / Real (Samples) * Real (I) +
			      Radix;
	       Sample (2) := High_Sample;
	       for K in 1 .. 2 loop
		  for L in 1 .. 2 loop
		     X := Complex'(Sample (K), Sample (L));
		     Y := Complex'(Sample (L), Sample (K));
		     Do_Mult_Div (X, Y);
                     if Failure_Detected then
                        return;   -- minimize flood of error messages
                     end if;
		  end loop;
	       end loop;
            end loop;  -- J
         end loop;  -- I
      end Mult_Div_Check;


      procedure Do_Test is
      begin
         Special_Values;
         Mult_Div_Check;
      end Do_Test;
   end A_Long_Float_Check;

   -----------------------------------------------------------------------
   -----------------------------------------------------------------------

   package Non_Generic_Check is
      subtype Real is Float;
      procedure Do_Test;
   end Non_Generic_Check;

   package body Non_Generic_Check is

      use Ada.Numerics.Complex_Types;

      -- keep track if an accuracy failure has occurred so the test
      -- can be short-circuited to avoid thousands of error messages.
      Failure_Detected : Boolean := False;

      Mult_MBE : constant Real := 5.0;
      Divide_MBE : constant Real := 13.0;


      procedure Check (Actual, Expected : Complex;
                       Test_Name : String;
                       MBE : Real) is
         Rel_Error : Real;
         Abs_Error : Real;
         Max_Error : Real;
      begin
         -- In the case where the expected result is very small or 0
         -- we compute the maximum error as a multiple of Model_Epsilon instead
         -- of Model_Epsilon and Expected.
         Rel_Error := MBE * abs Expected.Re * Real'Model_Epsilon;
         Abs_Error := MBE * Real'Model_Epsilon;
         if Rel_Error > Abs_Error then
            Max_Error := Rel_Error;
         else
            Max_Error := Abs_Error;
         end if;

         if abs (Actual.Re - Expected.Re) > Max_Error then
            Failure_Detected := True;
            Report.Failed (Test_Name &
                           " actual.re: " & Real'Image (Actual.Re) &
                           " expected.re: " & Real'Image (Expected.Re) &
                           " difference.re " &
                           Real'Image (Actual.Re - Expected.Re) &
                           " mre:" & Real'Image (Max_Error) );
         elsif Verbose then
	    if Actual = Expected then
	       Report.Comment (Test_Name & " exact result for real part");
	    else
	       Report.Comment (Test_Name & " passed for real part");
	    end if;
         end if;

         Rel_Error := MBE * abs Expected.Im * Real'Model_Epsilon;
         if Rel_Error > Abs_Error then
            Max_Error := Rel_Error;
         else
            Max_Error := Abs_Error;
         end if;
         if abs (Actual.Im - Expected.Im) > Max_Error then
            Failure_Detected := True;
            Report.Failed (Test_Name &
                           " actual.im: " & Real'Image (Actual.Im) &
                           " expected.im: " & Real'Image (Expected.Im) &
                           " difference.im " &
                           Real'Image (Actual.Im - Expected.Im) &
                           " mre:" & Real'Image (Max_Error) );
         elsif Verbose then
	    if Actual = Expected then
	       Report.Comment (Test_Name & " exact result for imaginary part");
	    else
	       Report.Comment (Test_Name & " passed for imaginary part");
	    end if;
         end if;
      end Check;


      procedure Special_Values is
      begin

         --- test 1 ---
         declare
            T : constant := (Real'Machine_EMax - 1) / 2;
            Big : constant := (1.0 * Real'Machine_Radix) ** (2 * T);
	    Expected : Complex := (0.0, 0.0);
            X : Complex := (0.0, 0.0);
	    Y : Complex := (Big, Big);
            Z : Complex;
         begin
            Z := X * Y;
            Check (Z, Expected, "test 1a -- (0+0i) * (big+big*i)",
                   Mult_MBE);
            Z := Y * X;
            Check (Z, Expected, "test 1b -- (big+big*i) * (0+0i)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 1");
            when others =>
               Report.Failed ("exception in test 1");
         end;

         --- test 2 ---
	 declare
            T : constant := Real'Model_EMin + 1;
            Tiny : constant := (1.0 * Real'Machine_Radix) ** T;
	    U : Complex := (Tiny, Tiny);
            X : Complex := (0.0, 0.0);
	    Expected : Complex := (0.0, 0.0);
	    Z : Complex;
         begin
            Z := U * X;
            Check (Z, Expected, "test 2 -- (tiny,tiny) * (0,0)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 2");
            when others =>
               Report.Failed ("exception in test 2");
         end;

         --- test 3 ---
	 declare
            T : constant := (Real'Machine_EMax - 1) / 2;
            Big : constant := (1.0 * Real'Machine_Radix) ** (2 * T);
	    B : Complex := (Big, Big);
            X : Complex := (0.0, 0.0);
	    Z : Complex;
         begin
            if Real'Machine_Overflows then
               Z := B / X;
               Report.Failed ("test 3 - Constraint_Error not raised");
               Check (Z, Z, "not executed - optimizer thwarting", 0.0);
            end if;
         exception
            when Constraint_Error => null;  -- expected
            when others =>
               Report.Failed ("exception in test 3");
         end;

         --- test 4 ---
	 declare
            T : constant := Real'Model_EMin + 1;
            Tiny : constant := (1.0 * Real'Machine_Radix) ** T;
	    U : Complex := (Tiny, Tiny);
            X : Complex := (0.0, 0.0);
	    Z : Complex;
         begin
            if Real'Machine_Overflows then
               Z := U / X;
               Report.Failed ("test 4 - Constraint_Error not raised");
               Check (Z, Z, "not executed - optimizer thwarting", 0.0);
            end if;
         exception
            when Constraint_Error => null;  -- expected
            when others =>
               Report.Failed ("exception in test 4");
         end;


         --- test 5 ---
	 declare
	    X : Complex := (Sqrt2, Sqrt2);
            Z : Complex;
            Expected : constant Complex := (0.0, 4.0);
         begin
            Z := X * X;
            Check (Z, Expected, "test 5 -- (sqrt2,sqrt2) * (sqrt2,sqrt2)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 5");
            when others =>
               Report.Failed ("exception in test 5");
         end;

         --- test 6 ---
	 declare
	    X : Complex := Sqrt3 - Sqrt3 * i;
            Z : Complex;
            Expected : constant Complex := (0.0, -6.0);
         begin
            Z := X * X;
            Check (Z, Expected, "test 6 -- (sqrt3,-sqrt3) * (sqrt3,-sqrt3)",
                   Mult_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 6");
            when others =>
               Report.Failed ("exception in test 6");
         end;

         --- test 7 ---
	 declare
	    X : Complex := Sqrt2 + Sqrt2 * i;
	    Y : Complex := Sqrt2 - Sqrt2 * i;
            Z : Complex;
            Expected : constant Complex := 0.0 + i;
         begin
            Z := X / Y;
            Check (Z, Expected, "test 7 -- (sqrt2,sqrt2) / (sqrt2,-sqrt2)",
                   Divide_MBE);
         exception
            when Constraint_Error =>
               Report.Failed ("Constraint_Error raised in test 7");
            when others =>
               Report.Failed ("exception in test 7");
         end;
      end Special_Values;


      procedure Do_Mult_Div (X, Y : Complex) is
	 Z : Complex;
	 Args : constant String :=
	   "X=(" & Real'Image (X.Re) & "," & Real'Image (X.Im) & ") " &
	   "Y=(" & Real'Image (Y.Re) & "," & Real'Image (Y.Im) & ") " ;
      begin
	 Z := (X * X) / X;
	 Check (Z, X, "X*X/X " & Args, Mult_MBE + Divide_MBE);
	 Z := (X * Y) / X;
	 Check (Z, Y, "X*Y/X " & Args, Mult_MBE + Divide_MBE);
	 Z := (X * Y) / Y;
	 Check (Z, X, "X*Y/Y " & Args, Mult_MBE + Divide_MBE);
      exception
         when Constraint_Error =>
            Report.Failed ("Constraint_Error in Do_Mult_Div for " & Args);
         when others =>
            Report.Failed ("exception in Do_Mult_Div for " & Args);
      end Do_Mult_Div;

      -- select complex values X and Y where the real and imaginary
      -- parts are selected from the ranges (1/radix..1) and
      -- (1..radix).  This translates into quite a few combinations.
      procedure Mult_Div_Check is
         Samples : constant := 17;
	 Radix : constant Real := Real(Real'Machine_Radix);
	 Inv_Radix : constant Real := 1.0 / Real(Real'Machine_Radix);
	 Low_Sample : Real;  -- (1/radix .. 1)
	 High_Sample : Real; -- (1 .. radix)
	 Sample : array (1..2) of Real;
	 X, Y : Complex;
      begin
         for I in 1 .. Samples loop
            Low_Sample := (1.0 - Inv_Radix) / Real (Samples) * Real (I) +
			  Inv_Radix;
	    Sample (1) := Low_Sample;
	    for J in 1 .. Samples loop
               High_Sample := (Radix - 1.0) / Real (Samples) * Real (I) +
			      Radix;
	       Sample (2) := High_Sample;
	       for K in 1 .. 2 loop
		  for L in 1 .. 2 loop
		     X := Complex'(Sample (K), Sample (L));
		     Y := Complex'(Sample (L), Sample (K));
		     Do_Mult_Div (X, Y);
                     if Failure_Detected then
                        return;   -- minimize flood of error messages
                     end if;
		  end loop;
	       end loop;
            end loop;  -- J
         end loop;  -- I
      end Mult_Div_Check;


      procedure Do_Test is
      begin
         Special_Values;
         Mult_Div_Check;
      end Do_Test;
   end Non_Generic_Check;

   -----------------------------------------------------------------------
   -----------------------------------------------------------------------

begin
   Report.Test ("CXG2008",
                "Check the accuracy of the complex multiplication and" &
                " division operators");

   if Verbose then
      Report.Comment ("checking Standard.Float");
   end if;

   Float_Check.Do_Test;

   if Verbose then
      Report.Comment ("checking a digits" &
                      Integer'Image (System.Max_Digits) &
                      " floating point type");
   end if;

   A_Long_Float_Check.Do_Test;

   if Verbose then
      Report.Comment ("checking non-generic package");
   end if;

   Non_Generic_Check.Do_Test;

   Report.Result;
end CXG2008;
