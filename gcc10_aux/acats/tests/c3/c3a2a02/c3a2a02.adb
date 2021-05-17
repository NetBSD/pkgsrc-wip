

     --==================================================================--


with F3A2A00;
with C3A2A02_0;
with C3A2A02_1;
with C3A2A02_2;
with C3A2A02_3;

with Report;
procedure C3A2A02 is
begin -- C3A2A02.                                              -- [ Level = 1 ]

   Report.Test ("C3A2A02", "Run-time accessibility checks: instance " &
                "bodies. Type of X'Access is local or global to instance");


   SUBTEST1:
   declare                                                     -- [ Level = 2 ]
      Result1 : F3A2A00.TC_Result_Kind;
      Result2 : F3A2A00.TC_Result_Kind;
   begin -- SUBTEST1.

      declare                                                  -- [ Level = 3 ]
         package Pack_Same_Level renames C3A2A02_3;
      begin
         -- The accessibility level of Pack_Same_Level.X is that of the
         -- instance (0), not that of the renaming declaration. The level of
         -- the type of Pack_Same_Level.X'Access (F3A2A00.AccTagClass_L0) is
         -- 0. Therefore, the X'Access in Pack_Same_Level.Proc does not raise
         -- an exception when the subprogram is called. The level of execution
         -- of the subprogram is irrelevant:

         Pack_Same_Level.Proc;
         Result1 := F3A2A00.OK;                             -- Expected result.
      exception
         when Program_Error => Result1 := F3A2A00.P_E;
         when others        => Result1 := F3A2A00.O_E;
      end;

      F3A2A00.TC_Display_Results (Result1, F3A2A00.OK,
                                  "SUBTEST #1 (same level)");


      declare                                                  -- [ Level = 3 ]
         -- The instantiation of C3A2A02_0 should NOT result in any
         -- exceptions.

         package Pack_Deeper_Level is new C3A2A02_0 (F3A2A00.Tagged_Type);
      begin
         -- The accessibility level of Pack_Deeper_Level.X is that of the
         -- instance (3). The level of the type of Pack_Deeper_Level.X'Access
         -- (F3A2A00.AccTagClass_L0) is 0. Therefore, the X'Access in
         -- Pack_Deeper_Level.Proc propagates Program_Error when the
         -- subprogram is called:

         Pack_Deeper_Level.Proc;
         Result2 := F3A2A00.OK;
      exception
         when Program_Error => Result2 := F3A2A00.P_E;      -- Expected result.
         when others        => Result2 := F3A2A00.O_E;
      end;

      F3A2A00.TC_Display_Results (Result2, F3A2A00.P_E,
                                  "SUBTEST #1: deeper level");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #1: Program_Error incorrectly raised " &
                        "during instantiation of generic");
      when others        =>
         Report.Failed ("SUBTEST #1: Unexpected exception raised " &
                        "during instantiation of generic");
   end SUBTEST1;



   SUBTEST2:
   declare                                                     -- [ Level = 2 ]
      Result1 : F3A2A00.TC_Result_Kind;
      Result2 : F3A2A00.TC_Result_Kind;
   begin -- SUBTEST2.

      declare                                                  -- [ Level = 3 ]
         X_L3 : F3A2A00.Tagged_Type;
      begin
         declare                                               -- [ Level = 4 ]
            -- The accessibility level of the actual object corresponding to
            -- FObj in Pack_PE is 3. The level of the type of FObj'Access
            -- (F3A2A00.AccTag_L0) is 0. Therefore, the FObj'Access in Pack_PE
            -- propagates Program_Error when the instance body is elaborated:

            package Pack_PE is new C3A2A02_1 (X_L3);
         begin
            Result1 := F3A2A00.OK;
         end;
      exception
         when Program_Error => Result1 := F3A2A00.P_E;      -- Expected result.
         when others        => Result1 := F3A2A00.O_E;
      end;

      F3A2A00.TC_Display_Results (Result1, F3A2A00.P_E,
                                  "SUBTEST #2: deeper level");


      begin                                                    -- [ Level = 3 ]
         declare                                               -- [ Level = 4 ]
            -- The accessibility level of the actual object corresponding to
            -- FObj in Pack_OK is 0. The level of the type of FObj'Access
            -- (F3A2A00.AccTag_L0) is also 0. Therefore, the FObj'Access in
            -- Pack_OK does not raise an exception when the instance body is
            -- elaborated:

            package Pack_OK is new C3A2A02_1 (F3A2A00.X_L0);
         begin
            Result2 := F3A2A00.OK;                          -- Expected result.
         end;
      exception
         when Program_Error => Result2 := F3A2A00.P_E;
         when others        => Result2 := F3A2A00.O_E;
      end;

      F3A2A00.TC_Display_Results (Result2, F3A2A00.OK,
                                  "SUBTEST #2: same level");

   end SUBTEST2;



   SUBTEST3:
   declare                                                     -- [ Level = 2 ]
      Result1 : F3A2A00.TC_Result_Kind;
      Result2 : F3A2A00.TC_Result_Kind;
   begin -- SUBTEST3.

      declare                                                  -- [ Level = 3 ]
         X_L3 : F3A2A00.Tagged_Type;
      begin
         declare                                               -- [ Level = 4 ]
            -- Since the accessibility level of the type of X'Access in
            -- both cases within Pack_OK1 is that of the instance, and since
            -- X is either passed as an actual (in which case its level will
            -- not be deeper than that of the instance) or is declared within
            -- the instance (in which case its level is the same as that of
            -- the instance), no exception should be raised when the instance
            -- body is elaborated:

            package Pack_OK1 is new C3A2A02_2 (F3A2A00.Array_Type, X_L3);
         begin
            Result1 := F3A2A00.OK;                          -- Expected result.
         end;
      exception
         when Program_Error => Result1 := F3A2A00.P_E;
         when others        => Result1 := F3A2A00.O_E;
      end;

      F3A2A00.TC_Display_Results (Result1, F3A2A00.OK,
                                  "SUBTEST #3: 1st okay case");


      declare                                                  -- [ Level = 3 ]
         type My_Array is new F3A2A00.Array_Type;
      begin
         declare                                               -- [ Level = 4 ]
            -- Since the accessibility level of the type of X'Access in
            -- both cases within Pack_OK2 is that of the instance, and since
            -- X is either passed as an actual (in which case its level will
            -- not be deeper than that of the instance) or is declared within
            -- the instance (in which case its level is the same as that of
            -- the instance), no exception should be raised when the instance
            -- body is elaborated:

            package Pack_OK2 is new C3A2A02_2 (My_Array, F3A2A00.X_L0);
         begin
            Result2 := F3A2A00.OK;                          -- Expected result.
         end;
      exception
         when Program_Error => Result2 := F3A2A00.P_E;
         when others        => Result2 := F3A2A00.O_E;
      end;

      F3A2A00.TC_Display_Results (Result2, F3A2A00.OK,
                                  "SUBTEST #3: 2nd okay case");


   end SUBTEST3;



   Report.Result;

end C3A2A02;
