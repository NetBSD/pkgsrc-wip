

     --==================================================================--


with Report;
package body C3A2A02_1 is
   Ptr : F3A2A00.AccTag_L0 := FObj'Access;

   procedure Dummy is
   begin
      null;
   end Dummy;
begin
   -- Avoid optimization (dead variable removal of Ptr):

   if not Report.Equal (Ptr.C, Ptr.C) then              -- Always false.
      Report.Failed ("Unexpected error in C3A2A02_1 instance");
   end if;
end C3A2A02_1;
