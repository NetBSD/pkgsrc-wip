

     --===================================================================--


with B3A0003_0;
with B3A0003_1;
generic                                                   -- Generic in which
                                                          -- illegal updating
   with package Formal_Package is new B3A0003_1 (<>);     -- is attempted.

   type Acc_Type is access constant B3A0003_0.Designated;

   Local_Formal_Obj    : in out Acc_Type;
   FP_Local_Formal_Obj : in out Formal_Package.FP_Local_Acc;

package B3A0003 is

--
-- Declarations using formal type local to B3A0003:
--

   Local_AC  : Acc_Type;
   Local_Val : Acc_Type := B3A0003_0.Rec'Access;

   procedure Local_Op (Acc_Parm : in out Acc_Type);


--
-- Declarations using formal type of Formal_Package:
--

   FP_Formal_AC  : Formal_Package.FP_Formal_Acc;
   FP_Formal_Val : Formal_Package.FP_Formal_Acc := Formal_Package.Priv'Access;

   procedure FP_Formal_Op (Acc_Parm : in out Formal_Package.FP_Formal_Acc);


--
-- Declarations using type declared within Formal_Package:
--

   FP_Local_AC  : Formal_Package.FP_Local_Acc;
   FP_Local_Val : Formal_Package.FP_Local_Acc := Formal_Package.Tag'Access;

   procedure FP_Local_Op (Acc_Parm : in out Formal_Package.FP_Local_Acc);

end B3A0003;
