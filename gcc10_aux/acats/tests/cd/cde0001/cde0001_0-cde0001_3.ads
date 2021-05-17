
     --==================================================================--

-- The following private child package instantiates its parent private generic
-- package. 

with CDE0001_0;
pragma Elaborate (CDE0001_0); -- So generic unit can be instantiated.
private 
package CDE0001_0.CDE0001_3 is

   type Arr01 is array (Small_Int) of Private_Type;
   type Arr02 is array (Small_Int) of Rec_Of_Limited_Private;
   type Acc01 is access Rec_Of_Private_Subtype;
   type Acc02 is access Array_Of_LP_Subtype;

   package Formal_Types_Pck is new CDE0001_2 (Arr01, Arr02, Acc01, Acc02);
   
   Arr01_Obj : Arr01;
   Arr02_Obj : Arr02;
   Acc01_Obj : Acc01;
   Acc02_Obj : Acc02;

end CDE0001_0.CDE0001_3;
