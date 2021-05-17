
     --==================================================================--

-- Private generic child of Complex_Number.  

private

generic               

-- No parameter.

package CA11021_0.CA11021_1 is
 
   -- ... Other declarations.

   -- Low level operation on complex number. 
   function "+" (Left, Right : Complex_Type)              
     return Complex_Type;                     

   function "-" (Right : Complex_Type)                
     return Complex_Type;                             

   -- ... Various other operations in real application.

end CA11021_0.CA11021_1;
