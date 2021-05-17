

     --==================================================================--


with Report;
procedure C3A2A01_2 (P: access FD; R: out F3A2A00.TC_Result_Kind) is
   Ptr   : FAF;
   Index : Integer := F3A2A00.Array_Type'First;
begin
   Ptr := P.all'Access;
   R   := F3A2A00.OK;

   -- Avoid optimization (dead variable removal of Ptr):

   if not Report.Equal (Ptr(Index).C, Ptr(Index).C) then   -- Always false.
      Report.Failed ("Unexpected error in C3A2A01_2 instance");
   end if;
exception
   when Program_Error => R := F3A2A00.P_E;
   when others        => R := F3A2A00.O_E;
end C3A2A01_2;
