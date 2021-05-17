

     --=================================================================--


with CB20006_0;                           -- Package Semaphore.
with Report;

procedure CB20006 is
begin

   Report.Test ("CB20006", "Check that exceptions are raised and " &
                           "handled / reraised and propagated "    &
                           "correctly by protected operations" );

   Test_Block:
   declare

      package Semaphore renames CB20006_0;

      Total_Resources_Available : constant := 1;

      Resources : Semaphore.Counting_Semaphore (Total_Resources_Available);
                                             -- An object of protected type.

   begin

      Allocate_Resources:
      declare
         Loop_Count : Integer := Total_Resources_Available + 1;
      begin
         for I in 1..Loop_Count loop -- Force exception
            Resources.Secure;
         end loop;
         Report.Failed 
           ("Exception not propagated from protected operation Secure");
      exception                                     
         when Semaphore.Resource_Underflow =>        -- Exception propagated
           Semaphore.Handled_In_Procedure_Caller := True;  -- from protected
         when others =>                                    -- procedure.
           Semaphore.Handled_In_Procedure_Caller := False;
      end Allocate_Resources;

   
      Deallocate_Resources:
      declare
         Loop_Count : Integer := Total_Resources_Available + 1;
      begin
         for I in 1..Loop_Count loop -- Force exception
            Resources.Release;  
         end loop;
         Report.Failed 
           ("Exception not propagated from protected operation Release");
      exception                                     
         when Semaphore.Resource_Overflow =>        -- Exception propagated 
            Semaphore.Handled_In_Function_Caller := True; -- from protected
         when others =>                                   -- function.
            Semaphore.Handled_In_Function_Caller := False;
      end Deallocate_Resources;


      if not (Semaphore.Reraised_In_Procedure and
              Semaphore.Reraised_In_Function  and
              Semaphore.Handled_In_Procedure_Caller and
              Semaphore.Handled_In_Function_Caller) 
      then                                       -- Incorrect excpt. handling
         Report.Failed                           -- in protected operations.
           ("Improper exception handling/reraising by protected operations");
      end if;

   exception

      when others =>
         Report.Failed ("Unexpected exception " & 
                        " raised and propagated in test");
   end Test_Block;

   Report.Result;


end CB20006;
