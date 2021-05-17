

     --==================================================================--


package body CC70001_0 is

   function End_Of_List (L : List_Type) return Boolean is
   begin
      return (L.Current = null);
   end End_Of_List;


   procedure Reset (L : in out List_Type) is
   begin
      L.Current := L.First;                 -- Set "current" pointer to first
   end Reset;                               -- list element.

end CC70001_0;
