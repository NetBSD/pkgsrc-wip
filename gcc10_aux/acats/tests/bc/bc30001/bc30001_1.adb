

     --===================================================================--


package body BC30001_1 is

   package body Derived_In_Body is

      type Derived_Type is new Formal_Private;

      procedure Dummy_Proc (P: Formal_Private) is
      begin
         null;
      end Dummy_Proc;

   end Derived_In_Body;

end BC30001_1;
