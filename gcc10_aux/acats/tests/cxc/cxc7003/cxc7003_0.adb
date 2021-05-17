

package body CXC7003_0 is
   procedure Finalize (Object : in out Notes_Finalization) is
   begin
      Last_Finalized := Object.Id;
      Object.Id := 0;
   end Finalize;

begin
   Object_1.Id := 1;
   Object_2.Id := 2;
   Object_3.Id := 3;
   Object_4.Id := 4;
end CXC7003_0;
