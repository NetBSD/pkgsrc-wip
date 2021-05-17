
package body B854004A is

   function Count (Obj : in Root) return Natural is
   begin
      return 0;
   end Count;

   procedure Sink (Obj : in Root) is
   begin
      null;
   end Sink;

   function Empty_1 return Root2 is
   begin
      return (null record);
   end Empty_1;

   Empty_Obj : aliased Root2 := (null record);

   function Empty_2 return access Root2 is
   begin
      return Empty_Obj'access;
   end Empty_2;

end B854004A;
