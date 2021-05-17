

     --=================================================================--


with CB20007_0;                           -- Package Semaphore.
with Report;

procedure CB20007 is
begin

   Test_Block:
   declare

      package Semaphore renames CB20007_0;

      Total_Resources_Available : constant := 1;

      Resources : Semaphore.Counting_Semaphore (Total_Resources_Available);
                                             -- An object of protected type.

   begin

      Report.Test ("CB20007", "Check that exceptions are raised and can "   &
                              "be directly propagated to the calling unit " &
                              "by protected operations" );

      Allocate_Resources:
      declare
         Loop_Count : Integer := Total_Resources_Available + 1;
      begin                                   -- Force exception.
         for I in 1..Loop_Count loop  
            Resources.Secure;
         end loop;
         Report.Failed ("Exception not propagated from protected " &
                        " operation in Allocate_Resources");
      exception                                     
         when Semaphore.Resource_Underflow =>              -- Exception prop.
            Semaphore.Handled_In_Procedure_Caller := True; -- from protected
                                                           -- procedure.
         when others =>
            Report.Failed ("Unknown exception during resource allocation");
      end Allocate_Resources;

   
      Deallocate_Resources:
      declare
         Loop_Count : Integer := Total_Resources_Available + 1;
      begin                                   -- Force exception.
         for I in 1..Loop_Count loop  
            Resources.Release;  
         end loop;
         Report.Failed ("Exception not propagated from protected " &
                        "operation in Deallocate_Resources");
      exception                                     
         when Semaphore.Resource_Overflow =>              -- Exception prop
            Semaphore.Handled_In_Function_Caller := True; -- from protected
                                                          -- function.
         when others =>
            Report.Failed ("Exception raised during resource deallocation");
      end Deallocate_Resources;


      if not (Semaphore.Handled_In_Procedure_Caller and -- Incorrect exception
              Semaphore.Handled_In_Function_Caller)     -- handling in
      then                                              -- protected ops.
          Report.Failed                                 
            ("Improper exception propagation by protected operations");
      end if;

   exception

      when others =>
         Report.Failed ("Unexpected exception " &
                        " raised and propagated in test");
   end Test_Block;


   Report.Result;

end CB20007;
