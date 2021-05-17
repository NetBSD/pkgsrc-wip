
     --==================================================================--

with BB20001_1;
generic                                                
   with package Formal_Pck5 is new BB20001_1 (<>);  
package BB20001_5 is 
   procedure Proc_5;
   package RN_FPck5 renames Formal_Pck5;
end BB20001_5;
