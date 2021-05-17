

     --===================================================================--


with B641001_0;
with B641001_1;
generic                                                   -- Generic in which
                                                          -- illegal calls
   with package Formal_Pack is new B641001_1 (<>);        -- are attempted.

   type Acc_Type is access constant B641001_0.Designated;

   Local_Form_Obj  : in out Acc_Type;
   FP_Loc_Form_Obj : in out Formal_Pack.FP_Local_Acc;

package B641001 is

--
-- Declarations using formal type local to B641001:
--

   procedure Local_Calls (Acc_Parm : in out Acc_Type);


   Local_Stat : Acc_Type := B641001_0.Rec'Access;
   Local_Dyna : Acc_Type := new B641001_0.Designated'(B641001_0.Rec);

   Loc_DVar   : B641001_0.Designated;
   Loc_CVar   : B641001_0.Component := 2;
   Loc_CVar2  : B641001_0.Component := 3;


   procedure Local_Acc_Op (P_In    : in     Acc_Type;
                           P_InOut : in out Acc_Type;
                           P_Out   :    out Acc_Type);

   procedure Local_Des_Op (P_In    : in     B641001_0.Designated;
                           P_InOut : in out B641001_0.Designated;
                           P_Out   :    out B641001_0.Designated);

   procedure Local_Cmp_Op (P_In    : in     B641001_0.Component;
                           P_InOut : in out B641001_0.Component;
                           P_Out   :    out B641001_0.Component);


--
-- Declarations using formal type of Formal_Pack:
--

   procedure FP_Formal_Calls (Acc_Parm : in out Formal_Pack.FP_Formal_Acc);


   FP_Form_Stat : Formal_Pack.FP_Formal_Acc :=
                  Formal_Pack.Priv'Access;
   FP_Form_Dyna : Formal_Pack.FP_Formal_Acc :=
                  new Formal_Pack.FP_Formal_Des'(Formal_Pack.Priv);

   FP_Form_DVar : Formal_Pack.FP_Formal_Des;


   procedure FP_Form_Acc_Op (P_In    : in     Formal_Pack.FP_Formal_Acc;
                             P_InOut : in out Formal_Pack.FP_Formal_Acc;
                             P_Out   :    out Formal_Pack.FP_Formal_Acc);

   procedure FP_Form_Des_Op (P_In    : in     Formal_Pack.FP_Formal_Des;
                             P_InOut : in out Formal_Pack.FP_Formal_Des;
                             P_Out   :    out Formal_Pack.FP_Formal_Des);


--
-- Declarations using type declared within Formal_Pack:
--

   procedure FP_Local_Calls (Acc_Parm : in out Formal_Pack.FP_Local_Acc);


   FP_Local_Stat : Formal_Pack.FP_Local_Acc :=
                   Formal_Pack.Tag'Access;
   FP_Local_Dyna : Formal_Pack.FP_Local_Acc :=
                   new Formal_Pack.FP_Local_Desig'(Formal_Pack.Tag);

   FP_Loc_DVar   : Formal_Pack.FP_Local_Desig;
   FP_Loc_CVar   : B641001_0.Component := 5;
   FP_Loc_CVar2  : B641001_0.Component := 9;


   procedure FP_Loc_Acc_Op (P_In    : in     Formal_Pack.FP_Local_Acc;
                            P_InOut : in out Formal_Pack.FP_Local_Acc;
                            P_Out   :    out Formal_Pack.FP_Local_Acc);

   procedure FP_Loc_Des_Op (P_In    : in     Formal_Pack.FP_Local_Desig;
                            P_InOut : in out Formal_Pack.FP_Local_Desig;
                            P_Out   :    out Formal_Pack.FP_Local_Desig);

   procedure FP_Loc_Cmp_Op (P_In    : in     B641001_0.Component;
                            P_InOut : in out B641001_0.Component;
                            P_Out   :    out B641001_0.Component);

end B641001;
