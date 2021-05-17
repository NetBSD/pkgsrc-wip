

     --==================================================================--


with Report;
package body C3A2A01_1 is

   procedure Handle (R: out F3A2A00.TC_Result_Kind) is
      Ptr : FAF;
   begin
      Ptr := FObj'Access;
      R   := F3A2A00.OK;

      -- Avoid optimization (dead variable removal of Ptr):

      if not Report.Equal (Ptr.C, Ptr.C) then              -- Always false.
         Report.Failed ("Unexpected error in Handle");
      end if;
   exception
      when Program_Error => R := F3A2A00.P_E;
      when others        => R := F3A2A00.O_E;
   end Handle;

end C3A2A01_1;
