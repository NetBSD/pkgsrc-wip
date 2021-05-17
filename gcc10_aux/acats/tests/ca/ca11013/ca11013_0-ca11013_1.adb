
               --==============================================--

function CA11013_0.CA11013_1 (Seed : Real_Type) return Complex_Type is

   Random_Real_Part  :  Real_Type  := Random_Generator (Seed);
                                      -- parent's formal subprogram
   Random_Imag_Part  :  Real_Type  
                     := Random_Generator (Random_Generator (Seed));
                                      -- parent's formal subprogram
   Random_Complex_No :  Complex_Type;

begin -- CA11013_0.CA11013_1

   Random_Complex_No := Make (Random_Real_Part, Random_Imag_Part);
                                      -- operation from parent
   return (Random_Complex_No); 

end CA11013_0.CA11013_1;
