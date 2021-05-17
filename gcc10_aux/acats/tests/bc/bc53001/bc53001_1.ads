

     --==================================================================--


with BC53001_0;
package BC53001_1 is

   function Upper_Bound return Natural renames BC53001_0;


   subtype Index_Static    is Natural range 1 .. 100;
   subtype Index_NonStatic is Natural range 1 .. Upper_Bound;


   type Record_Type (L: Index_Static := 10) is record
      S: String (1 .. L);
   end record;

   subtype Record_Comp is Record_Type(10);


   generic
      type Formal_Unconstr is array (Index_Nonstatic range <>) of Record_Comp;
   package Unconstrained_Formal is end;

   generic
      type Formal_Constr is array (Index_Static) of Record_Comp;
   package Constrained_Formal is end;

   generic
      type Formal_SEG_Constr is (<>);
   package Constrained_SEG_Formal is 
      subtype Same_Elab_Constr is Formal_SEG_Constr;
      type Unconstr_Arr is array (Same_Elab_Constr range <>) of Record_Comp;
   end Constrained_SEG_Formal;

end BC53001_1;
