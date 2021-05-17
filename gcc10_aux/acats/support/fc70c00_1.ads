

     --==================================================================--


-- No body for FC70C00_0;


     --==================================================================--


with FC70C00_0;                -- List abstraction.
generic
   with package List_Mgr is new FC70C00_0 (<>);
package FC70C00_1 is           -- Basic list operations.

   -- Return true if current element is last in the list.
   function End_Of_List (L : List_Mgr.List_Type) return Boolean;

   -- Set "current" pointer to first list element.
   procedure Reset (L : in out List_Mgr.List_Type);

end FC70C00_1;
