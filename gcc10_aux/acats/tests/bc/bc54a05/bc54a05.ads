

     --===================================================================--


with FC54A00;
with BC54A05_0;
with BC54A05_1;
package BC54A05 is

--
-- Instantiations:
--

   -- Formal private (array) designated type:
   -- One level of indirection through formal package:

   package Instance01 is new BC54A05_0.Gen_Access_To_Var_Form_Priv
     (BC54A05_0.Desig_String, BC54A05_1.Acc_Same_String);             -- OK.


   package Instance02 is new BC54A05_0.Gen_Access_To_Var_Form_Priv
     (BC54A05_0.Desig_Msg_Static, BC54A05_1.Acc_String);              -- ERROR:
                       -- Designated subtypes do not both have null constraint.

   package Instance03 is new BC54A05_0.Gen_Access_To_Var_Form_Priv
     (BC54A05_0.Desig_Msg_Static, BC54A05_1.Acc_Msg10);               -- ERROR:
                                             -- Designated types are different.

   package Instance04 is new BC54A05_0.Gen_Access_To_Var_Form_Priv
     (BC54A05_0.Desig_Msg_Static, BC54A05_1.Acc_Msg20);               -- ERROR:
                            -- Designated subtypes have different index ranges.

   package Instance05 is new BC54A05_0.Gen_Access_To_Var_Form_Priv
     (BC54A05_0.Desig_Msg_Static, BC54A05_1.Acc_Msg_Nonstat);         -- ERROR:
                -- Designated type in formal is static; in actual is nonstatic.



   -- Generic formal (tagged private) designated type:

   package Instance06 is new BC54A05_0.Gen_Access_To_Var_Form_Derived
     (FC54A00.Tag, BC54A05_1.Acc_FD_New_Tag);                         -- ERROR:
                                             -- Designated types are different.

   package Instance07 is new BC54A05_0.Gen_Access_To_Var_Form_Derived
     (FC54A00.Tag, BC54A05_1.Acc_FD_Tag_Class);                       -- ERROR:
                                             -- Designated types are different.

   package Instance08 is new BC54A05_0.Gen_Access_To_Var_Form_Derived
     (FC54A00.Tag'Class, BC54A05_1.Acc_FD_Tag);                       -- ERROR:
                                             -- Designated types are different.

   package Instance09 is new BC54A05_0.Gen_Access_To_Var_Form_Derived
     (FC54A00.Tag20, BC54A05_1.Acc_FD_Tag25);                         -- ERROR:
                -- Designated subtypes have different discriminant constraints.

   package Instance10 is new BC54A05_0.Gen_Access_To_Var_Form_Derived
     (FC54A00.Tag20_Nonstatic, BC54A05_1.Acc_FD_Tag_Twenty);          -- ERROR:
                -- Designated type in formal is nonstatic; in actual is static.


end BC54A05;
