

     --==================================================================--


with F460A00;
with C460A01_0;
with C460A01_1;
with C460A01_2;

with Report;
procedure C460A01 is
begin -- C460A01.                                              -- [ Level = 1 ]

   Report.Test ("C460A01", "Run-time accessibility checks: instance " &
                "bodies. Operand type of access type conversion is "  &
                "passed as actual to instance");


   SUBTEST1:
   declare                                                     -- [ Level = 2 ]
      type AccTag_L2 is access all F460A00.Tagged_Type;
      Operand: AccTag_L2 := new F460A00.Tagged_Type;

      Result : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST1.

      declare                                                  -- [ Level = 3 ]
         -- The instantiation of C460A01_0 should NOT result in any
         -- exceptions.

         package Pack_OK is new C460A01_0 (F460A00.Tagged_Type, AccTag_L2);
         Target : Pack_OK.Target_Type;
      begin
         -- The accessibility level of Pack_OK.Target_Type will always be at
         -- least as deep as the operand type passed as an actual. Thus,
         -- a call to Pack_OK.Convert does not propagate an exception:

         Target := Pack_OK.Convert(Operand);

         -- Avoid optimization (dead variable removal of Target):
         if not Report.Equal (Target.C, Target.C) then      -- Always false.
            Report.Failed ("Unexpected error in SUBTEST #1");
         end if;

         Result := F460A00.OK;                              -- Expected result.
      exception
         when Program_Error => Result := F460A00.PE_Exception;
         when others        => Result := F460A00.Others_Exception;
      end;

      F460A00.TC_Check_Results (Result, F460A00.OK, "SUBTEST #1");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #1: Program_Error incorrectly raised");
      when others        =>
         Report.Failed ("SUBTEST #1: Unexpected exception raised");
   end SUBTEST1;



   SUBTEST2:
   declare                                                     -- [ Level = 2 ]
      type AccTag_L2 is access all F460A00.Tagged_Type;
      Operand : AccTag_L2 := new F460A00.Tagged_Type;

      Result  : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST2.

      declare                                                  -- [ Level = 3 ]

         type AccTag_L3 is access all F460A00.Tagged_Type;
         Target : AccTag_L3;

         -- The instantiation of C460A01_1 should NOT result in any
         -- exceptions.

         package Pack_OK is new C460A01_1
           (Designated_Type => F460A00.Tagged_Type,
            Operand_Type    => AccTag_L2,
            Target_Type     => AccTag_L3);
      begin
         -- The accessibility level of the actual passed as the operand type
         -- in Pack_OK is 2. The accessibility level of the actual passed as
         -- the target type is 3. Therefore, the access type conversion in
         -- Pack_OK.Convert does not raise an exception when the subprogram is
         -- called. If an exception is (incorrectly) raised, it is propagated 
         -- to the innermost enclosing master:

         Target := Pack_OK.Convert(Operand);

         -- Avoid optimization (dead variable removal of Target):
         if not Report.Equal (Target.C, Target.C) then      -- Always false.
            Report.Failed ("Unexpected error in SUBTEST #2");
         end if;

         Result := F460A00.OK;                              -- Expected result.
      exception
         when Program_Error => Result := F460A00.PE_Exception;
         when others        => Result := F460A00.Others_Exception;
      end;

      F460A00.TC_Check_Results (Result, F460A00.OK, "SUBTEST #2");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #2: Program_Error incorrectly raised");
      when others        =>
         Report.Failed ("SUBTEST #2: Unexpected exception raised");
   end SUBTEST2;



   SUBTEST3:
   declare                                                     -- [ Level = 2 ]
      type AccTag_L2 is access all F460A00.Tagged_Type;
      Target : AccTag_L2;

      Result : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST3.

      declare                                                  -- [ Level = 3 ]

         type AccTag_L3 is access all F460A00.Tagged_Type;
         Operand : AccTag_L3 := new F460A00.Tagged_Type;

         -- The instantiation of C460A01_1 should NOT result in any
         -- exceptions.

         package Pack_PE is new C460A01_1
           (Designated_Type => F460A00.Tagged_Type,
            Operand_Type    => AccTag_L3,
            Target_Type     => AccTag_L2);
      begin
         -- The accessibility level of the actual passed as the operand type
         -- in Pack_PE is 3. The accessibility level of the actual passed as
         -- the target type is 2. Therefore, the access type conversion in
         -- Pack_PE.Convert raises Program_Error when the subprogram is
         -- called. The exception is propagated to the innermost enclosing
         -- master:

         Target := Pack_PE.Convert(Operand);

         -- Avoid optimization (dead variable removal of Target):
         if not Report.Equal (Target.C, Target.C) then      -- Always false.
            Report.Failed ("Unexpected error in SUBTEST #3");
         end if;

         Result := F460A00.OK;
      exception
         when Program_Error => Result := F460A00.PE_Exception; 
                                                          -- Expected result.
         when others        => Result := F460A00.Others_Exception;
      end;

      F460A00.TC_Check_Results (Result, F460A00.PE_Exception, "SUBTEST #3");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #3: Program_Error incorrectly raised");
      when others        =>
         Report.Failed ("SUBTEST #3: Unexpected exception raised");
   end SUBTEST3;



   SUBTEST4:
   declare                                                     -- [ Level = 2 ]
      Result : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST4.

      declare                                                  -- [ Level = 3 ]

         TType   :  F460A00.Tagged_Type;
         Operand :  F460A00.AccTagClass_L0 
                 := new F460A00.Tagged_Type'(TType);

         -- The instantiation of C460A01_2 should NOT result in any
         -- exceptions.

         package Pack_OK is new C460A01_2 (F460A00.Tagged_Type'Class,
                                           F460A00.AccTagClass_L0);
      begin
         -- The accessibility level of the actual passed as the operand type
         -- in Pack_OK is 0. The accessibility level of the target type
         -- (F460A00.AccTag_L0) is also 0. Therefore, the access type
         -- conversion in Pack_OK.Proc does not raise an exception when the
         -- subprogram is called. If an exception is (incorrectly) raised, 
         -- it is handled within the subprogram:

         Pack_OK.Proc(Operand, Result);
      end;

      F460A00.TC_Check_Results (Result, F460A00.OK, "SUBTEST #4");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #4: Program_Error incorrectly raised");
      when others        =>
         Report.Failed ("SUBTEST #4: Unexpected exception raised");
   end SUBTEST4;



   SUBTEST5:
   declare                                                     -- [ Level = 2 ]
      Result : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST5.

      declare                                                  -- [ Level = 3 ]

         type AccDerTag_L3 is access all F460A00.Derived_Tagged_Type;
         Operand : AccDerTag_L3 := new F460A00.Derived_Tagged_Type;

         -- The instantiation of C460A01_2 should NOT result in any
         -- exceptions.

         package Pack_PE is new C460A01_2 (F460A00.Derived_Tagged_Type,
                                           AccDerTag_L3);
      begin
         -- The accessibility level of the actual passed as the operand type
         -- in Pack_PE is 3. The accessibility level of the target type
         -- (F460A00.AccTag_L0) is 0. Therefore, the access type conversion
         -- in Pack_PE.Proc raises Program_Error when the subprogram is
         -- called. The exception is handled within the subprogram:

         Pack_PE.Proc(Operand, Result);
      end;

      F460A00.TC_Check_Results (Result, F460A00.PE_Exception, "SUBTEST #5");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #5: Program_Error incorrectly raised");
      when others        =>
         Report.Failed ("SUBTEST #5: Unexpected exception raised");
   end SUBTEST5;

   Report.Result;

end C460A01;
