

     --==================================================================--


with CC51004_0;  -- Matrix types.
with CC51004_1;  -- Generic double-matrix "clear" operation.

with Report;
procedure CC51004 is

   use CC51004_0;  -- "/=" operator directly visible for Sq_Type.

   -- Matrices of root type:

   Mat_2x2      : Square(Side => 2)  := (Side => 2, Mat => ( (1, 2), (3, 4) ));
   One_Mat_2x2  : Sq_Type(Num1 => 2) := (2, Mat_2x2);

   Zero_2x2     : constant Square(2)  := (2, Mat => ( (0, 0), (0, 0) ));
   Expected_2x2 : constant Sq_Type(2) := (Num1 => 2, One => Zero_2x2);


   Mat_3x3      : Square(Side => 3) := (Side => 3,
                                        Mat  => (1      => (5, 2, 7),
                                                 others => (1      => 4,
                                                            others => 9)));
   One_Mat_3x3  : Sq_Type(3)        := (Num1 => 3, One => Mat_3x3);

   Zero_3x3     : constant Square(3)        := (3, Mat => (others => (0,0,0)));
   Expected_3x3 : constant Sq_Type(Num1 => 3) := (3, Zero_3x3);


   New_Dbl_2x2      : New_Dbl_Sq(Num2 => 2) := (2, others => Mat_2x2);
   Expected_New_2x2 : constant New_Dbl_Sq := (2, Zero_2x2, Mat_2x2);



   -- Instantiations:

   procedure Clr_Mat is new CC51004_1 (Sq_Type);
   procedure Clr_New_Dbl is new CC51004_1 (New_Dbl_Sq);


begin
   Report.Test ("CC51004", "Check that a formal derived tagged type " &
                           "inherits components, including discriminants, " &
                           "from its ancestor type");

   -- Simulate use of matrix manipulation operations.


   Clr_Mat (One_Mat_2x2);

   if (One_Mat_2x2 /= Expected_2x2) then
      Report.Failed ("Wrong result root type (2x2 matrix)");
   end if;


   Clr_Mat (One_Mat_3x3);

   if (One_Mat_3x3 /= Expected_3x3) then
      Report.Failed ("Wrong result root type (3x3 matrix)");
   end if;


   Clr_New_Dbl (New_Dbl_2x2);

   if (New_Dbl_2x2 /= Expected_New_2x2) then
      Report.Failed ("Wrong result extended type (2x2 matrix)");
   end if;


   Report.Result;
end CC51004;
