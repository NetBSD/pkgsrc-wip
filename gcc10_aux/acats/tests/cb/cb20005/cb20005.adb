

     --=================================================================--


with CB20005_0;                           -- Package Semaphore.
with Report;

procedure CB20005 is
begin

   Report.Test ("CB20005", "Check that exceptions are raised and handled " &
                           "correctly in protected operations" );

   Test_Block:
   declare

      package Semaphore renames CB20005_0;

      Total_Resources_Available : constant := 1;

      Resources : Semaphore.Counting_Semaphore(Total_Resources_Available);
                                          -- An object of protected type.

   begin

      Allocate_Resources:
      declare
         Loop_Count : Integer := Total_Resources_Available + 1;
      begin
         for I in 1..Loop_Count loop -- Force exception.
            Resources.Secure;
         end loop;
      exception                                     
         when Semaphore.Resource_Underflow =>
            Semaphore.Handled_In_Procedure := False; -- Excptn not handled 
            Report.Failed                            -- in prot. operation.
              ("Resource_Underflow exception not handled " &
               "in Allocate_Resources");
         when others =>
            Report.Failed 
              ("Exception unexpectedly raised during resource allocation");
      end Allocate_Resources;

   
      Deallocate_Resources:
      declare
         Loop_Count : Integer := Total_Resources_Available + 1;
      begin
         for I in 1..Loop_Count loop -- Force excptn.
            Resources.Release;  
         end loop;
      exception                                     
         when Semaphore.Resource_Overflow =>
            Semaphore.Handled_In_Function := False; -- Exception not handled
               Report.Failed                        -- in prot. operation.
                 ("Resource overflow not handled by function");
            when others =>
               Report.Failed 
                 ("Exception raised during resource deallocation"); 
      end Deallocate_Resources;


      if not (Semaphore.Handled_In_Procedure and -- Incorrect excpt. handling
              Semaphore.Handled_In_Function)     -- in protected operations.
      then
         Report.Failed 
           ("Improper exception handling by protected operations");
      end if;


   exception
      when others =>
         Report.Failed ("Exception raised and propagated in test");

   end Test_Block;

   Report.Result;

end CB20005;
