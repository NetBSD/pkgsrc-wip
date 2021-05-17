
     --==================================================================--

-- Generic child of complex number package.  Child must be generic since 
-- parent is generic. 

generic               -- Complex additional operations

package CA11012_0.CA11012_1 is
 
   -- More operations on complex number. This child adds a layer of
   -- functionality to the parent generic.

   function Real_Part (Complex_No : Complex_Type)
     return Int_Type;

   function Imag_Part (Complex_No : Complex_Type)
     return Int_Type;

   function "*" (Factor : Int_Type; 
                 C      : Complex_Type) return Complex_Type;

   function Vector_Magnitude (Complex_No : Complex_Type)
     return Int_Type;

end CA11012_0.CA11012_1;
