
     --==================================================================--

with CA11012_2;                -- Package containing integer type
with CA11012_3.CA11012_4;      -- Complex abstraction + additional operations
with Report;

procedure CA11012 is

   package My_Complex_Pkg renames CA11012_3;

   package My_Complex_Operation renames CA11012_3.CA11012_4;

   use My_Complex_Pkg,                                -- All user-defined
       My_Complex_Operation;                          -- operators directly
                                                      -- visible.
   Complex_One, Complex_Two : Complex_Type;

begin

   Report.Test ("CA11012", "Check that child instance can use its parent's "  &
                           "declarations and operations, including a formal " &
                           "type of the parent");

   Correct_Range_Test:
   declare
      My_Literal  : CA11012_2.My_Integer := -3;

   begin
      Complex_One := Complex (-4, 7);          -- Operation from the generic 
                                               -- parent package.

      Complex_Two := My_Literal * Complex_One; -- Operation from the generic 
                                               -- child package.

      if Real_Part (Complex_Two) /= 12         -- Operation from the generic 
        or Imag_Part (Complex_Two) /= -21      -- child package.
          then
             Report.Failed ("Incorrect results from complex operation");
      end if;

   end Correct_Range_Test;

   ---------------------------------------------------------------

   Out_Of_Range_Test:
   declare
      My_Vector : CA11012_2.My_Integer;

   begin
      Complex_One := Complex (70, 70);         -- Operation from the generic 
                                               -- parent package.
      My_Vector := Vector_Magnitude (Complex_One);         
                     -- Operation from the generic child package.

      Report.Failed ("Exception not raised in child package");

   exception
      when Constraint_Error =>
        Report.Comment ("Exception is raised as expected");

      when others           =>
        Report.Failed ("Others exception is raised");

   end Out_Of_Range_Test;

   Report.Result;

end CA11012;
