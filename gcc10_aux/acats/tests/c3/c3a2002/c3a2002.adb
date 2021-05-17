

     --==================================================================--


with C3A2002_0;
with Report;

procedure C3A2002 is

   X1 : aliased C3A2002_0.Desig;                                  -- Level = 1.

   type Acc_L1 is access all C3A2002_0.Desig;                     -- Level = 1.
   A1 : Acc_L1;

   Expr_L0 : C3A2002_0.Acc_L0 := C3A2002_0.X0'Access;
   Expr_L1 : Acc_L1           := X1'Access;

   Res : C3A2002_0.Result_Kind;

   use type C3A2002_0.Result_Kind;

   -----------------------------------------------
   procedure A_Is_Level_1 (X : access C3A2002_0.Desig;
                           R : out C3A2002_0.Result_Kind) is
      -- Dereference of an access_to_object value is aliased.
      Ren : C3A2002_0.Desig renames X.all;      -- Renaming of a dereference
   begin                                        -- of an access parameter.
      -- The accessibility level of the type of A1 is 1.
      A1 := Ren'Access;
      R  := C3A2002_0.OK;
   exception
      when Program_Error =>    
         R := C3A2002_0.P_E;
      when others        =>    
         R := C3A2002_0.O_E;
   end A_Is_Level_1;

   -----------------------------------------------
   procedure Display_Results (Result  : in C3A2002_0.Result_Kind;
                              Expected: in C3A2002_0.Result_Kind;
                              Message : in String) is
   begin
      if Result /= Expected then
         case Result is
            when C3A2002_0.OK  => Report.Failed ("No exception raised: "  & 
                                                 Message);
            when C3A2002_0.P_E => Report.Failed ("Program_Error raised: " & 
                                                 Message);
            when C3A2002_0.O_E => Report.Failed ("Unexpected exception "  &
                                                 "raised: " & Message);
         end case;
      end if;
   end Display_Results;

begin -- C3A2002 

   Report.Test ("C3A2002", "Check that, for X'Access of general access "   &
                "type A, Program_Error is raised if the accessibility "    &
                "level of X is deeper than that of A: X is an access "     &
                "parameter; corresponding actual is an allocator, "        &
                "expression of a named access type, Obj'Access, or a "     &
                "rename thereof");


   -- Actual is X'Access:

   C3A2002_0.Never_Fails (C3A2002_0.X0'Access, Res);
   Display_Results (Res, C3A2002_0.OK, "X0'Access, local access type");

   C3A2002_0.A_Is_Level_0 (C3A2002_0.X0'Access, Res);
   Display_Results (Res, C3A2002_0.OK, "X0'Access, level 0 access type");

   C3A2002_0.A_Is_Level_0 (X1'Access, Res);
   Display_Results (Res, C3A2002_0.P_E, "X1'Access, level 0 access type");

   A_Is_Level_1 (X1'Access, Res);
   Display_Results (Res, C3A2002_0.OK, "X1'Access, level 1 access type");


   -- Actual is expression of a named access type:

   C3A2002_0.Never_Fails (Expr_L1, Res);
   Display_Results (Res, C3A2002_0.OK, "Expr_L1, local access type");

   C3A2002_0.A_Is_Level_0 (Expr_L1, Res);
   Display_Results (Res, C3A2002_0.P_E, "Expr_L1, level 0 access type");

   A_Is_Level_1 (Expr_L0, Res);
   Display_Results (Res, C3A2002_0.OK, "Expr_L0, level 1 access type");

   A_Is_Level_1 (Expr_L1, Res);
   Display_Results (Res, C3A2002_0.OK, "Expr_L1, level 1 access type");

   -- Actual is allocator (level of execution = 2):

   C3A2002_0.Never_Fails (new C3A2002_0.Desig, Res);
   Display_Results (Res, C3A2002_0.OK, "Allocator level 2, " &
                                       "local access type");

   -- Since actual is an allocator, its accessibility level is that of
   -- the execution of the called subprogram, i.e., level 2.

   C3A2002_0.A_Is_Level_0 (new C3A2002_0.Desig, Res);
   Display_Results (Res, C3A2002_0.P_E, "Allocator level 2, " &
                                        "level 0 access type");

   A_Is_Level_1 (new C3A2002_0.Desig, Res);
   Display_Results (Res, C3A2002_0.P_E, "Allocator level 2, " &
                                        "level 1 access type");


   Block_L2:
   declare
      X2 : aliased C3A2002_0.Desig;                               -- Level = 2.
      type Acc_L2 is access all C3A2002_0.Desig;                  -- Level = 2.
      Expr_L2 : Acc_L2 := X1'Access;
   begin

      -- Actual is X'Access:

      C3A2002_0.Never_Fails (X2'Access, Res);
      Display_Results (Res, C3A2002_0.OK, "X2'Access, local access type");

      C3A2002_0.A_Is_Level_0 (X2'Access, Res);
      Display_Results (Res, C3A2002_0.P_E, "X2'Access, level 0 access type");


      -- Actual is expression of a named access type:

      A_Is_Level_1 (Expr_L2, Res);
      Display_Results (Res, C3A2002_0.P_E, "Expr_L2, level 1 access type");


      -- Actual is allocator (level of execution = 3):

      C3A2002_0.Never_Fails (new C3A2002_0.Desig, Res);
      Display_Results (Res, C3A2002_0.OK, "Allocator level 3, " &
                                          "local access type");

      A_Is_Level_1 (new C3A2002_0.Desig, Res);
      Display_Results (Res, C3A2002_0.P_E, "Allocator level 3, " &
                                           "level 1 access type");

   end Block_L2;

   Report.Result;

end C3A2002;
