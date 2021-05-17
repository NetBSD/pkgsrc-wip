

     --==================================================================--


with C460001_0;
with Report;

procedure C460001 is

   X1 : aliased C460001_0.Desig;                                  -- Level = 1.

   type Acc_L1 is access all C460001_0.Desig;                     -- Level = 1.
   A1 : Acc_L1;

   Expr_L0 : C460001_0.Acc_L0 := C460001_0.X0'Access;
   Expr_L1 : Acc_L1           := X1'Access;

   Res : C460001_0.Result_Kind;

   use type C460001_0.Result_Kind;

   -----------------------------------------------
   procedure Target_Is_Level_1 (X : access C460001_0.Desig;
                                R : out C460001_0.Result_Kind) is
   begin
      -- The accessibility level of type Acc_L1 is 1.
      A1 := Acc_L1(X);
      R  := C460001_0.OK;
   exception
      when Program_Error =>    
         R := C460001_0.P_E;
      when others        =>    
         R := C460001_0.O_E;
   end Target_Is_Level_1;

   -----------------------------------------------
   procedure Display_Results (Result  : in C460001_0.Result_Kind;
                              Expected: in C460001_0.Result_Kind;
                              Message : in String) is
   begin
      if Result /= Expected then
         case Result is
            when C460001_0.OK  => Report.Failed ("No exception raised: "  & 
                                                 Message);
            when C460001_0.P_E => Report.Failed ("Program_Error raised: " & 
                                                 Message);
            when C460001_0.O_E => Report.Failed ("Unexpected exception "  &
                                                 "raised: " & Message);
         end case;
      end if;
   end Display_Results;

begin -- C460001

   Report.Test ("C460001", "Check that if the target type of a type "      &
                "conversion is a general access type, Program_Error is "   &
                "raised if the accessibility level of the operand type "   &
                "is deeper than that of the target type: operand is an "   &
                "access parameter; corresponding actual is an allocator, " &
                "expression of a named access type, Obj'Access");


   -- Actual is X'Access:

   C460001_0.Never_Fails (X1'Access, Res);
   Display_Results (Res, C460001_0.OK, "X1'Access, local access type");

   C460001_0.Target_Is_Level_0 (X1'Access, Res);
   Display_Results (Res, C460001_0.P_E, "X1'Access, level 0 access type");

   Target_Is_Level_1 (C460001_0.X0'Access, Res);
   Display_Results (Res, C460001_0.OK, "X0'Access, level 1 access type");

   Target_Is_Level_1 (X1'Access, Res);
   Display_Results (Res, C460001_0.OK, "X1'Access, level 1 access type");

   C460001_0.Target_Is_Level_0 (C460001_0.X0'Access, Res);
   Display_Results (Res, C460001_0.OK, "X0'Access, level 0 access type");


   -- Actual is expression of a named access type:

   C460001_0.Never_Fails (Expr_L0, Res);
   Display_Results (Res, C460001_0.OK, "Expr_L0, local access type");

   C460001_0.Target_Is_Level_0 (Expr_L0, Res);
   Display_Results (Res, C460001_0.OK, "Expr_L0, level 0 access type");

   C460001_0.Target_Is_Level_0 (Expr_L1, Res);
   Display_Results (Res, C460001_0.P_E, "Expr_L1, level 0 access type");

   Target_Is_Level_1 (Expr_L1, Res);
   Display_Results (Res, C460001_0.OK, "Expr_L1, level 1 access type");

   Target_Is_Level_1 (Expr_L0, Res);
   Display_Results (Res, C460001_0.OK, "Expr_L0, level 1 access type");

   -- Actual is allocator (level of execution = 2):

   C460001_0.Never_Fails (new C460001_0.Desig, Res);
   Display_Results (Res, C460001_0.OK, "Allocator level 2, " &
                                       "local access type");

   C460001_0.Target_Is_Level_0 (new C460001_0.Desig, Res);
   Display_Results (Res, C460001_0.P_E, "Allocator level 2, " &
                                        "level 0 access type");

   Target_Is_Level_1 (new C460001_0.Desig, Res);
   Display_Results (Res, C460001_0.P_E, "Allocator level 2, " &
                                        "level 1 access type");


   Block_L2:
   declare
      X2 : aliased C460001_0.Desig;                               -- Level = 2.
      type Acc_L2 is access all C460001_0.Desig;                  -- Level = 2.
      Expr_L2 : Acc_L2 := X1'Access;
   begin

      -- Actual is X'Access:

      C460001_0.Never_Fails (X2'Access, Res);
      Display_Results (Res, C460001_0.OK, "X2'Access, local access type");

      Target_Is_Level_1 (X2'Access, Res);
      Display_Results (Res, C460001_0.P_E, "X2'Access, level 1 access type");

      -- Actual is expression of a named access type:

      C460001_0.Never_Fails (Expr_L2, Res);
      Display_Results (Res, C460001_0.OK, "Expr_L2, local access type");

      C460001_0.Target_Is_Level_0 (Expr_L2, Res);
      Display_Results (Res, C460001_0.P_E, "Expr_L2, level 0 access type");


      -- Actual is allocator (level of execution = 3):

      C460001_0.Never_Fails (new C460001_0.Desig, Res);
      Display_Results (Res, C460001_0.OK, "Allocator level 3, " &
                                          "local access type");

      Target_Is_Level_1 (new C460001_0.Desig, Res);
      Display_Results (Res, C460001_0.P_E, "Allocator level 3, " &
                                           "level 1 access type");

   end Block_L2;

   Report.Result;

end C460001;
