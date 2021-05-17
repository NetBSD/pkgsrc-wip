
     --==================================================================--

with BB20001_2;

generic                                                
   with package Formal_Pck7 is new BB20001_2 (<>);  
package BB20001_7 is 
   Exception_7 : exception;
   package RN_FPck7 renames Formal_Pck7;
   procedure Proc_7;
end BB20001_7;
