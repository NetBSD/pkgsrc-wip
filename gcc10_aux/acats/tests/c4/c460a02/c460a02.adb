

     --==================================================================--


with F460A00;
with C460A02_0;
with C460A02_1;
with C460A02_2;

with Report;
procedure C460A02 is
begin -- C460A02.                                              -- [ Level = 1 ]

   Report.Test ("C460A02", "Run-time accessibility checks: instance " &
                "bodies. Operand type of access type conversion is "  &
                "declared inside instance or is anonymous");


   SUBTEST1:
   declare                                                     -- [ Level = 2 ]
      type AccTag_L2 is access all F460A00.Tagged_Type;
      PTag_L2    : AccTag_L2 := new F460A00.Tagged_Type;
      Operand_L2 : F460A00.Composite_Type(PTag_L2);

      Result     : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST1.

      begin                                                    -- [ Level = 3 ]
         declare                                               -- [ Level = 4 ]
            -- The accessibility level of the actual passed as the target type
            -- in Pack_OK is 2. The accessibility level of the composite actual
            -- (and thus, the level of the anonymous type of the access
            -- discriminant, which is the same as that of the containing 
            -- object) is also 2. Therefore, the access type conversion in 
            -- Pack_OK does not raise an exception upon instantiation:

            package Pack_OK is new C460A02_0 
              (Target_Type => AccTag_L2, FObj => Operand_L2);
         begin
            Result := F460A00.OK;                           -- Expected result.
         end;
      exception
         when Program_Error => Result := F460A00.PE_Exception;
         when others        => Result := F460A00.Others_Exception;
      end;

      F460A00.TC_Check_Results (Result, F460A00.OK, "SUBTEST #1");

   end SUBTEST1;



   SUBTEST2:
   declare                                                     -- [ Level = 2 ]
      type AccTag_L2 is access all F460A00.Tagged_Type;
      PTag_L2 : AccTag_L2 := new F460A00.Tagged_Type;

      Result  : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST2.

      declare                                                  -- [ Level = 3 ]
         Operand_L3 : F460A00.Composite_Type(PTag_L2);
      begin
         declare                                               -- [ Level = 4 ]
            -- The accessibility level of the actual passed as the target type
            -- in Pack_PE is 2. The accessibility level of the composite actual
            -- (and thus, the level of the anonymous type of the access
            -- discriminant, which is the same as that of the containing 
            -- object) is 3. Therefore, the access type conversion in Pack_PE 
            -- propagates Program_Error upon instantiation:

            package Pack_PE is new C460A02_0 (AccTag_L2, Operand_L3);
         begin
            Result := F460A00.OK;
         end;
      exception
         when Program_Error => Result := F460A00.PE_Exception;       
                                                          -- Expected result.
         when others        => Result := F460A00.Others_Exception;
      end;

      F460A00.TC_Check_Results (Result, F460A00.PE_Exception, "SUBTEST #2");

   end SUBTEST2;



   SUBTEST3:
   declare                                                     -- [ Level = 2 ]
      Result : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST3.

      declare                                                  -- [ Level = 3 ]
         type AccArr_L3 is access all F460A00.Array_Type;
         Target: AccArr_L3;

         -- The accessibility level of the actual passed as the target type
         -- in Pack_OK is 3. The accessibility level of the operand type is
         -- that of the instance, which is also 3. Therefore, the access type
         -- conversion in Pack_OK does not raise an exception upon
         -- instantiation. If an exception is (incorrectly) raised, it is 
         -- handled within the instance:

         package Pack_OK is new C460A02_1
           (Designated_Type => F460A00.Array_Type,
            Target_Type     => AccArr_L3,
            FObj            => Target,
            FRes            => Result);
      begin
         null;
      end;

      F460A00.TC_Check_Results (Result, F460A00.OK, "SUBTEST #3");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #3: Program_Error incorrectly propagated");
      when others        =>
         Report.Failed ("SUBTEST #3: Unexpected exception propagated");
   end SUBTEST3;



   SUBTEST4:
   declare                                                     -- [ Level = 2 ]
      Result : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST4.

      declare                                                  -- [ Level = 3 ]
         Target: F460A00.AccArr_L0;

         -- The accessibility level of the actual passed as the target type
         -- in Pack_PE is 0. The accessibility level of the operand type is
         -- that of the instance, which is 3. Therefore, the access type
         -- conversion in Pack_PE raises Program_Error upon instantiation.
         -- The exception is handled within the instance:

         package Pack_PE is new C460A02_1
           (Designated_Type => F460A00.Array_Type,
            Target_Type     => F460A00.AccArr_L0,
            FObj            => Target,
            FRes            => Result);
      begin
         null;
      end;

      F460A00.TC_Check_Results (Result, F460A00.PE_Exception, "SUBTEST #4");

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
         -- The instantiation of C460A02_2 should NOT result in any
         -- exceptions.

         procedure Proc is new C460A02_2 (F460A00.Tagged_Type,
                                          F460A00.AccTag_L0);
      begin
         -- The accessibility level of the actual passed to Proc is 0. The
         -- accessibility level of the actual passed as the target type is
         -- also 0. Therefore, the access type conversion in Proc does not
         -- raise an exception when the subprogram is called. If an exception
         -- is (incorrectly) raised, it is handled within the subprogram:

         Proc (F460A00.PTagClass_L0, Result);
      end;

      F460A00.TC_Check_Results (Result, F460A00.OK, "SUBTEST #5");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #5: Program_Error incorrectly raised");
      when others        =>
         Report.Failed ("SUBTEST #5: Unexpected exception raised");
   end SUBTEST5;



   SUBTEST6:
   declare                                                     -- [ Level = 2 ]
      Result : F460A00.TC_Result_Kind := F460A00.UN_Init;
   begin -- SUBTEST6.

      declare                                                  -- [ Level = 3 ]
         -- The instantiation of C460A02_2 should NOT result in any
         -- exceptions.

         procedure Proc is new C460A02_2 (F460A00.Tagged_Type,
                                          F460A00.AccTag_L0);
      begin
         -- In the call to (instantiated) procedure Proc, the first actual
         -- parameter is an allocator. Its accessibility level is that of 
         -- the level of execution of Proc, which is 3. The accessibility 
         -- level of the actual passed as the target type is 0.  Therefore, 
         -- the access type conversion in Proc raises Program_Error when the
         -- subprogram is called. The exception is handled within the
         -- subprogram:

         Proc (new F460A00.Tagged_Type, Result);
      end;

      F460A00.TC_Check_Results (Result, F460A00.PE_Exception, "SUBTEST #6");

   exception
      when Program_Error =>
         Report.Failed ("SUBTEST #6: Program_Error incorrectly raised");
      when others        =>
         Report.Failed ("SUBTEST #6: Unexpected exception raised");
   end SUBTEST6;

   Report.Result;

end C460A02;
