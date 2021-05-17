

     --==================================================================--


with BB20001_1;
generic                                                
   with package Formal_Pck2 is new BB20001_1 (<>);  
package BB20001_2 is                                   
   Exception_2           : exception;
   RN_FP_Exception_2     : exception renames Formal_Pck2.FP_Exception_1;
   RN_Common_Exception_2 : exception renames Formal_Pck2.RN_Common_Exception_1;
   package RN_FPck2 renames Formal_Pck2;
   function Do_Something (P : Formal_Pck2.Element_Type) return 
     Formal_Pck2.Element_Type;
end BB20001_2;
