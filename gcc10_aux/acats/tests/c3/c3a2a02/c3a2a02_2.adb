

     --==================================================================--


with Report;
package body C3A2A02_2 is
   PtrO : GAO := FObj'Access;

   procedure Dummy is
   begin
      null;
   end Dummy;
begin
   PtrF := XG'Access;

   -- Avoid optimization (dead variable removal of PtrO and/or PtrF):

   if not Report.Equal (PtrO.C, PtrO.C) then                -- Always false.
      Report.Failed ("Unexpected error in C3A2A02_2 instance: PtrO");
   end if;

   if not Report.Equal (PtrF(Index).C, PtrF(Index).C) then  -- Always false.
      Report.Failed ("Unexpected error in C3A2A02_2 instance: PtrF");
   end if;
end C3A2A02_2;
