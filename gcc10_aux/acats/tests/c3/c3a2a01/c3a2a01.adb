

     --==================================================================--


with F3A2A00;
with C3A2A01_0;
with C3A2A01_1;
with C3A2A01_2;

with Report;
procedure C3A2A01 is
begin -- C3A2A01.                                              -- [ Level = 1 ]

   Report.Test ("C3A2A01", "Run-time accessibility checks: instance " &
                "bodies. Type of X'Access is passed as actual to instance");


   SUBTEST1:
   declare                                                     -- [ Level = 2 ]
      Result : F3A2A00.TC_Result_Kind;
   begin -- SUBTEST1.

      declare                                                  -- [ Level = 3 ]
         type AccArr_L3 is access all F3A2A00.Array_Type;
      begin
         declare                                               -- [ Level = 4 ]
            -- The accessibility level of Pack.X is that of the instantiation
            -- (4). The accessibility level of the actual access type used to
            -- instantiate Pack is 3. Therefore, the X'Access in Pack
            -- propagates Program_Error when the instance body is elaborated:

            package Pack is new C3A2A01_0 (F3A2A00.Array_Type, AccArr_L3);
         begin
            Result := F3A2A00.OK;
         end;
      exception
         when Program_Error => Result := F3A2A00.P_E;       -- Expected result.
         when others        => Result := F3A2A00.O_E;
      end;

      F3A2A00.TC_Display_Results (Result, F3A2A00.P_E, "SUBTEST #1");

   end SUBTEST1;



   SUBTEST2:
   declare                                                     -- [ Level = 2 ]
      Result : F3A2A00.TC_Result_Kind;
   begin -- SUBTEST2.

      declare                                                  -- [ Level = 3 ]
         -- The instantiation of C3A2A01_1 should NOT result in any
         -- exceptions.

         type AccTag_L3 is access all F3A2A00.Tagged_Type;

         package Pack_OK is new C3A2A01_1 (F3A2A00.Tagged_Type,
                                           AccTag_L3,
                                           F3A2A00.X_L0);
      begin
         -- The accessibility level of the actual object used to instantiate
         -- Pack_OK is 0. The accessibility level of the actual access type
         -- used to instantiate Pack_OK is 3. Therefore, the FObj'Access in
         -- Pack_OK.Handle does not raise an exception when the subprogram is
         -- called. If an exception is (incorrectly) raised, however, it is
         -- handled within the subprogram:

         Pack_OK.Handle (Result);
      end;

      F3A2A00.TC_Display_Results (Result, F3A2A00.OK, "SUBTEST #2");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #2: Program_Error incorrectly raised " &
                        "during instantiation of generic");
      when others        =>
         Report.Failed ("SUBTEST #2: Unexpected exception raised " &
                        "during instantiation of generic");
   end SUBTEST2;



   SUBTEST3:
   declare                                                     -- [ Level = 2 ]
      Result : F3A2A00.TC_Result_Kind;
   begin -- SUBTEST3.

      declare                                                  -- [ Level = 3 ]
         -- The instantiation of C3A2A01_1 should NOT result in any
         -- exceptions.

         X_L3: F3A2A00.Tagged_Type;

         package Pack_PE is new C3A2A01_1 (F3A2A00.Tagged_Type,
                                           F3A2A00.AccTag_L0,
                                           X_L3);
      begin
         -- The accessibility level of the actual object used to instantiate
         -- Pack_PE is 3. The accessibility level of the actual access type
         -- used to instantiate Pack_PE is 0. Therefore, the FObj'Access in
         -- Pack_OK.Handle raises Program_Error when the subprogram is
         -- called. The exception is handled within the subprogram:

         Pack_PE.Handle (Result);
      end;

      F3A2A00.TC_Display_Results (Result, F3A2A00.P_E, "SUBTEST #3");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #3: Program_Error incorrectly raised " &
                        "during instantiation of generic");
      when others        =>
         Report.Failed ("SUBTEST #3: Unexpected exception raised " &
                        "during instantiation of generic");
   end SUBTEST3;



   SUBTEST4:
   declare                                                     -- [ Level = 2 ]
      Result1 : F3A2A00.TC_Result_Kind;
      Result2 : F3A2A00.TC_Result_Kind;
   begin -- SUBTEST4.

      declare                                                  -- [ Level = 3 ]
         -- The instantiation of C3A2A01_2 should NOT result in any
         -- exceptions.

         X_L3: aliased F3A2A00.Array_Type;
         type AccArr_L3 is access all F3A2A00.Array_Type;

         procedure Proc is new C3A2A01_2 (F3A2A00.Array_Type, AccArr_L3);
      begin
         -- The accessibility level of Proc.P.all is that of the corresponding
         -- actual during the call (in this case 3). The accessibility level of
         -- the access type used to instantiate Proc is also 3. Therefore, the
         -- P.all'Access in Proc does not raise an exception when the
         -- subprogram is called. If an exception is (incorrectly) raised,
         -- however, it is handled within the subprogram:

         Proc (X_L3'Access, Result1);

         F3A2A00.TC_Display_Results (Result1, F3A2A00.OK,
                                     "SUBTEST #4: same levels");

         declare                                               -- [ Level = 4 ]
            X_L4: aliased F3A2A00.Array_Type;
         begin
            -- Within this block, the accessibility level of the actual
            -- corresponding to Proc.P.all is 4. Therefore, the P.all'Access
            -- in Proc raises Program_Error when the subprogram is called. The
            -- exception is handled within the subprogram:

            Proc (X_L4'Access, Result2);

            F3A2A00.TC_Display_Results (Result2, F3A2A00.P_E,
                                        "SUBTEST #4: object at deeper level");
         end;

      end;

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #4: Program_Error incorrectly raised " &
                        "during instantiation of generic");
      when others        =>
         Report.Failed ("SUBTEST #4: Unexpected exception raised " &
                        "during instantiation of generic");
   end SUBTEST4;


   Report.Result;

end C3A2A01;
