

     --==================================================================--


package body FC70C00_1 is

   function End_Of_List (L : List_Mgr.List_Type) return Boolean is
      use List_Mgr;  -- Renders "=" directly visible.
   begin
      return (L.Current = null);
   end End_Of_List;


   procedure Reset (L : in out List_Mgr.List_Type) is
   begin
      L.Current := L.First;                 -- Set "current" pointer to first
   end Reset;                               -- list element.

end FC70C00_1;
