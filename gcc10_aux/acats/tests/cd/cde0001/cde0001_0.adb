
     --==================================================================--

package body CDE0001_0 is

   package body CDE0001_1 is

      procedure Assign_Objects is
      begin
         Formal_Obj01 := Private_Type'First;
         Formal_Obj02 := Limited_Private'Last;
         Formal_Obj03 := Private_Subtype'Last;
         Formal_Obj04 := Limited_Private_Subtype'First;
         Formal_Obj05 := New_TagType'(C1 => 2, C2 => Private_Type'Last);

      end Assign_Objects;

   end CDE0001_1;

   --===========================================================--

   package body CDE0001_2 is

      procedure Assign_Arrays (P1 : out Formal_Arr01;
                               P2 : out Formal_Arr02) is
      begin
         P1(1)    := Private_Type'Pred(Private_Type'Last);
         P1(2)    := Private_Type'Succ(Private_Type'First);
         P2(1).C1 := Limited_Private'Succ(Limited_Private'First);
         P2(2).C1 := Limited_Private'Pred(Limited_Private'Last);

      end Assign_Arrays;

      -----------------------------------------------------------------
      procedure Assign_Access (P1 : out Formal_Acc01;
                               P2 : out Formal_Acc02) is
      begin
         P1 := new Rec_Of_Private_Subtype'(C1 => Private_Subtype'Last);
         P2 := new Array_Of_LP_Subtype'(Eh, Dee);

      end Assign_Access;

   end CDE0001_2;

end CDE0001_0;
