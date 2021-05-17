  
     --==================================================================--

with Report;
with CA11013_2;                       -- Random number generator.
with CA11013_3.CA11013_4;             -- Complex abstraction + Random complex 
                                      -- number operation.
procedure CA11013 is

   package My_Complex_Pkg renames CA11013_3;
   use type CA11013_2.My_Float;

   My_Complex                 : My_Complex_Pkg.Complex_Type;
   My_Literal                 : CA11013_2.My_Float := 3.0;
   My_Real_Part, My_Imag_Part : CA11013_2.My_Float;

begin

   Report.Test ("CA11013", "Check that child instance can use its parent's "  &
                           "declarations and operations, including a formal " &
                           "subprogram of the parent");

   My_Complex := CA11013_3.CA11013_4 (My_Literal); 
                 -- Operation from the generic child function.

   My_Complex_Pkg.Components (My_Complex, My_Real_Part, My_Imag_Part);
                 -- Operation from the generic parent package.

   if My_Real_Part /= 6.0           -- Operation from the generic 
     or My_Imag_Part /= 9.0         -- parent package.
       then
         Report.Failed ("Incorrect results from complex operation");
   end if;

   Report.Result;

end CA11013;
