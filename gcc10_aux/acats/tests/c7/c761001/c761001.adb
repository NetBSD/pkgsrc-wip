
with Report;
with C761001_0;

procedure C761001 is

begin  -- Main test procedure.

  Report.Test ("C761001", "Check that controlled objects declared "
                        & "immediately within a library package are "
                        & "finalized following the completion of the "
                        & "environment task (and prior to termination "
                        & "of the program)");

  -- note that if the test DOES call report twice, the first will report a
  -- false pass, the second call will correctly fail the test.

  -- not calling Report.Result;
  -- Result is called as part of the finalization of C761001_0.My_Object.

end C761001;
