

     --==================================================================--


with CC51003_0;  -- Matrix types.
with CC51003_1;  -- Generic double-matrix "clear" operation.

with Report;
procedure CC51003 is

   use CC51003_0;  -- "/=" operator directly visible for Double_Square.

   -- Matrices of root type:

   Mat_2x2      : Square(Side => 2)           := (Side => 2,
                                                  Mat  => ( (1, 2), (3, 4) ));
   Dbl_Mat_2x2  : Double_Square(Number => 2)  := (2, Mat_2x2, Mat_2x2);


   Zero_2x2     : constant Square(2)        := (2, Mat => ( (0, 0), (0, 0) ));
   Expected_2x2 : constant Double_Square(2) := (Number => 2,
                                                others => Zero_2x2);



   Mat_3x3      : Square(Side => 3) := (Side => 3,
                                        Mat  => (1      => (1, 4, 9),
                                                 others => (1      => 5,
                                                            others => 7)));
   Dbl_Mat_3x3  : Double_Square(3)  := (Number => 3, others => Mat_3x3);


   Zero_3x3     : constant Square(3) := (3, Mat => (others => (0,0,0)));
   Expected_3x3 : constant Double_Square(Number => 3) :=
                                        (3, Zero_3x3, Zero_3x3);


   -- Derived type with new discriminant part (which constrains parent):

   type New_Dbl_Sq (Num : Natural) is new Double_Square(Num);

   New_Dbl_2x2      : New_Dbl_Sq (Num => 2) := (2, Mat_2x2, Mat_2x2);
   Expected_New_2x2 : constant New_Dbl_Sq   := (Num => 2, others => Zero_2x2);



   -- Instantiations:

   procedure Clr_Dbl is new CC51003_1 (Double_Square);
   procedure Clr_New_Dbl is new CC51003_1 (New_Dbl_Sq);


begin
   Report.Test ("CC51003", "Check that a formal derived record type " &
                           "inherits components, including discriminants, " &
                           "from its ancestor type");

   -- Simulate use of matrix manipulation operations.

   Clr_Dbl (Dbl_Mat_2x2);

   if (Dbl_Mat_2x2 /= Expected_2x2) then
      Report.Failed ("Wrong result for root type (2x2 matrix)");
   end if;


   Clr_Dbl (Dbl_Mat_3x3);

   if (Dbl_Mat_3x3 /= Expected_3x3) then
      Report.Failed ("Wrong result for root type (3x3 matrix)");
   end if;


   Clr_New_Dbl (New_Dbl_2x2);

   if (New_Dbl_2x2 /= Expected_New_2x2) then
      Report.Failed ("Wrong result for derived type (2x2 matrix)");
   end if;


   Report.Result;

end CC51003;
