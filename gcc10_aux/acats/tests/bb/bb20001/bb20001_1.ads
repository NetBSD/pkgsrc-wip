
     --==================================================================--

with BB20001_0;
generic                                                
   type Element_Type is private;                      
package BB20001_1 is                                   
   FP_Exception_1        : exception;
   RN_Common_Exception_1 : exception renames BB20001_0.Common_Exception;
end BB20001_1;
