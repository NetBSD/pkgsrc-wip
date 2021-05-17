

     --===================================================================--


with BC30001_0;
package BC30001_1 is

   generic
      type Formal_Private is private;
   package Derived_In_Visible_Part is
      type Derived_Type is new Formal_Private;
   end Derived_In_Visible_Part;



   generic
      type Formal_Private is private;
   package Derived_In_Private_Part is
      type Derived_Type is private;           -- View visible outside instance.
   private
      type Derived_Type is new Formal_Private;
   end Derived_In_Private_Part;



   generic
      type Formal_Private is private;
   package Derived_In_Body is

      procedure Dummy_Proc (P: Formal_Private);       -- Needed to allow body
                                                      -- for BC30001_1.
   end Derived_In_Body;

end BC30001_1;
