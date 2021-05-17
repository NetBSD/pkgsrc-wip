

     --==================================================================--


with Report;
procedure C460A02_2 (P   : access Designated_Type'Class;
                     Res : out    F460A00.TC_Result_Kind) is
   Ptr : Target_Type;
begin
   Res := F460A00.UN_Init;
   Ptr := Target_Type(P);

   -- Avoid optimization (dead variable removal of Ptr):
   if not Report.Equal (Ptr.C, Ptr.C) then                  -- Always false.
      Report.Failed ("Unexpected error in C460A02_2 instance");
   end if;
   Res := F460A00.OK;
exception
   when Program_Error => Res := F460A00.PE_Exception;
   when others        => Res := F460A00.Others_Exception;
end C460A02_2;
