

     --==================================================================--


with BC53001_1;
use  BC53001_1;
package BC53001_2 is

--
-- Nonstatic index subtypes:
--

   subtype Same_Elab_Constraint is Index_Nonstatic;
   subtype Dupl_Range_Nonstatic is Natural range 1 .. Upper_Bound;


--
-- Static index subtypes:
--

   subtype Attr_Range_Static is Natural range
     Index_Static'first .. Index_Static'last;

   subtype Diff_Range_Static is Index_Static range 2 .. 100;



--
-- Component subtypes:
--

   type    New_Record_Type      is new Record_Comp;
   subtype Same_Disc_Constraint is Record_Type(10);


--
-- Unconstrained array actuals:
--

   type Unconstr_Arr1 is array (Index_Nonstatic      range <>) of Record_Comp;
   type Unconstr_Arr2 is array (Same_Elab_Constraint range <>) of Record_Comp;
   type Unconstr_Arr3 is array (Dupl_Range_Nonstatic range <>) of Record_Comp;


--
-- Constrained array actuals (with various index subtypes):
--

   type Constr_Arr1 is array (1 .. 100)          of Record_Comp;
   type Constr_Arr2 is array (Attr_Range_Static) of Record_Comp;
   type Constr_Arr3 is array (Diff_Range_Static) of Record_Comp;


--
-- Constrained array actuals (with various component subtypes):
--

   type Constr_Arr4 is array (Index_Static) of Record_Type;
   type Constr_Arr5 is array (Index_Static) of New_Record_Type;
   type Constr_Arr6 is array (Index_Static) of Same_Disc_Constraint;


end BC53001_2;
