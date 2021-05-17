

     --==================================================================--


with Report;
package body C3A2A02_0 is
   X : aliased FD;

   procedure Proc is
      Ptr : F3A2A00.AccTagClass_L0 := X'Access;
   begin
      -- Avoid optimization (dead variable removal of Ptr):

      if not Report.Equal (Ptr.C, Ptr.C) then              -- Always false.
         Report.Failed ("Unexpected error in Proc");
      end if;
   end Proc;
end C3A2A02_0;
