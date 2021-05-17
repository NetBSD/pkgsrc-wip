

     --==================================================================--


with B3A2009_0;
use  B3A2009_0;
package body B3A2009 is

   procedure Gen_Procedure is

      type Acc_GenBody is access procedure;

      AForm : Acc_Formal;
      ABody : Acc_GenBody;

      procedure Designated is
      begin
         null;
      end Designated;

   begin
      AForm := Designated'Access;                              -- ERROR: {7;1}
                -- Type of Designated'Access not declared in this generic unit.

      ABody := Designated'Access;                              -- OK. {7;1}
   end Gen_Procedure;



   package body Gen_Package is

      type Acc_GenBody is access procedure;

      ABody : Acc_GenBody;

      procedure Designated is
      begin
         null;
      end Designated;


      procedure Some_Operation is
         type Acc_GenOp is access procedure;
         AOp : Acc_GenOp;
      begin
         AOut := Designated'Access;                            -- ERROR: {7;1}
                -- Type of Designated'Access not declared in this generic unit.

         AForm := Designated'Access;                           -- ERROR: {7;1}
                -- Type of Designated'Access not declared in this generic unit.

         ADecl := Designated'Access;                           -- OK. {7;1}

         ABody := Designated'Access;                           -- OK. {7;1}
         AOp   := Designated'Access;                           -- OK. {7;1}

      end Some_Operation;

   end Gen_Package;

end B3A2009;
