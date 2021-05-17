

     --==================================================================--


with F3A2A00;
generic
   type FD is new F3A2A00.Array_Type;
   FObj : in F3A2A00.Tagged_Type;
package C3A2A02_2 is
   type GAF is access all FD;
   type GAO is access constant F3A2A00.Tagged_Type;
   XG    : aliased FD;
   PtrF  : GAF;
   Index : Integer := FD'First;

   procedure Dummy; -- Needed to allow package body.
end C3A2A02_2;
