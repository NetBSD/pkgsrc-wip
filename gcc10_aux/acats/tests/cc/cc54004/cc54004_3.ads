

     --===================================================================--


with CC54004_0;
with CC54004_1;
with CC54004_2;
pragma Elaborate (CC54004_2);

package CC54004_3 is

   package Alert_Stacks is new CC54004_2 (Element_Type => CC54004_0.Alert,
                                          Element_Ptr  => CC54004_0.Alert_Ptr);

   -- All overriding versions of Handle visible at the point of instantiation.

   Alert_List  : Alert_Stacks.Stack_Type;

   procedure TC_Create_Alert_Stack;

end CC54004_3;
