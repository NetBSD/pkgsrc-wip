

     --==================================================================--

with Report;
package body C460A01_2 is
   procedure Proc (P   : Operand_Type; 
                   Res : out F460A00.TC_Result_Kind) is
      Ptr : F460A00.AccTag_L0;
   begin
      Ptr := F460A00.AccTag_L0(P);

      -- Avoid optimization (dead variable removal of Ptr):
      if not Report.Equal (Ptr.C, Ptr.C) then                  -- Always false.
         Report.Failed ("Unexpected error in C460A01_2 instance");
      end if;

      Res := F460A00.OK;
   exception
      when Program_Error => Res := F460A00.PE_Exception;
      when others        => Res := F460A00.Others_Exception;
   end Proc;
end C460A01_2;
