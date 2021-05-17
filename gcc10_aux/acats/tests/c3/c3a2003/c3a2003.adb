

     --==================================================================--


with C3A2003_0;
use  C3A2003_0;

with Report; use report;

procedure C3A2003 is

   type Acc_L1 is access all Desig;                               -- Level = 1.
   A1  : Acc_L1;
   X1 : aliased Desig := (Desig'Range => Ident_Int(3));
   Res : Result_Kind;


   procedure Called_By_Target_L1 (X: access Desig; R: out Result_Kind) is
   begin
      -- The accessibility level of the type of A1 is 1.
      A1 := X.all'Access;
      if IDENT_INT (A1(4)) /= 3 then       --Avoid optimization of A1
        FAILED ("Initial values not correct.");
      end if;
      R  := OK;
   exception
      when Program_Error =>
         R := P_E;
      when others        =>
         R := O_E;
   end Called_By_Target_L1;

   ------------------------------------------------------------------

   function Target_Is_Level_1_Same (Y: access Desig) return Result_Kind is
      S : Result_Kind;
   begin
      Called_By_Target_L1 (Y, S);
      return S;
   end Target_Is_Level_1_Same;

   ------------------------------------------------------------------

   procedure Display_Results (Result  : in Result_Kind;
                              Expected: in Result_Kind;
                              Msg     : in String) is
   begin
      if Result /= Expected then
         case Result is
            when OK  => Report.Failed ("No exception raised: "         & Msg);
            when P_E => Report.Failed ("Program_Error raised: "        & Msg);
            when O_E => Report.Failed ("Unexpected exception raised: " & Msg);
         end case;
      end if;
   end Display_Results;

begin -- C3A2003

   Report.Test ("C3A2003", "Check that, for X'Access of general access "   &
                "type A, Program_Error is raised if the accessibility "    &
                "level of X is deeper than that of A: X is an access "     &
                "parameter; corresponding actual is another access "       &
                "parameter");


   -- Accessibility level of actual is 0 (actual is X'Access):

   Never_Fails_Same (X0'Access, Res);
   Display_Results (Res, OK, "Never_Fails_Same, level 0 actual");

   Never_Fails_Nest (X0'Access, Res);
   Display_Results (Res, OK, "Target_L1_Nest, level 0 actual");

   Target_Is_Level_0_Nest (X0'Access, Res);
   Display_Results (Res, OK, "Target_L0_Nest, level 0 actual");

   Res := Target_Is_Level_1_Same (X0'Access);
   Display_Results (Res, OK, "Target_L1_Same, level 0 actual");


   -- Accessibility level of actual is 1 (actual is X'Access):

   Never_Fails_Same (X1'Access, Res);
   Display_Results (Res, OK, "Never_Fails_Same, level 1 actual");

   Never_Fails_Nest (X1'Access, Res);
   Display_Results (Res, OK, "Target_L1_Nest, level 1 actual");

   Target_Is_Level_0_Nest (X1'Access, Res);
   Display_Results (Res, P_E, "Target_L0_Nest, level 1 actual");

   Res := Target_Is_Level_1_Same (X1'Access);
   Display_Results (Res, OK, "Target_L1_Same, level 1 actual");


   Block_L2:
   declare
      X2 : aliased Desig := (Desig'Range => Ident_Int(3));
      type Acc_L2 is access all Desig;                            -- Level = 2.
      Expr_L2 : Acc_L2 := X2'Access;
   begin

      -- Accessibility level of actual is 2 (actual is expression of named
      -- access type):

      Never_Fails_Same (Expr_L2, Res);
      Display_Results (Res, OK, "Never_Fails_Same, level 2 actual");

      Never_Fails_Nest (Expr_L2, Res);
      Display_Results (Res, OK, "Target_L1_Nest, level 2 actual");

      Target_Is_Level_0_Nest (Expr_L2, Res);
      Display_Results (Res, P_E, "Target_L0_Nest, level 2 actual");

      Res := Target_Is_Level_1_Same (Expr_L2);
      Display_Results (Res, P_E, "Target_L1_Same, level 2 actual");

   end Block_L2;

   Report.Result;

end C3A2003;
