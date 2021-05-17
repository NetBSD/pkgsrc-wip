

     --==================================================================--


package B3A2009 is

   generic
      type Acc_Formal is access procedure;
   procedure Gen_Procedure;


   generic
      type Acc_Formal is access procedure;
   package Gen_Package is

      type Acc_GenDecl is access procedure;

      AForm : Acc_Formal;
      ADecl : Acc_GenDecl;

      procedure Some_Operation;

   end Gen_Package;

end B3A2009;
